#include <stdio.h>
#include <getopt.h>
#include "dbcreate.h"
#include "dbquery.h"
#include "dbupdate.h"

extern char *optarg;

int main(int argc, char *argv[])
{
// 	int flag_c = 0, flag_q = 0, flag_c = 0;
	int opt;
    // while 
	while ((opt = getopt(argc, argv, "cqu")) != -1)
	{
		switch(opt)
		{
			case 'c': //optarg =옵션다음의 한 인수
				dbcreate(argc, &argv[1]);break;
			case 'q': //argc==4이어야...
				//printf("asd%ss", optarg);
				dbquery(argc, &argv[1]);break;
			case 'u': //argc >=4 
				dbupdate(argc, &argv[1]);break;
			case 'p':
				
			default : 
				printf("-c 옵션 : dbman -c file\n");
				printf("-q 옵션 : dbman -q file\n");
				printf("-u 옵션 : dbman -u file\n");
				break;
		}
	}
}


