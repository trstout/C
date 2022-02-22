#include <stdio.h>
#include <string.h>

int main() {
    char message[14];
    int count, i;

    strcpy(message, "Hello, world!");

    printf("Repeat how many times? ");
    scanf("%d", &count);

    for(i=0; i < count; i++)
        printf("%3d - %s\n", i, message);
}

/* └─$ ./input      
Repeat how many times? 10
  0 - Hello, world!
  1 - Hello, world!
  2 - Hello, world!
  3 - Hello, world!
  4 - Hello, world!
  5 - Hello, world!
  6 - Hello, world!
  7 - Hello, world!
  8 - Hello, world!
  9 - Hello, world! */
                    