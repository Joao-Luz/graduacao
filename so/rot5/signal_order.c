#define _POSIX_SOURCE
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int signals[] = { SIGSTOP, SIGURG, SIGUSR1, SIGHUP, SIGCONT, 0 };

static void
handler(int signo) {
  // XXX not async-signal-safe
  printf("<signal %d>\n", signo);
}

int main(int argc, char **argv) {
  int *sig = signals;
  struct sigaction sa = { .sa_flags = 0, .sa_handler = handler };

  sigfillset(&sa.sa_mask);

  sig++; // can't catch SIGSTOP
  while (*sig) {
    sigaction(*sig, &sa, NULL); // XXX error check
    sig++;
  }

  if (fork() == 0) { // XXX error check
    sleep(2);        // faux synchronization - let parent pause()

    sig = signals;
    while (*sig) {
      printf("sending signal %d\n", *sig);
      kill(getppid(), *sig);
      sig++;
    }
    exit(0);
  }

  pause();

  return 0;
}
