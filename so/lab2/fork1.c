#include <stdio.h>
#include <unistd.h>     // For the syscall functions.
#include <sys/wait.h>   // For wait and related macros.

int main() {
    pid_t pid = fork(); // Fork a child process.
    if (pid < 0) { // Error occurred.
        fprintf(stderr, "Fork failed!\n");
        return 1;
    } else if (pid == 0) { // Child process.
        sleep(30);
        printf("[CHILD]: I'm finished.\n");
        return 42;
    } else { // Parent process.
        printf("[PARENT]: Waiting on child.\n");
        int wstatus;
        waitpid(pid, &wstatus, WUNTRACED);
        if (WIFEXITED(wstatus)) {
            printf("[PARENT]: Child returned with code %d.\n",
                   WEXITSTATUS(wstatus));
        }

        if (WIFSIGNALED(wstatus)) {
            printf("[PARENT]: Child ended due to a signal with code %d.\n",
                   WTERMSIG(wstatus));
        }

        if (WIFSTOPPED(wstatus)) {
            printf("[PARENT]: Child stopped due to a signal with code %d.\n",
                   WSTOPSIG(wstatus));
        }

    }
    return 0;
}
