#include <stdio.h>
#include "student.h"

int		dbupdate(int argc, char *argv[])
{
	int fd, id;
	char c;

	struct student record;
	if (argc < 2)
	{
		fprintf(stderr, "사용법 : %s file\n", argv[0]);
		exit(1);
	}
	if ((fd = open(argv[1], O_RDWR)) == -1)
	{
		perror (argv[1]);
		exit (2);
	}
	do {
		printf("수정할 학생의 학번 입력: ");
		if (scanf("%d", &id) == 1)
		{
			lseek(fd, (long)(id-START_ID)*sizeof(record), SEEK_SET);
			if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0))
			{
				printf("학번:%8d\t 이름:%4s\t 1차:%4d 2차:%4d 3차:%4d 4차 : %4d\n", record.id, record.name, record.score1, record.score2, record.score3, record.score4);
				printf("새로운 점수: ");
				scanf("%d %d %d %d", &record.score1, &record.score2, &record.score3, &record.score4);
				lseek(fd, (long) -sizeof(record), SEEK_CUR);
				write(fd, (char *) &record, sizeof(record));
			}
			else
				printf("레코드 %d 없음\n", id);
		}
			else
				printf("입력 오류");
			printf("계속하겠습니까? (Y/N)\n");
			scanf("%c", &c);
	}
		while (c == 'Y');
	close (fd);
	exit (0);
}
