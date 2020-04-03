#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    struct sched_param param;
    int max_priority=sched_get_priority_max(SCHED_OTHER);
    if(max_priority==-1){
        perror("sched_get_priority_max() failed");
        exit(1);
    }
    param.sched_priority=max_priority;
    int sched_set_flag=sched_setscheduler(getpid(),SCHED_OTHER,&param);
    printf("%d\n",sched_set_flag);
//    system("java -jar  dacapo-9.12-MR1-bach.jar avrora -s small");
   // if(sched_set_flag==-1){
    if(sched_set_flag==-1){
        perror("sched_setscheduler() failed");
        exit(1);
    }
//    system("java -jar  /home/huang/Desktop/NEU-Design/dacapo-9.12-MR1-bach.jar avrora -n 21 -s large -t 6");
    char pid[10];
    sprintf(pid,"%d",getpid());
//    execlp("taskset","taskset","-pc","3",pid,NULL);
  //  printf("hello");
    execlp("taskset","taskset","-c","0,1,2,3","java","-jar","/home/huang/Desktop/NEU-Design/dacapo-9.12-MR1-bach.jar","batik","-s","large","-n","10",NULL);
}
