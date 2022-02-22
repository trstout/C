#include <stdio.h>

void usage(char *program_name) {
    printf("Usage: %s <message> <# of times to repeat>\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    int i, count;

    if(argc < 3) // If fewer than 3 arguments are used,
        usage(argv[0]); // display usage message and exit.

    count = atoi(argv[2]); // Convert the 2nd arg into an integer.
    printf("Repeating %d times..\n", count);
    
    for(i=0; i < count; i++)
        printf("%3d - %s\n", i, argv[1]); // Print the 1st arg.
}

/* gcc error message:
convert.c: In function ‘usage’:
convert.c:5:5: warning: implicit declaration of function ‘exit’ [-Wimplicit-function-declaration]
    5 |     exit(1);
      |     ^~~~
convert.c:2:1: note: include ‘<stdlib.h>’ or provide a declaration of ‘exit’
    1 | #include <stdio.h>
  +++ |+#include <stdlib.h>
    2 | 
convert.c:5:5: warning: incompatible implicit declaration of built-in function ‘exit’ [-Wbuiltin-declaration-mismatch]
    5 |     exit(1);
      |     ^~~~
convert.c:5:5: note: include ‘<stdlib.h>’ or provide a declaration of ‘exit’
convert.c: In function ‘main’:
convert.c:13:13: warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
   13 |     count = atoi(argv[2]); // Convert the 2nd arg into an integer. */

/* output examples: 
./convert                        
Usage: ./convert <message> <# of times to repeat> */

/* ./convert Hello! 5       
Repeating 5 times..
  0 - Hello!
  1 - Hello!
  2 - Hello!
  3 - Hello!
  4 - Hello! */