#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    printf("RAND_MAX is %u\n", RAND_MAX);
    srand(time(0));
    
    printf("random values from 0 to RAND_MAX\n");
    for(i=0; i < 8; i++)
        printf("%d\n", rand());
    printf("random values from 1 to 20\n");
    for(i=0; i < 8; i++)
        printf("%d\n", (rand()%20)+1);
}

/* RAND_MAX is 2147483647
random values from 0 to RAND_MAX
504209727
841022593
232678160
1750408134
1141903172
1736586551
905239419
2067544097
random values from 1 to 20
18
3
20
20
14
8
7
6 */

/* RAND_MAX is 2147483647
random values from 0 to RAND_MAX
1035665004
1923520780
154443410
393298314
39989580
839000037
1570878069
1618442448
random values from 1 to 20
6
2
19
4
5
6
17
2 */