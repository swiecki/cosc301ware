#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int a[10];

    int i;
    for (i = 0; i < 10; i++) {
        a[i] = 0;
    }

    /* this intentionally will cause a segfault! */
    for (i = 0; i < 1200; i++) {
        a[i] = random();
    }

    for (i = 0; i < 1200; i++) {
        printf("%d: %d\n", i, a[i]);
    }

    return 0;
}
