#include <stdio.h>
#include <time.h>

void dump_time_struct_bytes(struct tm *time_ptr, int size) {
    int i;
    unsigned char *raw_ptr;

    printf("bytes of struct located at 0x%08x\n", time_ptr);
    raw_ptr = (unsigned char *) time_ptr;
    for(i=0; i < size; i++)
    {
        printf("%02x ", raw_ptr[i]);
        if(i%16 == 15) // Print a newline every 16 bytes.
            printf("\n");
    }
    printf("\n");
}

int main() {
    long int seconds_since_epoch;
    struct tm current_time, *time_ptr;
    int hour, minute, second, i, *int_ptr;
    
    seconds_since_epoch = time(0); // Pass time a null pointer as argument.
    printf("time() - seconds since epoch: %ld\n", seconds_since_epoch);
    
    time_ptr = &current_time;   // Set time_ptr to the address of
                                // the current_time struct.
    localtime_r(&seconds_since_epoch, time_ptr);
    
    // Three different ways to access struct elements:
    hour = current_time.tm_hour; // Direct access
    minute = time_ptr->tm_min; // Access via pointer
    second = *((int *) time_ptr); // Hacky pointer access
    
    printf("Current time is: %02d:%02d:%02d\n", hour, minute, second);
    
    dump_time_struct_bytes(time_ptr, sizeof(struct tm));
    
    minute = hour = 0; // Clear out minute and hour.
    int_ptr = (int *) time_ptr;
    
    for(i=0; i < 3; i++) {
        printf("int_ptr @ 0x%08x : %d\n", int_ptr, *int_ptr);
        int_ptr++;  // Adding 1 to int_ptr adds 4 to the address,
    }               // since an int is 4 bytes in size.
}

/* └─$ ./time_example 
time() - seconds since epoch: 1645005645
Current time is: 02:00:45
bytes of struct located at 0x7d6ceb70
2d 00 00 00 00 00 00 00 02 00 00 00 10 00 00 00 
01 00 00 00 7a 00 00 00 03 00 00 00 2e 00 00 00 
00 00 00 00 00 00 00 00 80 8f ff ff ff ff ff ff 
00 89 a5 e6 64 55 00 00 
int_ptr @ 0x7d6ceb70 : 45
int_ptr @ 0x7d6ceb74 : 0
int_ptr @ 0x7d6ceb78 : 2 */