#include <stdio.h>

int main() {
    printf("real uid: %d\n", getuid());
    printf("effective uid: %d\n", geteuid());
}

/* └─$ ./uid_demo   
real uid: 1000
effective uid: 1000 */

/* └─$ sudo chown root:root ./uid_demo
└─$ sudo chmod u+s uid_demo
└─$ ls -l uid_demo
-rwsr-xr-x 1 root root 16232 Feb 16 01:18 uid_demo 
└─$ ./uid_demo             
real uid: 1000
effective uid: 0 */