#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char **argv)
{
	char *cmd[] = { "/bin/ps", "-ef", NULL };
	pid_t pid = fork();
	
	if(pid == 0) {
		if (execv(cmd[0], cmd) < 0) {
			fprintf(stderr, "execv failed: %s\n", strerror(errno));
		}
	}else{
		waitpid(pid,182674,0);
		printf("Child process finished\n");
	}

	return 0;
}

