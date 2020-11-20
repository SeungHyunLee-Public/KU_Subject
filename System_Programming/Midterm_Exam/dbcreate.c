#include <stdio.h>
#include "student.h"

int		dbcreate(int argc, char *argv[])
{
	int fd;

	struct student record;
//       record.po = (float)(record.score1 + record.score2 + record.score3 + record.score4) / 4.0;
	if (argc < 2)
	{
		fprintf(stderr, "사용법 : %s file\n", argv[0]);
		exit (1);
	}

//	if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0640)) == -1)
	if ((fd = creat(argv[1], 0640)) == -1)
	{
		perror (argv[1]);
		exit (2);
	}
	printf("%-9s %-8s %-4s %-4s %-4s %-4s %-4s\n", "학번", "이름", "1차", "2차", "3차", "4차", "평균");
	while (scanf("%d %s %d %d %d %d", &record.id, record.name, &record.score1, &record.score2, &record.score3, &record.score4) == 6)
	{

		lseek(fd, (record.id - START_ID) * sizeof(record), SEEK_SET);
		write(fd, (char *) &record, sizeof(record));
	}
	close (fd);
		return (0);
}
