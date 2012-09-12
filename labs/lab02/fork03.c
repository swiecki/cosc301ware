#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char **argv)
{
        
    char *cmd[] = { "/bin/ps", "-ef", ".", NULL };

    if (execv(cmd[0], cmd) < 0) {
        fprintf(stderr, "execv failed: %s\n", strerror(errno));
    }

    return 0;
}

