#include<stdio.h>
#include<unistd.h>
int main()
{
pid_t pid;

pid=fork();

if(pid==0)
{
printf("I am Child process\n");
}
else
{
printf("i am Parent Process\n");
}
return 0;
}


