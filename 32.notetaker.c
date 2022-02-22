#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

void usage(char *prog_name, char *filename) {
    printf("Usage: %s <data to add to %s>\n", prog_name, filename);
    exit(0);
}

void fatal(char *); // A function for fatal errors
void *ec_malloc(unsigned int); // An error-checked malloc() wrapper

int main(int argc, char *argv[]) {
    int userid, fd; // File descriptor
    char *buffer, *datafile;
    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);
    strcpy(datafile, "/var/notes");
    if(argc < 2) // If there aren't command-line arguments,
        usage(argv[0], datafile); // display usage message and exit.
 
    strcpy(buffer, argv[1]); // Copy into buffer.
    printf("[DEBUG] buffer @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

// Opening the file
    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
    if(fd == -1)
        fatal("in main() while opening file");
    printf("[DEBUG] file descriptor is %d\n", fd);
    userid = getuid(); // Get the real user ID.

// Writing data
    if(write(fd, &userid, 4) == -1) // Write user ID before note data.
        fatal("in main() while writing userid to file");
    write(fd, "\n", 1); // Terminate line.
    
    if(write(fd, buffer, strlen(buffer)) == -1) // Write note.
        fatal("in main() while writing buffer to file");
    write(fd, "\n", 1); // Terminate line.

// Closing file
    if(close(fd) == -1)
        fatal("in main() while closing file");
    printf("Note has been saved.\n");
    free(buffer);
    free(datafile);
}

/* └─$ sudo chown root:root ./notetaker
└─$ sudo chmod u+s ./notetaker 
└─$ ls -l ./notetaker 
-rwsr-xr-x 1 root root 16832 Feb 16 01:47 ./notetaker
└─$ ./notetaker "this is a note for jose"
[DEBUG] buffer @ 0x563c5a1492a0: 'this is a note for jose'
[DEBUG] datafile @ 0x563c5a149310: '/var/notes'
[DEBUG] file descriptor is 3
Note has been saved. */

/* └─$ sudo hexdump -C /var/notes
00000000  e8 03 00 00 0a 74 68 69  73 20 69 73 20 61 20 6e  |.....this is a n|
00000010  6f 74 65 20 66 6f 72 20  6a 6f 73 65 0a           |ote for jose.|
0000001d */