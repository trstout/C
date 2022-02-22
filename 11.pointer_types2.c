#include <stdio.h>
int main() {
    int i;

    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    char *char_pointer;
    int *int_pointer;

    char_pointer = int_array; // The char_pointer and int_pointer now
    int_pointer = char_array; // point to incompatible data types.

    for(i=0; i < 5; i++) { // Iterate through the int array with the int_pointer.
        printf("[integer pointer] points to %p, which contains the char '%c'\n",
            int_pointer, *int_pointer);
        int_pointer = int_pointer + 1;
    }

    for(i=0; i < 5; i++) { // Iterate through the char array with the char_pointer.
        printf("[char pointer] points to %p, which contains the integer %d\n",
            char_pointer, *char_pointer);
        char_pointer = char_pointer + 1;
    }
}
// gcc will print the following errors:

/* pointer_types2.c: In function ‘main’:
pointer_types2.c:11:18: warning: assignment to ‘char *’ from incompatible pointer type ‘int *’ [-Wincompatible-pointer-types]
   11 |     char_pointer = int_array; // The char_pointer and int_pointer now
      |                  ^
pointer_types2.c:12:17: warning: assignment to ‘int *’ from incompatible pointer type ‘char *’ [-Wincompatible-pointer-types]
   12 |     int_pointer = char_array; // point to incompatible data types.
      |                 ^ */

/* └─$ ./pointer_types2
[integer pointer] points to 0x7fffedb648b3, which contains the char 'a'
[integer pointer] points to 0x7fffedb648b7, which contains the char 'e'
[integer pointer] points to 0x7fffedb648bb, which contains the char '�'
[integer pointer] points to 0x7fffedb648bf, which contains the char ''
[integer pointer] points to 0x7fffedb648c3, which contains the char '�'
[char pointer] points to 0x7fffedb64890, which contains the integer 1
[char pointer] points to 0x7fffedb64891, which contains the integer 0
[char pointer] points to 0x7fffedb64892, which contains the integer 0
[char pointer] points to 0x7fffedb64893, which contains the integer 0
[char pointer] points to 0x7fffedb64894, which contains the integer 2 */