#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX 24
#define START_ID 201520000

struct student
{
	char name[MAX];
	int id;
	int score1;
	int score2;
	int score3;
	int score4;
	float po;
};
