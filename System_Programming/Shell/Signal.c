#include  <stdio.h>
#include  <time.h>
#include <stdlib.h>
#include <string.h>
#include  <errno.h>
#include  <unistd.h>
#include  <sys/types.h>
#include  <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <signal.h>

void cmd_proc(char *cmdline, char *delim, char *cmd[]);
int pid;
void	intHandler();
int main()
{
   char cmdline[500];
   char *cmds[100], *args[100], *ptr, *red_in, *red_out, *tmp[2];
    int j, status, bg, fd, fd1;
	signal(SIGCHLD, SIG_IGN);
	signal(SIGINT, intHandler);
	while (1)
	{
		printf("[명령입력]: ");
		fflush(stdout);
		fgets(cmdline, 99, stdin);
		cmdline[strlen(cmdline) - 1] = '\0';
		if (strcmp(cmdline, "quit") == 0)
		{
			printf("201721207 의학공학전공 이승현\n");
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			printf("현재시간: %d-%d-%d %d:%d:%d\n",
			tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
			tm.tm_hour, tm.tm_min, tm.tm_sec);
			break;
		}
		cmd_proc(cmdline, ";", cmds);
		for(j=0; cmds[j] !=NULL ; j++)
		{
			bg = 0; red_in = NULL; red_out = NULL;
			if ((ptr = strchr(cmds[j], '|')))
			{
				*ptr = '\0';
				cmd_proc(ptr + 1, " ", tmp);
				red_in = tmp[0];
			}
			if ((ptr = strchr(cmds[j], '&')))
			{
				bg = 1;
				*ptr = '\0';
			}
			if ((ptr = strchr(cmds[j], '<')))
			{
				*ptr = '\0';
				cmd_proc(ptr + 1, " ", tmp);
				red_in = tmp[0];
			}
			if ((ptr = strchr(cmds[j], '>')))
			{
				*ptr = '\0';
				cmd_proc(ptr + 1, " ", tmp);
				red_in = tmp[0];
			}
		//printf("red_in = [%s], red_out = [%s]\n", red_in, red_out);
			cmd_proc(cmds[j], " ", args);
			if ((pid = fork()) == 0)
			{
				if (red_in)
				{
					fd = open(red_in, O_RDONLY);
					dup2(fd, 0); // 파일을 표준입력에 복제
					close(fd);
				}
				if (red_out)
				{
					fd1 = open(red_out, O_CREAT | O_TRUNC | O_WRONLY, 0600);
					dup2(fd1, 1);
					close(fd1);
				}
				execvp(args[0], &args[0]);
				fprintf(stderr, "%s: error\n", args[0]);
				exit(0);
			}
			else
			{
				if (bg == 0)
					while (waitpid(pid, &status, 0) > 0);
				else
					printf("[%d] %s\n", pid, args[0]);
			}
		}
	}
}

void	intHandler()
{
	if (getpid() != pid)
	{
		kill(pid, SIGTERM);
		signal(SIGINT, intHandler);
	}
}
		
void cmd_proc(char *cmdline, char *delim, char *cmds[])
{
   char *str1, *token;
   char *saveptr1;
   int j;
   for (j = 0, str1 = cmdline;; j++, str1 = NULL)
	{
		token = strtok_r(str1, delim, &saveptr1);
		cmds[j] = token;
		if (token == NULL)
			break;
	}
}
