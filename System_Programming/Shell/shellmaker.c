#include  <stdio.h>
#include  <time.h>
#include <stdlib.h>
#include <string.h>
#include  <errno.h>
#include  <unistd.h>
#include  <sys/types.h>
#include  <sys/wait.h>

int mysystem(const char *cmdstring);
int cmd_proc(char *cmdlines, char *delim,char *cmd[]);

int main()
{
   char cmdlines[100];
   char *cmd_list[100];
    int j;
   while (1) {
      printf("[shell]");
      fflush(stdout);
      fgets(cmdlines, 99, stdin);
      cmdlines[strlen(cmdlines) - 1] = '\0';
      if (strcmp(cmdlines, "quit") == 0)
	  {
		printf("201721207 의학공학전공 이승현\n");
		  time_t t = time(NULL);
		  struct tm tm = *localtime(&t);
  printf("현재시간: %d-%d-%d %d:%d:%d\n",
         tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
         tm.tm_hour, tm.tm_min, tm.tm_sec);
		break;
		}
      cmd_proc(cmdlines, "&", cmd_list);
      cmd_proc(cmdlines, ";",cmd_list);
        for(j=0; cmd_list[j] !=NULL ; j++){
         mysystem(cmd_list[j]);
      }
      cmd_proc(cmdlines, ">", cmd_list);
      cmd_proc(cmdlines, "<", cmd_list);
   }

}

int cmd_proc(char *cmdlines, char *delim,char *cmd_list[])
{
   char *str1, *str2, *token, *subtoken;
   char *saveptr1, *saveptr2;
   int j;
   for (j = 0, str1 = cmdlines;; j++, str1 = NULL) {
      token = strtok_r(str1, delim, &saveptr1);
        cmd_list[j]=token;


      if (token == NULL)
         break;
   }
	return 0;
}



int mysystem(const char *cmdstring)
{
   int pid, status;

   if (cmdstring == NULL)
      return 1;            /* 명령어가 NULL인 경우 */
   if ((pid = fork()) == 0) {
      execl("/bin/sh", "sh", "-c", cmdstring, (char *) 0);
      _exit(127);            /* 명령어 실행 오류 */
   } else if (pid == -1)
      return -1;            /* 프로세스 생성 실패 */
   do {
      if (waitpid(pid, &status, 0) == -1) {
         if (errno != EINTR)   /* waitpid()로부터 EINTR 오류 외 */
            return -1;
      } else
         return status;
   } while (1);
}
