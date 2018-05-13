#include"Header.h"
typedef struct dynamic dym;
typedef struct details dyndetail;
typedef struct tempdetails dyntmp;
struct dynamic
{
	char sch_name[10][30];
	dyndetail *detail[10];
};

struct details
{
	char vars[20][10];
	char types[20][10];
	int varcnt;
	int intcnt;
	int charscnt;
	int flocnt;
	int recordscnt;
	int **inarr;
	char ***carr;
	float **farr;
};
struct tempdetails
{
	int intcnt;
	int charscnt;
	int flocnt;
	int recordscnt;
	int **inarr;
	char ***carr;
	float **farr;
};