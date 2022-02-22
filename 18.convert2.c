#include <stdio.h>

void usage(char *program_name) {
    printf("Usage: %s <message> <# of times to repeat>\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    int i, count;

// if(argc < 3) // If fewer than 3 arguments are used,
// usage(argv[0]); // display usage message and exit.
    
    count = atoi(argv[2]); // Convert the 2nd arg into an integer.
    printf("Repeating %d times..\n", count);
    
    for(i=0; i < count; i++)
        printf("%3d - %s\n", i, argv[1]); // Print the 1st arg.
}

/* convert2.c: In function ‘usage’:
convert2.c:5:5: warning: implicit declaration of function ‘exit’ [-Wimplicit-function-declaration]
    5 |     exit(1);
      |     ^~~~
convert2.c:2:1: note: include ‘<stdlib.h>’ or provide a declaration of ‘exit’
    1 | #include <stdio.h>
  +++ |+#include <stdlib.h>
    2 | 
convert2.c:5:5: warning: incompatible implicit declaration of built-in function ‘exit’ [-Wbuiltin-declaration-mismatch]
    5 |     exit(1);
      |     ^~~~
convert2.c:5:5: note: include ‘<stdlib.h>’ or provide a declaration of ‘exit’
convert2.c: In function ‘main’:
convert2.c:14:13: warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
   14 |     count = atoi(argv[2]); // Convert the 2nd arg into an integer.
      |             ^~~~
                               

./convert2 test   
zsh: segmentation fault  ./convert2 test

./convert2 test 5                                                                                139 ⨯
Repeating 5 times..
  0 - test
  1 - test
  2 - test
  3 - test
  4 - test */

/* gdb -q convert2           
Reading symbols from convert2...
(No debugging symbols found in convert2)
(gdb) run test
Starting program: /home/omit/Projects/C/convert2 test

Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7e24f78 in ?? () from /lib/x86_64-linux-gnu/libc.so.6
(gdb) where
#0  0x00007ffff7e24f78 in ?? () from /lib/x86_64-linux-gnu/libc.so.6
#1  0x00007ffff7e21a30 in atoi () from /lib/x86_64-linux-gnu/libc.so.6
#2  0x00005555555551b1 in main () */