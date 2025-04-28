#include <unistd.h>
#include <stdio.h>

int main() {
    long open_max = sysconf(_SC_OPEN_MAX);
    if (open_max == -1) {
        perror("sysconf");
        return 1;
    }
    printf("Maximum open files: %ld\n", open_max);
    return 0;
}
