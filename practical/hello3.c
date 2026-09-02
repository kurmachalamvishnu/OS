#include <stdio.h>
#include <unistd.h>
int main()
{
pid_t pid;
pid*fork();
if(pid==0)
{
printf("Child PID =%d\n",getpid());
printf("ParentPID=%d\n",getpid());
}
}
