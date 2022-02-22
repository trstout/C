#include <stdio.h>

int main() {
    int i;

    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    char *char_pointer;
    int *int_pointer;

    char_pointer = (char *) int_array; // Typecast into the
    int_pointer = (int *) char_array; // pointer's data type.

    for(i=0; i < 5; i++) { // Iterate through the int array with the int_pointer.
        printf("[integer pointer] points to %p, which contains the char '%c'\n",
            int_pointer, *int_pointer);
        int_pointer = (int *) ((char *) int_pointer + 1);
    }

    for(i=0; i < 5; i++) { // Iterate through the char array with the char_pointer.
        printf("[char pointer] points to %p, which contains the integer %d\n",
            char_pointer, *char_pointer);
        char_pointer = (char *) ((int *) char_pointer + 1);
    }
}

/* └─$ ./pointer_types3
[integer pointer] points to 0x7ffed19bfec3, which contains the char 'a'
[integer pointer] points to 0x7ffed19bfec4, which contains the char 'b'
[integer pointer] points to 0x7ffed19bfec5, which contains the char 'c'
[integer pointer] points to 0x7ffed19bfec6, which contains the char 'd'
[integer pointer] points to 0x7ffed19bfec7, which contains the char 'e'
[char pointer] points to 0x7ffed19bfea0, which contains the integer 1
[char pointer] points to 0x7ffed19bfea4, which contains the integer 2
[char pointer] points to 0x7ffed19bfea8, which contains the integer 3
[char pointer] points to 0x7ffed19bfeac, which contains the integer 4
[char pointer] points to 0x7ffed19bfeb0, which contains the integer 5 */