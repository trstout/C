#include <stdio.h>

void function() { // An example function, with its own context
    int var = 5;
    static int static_var = 5; // Static variable initialization
    printf("\t[in function] var @ %p = %d\n", &var, var);
    printf("\t[in function] static_var @ %p = %d\n", &static_var, static_var);
    var++; // Add 1 to var.
    static_var++; // Add 1 to static_var.
}

int main() { // The main function, with its own context
    int i;
    static int static_var = 1337; // Another static, in a different context
    
    for(i=0; i < 5; i++) { // loop 5 times
        printf("[in main] static_var @ %p = %d\n", &static_var, static_var);
        function(); // Call the function.
    }
}

/* [in main] static_var @ 0x564cbda85034 = 1337
        [in function] var @ 0x7fffb06c124c = 5
        [in function] static_var @ 0x564cbda85030 = 5
[in main] static_var @ 0x564cbda85034 = 1337
        [in function] var @ 0x7fffb06c124c = 5
        [in function] static_var @ 0x564cbda85030 = 6
[in main] static_var @ 0x564cbda85034 = 1337
        [in function] var @ 0x7fffb06c124c = 5
        [in function] static_var @ 0x564cbda85030 = 7
[in main] static_var @ 0x564cbda85034 = 1337
        [in function] var @ 0x7fffb06c124c = 5
        [in function] static_var @ 0x564cbda85030 = 8
[in main] static_var @ 0x564cbda85034 = 1337
        [in function] var @ 0x7fffb06c124c = 5
        [in function] static_var @ 0x564cbda85030 = 9 */

/*         "You may have noticed that the addresses of the local variables all have very
high addresses, like 0xbffff814, while the global and static variables all have
very low memory addresses, like 0x0804968c and 0x8049688. That’s very astute
of you—noticing details like this and asking why is one of the cornerstones of
hacking. Read on for your answers." */