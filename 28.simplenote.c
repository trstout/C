#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>


void usage(char *prog_name, char *filename) {
    printf("Usage: %s <data to add to %s>\n", prog_name, filename);
    exit(0);
}

void fatal(char *); // A function for fatal errors
void *ec_malloc(unsigned int); // An error-checked malloc() wrapper

int main(int argc, char *argv[]) {
    int userid, fd; // File descripter
    //int fd; // file descriptor
    char *buffer, *datafile;

    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);
    strcpy(datafile, "/tmp/notes");

    if(argc < 2) // If there aren't command-line arguments,
        usage(argv[0], datafile); // display usage message and exit.
    strcpy(buffer, argv[1]); // Copy into buffer.
    
    printf("[DEBUG] buffer @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);
    
    strncat(buffer, "\n", 1); // Add a newline on the end.

// Opening file
    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
    if(fd == -1)
        fatal("in main() while opening file");
    printf("[DEBUG] file descriptor is %d\n", fd);

    userid = getuid(); // Get the real UID.

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

// A function to display an error message and then exit
void fatal(char *message) {
    char error_message[100];
    
    strcpy(error_message, "[!!] Fatal Error ");
    strncat(error_message, message, 83);
    perror(error_message);
    exit(-1);
}

// An error-checked malloc() wrapper function
void *ec_malloc(unsigned int size) {
    void *ptr;
    ptr = malloc(size);
    if(ptr == NULL)
        fatal("in ec_malloc() on memory allocation");
    return ptr;
}

// Compiler Notes:
/* 28.simplenote.c: In function ‘main’:
28.simplenote.c:38:8: warning: implicit declaration of function ‘write’; did you mean ‘fwrite’? [-Wimplicit-function-declaration]
   38 |     if(write(fd, buffer, strlen(buffer)) == -1)
      |        ^~~~~
      |        fwrite
28.simplenote.c:41:8: warning: implicit declaration of function ‘close’; did you mean ‘pclose’? [-Wimplicit-function-declaration]
   41 |     if(close(fd) == -1)
      |        ^~~~~
      |        pclose
28.simplenote.c:30:5: warning: ‘strncat’ specified bound 1 equals source length [-Wstringop-overflow=]
   30 |     strncat(buffer, "\n", 1); // Add a newline on the end. */

// Test
/* ./simplenote "does this work???"
[DEBUG] buffer @ 0x55abdea4e2a0: 'does this work???'
[DEBUG] datafile @ 0x55abdea4e310: '/tmp/notes'
[DEBUG] file descriptor is 3
Note has been saved.
                                                                                                           
┌──[~/Projects/C]
└─$ cat /tmp/notes
does this work??? */