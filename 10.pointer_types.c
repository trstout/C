#include <stdio.h>

int main() {
    int i;

    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    char *char_pointer;
    int *int_pointer;

    char_pointer = char_array;
    int_pointer = int_array;

    for(i=0; i < 5; i++) { // Iterate through the int array with the int_pointer.
        printf("[integer pointer] points to %p, which contains the integer %d\n",
            int_pointer, *int_pointer);
        int_pointer = int_pointer + 1;
    }

    for(i=0; i < 5; i++) { // Iterate through the char array with the char_pointer.
        printf("[char pointer] points to %p, which contains the char '%c'\n",
            char_pointer, *char_pointer);
        char_pointer = char_pointer + 1;
    }
}

/* └─$ ./pointer_types 
[integer pointer] points to 0x7ffce29729f0, which contains the integer 1
[integer pointer] points to 0x7ffce29729f4, which contains the integer 2
[integer pointer] points to 0x7ffce29729f8, which contains the integer 3
[integer pointer] points to 0x7ffce29729fc, which contains the integer 4
[integer pointer] points to 0x7ffce2972a00, which contains the integer 5
[char pointer] points to 0x7ffce2972a13, which contains the char 'a'
[char pointer] points to 0x7ffce2972a14, which contains the char 'b'
[char pointer] points to 0x7ffce2972a15, which contains the char 'c'
[char pointer] points to 0x7ffce2972a16, which contains the char 'd'
[char pointer] points to 0x7ffce2972a17, which contains the char 'e' */