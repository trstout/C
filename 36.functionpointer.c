#include <stdio.h>

int func_one() {
    printf("This is function one\n");
    return 1;
}

int func_two() {
    printf("This is function two\n");
    return 2;
}

int main() {
    int value;
    int (*function_ptr) ();
 
    function_ptr = func_one;
    printf("function_ptr is 0x%08x\n", function_ptr);
    value = function_ptr();
    printf("value returned was %d\n", value);
    
    function_ptr = func_two;
    printf("function_ptr is 0x%08x\n", function_ptr);
    value = function_ptr();
    printf("value returned was %d\n", value);
}

/* └─$ ./functionpointer
function_ptr is 0x44ffd149
This is function one
value returned was 1
function_ptr is 0x44ffd163
This is function two
value returned was 2 */