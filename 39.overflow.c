#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
    int value = 5;
    char buffer_one[8], buffer_two[8];
    
    strcpy(buffer_one, "one"); /* Put "one" into buffer_one. */
    strcpy(buffer_two, "two"); /* Put "two" into buffer_two. */
    
    printf("[BEFORE] buffer_two is at %p and contains \'%s\'\n", buffer_two, buffer_two);
    printf("[BEFORE] buffer_one is at %p and contains \'%s\'\n", buffer_one, buffer_one);
    printf("[BEFORE] value is at %p and is %d (0x%08x)\n", &value, value, value);
    
    printf("\n[STRCPY] copying %d bytes into buffer_two\n\n", strlen(argv[1]));
    strcpy(buffer_two, argv[1]); /* Copy first argument into buffer_two. */
    
    printf("[AFTER] buffer_two is at %p and contains \'%s\'\n", buffer_two, buffer_two);
    printf("[AFTER] buffer_one is at %p and contains \'%s\'\n", buffer_one, buffer_one);
    printf("[AFTER] value is at %p and is %d (0x%08x)\n", &value, value, value);
}

/* └─$ ./overflow 123456789
[BEFORE] buffer_two is at 0x7ffef4281c7c and contains 'two'
[BEFORE] buffer_one is at 0x7ffef4281c84 and contains 'one'
[BEFORE] value is at 0x7ffef4281c8c and is 5 (0x00000005)

[STRCPY] copying 9 bytes into buffer_two

[AFTER] buffer_two is at 0x7ffef4281c7c and contains '123456789'
[AFTER] buffer_one is at 0x7ffef4281c84 and contains '9'
[AFTER] value is at 0x7ffef4281c8c and is 5 (0x00000005) */

// OVERFLOW:

/* └─$ ./overflow $(python -c 'print "A"*100')
[BEFORE] buffer_two is at 0x7ffff3324b8c and contains 'two'
[BEFORE] buffer_one is at 0x7ffff3324b94 and contains 'one'
[BEFORE] value is at 0x7ffff3324b9c and is 5 (0x00000005)

[STRCPY] copying 100 bytes into buffer_two

[AFTER] buffer_two is at 0x7ffff3324b8c and contains 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA'
[AFTER] buffer_one is at 0x7ffff3324b94 and contains 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA'
[AFTER] value is at 0x7ffff3324b9c and is 1094795585 (0x41414141)
zsh: segmentation fault  ./overflow $(python -c 'print "A"*100') */