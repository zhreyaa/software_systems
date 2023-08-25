#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main() {
    char **env = environ;

    printf("Environmental variables:\n");
    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}

