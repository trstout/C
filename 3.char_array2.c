#include <stdio.h>
#include <string.h>

int main() {
    char str_a[20];

    strcpy(str_a, "Hello, world!\n");
    printf(str_a);
}

/* └─$ ./char_array2
Hello, world! */