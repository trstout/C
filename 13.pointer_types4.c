#include <stdio.h>

int main() {
    int i;

    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    void *void_pointer;
    void_pointer = (void *) char_array;
    
    for(i=0; i < 5; i++) { // Iterate through the int array with the int_pointer.
        printf("[char pointer] points to %p, which contains the char '%c'\n",
            void_pointer, *((char *) void_pointer));
        void_pointer = (void *) ((char *) void_pointer + 1);
    }

    void_pointer = (void *) int_array;

    for(i=0; i < 5; i++) { // Iterate through the int array with the int_pointer.
        printf("[integer pointer] points to %p, which contains the integer %d\n",
            void_pointer, *((int *) void_pointer));
        void_pointer = (void *) ((int *) void_pointer + 1);
    }
}

/* └─$ ./pointer_types4
[char pointer] points to 0x7ffeabccdedb, which contains the char 'a'
[char pointer] points to 0x7ffeabccdedc, which contains the char 'b'
[char pointer] points to 0x7ffeabccdedd, which contains the char 'c'
[char pointer] points to 0x7ffeabccdede, which contains the char 'd'
[char pointer] points to 0x7ffeabccdedf, which contains the char 'e'
[integer pointer] points to 0x7ffeabccdec0, which contains the integer 1
[integer pointer] points to 0x7ffeabccdec4, which contains the integer 2
[integer pointer] points to 0x7ffeabccdec8, which contains the integer 3
[integer pointer] points to 0x7ffeabccdecc, which contains the integer 4
[integer pointer] points to 0x7ffeabccded0, which contains the integer 5 */
