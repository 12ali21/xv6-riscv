#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

volatile int a = 0, b = 0, c = 0;

void fa() {
    printf("hadsf");
}


void fb() {
    printf("hfadsf");
}

void *my_thread(void *arg) {
    printf("HHH\n");
    // int *number = arg;
    // for (int i = 0; i < 100; ++i) {
    //     (*number)++;
    //     if(number == &a) {
    //         printf("thread a: %d\n", *number);
    //     } else if(number == &b) {
    //         printf("thread b: %d\n", *number);
    //     } else {
    //         printf("thread c: %d\n", *number);
    //     }
    // }

    // return (void *) number;
    return 0;
}



int main(int argc, char const *argv[])
{
    printf("func addr: %ld\n", (uint64) fa);
    printf("func addr: %ld\n", (uint64) fb);
    printf("func addr: %ld\n", (uint64) my_thread);
    printf("func addr: %ld\n", (uint64) fa);
    printf("func addr: %ld\n", (uint64) fb);
    printf("func addr: %ld\n", (uint64) my_thread);
    int ta = crthread((void *) my_thread, (void *) &a);
    printf("%d\n", ta);
    // printf("MAIN\n");
    // // int tb = crthread(my_thread, (void *) &b);
    // // int tc = crthread(my_thread, (void *) &c);
    sleep(1);
    // jointhread(ta);
    // // jointhread(tb);
    // // jointhread(tc);
    
    return 0;
}
