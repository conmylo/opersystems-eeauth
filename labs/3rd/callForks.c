void callForks(int inputorder[3],char filename[]){
    FILE *fptr;
    int status, sleep_time[3], i;
    pid_t pid;
    
    fptr = fopen(filename, "w");
    
    if(fptr == NULL) {
      exit(1);             
    }
    
    for(i = 0; i < 3; i++) {
        if(inputorder[i] == 1) {
            sleep_time[0] = i+1;
        } else if(inputorder[i] == 2) {
            sleep_time[1] = i+1;
        } else {
            sleep_time[2] = i+1;
        }
    }

    
    for (i = 0; i < 3; i++) {
        pid = fork();
        if (pid == 0) {
            sleep(sleep_time[i]);
            fprintf(fptr, "%d %d\n", getpid(), getppid());
            printf("child[%d]-> pid %d and ppid = %d\n", i+1, getpid(), getppid());
            exit(0);
        }
    }

    for (i = 0; i < 3; i++) {
        wait(&status);
    }
    
    fclose(fptr);
    
    return;
}