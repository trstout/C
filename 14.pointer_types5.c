#include <stdio.h>

int main() {
    int i;

    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    unsigned int hacky_nonpointer;

    hacky_nonpointer = (unsigned int) char_array;

    for(i=0; i < 5; i++) { // Iterate through the int array with the int_pointer.
        printf("[hacky_nonpointer] points to %p, which contains the char '%c'\n",hacky_nonpointer, *((char *) hacky_nonpointer));
        hacky_nonpointer = hacky_nonpointer + sizeof(char);
    }

    hacky_nonpointer = (unsigned int) int_array;

    for(i=0; i < 5; i++) { // Iterate through the int array with the int_pointer.
        printf("[hacky_nonpointer] points to %p, which contains the integer %d\n",hacky_nonpointer, *((int *) hacky_nonpointer));
        hacky_nonpointer = hacky_nonpointer + sizeof(int);
    }
}

// 'hacky_nonpointer' for a reason:

/* gcc pointer_types5.c -o pointer_types5
pointer_types5.c: In function ‘main’:
pointer_types5.c:11:24: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
   11 |     hacky_nonpointer = (unsigned int) char_array;
      |                        ^
pointer_types5.c:15:33: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
   15 |             hacky_nonpointer, *((char *) hacky_nonpointer));
      |                                 ^
pointer_types5.c:19:24: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
   19 |     hacky_nonpointer = (unsigned int) int_array;
      |                        ^
pointer_types5.c:23:33: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
   23 |             hacky_nonpointer, *((int *) hacky_nonpointer));
      |                                 ^ */