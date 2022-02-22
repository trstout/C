#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *errorchecked_malloc(unsigned int); // Function prototype for errorchecked_malloc()

int main(int argc, char *argv[]) {
    char *char_ptr; // A char pointer
    int *int_ptr; // An integer pointer
    int mem_size;
    
    if (argc < 2) // If there aren't command-line arguments,
        mem_size = 50; // use 50 as the default value.
    else
        mem_size = atoi(argv[1]);
    
    printf("\t[+] allocating %d bytes of memory on the heap for char_ptr\n", mem_size);
    char_ptr = (char *) errorchecked_malloc(mem_size); // Allocating heap memory
    
    strcpy(char_ptr, "This is memory is located on the heap.");
    printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);
    printf("\t[+] allocating 12 bytes of memory on the heap for int_ptr\n");
    int_ptr = (int *) errorchecked_malloc(12); // Allocated heap memory again
    
    *int_ptr = 31337; // Put the value of 31337 where int_ptr is pointing.
    printf("int_ptr (%p) --> %d\n", int_ptr, *int_ptr);
    
    printf("\t[-] freeing char_ptr's heap memory...\n");
    free(char_ptr); // Freeing heap memory
    
    printf("\t[+] allocating another 15 bytes for char_ptr\n");
    char_ptr = (char *) errorchecked_malloc(15); // Allocating more heap memory
    
    strcpy(char_ptr, "new memory");
    printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);
    
    printf("\t[-] freeing int_ptr's heap memory...\n");
    free(int_ptr); // Freeing heap memory
    printf("\t[-] freeing char_ptr's heap memory...\n");
    free(char_ptr); // Freeing the other block of heap memory
}

void *errorchecked_malloc(unsigned int size) { // An error-checked malloc() function
    void *ptr;
    ptr = malloc(size);
    if(ptr == NULL) {
        fprintf(stderr, "Error: could not allocate heap memory.\n");
        exit(-1);
    }
    return ptr;
}

/* └─$ ./errorchecked_heap 
        [+] allocating 50 bytes of memory on the heap for char_ptr
char_ptr (0x55dfb04c66b0) --> 'This is memory is located on the heap.'
        [+] allocating 12 bytes of memory on the heap for int_ptr
int_ptr (0x55dfb04c66f0) --> 31337
        [-] freeing char_ptr's heap memory...
        [+] allocating another 15 bytes for char_ptr
char_ptr (0x55dfb04c6710) --> 'new memory'
        [-] freeing int_ptr's heap memory...
        [-] freeing char_ptr's heap memory... */

/* (gdb) disass main
Dump of assembler code for function main:
   0x0000000000001199 <+0>:     push   rbp
   0x000000000000119a <+1>:     mov    rbp,rsp
   0x000000000000119d <+4>:     sub    rsp,0x30
   0x00000000000011a1 <+8>:     mov    DWORD PTR [rbp-0x24],edi
   0x00000000000011a4 <+11>:    mov    QWORD PTR [rbp-0x30],rsi
   0x00000000000011a8 <+15>:    cmp    DWORD PTR [rbp-0x24],0x1
   0x00000000000011ac <+19>:    jg     0x11b7 <main+30>
   0x00000000000011ae <+21>:    mov    DWORD PTR [rbp-0x4],0x32
   0x00000000000011b5 <+28>:    jmp    0x11cd <main+52>
   0x00000000000011b7 <+30>:    mov    rax,QWORD PTR [rbp-0x30]
   0x00000000000011bb <+34>:    add    rax,0x8
   0x00000000000011bf <+38>:    mov    rax,QWORD PTR [rax]
   0x00000000000011c2 <+41>:    mov    rdi,rax
   0x00000000000011c5 <+44>:    call   0x1070 <atoi@plt>
   0x00000000000011ca <+49>:    mov    DWORD PTR [rbp-0x4],eax
   0x00000000000011cd <+52>:    mov    eax,DWORD PTR [rbp-0x4]
   0x00000000000011d0 <+55>:    mov    esi,eax
   0x00000000000011d2 <+57>:    lea    rax,[rip+0xe2f]        # 0x2008
   0x00000000000011d9 <+64>:    mov    rdi,rax
--Type <RET> for more, q to quit, c to continue without paging--
   0x00000000000011dc <+67>:    mov    eax,0x0
   0x00000000000011e1 <+72>:    call   0x1050 <printf@plt>
   0x00000000000011e6 <+77>:    mov    eax,DWORD PTR [rbp-0x4]
   0x00000000000011e9 <+80>:    mov    edi,eax
   0x00000000000011eb <+82>:    call   0x1356 <errorchecked_malloc>
   0x00000000000011f0 <+87>:    mov    QWORD PTR [rbp-0x10],rax
   0x00000000000011f4 <+91>:    mov    rax,QWORD PTR [rbp-0x10]
   0x00000000000011f8 <+95>:    movabs rsi,0x2073692073696854
   0x0000000000001202 <+105>:   movabs rdi,0x692079726f6d656d
   0x000000000000120c <+115>:   mov    QWORD PTR [rax],rsi
   0x000000000000120f <+118>:   mov    QWORD PTR [rax+0x8],rdi
   0x0000000000001213 <+122>:   movabs rsi,0x657461636f6c2073
   0x000000000000121d <+132>:   movabs rdi,0x656874206e6f2064
   0x0000000000001227 <+142>:   mov    QWORD PTR [rax+0x10],rsi
   0x000000000000122b <+146>:   mov    QWORD PTR [rax+0x18],rdi
   0x000000000000122f <+150>:   mov    DWORD PTR [rax+0x20],0x61656820
   0x0000000000001236 <+157>:   mov    WORD PTR [rax+0x24],0x2e70
   0x000000000000123c <+163>:   mov    BYTE PTR [rax+0x26],0x0
   0x0000000000001240 <+167>:   mov    rdx,QWORD PTR [rbp-0x10]
   0x0000000000001244 <+171>:   mov    rax,QWORD PTR [rbp-0x10]
--Type <RET> for more, q to quit, c to continue without paging--
   0x0000000000001248 <+175>:   mov    rsi,rax
   0x000000000000124b <+178>:   lea    rax,[rip+0xdf3]        # 0x2045
   0x0000000000001252 <+185>:   mov    rdi,rax
   0x0000000000001255 <+188>:   mov    eax,0x0
   0x000000000000125a <+193>:   call   0x1050 <printf@plt>
   0x000000000000125f <+198>:   lea    rax,[rip+0xdfa]        # 0x2060
   0x0000000000001266 <+205>:   mov    rdi,rax
   0x0000000000001269 <+208>:   call   0x1040 <puts@plt>
   0x000000000000126e <+213>:   mov    edi,0xc
   0x0000000000001273 <+218>:   call   0x1356 <errorchecked_malloc>
   0x0000000000001278 <+223>:   mov    QWORD PTR [rbp-0x18],rax
   0x000000000000127c <+227>:   mov    rax,QWORD PTR [rbp-0x18]
   0x0000000000001280 <+231>:   mov    DWORD PTR [rax],0x7a69
   0x0000000000001286 <+237>:   mov    rax,QWORD PTR [rbp-0x18]
   0x000000000000128a <+241>:   mov    edx,DWORD PTR [rax]
   0x000000000000128c <+243>:   mov    rax,QWORD PTR [rbp-0x18]
   0x0000000000001290 <+247>:   mov    rsi,rax
   0x0000000000001293 <+250>:   lea    rax,[rip+0xe01]        # 0x209b
   0x000000000000129a <+257>:   mov    rdi,rax
   0x000000000000129d <+260>:   mov    eax,0x0
--Type <RET> for more, q to quit, c to continue without paging--
   0x00000000000012a2 <+265>:   call   0x1050 <printf@plt>
   0x00000000000012a7 <+270>:   lea    rax,[rip+0xe02]        # 0x20b0
   0x00000000000012ae <+277>:   mov    rdi,rax
   0x00000000000012b1 <+280>:   call   0x1040 <puts@plt>
   0x00000000000012b6 <+285>:   mov    rax,QWORD PTR [rbp-0x10]
   0x00000000000012ba <+289>:   mov    rdi,rax
   0x00000000000012bd <+292>:   call   0x1030 <free@plt>
   0x00000000000012c2 <+297>:   lea    rax,[rip+0xe0f]        # 0x20d8
   0x00000000000012c9 <+304>:   mov    rdi,rax
   0x00000000000012cc <+307>:   call   0x1040 <puts@plt>
   0x00000000000012d1 <+312>:   mov    edi,0xf
   0x00000000000012d6 <+317>:   call   0x1356 <errorchecked_malloc>
   0x00000000000012db <+322>:   mov    QWORD PTR [rbp-0x10],rax
   0x00000000000012df <+326>:   mov    rax,QWORD PTR [rbp-0x10]
   0x00000000000012e3 <+330>:   movabs rcx,0x6f6d656d2077656e
   0x00000000000012ed <+340>:   mov    QWORD PTR [rax],rcx
   0x00000000000012f0 <+343>:   mov    WORD PTR [rax+0x8],0x7972
   0x00000000000012f6 <+349>:   mov    BYTE PTR [rax+0xa],0x0
   0x00000000000012fa <+353>:   mov    rdx,QWORD PTR [rbp-0x10]
   0x00000000000012fe <+357>:   mov    rax,QWORD PTR [rbp-0x10]
--Type <RET> for more, q to quit, c to continue without paging--
   0x0000000000001302 <+361>:   mov    rsi,rax
   0x0000000000001305 <+364>:   lea    rax,[rip+0xd39]        # 0x2045
   0x000000000000130c <+371>:   mov    rdi,rax
   0x000000000000130f <+374>:   mov    eax,0x0
   0x0000000000001314 <+379>:   call   0x1050 <printf@plt>
   0x0000000000001319 <+384>:   lea    rax,[rip+0xde8]        # 0x2108
   0x0000000000001320 <+391>:   mov    rdi,rax
   0x0000000000001323 <+394>:   call   0x1040 <puts@plt>
   0x0000000000001328 <+399>:   mov    rax,QWORD PTR [rbp-0x18]
   0x000000000000132c <+403>:   mov    rdi,rax
   0x000000000000132f <+406>:   call   0x1030 <free@plt>
   0x0000000000001334 <+411>:   lea    rax,[rip+0xd75]        # 0x20b0
   0x000000000000133b <+418>:   mov    rdi,rax
   0x000000000000133e <+421>:   call   0x1040 <puts@plt>
   0x0000000000001343 <+426>:   mov    rax,QWORD PTR [rbp-0x10]
   0x0000000000001347 <+430>:   mov    rdi,rax
   0x000000000000134a <+433>:   call   0x1030 <free@plt>
   0x000000000000134f <+438>:   mov    eax,0x0
   0x0000000000001354 <+443>:   leave  
   0x0000000000001355 <+444>:   ret    
--Type <RET> for more, q to quit, c to continue without paging--
End of assembler dump. */