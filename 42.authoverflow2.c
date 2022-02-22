#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_authentication(char *password) {
    char password_buffer[16];
    int auth_flag = 0;
    
    strcpy(password_buffer, password);
    
    if(strcmp(password_buffer, "brillig") == 0)
        auth_flag = 1;
    if(strcmp(password_buffer, "outgrabe") == 0)
        auth_flag = 1;
    
    return auth_flag;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <password>\n", argv[0]);
        exit(0);
    }
    if(check_authentication(argv[1])) {
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf(" Access Granted.\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    } else {
        printf("\nAccess Denied.\n");
    }
}

/* └─$ gdb -q ./a.out           
Reading symbols from ./a.out...
(gdb) list 1
1       #include <stdio.h>
2       #include <stdlib.h>
3       #include <string.h>
4
5       int check_authentication(char *password) {
6           char password_buffer[16];
7           int auth_flag = 0;
8           
9           strcpy(password_buffer, password);
10          
(gdb) 
11          if(strcmp(password_buffer, "brillig") == 0)
12              auth_flag = 1;
13          if(strcmp(password_buffer, "outgrabe") == 0)
14              auth_flag = 1;
15          
16          return auth_flag;
17      }
18
19      int main(int argc, char *argv[]) {
20          if(argc < 2) {
(gdb) break 9
Breakpoint 1 at 0x118c: file 42.authoverflow2.c, line 9.
(gdb) break 16
Breakpoint 2 at 0x11e1: file 42.authoverflow2.c, line 16.
(gdb) run AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
Starting program: /home/omit/Projects/Code/C/a.out AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

Breakpoint 1, check_authentication (password=0x7fffffffe0f9 'A' <repeats 30 times>)
    at 42.authoverflow2.c:9
9           strcpy(password_buffer, password);
(gdb) x/s password_buffer
0x7fffffffdbd0: ""
(gdb) x/x &auth_flag
0x7fffffffdbec: 0x00
(gdb) x/16xw &auth_flag
0x7fffffffdbec: 0x00000000      0xffffdc10      0x00007fff      0x55555236
0x7fffffffdbfc: 0x00005555      0xffffdd08      0x00007fff      0x00000000
0x7fffffffdc0c: 0x00000002      0x00000000      0x00000000      0xf7e0b7ed
0x7fffffffdc1c: 0x00007fff      0xffffdd08      0x00007fff      0xf7fca000
(gdb) continue
Continuing.

Breakpoint 2, check_authentication (password=0x7fffffffe0f9 'A' <repeats 30 times>)
    at 42.authoverflow2.c:16
16          return auth_flag;
(gdb) x/s password_buffer
0x7fffffffdbd0: 'A' <repeats 30 times>
(gdb) x/x &auth_flag
0x7fffffffdbec: 0x41
(gdb) x/16xw &auth_flag
0x7fffffffdbec: 0x00004141      0xffffdc10      0x00007fff      0x55555236
0x7fffffffdbfc: 0x00005555      0xffffdd08      0x00007fff      0x00000000
0x7fffffffdc0c: 0x00000002      0x00000000      0x00000000      0xf7e0b7ed
0x7fffffffdc1c: 0x00007fff      0xffffdd08      0x00007fff      0xf7fca000
(gdb) c
Continuing.

-=-=-=-=-=-=-=-=-=-=-=-=-=-
 Access Granted.
-=-=-=-=-=-=-=-=-=-=-=-=-=-
[Inferior 1 (process 2093378) exited normally]
(gdb)  */