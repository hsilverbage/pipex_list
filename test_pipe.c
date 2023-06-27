#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
	int pipefd[2];
	pid_t childPid;

	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(1);
	}

	childPid = fork();

	if (childPid == 0) {
		// Child process
		close(pipefd[0]); // Close unused read end of the pipe
		// Write data to the pipe
		write(pipefd[1], "Hello from the child process!", 28);
		close(pipefd[1]); // Close write end of the pipe
		exit(0);
	} else if (childPid > 0) {
		// Parent process
		close(pipefd[1]); // Close unused write end of the pipe
		char buffer[100];
		// Read data from the pipe
		read(pipefd[0], buffer, sizeof(buffer));
		printf("Received message from child process: %s\n", buffer);
		close(pipefd[0]); // Close read end of the pipe
	} else {
		// Error occurred
		perror("fork");
		exit(1);
	}

	return 0;
}
