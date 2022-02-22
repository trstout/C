void test_function(int a, int b, int c, int d) {
    int flag;
    char buffer[10];

    flag = 31337;
    buffer[0] = 'A';
}

int main() {
    test_function(1, 2, 3, 4);
}

/* └─$ gdb -q stack_example                      
Reading symbols from stack_example...
(gdb) disass main
Dump of assembler code for function main:
   0x0000000000001147 <+0>:     push   rbp
   0x0000000000001148 <+1>:     mov    rbp,rsp
   0x000000000000114b <+4>:     mov    ecx,0x4
   0x0000000000001150 <+9>:     mov    edx,0x3
   0x0000000000001155 <+14>:    mov    esi,0x2
   0x000000000000115a <+19>:    mov    edi,0x1
   0x000000000000115f <+24>:    call   0x1129 <test_function>
   0x0000000000001164 <+29>:    mov    eax,0x0
   0x0000000000001169 <+34>:    pop    rbp
   0x000000000000116a <+35>:    ret   
End of assembler dump. */

/* (gdb) disass test_function
Dump of assembler code for function test_function:
   0x0000000000001129 <+0>:     push   rbp
   0x000000000000112a <+1>:     mov    rbp,rsp
   0x000000000000112d <+4>:     mov    DWORD PTR [rbp-0x14],edi
   0x0000000000001130 <+7>:     mov    DWORD PTR [rbp-0x18],esi
   0x0000000000001133 <+10>:    mov    DWORD PTR [rbp-0x1c],edx
   0x0000000000001136 <+13>:    mov    DWORD PTR [rbp-0x20],ecx
   0x0000000000001139 <+16>:    mov    DWORD PTR [rbp-0x4],0x7a69
   0x0000000000001140 <+23>:    mov    BYTE PTR [rbp-0xe],0x41
   0x0000000000001144 <+27>:    nop
   0x0000000000001145 <+28>:    pop    rbp
   0x0000000000001146 <+29>:    ret    
End of assembler dump. */

/* (gdb) list main
3           char buffer[10];
4           
5           flag = 31337;
6           buffer[0] = 'A';
7       }
8
9       int main() {
10          test_function(1, 2, 3, 4);
11      } */