#include"Header.h"
typedef struct studentmarklist mrklist;
struct studentmarklist
{
	int roll;
	char name[20];
	int m1, m2, m3, m4;
	float avg,cgpa;
};
typedef struct stuinfo info;
struct stuinfo
{
	int roll;
	char phone[11];
	char address[30];
	char city[20];
	char pin[10];
};
typedef struct mergelist merg;
struct mergelist
{
	int roll;
	char name[20];
	int m1, m2, m3, m4;
	float avg, cgpa;
	char phone[11];
	char address[30];
	char city[20];
	char pin[10];
};
typedef struct dynamic dym;
typedef struct details dyndetail;
struct dynamic
{
	char sch_name[10][30];
	dyndetail *detail[10];
};

struct details
{
	char vars[20][10];
	char types[20][10];
	int varcnt[20];
	int intcnt;
	int charscnt;
	int flocnt;
	int **inarr;
	char ***carr;
	float **farr;
};