#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char *argv[]){
	int x = 100;
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { 
		printf("x = %d in child (pid %d)\n", x, getpid());
	} else {
		int wc = wait(NULL);
		printf("x = %d in parent (pid %d), child is (pid %d)\n", x, getpid(), rc);
	}
	return 0;
}
