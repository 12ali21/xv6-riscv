#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

volatile int a = 0, b = 1, c = 2;

void *my_thread(void *arg) {
    // int *num = (int *) arg;
    // int i = 0;
    while(1) {
        printf("In thread with %p\n", arg);
    }

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
    void *stack = malloc(4096);
    printf("MAIN %p\n", &a);
    int ta = crthread((void *) my_thread, (void *) &a, stack);
    // stack = malloc(4096);
    // int tb = crthread((void *) my_thread, (void *) &b, stack);
    // stack = malloc(4096);
    // int tc = crthread((void *) my_thread, (void *) &c, stack);
    // printf("%d\n", ta);
    // printf("MAIN\n");
    jointhread(ta);
    // jointhread(tb);
    // jointhread(tc);
    // // int tb = crthread(my_thread, (void *) &b);
    // // int tc = crthread(my_thread, (void *) &c);
    // sleep(1);
    // printf("MAIN After sleep\n");

    while(1) {
        printf("In Main\n");
    }
    // jointhread(ta);
    // // jointhread(tb);
    // // jointhread(tc);
    
    return 0;
}
