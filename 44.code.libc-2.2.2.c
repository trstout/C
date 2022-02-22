int system(const char * cmd)
{
    int ret, pid, waitstat;
    void (*sigint) (), (*sigquit) ();
    
    if ((pid = fork()) == 0) {
        execl("/bin/sh", "sh", "-c", cmd, NULL);
        exit(127);
    }
    if (pid < 0) return(127 << 8);
    sigint = signal(SIGINT, SIG_IGN);
    sigquit = signal(SIGQUIT, SIG_IGN);
    while ((waitstat = wait(&ret)) != pid && waitstat != -1);
    if (waitstat == -1) ret = -1;
        signal(SIGINT, sigint);
        signal(SIGQUIT, sigquit);
        return(ret);
}

// Code for libc-2.2.2
  /*   if ((pid = fork()) == 0) {
        execl("/bin/sh", "sh", "-c", cmd, NULL);
        exit(127);
    } */

/*     "The fork() function
starts a new process, and the execl() function is used to run the command
through /bin/sh with the appropriate command-line arguments." */