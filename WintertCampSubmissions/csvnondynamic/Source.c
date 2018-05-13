#include"Header.h"
#include"struct.h"
void view();
void compute();
void display(FILE *fp);
void read();
int char_to_int(char *s, int n);
void csr(char *arr, char* tmp, int *k, int *i);
void console();
int stcmp(char *s1, char *s2);
mrklist** imports1(char *filename, mrklist** mlist, int *ls1);
info** imports2(char *filename, info **infolist, int *ls2);
merg** joins(mrklist** mlist, info **infolist, merg **mrg, int *ls1, int *ls2, int *ls3);
void flush(char *filename, merg** mrg, int *ls3);
int findroll(int key, merg **mrg, int n);
void query(char *quer);
int indexs(char *whr);
char *operats3(int *arr, char *oper, char *value, int k);
merg **lts3(int key, merg** mrg, merg** tmp, char *value, int *l);
merg **les3(int key, merg** mrg, merg** tmp, char *value, int *l);
merg **gts3(int key, merg** mrg, merg** tmp, char *value, int *l);
merg **ges3(int key, merg** mrg, merg** tmp, char *value, int *l);
merg **tmpsaves3(merg** mrg, merg** tmp, int *i, int *j);
merg **containss3(int key, merg** mrg, merg** tmp, char *value, int *l);
merg **matchess3(int key, merg** mrg, merg** tmp, char *value, int *l);
int substr(char *str, char *search);
void importtmp();
char *operats1(int *arr, char *oper, char *value, int key);
mrklist **lts1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l);
mrklist **les1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l);
mrklist **gts1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l);
mrklist **ges1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l);
mrklist **tmpsaves1(mrklist** mrg, mrklist** tmp, int *i, int *j);
mrklist **contains1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l);
mrklist **matches1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l);

char *operats2(int *arr, char *oper, char *value, int key);
info **lts2(int key, info** mrg, info** tmp, char *value, int *l);
info **les2(int key, info** mrg, info** tmp, char *value, int *l);
info **gts2(int key, info** mrg, info** tmp, char *value, int *l);
info **ges2(int key, info** mrg, info** tmp, char *value, int *l);
info **tmpsaves2(info** mrg, info** tmp, int *i, int *j);
info **contains2(int key, info** mrg, info** tmp, char *value, int *l);
info **matches2(int key, info** mrg, info** tmp, char *value, int *l);
void typescount(char *types, int *inc, int *cc, int *fc);
dym* create(char *quer, dym *dyn,int *indp);
dym *insert(char* quer, dym* dyn, int *indp);

int main()
{
	int c;
	while (1)
	{
		printf("Menu \n 1.View 2.Compute 3.Command Console \n 4.Quit\n");
		scanf("%d", &c);
		switch (c)
		{
		case 1: view();
			break;
		case 2:compute();
			break;
		case 3:console();
			break;
		case 4:exit(1);
		}
	}
}
void view()
{
	FILE *ptr1;
	int c;
	char file_name[30];
	while (1)
	{
		printf("View Menu\n 1.Import a file\n 2.Clear Screen\n 3.Back to Main Menu");
		scanf("%c", &c);
		switch (c)
		{
		case 1:printf("Enter file name\t:");
			scanf("%s", &file_name);
			break;
		case 2: system("cls");
			break;
		case 3: return;
		}
		ptr1 = fopen(file_name, "r");
		display(ptr1);
	}
}
void display(FILE *fp)
{
	char buff[10000];
	if (fp == NULL)
	{
		printf("File open error");
	}
	else
	{
		fscanf(fp, "%[^\0]%", buff);
		printf("%s\n", buff);
		fclose(fp);
	}
}
void compute()
{
	int lines, c, k, l;
	long i;
	char buff[10000];
	char tmp[100];
	printf("Compute Menu \n 1.Compute Average && GCPA\n 2.Join\n 3.Back to Main Menu");
	scanf("%d", &c);
	FILE *fp;
	if (c == 1)
	{
		fp = fopen("studentmarkslist.csv", "r");
		if (fp == NULL)
		{
			printf("File open error");
			return;
		}
		fscanf(fp, "%[^\0]%", buff);
		i = lines = 0;
		while (buff[i] != '\0')
		{
			if (buff[i] == '\n')
				lines++;
			i++;
		}
		mrklist** mlist = (mrklist**)malloc(sizeof(mrklist*)*(lines));
		for (i = 0; i < lines; i++)
		{
			mlist[i] = (mrklist*)malloc(sizeof(mrklist));
		}
		i = 0;
		while (buff[i] != '\n')
			i++;
		i++;
		l = 0;
		while (buff[i] != '\0')
		{
			while (buff[i] != '\n' && buff[i] != '\0')
			{
				k = 0;
				csr(buff, tmp, &k, &i);
				mlist[l]->roll = char_to_int(tmp, k);
				strcpy(tmp, "\0");
				k = 0; i++;
				csr(buff, tmp, &k, &i);
				strcpy(mlist[l]->name, tmp);
				k = 0; i++;
				strcpy(tmp, "\0");
				csr(buff, tmp, &k, &i);
				mlist[l]->m1 = char_to_int(tmp, k);
				k = 0; i++;
				strcpy(tmp, "\0");
				csr(buff, tmp, &k, &i);
				mlist[l]->m2 = char_to_int(tmp, k);
				k = 0; i++;
				strcpy(tmp, "\0");
				csr(buff, tmp, &k, &i);
				mlist[l]->m3 = char_to_int(tmp, k);
				k = 0; i++;
				strcpy(tmp, "\0");
				csr(buff, tmp, &k, &i);
				if (buff[i] != '\0' && buff[i] != '\n')
					i++;
				mlist[l]->m4 = char_to_int(tmp, k);
				mlist[l]->avg = ((mlist[l]->m1) + (mlist[l]->m2) + (mlist[l]->m3) + (mlist[l]->m4)) / 4;
				if ((mlist[l]->avg) <= 100 && (mlist[l]->avg) >= 90)
					mlist[l]->cgpa = 4.0;
				else if ((mlist[l]->avg) <= 89 && (mlist[l]->avg) >= 85)
					mlist[l]->cgpa = 3.75;
				else if ((mlist[l]->avg) <= 84 && (mlist[l]->avg) >= 80)
					mlist[l]->cgpa = 3.5;
				else if ((mlist[l]->avg) <= 79 && (mlist[l]->avg) >= 75)
					mlist[l]->cgpa = 3.33;
				else if ((mlist[l]->avg) <= 74 && (mlist[l]->avg) >= 70)
					mlist[l]->cgpa = 3;
				else if ((mlist[l]->avg) <= 69 && (mlist[l]->avg) >= 65)
					mlist[l]->cgpa = 2.75;
				else if ((mlist[l]->avg) <= 64 && (mlist[l]->avg) >= 60)
					mlist[l]->cgpa = 2.5;
				else
					mlist[l]->cgpa = 2;
				if (buff[i] == '\n')
				{
					i++;
					break;
				}
			}
			l++;
		}
		fclose(fp);
		FILE *ptr = fopen("sml.csv", "w+");
		for (i = 0; i < l; i++)
			fprintf(ptr, "%d,%s,%d,%d,%d,%d,%f,%f\n", mlist[i]->roll, mlist[i]->name, mlist[i]->m1, mlist[i]->m2, mlist[i]->m3, mlist[i]->m4, mlist[i]->avg, mlist[i]->cgpa);
		fclose(ptr);
		free(mlist);
	}
	else
		if (c == 2)
		{
			fp = fopen("studentmarkslist.csv", "r");
			if (fp == NULL)
			{
				printf("File open error");
				return;
			}
			fscanf(fp, "%[^\0]%", buff);
			i = lines = 0;
			while (buff[i] != '\0')
			{
				if (buff[i] == '\n')
					lines++;
				i++;
			}
			mrklist** mlist = (mrklist**)malloc(sizeof(mrklist*)*(lines));
			for (i = 0; i < lines; i++)
			{
				mlist[i] = (mrklist*)malloc(sizeof(mrklist));
			}
		}

}
int char_to_int(char *s, int n)
{
	int i, r, m;
	r = 0; m = 1;
	for (i = n - 1; i >= 0; i--)
	{
		r = r + (s[i] - '0')*m;
		m = m * 10;
	}
	return r;
}
void csr(char *arr, char *tmp, int *k, int *i)
{
	while (arr[*i] != ',' && arr[*i] != '\n' && arr[*i] != '\0')
	{
		tmp[*k] = arr[*i];
		(*k)++; (*i)++;
	}
	tmp[(*k)] = '\0';
	return tmp;
}
void console()
{
	char command[30];
	char key[10];
	int i, k, j, ls1, ls2, ls3,indp,vs;
	ls1 = ls2 = ls3 = indp = vs = 0;
	mrklist** mlist;
	info** infolist;
	char schema1[4];
	char schema2[4];
	dym *dyn = (dym*)malloc(sizeof(dym));
	infolist = NULL;
	mlist = NULL;
	merg** mrg;
	mrg = NULL;
	char filename[20];
	printf("Select Syntax:Select cols from schema where cols operation value\n");
	while (1)
	{
		printf(">");
		scanf(" %[^\n]s", &command);
		for (i = 0; command[i] != ' ' && command[i] != '\0'; i++)
		{
			key[i] = command[i];
		}
		key[i] = '\0';
		i++;
		if (stcmp(key, "exit"))
		{
			break;
		}
		else if (stcmp(key, "import"))
		{
			k = 0;
			while (command[i] != ' ')
			{
				filename[k] = command[i];
				i++, k++;
			}
			filename[k] = '\0';
			i++;
			k = 0;
			while (command[i] != ' ' && command[i] != '\0')
			{
				schema1[k] = command[i];
				i++; k++;
			}
			schema1[k] = '\0';
			if (stcmp(schema1, "s1"))
			{
				mlist = imports1(filename, mlist, &ls1);
			}
			else if (stcmp(schema1, "s2"))
			{
				infolist = imports2(filename, infolist, &ls2);
			}

		}
		else if (stcmp(key, "join"))
		{
			k = 0;
			while (command[i] != ' ')
			{
				schema1[k++] = command[i];
				i++;
			}
			schema1[k] = '\0';
			k = 0;
			i++;
			while (command[i] != ' ' && command[i] != '\0')
			{
				schema2[k++] = command[i];
				i++;
			}
			mlist;
			infolist;
			mrg = joins(mlist, infolist, mrg, &ls1, &ls2, &ls3);
		}
		else if (stcmp(key, "exit"))
		{
			free(mlist);
			free(infolist);
			return;
		}
		else if (stcmp(key, "flush"))
		{
			k = 0;
			while (command[i] != ' ')
			{
				filename[k] = command[i];
				i++, k++;
			}
			filename[k] = '\0';
			flush(filename, mrg, &ls3);
		}
		else if (stcmp(key, "select"))
		{
			query(command);
		}
		/*else if (stcmp(key, "create"))
		{
			dyn=create(command,dyn,&indp);
		}
		else if (stcmp(key, "insert"))
		{
			dyn = insert(command, dyn, &indp);
		}*/
	}
	return;
}
int stcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return 0;
		i++;
	}
	if ((s1[i] == '\0' && s2[i] == '\0') || ((s1[i] == ' ' && s2[i] == ' ')))
		return 1;
	else
		return 0;
}
mrklist** imports1(char *filename, mrklist** mlist, int *ls1)
{
	// import filename schema
	char buff[10000];
	char *tmp = (char*)malloc(sizeof(char) * 100);
	int i, lines, l, k;
	FILE *fp;
	fp = fopen(filename, "r+");
	fscanf(fp, "%[^\0]%", buff);
	i = lines = l = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			lines++;
		i++;
	}
	if (*ls1 == 0)
	{
		mlist = (mrklist**)malloc(sizeof(mrklist*)*(lines));
		for (i = 0; i < lines; i++)
		{
			mlist[i] = (mrklist*)malloc(sizeof(mrklist));
		}
	}
	else
	{
		lines = lines + *ls1;
		mlist = (mrklist **)realloc(mlist, lines);
	}
	i = 0;
	l = *ls1;
	*ls1 = lines;
	while (buff[i] != '\0')
	{
		while (buff[i] != '\n' && buff[i] != '\0')
		{
			k = 0;
			csr(buff, tmp, &k, &i);
			mlist[l]->roll = char_to_int(tmp, k);
			strcpy(tmp, "\0");
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(mlist[l]->name, tmp);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mlist[l]->m1 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mlist[l]->m2 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mlist[l]->m3 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mlist[l]->m4 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mlist[l]->avg = atof(tmp);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			if (buff[i] != '\0' && buff[i] != '\n')
				i++;
			mlist[l]->cgpa = atof(tmp);
			if (buff[i] == '\n')
			{
				i++;
				break;
			}
		}
		l++;
		if (buff[i] == '\0')
			break;
	}
	/*fclose(fp);
	FILE *ptr = fopen("studentmarklistnew.csv", "w+");
	for (i = 0; i < l; i++)
	fprintf(ptr, "%d,%s,%d,%d,%d,%d,%f,%f\n", mlist[i]->roll, mlist[i]->name, mlist[i]->m1, mlist[i]->m2, mlist[i]->m3, mlist[i]->m4, mlist[i]->avg, mlist[i]->cgpa);
	fclose(ptr);
	*/

	return mlist;
}
info** imports2(char *filename, info **infolist, int *ls2)
{
	// import filename schema
	char buff[10000];
	char *tmp = (char*)malloc(sizeof(char) * 100);
	int i, lines, l, k;
	FILE *fp;
	fp = fopen(filename, "r+");
	fscanf(fp, "%[^\0]%", buff);
	i = lines = l = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			lines++;
		i++;
	}
	if (*ls2 == 0)
	{
		infolist = (info**)malloc(sizeof(info*)*(lines));
		for (i = 0; i < lines; i++)
		{
			infolist[i] = (info*)malloc(sizeof(info));
		}
	}
	else
	{
		lines = lines + *ls2;
		infolist = (info **)realloc(infolist, lines);
	}
	i = 0; l = *ls2;
	*ls2 = lines;
	while (buff[i] != '\0')
	{
		while (buff[i] != '\n' && buff[i] != '\0')
		{
			k = 0;
			csr(buff, tmp, &k, &i);
			infolist[l]->roll = char_to_int(tmp, k);
			free(tmp);
			tmp = (char*)malloc(sizeof(char) * 100);
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(infolist[l]->phone, tmp);
			free(tmp);
			tmp = (char*)malloc(sizeof(char) * 100);
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(infolist[l]->address, tmp);
			free(tmp);
			tmp = (char*)malloc(sizeof(char) * 100);
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(infolist[l]->city, tmp);
			free(tmp);
			tmp = (char*)malloc(sizeof(char) * 100);
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(infolist[l]->pin, tmp);
			if (buff[i] == '\n')
			{
				i++;
				break;
			}
		}
		l++;
	}
	FILE *ptr = fopen("csvi2.csv", "w+");
	for (i = 0; i < l; i++)
		fprintf(ptr, "%d,%s,%s,%s,%s\n", infolist[i]->roll, infolist[i]->phone, infolist[i]->address, infolist[i]->city, infolist[i]->pin);
	return infolist;
}
void flush(char *filename, merg **mrg, int *ls3)
{
	int i;
	FILE *fpt = fopen(filename, "w");
	for (i = 0; i < *ls3; i++)
	{
		fprintf(fpt, "%d,%s,%d,%d,%d,%d,%f,%f,%s,%s,%s,%s\n", mrg[i]->roll, mrg[i]->name, mrg[i]->m1, mrg[i]->m2, mrg[i]->m3,
			mrg[i]->m4, mrg[i]->avg, mrg[i]->cgpa, mrg[i]->phone, mrg[i]->address, mrg[i]->city, mrg[i]->pin);
	}
	fclose(fpt);
	free(mrg);
	*ls3 = 0;
}
merg** joins(mrklist** mlist, info **infolist, merg **mrg, int *ls1, int *ls2, int *ls3)
{
	//join schema1 schema2
	int i, j, key, f;
	*ls3 = *ls1 + *ls2;
	mrg = (merg**)malloc(sizeof(merg*)*(*ls3));
	for (i = 0; i < (*ls3); i++)
	{
		mrg[i] = (merg*)malloc(sizeof(merg));
	}
	for (i = 0; i < (*ls1); i++)
	{
		mrg[i]->roll = mlist[i]->roll;
		strcpy(mrg[i]->name, mlist[i]->name);
		mrg[i]->m1 = mlist[i]->m1;
		mrg[i]->m2 = mlist[i]->m2;
		mrg[i]->m3 = mlist[i]->m3;
		mrg[i]->m4 = mlist[i]->m4;
		mrg[i]->avg = mlist[i]->avg;
		mrg[i]->cgpa = mlist[i]->cgpa;

		strcpy(mrg[i]->phone, "NoData");
		strcpy(mrg[i]->address, "NoData");
		strcpy(mrg[i]->city, "NoData");
		strcpy(mrg[i]->pin, "NoData");
	}
	j = i;
	for (i = 0; i < *ls2; i++)
	{
		key = infolist[i]->roll;
		f = findroll(key, mrg, *ls1);
		if (f == -1)
		{
			mrg[i]->roll = 0;
			strcpy(mrg[i]->name, "NoData");
			mrg[j]->m1 = 0;
			mrg[j]->m2 = 0;
			mrg[j]->m3 = 0;
			mrg[j]->m4 = 0;
			mrg[j]->avg = 0;
			mrg[j]->cgpa = 0;

			strcpy(mrg[j]->phone, infolist[i]->phone);
			strcpy(mrg[j]->address, infolist[i]->address);
			strcpy(mrg[j]->city, infolist[i]->city);
			strcpy(mrg[j]->pin, infolist[i]->pin);
			j++;
		}
		else
		{
			strcpy(mrg[f]->phone, infolist[i]->phone);
			strcpy(mrg[f]->address, infolist[i]->address);
			strcpy(mrg[f]->city, infolist[i]->city);
			strcpy(mrg[f]->pin, infolist[i]->pin);
		}
	}
	*ls3 = j;
	/*FILE *fpt = fopen("join.csv","w+");
	for (i = 0; i < j; i++)
	{
	fprintf(fpt,"%d,%s,%d,%d,%d,%d,%f,%f,%s,%s,%s,%s\n", mrg[i]->roll, mrg[i]->name, mrg[i]->m1, mrg[i]->m2, mrg[i]->m3,
	mrg[i]->m4, mrg[i]->avg, mrg[i]->cgpa, mrg[i]->phone, mrg[i]->address, mrg[i]->city, mrg[i]->pin);
	}
	fclose(fpt);
	*/
	return mrg;
}
int findroll(int key, merg **mrg, int n)
{
	int i, k;
	for (i = 0; i < n; i++)
	{
		k = mrg[i]->roll;
		if (key == mrg[i]->roll)
		{
			return i;
		}
	}
	return -1;
}
void query(char *quer)
{
	//syntax select a,b where a>75 gt ls ge le eq ne
	int i, ls, lines, j, k, key, l, c;
	char whr[15];
	char operation[10];
	char value[20];
	char* tmpfile;
	char schema[5];
	int *var = (int *)calloc(13, sizeof(int));
	for (i = 0; i < 12; i++)
		var[i];
	k = 0;
	for (i = 0; quer[i] != ' '; i++)
	{
		whr[k++] = quer[i];
	}
	whr[k] = '\0';
	i++;
	if (stcmp(whr, "exit"))
		return;
	while (1)
	{
		k = j = 0;
		while (quer[i] != ',' && quer[i] != ' ')
		{
			whr[k++] = quer[i++];
		}
		whr[k] = '\0';
		i++;
		if (stcmp(whr, "from"))
			break;
		else
		{
			j = indxes(whr);
			if (j == 0)
			{
				for (j = 0; j < 13; j++)
					var[j] = 1;
			}
			else
				var[j] = 1;
		}

	}
	k = 0;
	while (quer[i] != ' ')
	{
		schema[k++] = quer[i++];
	}
	schema[k] = '\0';
	i++;
	while (quer[i] != ' '){ i++; }
	i++;
	k = 0;
	while (quer[i] != ' ')
	{
		whr[k++] = quer[i++];
	}
	whr[k] = '\0';
	i++;
	key = indxes(whr);
	k = 0;
	while (quer[i] != ' ')
	{
		operation[k++] = quer[i++];
	}
	operation[k] = '\0';
	i++;
	k = 0;
	while (quer[i] != ' ' && quer[i] != '\0')
	{
		value[k++] = quer[i++];
	}
	value[k] = '\0';
	if (stcmp(schema, "s1"))
	{
		tmpfile = operats1(var, operation, value, key);
	}
	else if (stcmp(schema, "s2"))
	{
		tmpfile = operats2(var, operation, value, key);
	}
	else if (stcmp(schema, "s3"))
	{
		tmpfile = operats3(var, operation, value, key);
	}
	return;
}
int indxes(char *whr)
{
	if (stcmp(whr, "*"))
	{
		return 0;
	}
	else if (stcmp(whr, "roll"))
		return 1;
	else if (stcmp(whr, "name"))
		return 2;
	else if (stcmp(whr, "m1"))
		return 3;
	else if (stcmp(whr, "m2"))
		return 4;
	else if (stcmp(whr, "m3"))
		return 5;
	else if (stcmp(whr, "m4"))
		return 6;
	else if (stcmp(whr, "avg"))
		return 7;
	else if (stcmp(whr, "cgpa"))
		return 8;
	else if (stcmp(whr, "phone"))
		return 9;
	else if (stcmp(whr, "address"))
		return 10;
	else if (stcmp(whr, "city"))
		return 11;
	else if (stcmp(whr, "pin"))
		return 12;
}
char *operats3(int *arr, char *oper, char *value, int key)
{
	int i, c, lines, l, k;
	char buff[50000];
	char *tmp = (char*)malloc(sizeof(char) * 100);
	merg **mrg;
	FILE *fp;
	lines = 0;
	char *filename = "joint.csv";
	fp = fopen(filename, "r+");
	fscanf(fp, "%[^\0]s", buff);
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			lines++;
		i++;
	}
	c = i;
	lines++;
	mrg = (merg**)malloc(sizeof(merg)*lines);
	for (i = 0; i < lines; i++)
	{
		mrg[i] = (merg*)malloc(sizeof(merg));
	}
	l = i = 0;
	while (buff[i] != '\0' && c != i)
	{
		while (buff[i] != '\n' && buff[i] != '\0')
		{
			k = 0;
			csr(buff, tmp, &k, &i);
			mrg[l]->roll = char_to_int(tmp, k);
			strcpy(tmp, "\0");
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(mrg[l]->name, tmp);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mrg[l]->m1 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mrg[l]->m2 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mrg[l]->m3 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mrg[l]->m4 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mrg[l]->avg = atof(tmp);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			if (buff[i] != '\0' && buff[i] != '\n')
				i++;
			mrg[l]->cgpa = atof(tmp);
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(mrg[l]->phone, tmp);
			free(tmp);
			tmp = (char*)malloc(sizeof(char) * 100);
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(mrg[l]->address, tmp);
			free(tmp);
			tmp = (char*)malloc(sizeof(char) * 100);
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(mrg[l]->city, tmp);
			free(tmp);
			tmp = (char*)malloc(sizeof(char) * 100);
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(mrg[l]->pin, tmp);
			if (buff[i] == '\n')
			{
				i++;
				break;
			}
		}
		l++;
		if (buff[i] == '\0')
			break;
		if (c == i)
			break;
	}

	merg **tmparr;
	tmparr = NULL;
	if (stcmp(oper, "lt"))
	{
		tmparr = lts3(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "le"))
	{
		tmparr = les3(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "gt"))
	{
		tmparr = gts3(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "ge"))
	{
		tmparr = ges3(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "matches"))
	{
		tmparr = matchess3(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "contains"))
	{
		tmparr = containss3(key, mrg, tmparr, value, &l);
	}
	FILE *fptr = fopen("tmp.csv", "w");
	c == 0;
	if (arr[0])
	{
		for (i = 0; i < l; i++)
		{
			fprintf(fptr, "%d,%s,%d,%d,%d,%d,%f,%f,%s,%s,%s,%s\n", tmparr[i]->roll, tmparr[i]->name, tmparr[i]->m1, tmparr[i]->m2, tmparr[i]->m3, tmparr[i]->m4, tmparr[i]->avg, tmparr[i]->cgpa, tmparr[i]->phone, tmparr[i]->address, tmparr[i]->city, tmparr[i]->pin);
		}
	}
	else
	{
		for (i = 0; i < l; i++)
		{
			if (arr[1])
			{
				fprintf(fptr, "%d", tmparr[i]->roll);
				c++;
			}
			if (arr[2])
			{
				if (c)
					fprintf(fptr, ",%s", tmparr[i]->name);
				else
				{
					fprintf(fptr, "%s", tmparr[i]->name);
					c++;
				}
			}
			if (arr[3])
			{
				if (c)
					fprintf(fptr, ",%d", tmparr[i]->m1);
				else
				{
					fprintf(fptr, "%d", tmparr[i]->m1);
					c++;
				}
			}
			if (arr[4])
			{
				if (c)
					fprintf(fptr, ",%d", tmparr[i]->m2);
				else
				{
					fprintf(fptr, "%d", tmparr[i]->m2);
					c++;
				}
			}
			if (arr[5])
			{
				if (c)
					fprintf(fptr, ",%d", tmparr[i]->m3);
				else
				{
					fprintf(fptr, "%d", tmparr[i]->m3);
					c++;
				}
			}
			if (arr[6])
			{
				if (c)
					fprintf(fptr, ",%d", tmparr[i]->m4);
				else
				{
					fprintf(fptr, "%d", tmparr[i]->m4);
					c++;
				}
			}
			if (arr[7])
			{
				if (c)
					fprintf(fptr, ",%f", tmparr[i]->avg);
				else
				{
					fprintf(fptr, "%f", tmparr[i]->avg);
					c++;
				}
			}
			if (arr[8])
			{
				if (c)
					fprintf(fptr, ",%f", tmparr[i]->cgpa);
				else
				{
					fprintf(fptr, "%f", tmparr[i]->cgpa);
					c++;
				}
			}
			if (arr[9])
			{
				if (c)
					fprintf(fptr, ",%s", tmparr[i]->phone);
				else
				{
					fprintf(fptr, "%s", tmparr[i]->phone);
					c++;
				}
			}
			if (arr[10])
			{
				if (c)
					fprintf(fptr, ",%s", tmparr[i]->address);
				else
				{
					fprintf(fptr, "%s", tmparr[i]->address);
					c++;
				}
			}
			if (arr[11])
			{
				if (c)
					fprintf(fptr, ",%s", tmparr[i]->city);
				else
				{
					fprintf(fptr, "%s", tmparr[i]->city);
					c++;
				}
			}
			if (arr[12])
			{
				if (c)
					fprintf(fptr, ",%s", tmparr[i]->pin);
				else
				{
					fprintf(fptr, "%s", tmparr[i]->pin);
					c++;
				}
			}
			if (i == l - 1)
				fprintf(fptr, "\0");
			else
			fprintf(fptr, "\n");
		}
	}
	fclose(fptr);
	importtmp();
	free(mrg);
	free(tmparr);
	return "tmp.csv";
}

merg **lts3(int key, merg** mrg, merg** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (merg**)malloc(sizeof(merg)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (merg*)malloc(sizeof(merg));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll < k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 3)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 < k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 4)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m2 < k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 5)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m3 < k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 6)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m4 < k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 7)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->avg < f)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 8)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 < f)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}

	return tmp;
}
merg **gts3(int key, merg** mrg, merg** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (merg**)malloc(sizeof(merg)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (merg*)malloc(sizeof(merg));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll > k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 3)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 > k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 4)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m2 > k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 5)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m3 > k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 6)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m4 > k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 7)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->avg > f)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 8)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 > f)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}

	return tmp;
}
merg **les3(int key, merg** mrg, merg** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (merg**)malloc(sizeof(merg)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (merg*)malloc(sizeof(merg));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll <= k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 3)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 <= k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 4)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m2 <= k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 5)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m3 <= k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 6)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m4 <= k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 7)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->avg <= f)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 8)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 <= f)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}

	return tmp;
}
merg **ges3(int key, merg** mrg, merg** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (merg**)malloc(sizeof(merg)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (merg*)malloc(sizeof(merg));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll >= k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 3)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 >= k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 4)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m2 >= k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 5)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m3 >= k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 6)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m4 >= k)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 7)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->avg >= f)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 8)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 >= f)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	return tmp;
}
merg **tmpsaves3(merg** mrg, merg** tmp, int *i, int *j)
{
	tmp[*j]->roll = mrg[*i]->roll;
	strcpy(tmp[*j]->name, mrg[*i]->name);
	tmp[*j]->m1 = mrg[*i]->m1;
	tmp[*j]->m2 = mrg[*i]->m2;
	tmp[*j]->m3 = mrg[*i]->m3;
	tmp[*j]->m4 = mrg[*i]->m4;
	tmp[*j]->avg = mrg[*i]->avg;
	tmp[*j]->cgpa = mrg[*i]->cgpa;
	strcpy(tmp[*j]->phone, mrg[*i]->phone);
	strcpy(tmp[*j]->address, mrg[*i]->address);
	strcpy(tmp[*j]->city, mrg[*i]->city);
	strcpy(tmp[*j]->pin, mrg[*i]->pin);
	(*j)++;
	return tmp;
}
void importtmp()
{
	int i, k;
	char buffer[100000];
	char tmp[1000];
	FILE *fp = fopen("tmp.csv", "r");
	fscanf(fp, "%[^\0]s", buffer);
	i = 0;
	while (buffer[i] != '\0')
	{
		k = 0;
		while (buffer[i] != '\0' && buffer[i] != '\n')
		{
			tmp[k++] = buffer[i++];
		}
		if (buffer[i] == '\n')
			i++;
		tmp[k] = '\0';
		printf("%s\n", tmp);
	}
}
merg **matchess3(int key, merg** mrg, merg** tmp, char *value, int *l)
{
	int i, j, k;
	tmp = (merg**)malloc(sizeof(merg)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (merg*)malloc(sizeof(merg));
	}
	if (key == 2)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (stcmp(mrg[i]->name, value) == 0)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 9)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (stcmp(mrg[i]->phone, value))
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 10)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (stcmp(mrg[i]->address, value))
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 11)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (stcmp(mrg[i]->city, value))
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 12)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (stcmp(mrg[i]->pin, value))
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	return tmp;
}
merg **containss3(int key, merg** mrg, merg** tmp, char *value, int *l)
{
	int i, j, k;
	tmp = (merg**)malloc(sizeof(merg)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (merg*)malloc(sizeof(merg));
	}
	if (key == 2)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (substr(mrg[i]->name, value) == 0)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 9)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (substr(mrg[i]->phone, value))
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 10)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (substr(mrg[i]->address, value))
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 11)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (substr(mrg[i]->city, value))
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 12)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (substr(mrg[i]->pin, value))
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	return tmp;
}
int substr(char *str, char *search)
{
	int count1 = 0, count2 = 0, i, j, flag;
	while (str[count1] != '\0')
		count1++;
	while (search[count2] != '\0')
		count2++;
	for (i = 0; i <= count1 - count2; i++)
	{
		for (j = i; j < i + count2; j++)
		{
			flag = 1;
			if (str[j] != search[j - i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	if (flag)
		return 1;
	else
		return 0;
}

char *operats1(int *arr, char *oper, char *value, int key)
{
	int i, c, lines, l, k;
	char buff[50000];
	char *tmp = (char*)malloc(sizeof(char) * 100);
	mrklist **mrg;
	FILE *fp;
	lines = 0;
	char *filename = "sml.csv";
	fp = fopen(filename, "r+");
	fscanf(fp, "%[^\0]s", buff);
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			lines++;
		i++;
	}
	c = i;
	lines++;
	mrg = (mrklist**)malloc(sizeof(mrklist)*lines);
	for (i = 0; i < lines; i++)
	{
		mrg[i] = (mrklist*)malloc(sizeof(mrklist));
	}
	l = i = 0;
	while (buff[i] != '\0' && c != i)
	{
		while (buff[i] != '\n' && buff[i] != '\0')
		{
			k = 0;
			csr(buff, tmp, &k, &i);
			mrg[l]->roll = char_to_int(tmp, k);
			strcpy(tmp, "\0");
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(mrg[l]->name, tmp);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mrg[l]->m1 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mrg[l]->m2 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mrg[l]->m3 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mrg[l]->m4 = char_to_int(tmp, k);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			mrg[l]->avg = atof(tmp);
			k = 0; i++;
			strcpy(tmp, "\0");
			csr(buff, tmp, &k, &i);
			if (buff[i] != '\0' && buff[i] != '\n')
				i++;
			mrg[l]->cgpa = atof(tmp);
			if (buff[i] == '\n')
			{
				i++;
				break;
			}
		}
		l++;
		if (buff[i] == '\0')
			break;
		if (c == i)
			break;
	}

	mrklist **tmparr;
	tmparr = NULL;
	if (stcmp(oper, "lt"))
	{
		tmparr = lts1(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "le"))
	{
		tmparr = les1(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "gt"))
	{
		tmparr = gts1(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "ge"))
	{
		tmparr = ges1(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "matches"))
	{
		tmparr = matches1(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "contains"))
	{
		tmparr = contains1(key, mrg, tmparr, value, &l);
	}
	FILE *fptr = fopen("tmp.csv", "w");
	c == 0;
	if (arr[0])
	{
		for (i = 0; i < l; i++)
		{
			fprintf(fptr, "%d,%s,%d,%d,%d,%d,%f,%f\n", tmparr[i]->roll, tmparr[i]->name, tmparr[i]->m1, tmparr[i]->m2, tmparr[i]->m3, tmparr[i]->m4, tmparr[i]->avg, tmparr[i]->cgpa);
		}
	}
	else
	{
		for (i = 0; i < l; i++)
		{
			if (arr[1])
			{
				fprintf(fptr, "%d", tmparr[i]->roll);
				c++;
			}
			if (arr[2])
			{
				if (c)
					fprintf(fptr, ",%s", tmparr[i]->name);
				else
				{
					fprintf(fptr, "%s", tmparr[i]->name);
					c++;
				}
			}
			if (arr[3])
			{
				if (c)
					fprintf(fptr, ",%d", tmparr[i]->m1);
				else
				{
					fprintf(fptr, "%d", tmparr[i]->m1);
					c++;
				}
			}
			if (arr[4])
			{
				if (c)
					fprintf(fptr, ",%d", tmparr[i]->m2);
				else
				{
					fprintf(fptr, "%d", tmparr[i]->m2);
					c++;
				}
			}
			if (arr[5])
			{
				if (c)
					fprintf(fptr, ",%d", tmparr[i]->m3);
				else
				{
					fprintf(fptr, "%d", tmparr[i]->m3);
					c++;
				}
			}
			if (arr[6])
			{
				if (c)
					fprintf(fptr, ",%d", tmparr[i]->m4);
				else
				{
					fprintf(fptr, "%d", tmparr[i]->m4);
					c++;
				}
			}
			if (arr[7])
			{
				if (c)
					fprintf(fptr, ",%f", tmparr[i]->avg);
				else
				{
					fprintf(fptr, "%f", tmparr[i]->avg);
					c++;
				}
			}
			if (arr[8])
			{
				if (c)
					fprintf(fptr, ",%f", tmparr[i]->cgpa);
				else
				{
					fprintf(fptr, "%f", tmparr[i]->cgpa);
					c++;
				}
			}
			if (i == l - 1)
				fprintf(fptr, "\0");
			else
				fprintf(fptr, "\n");
		}
	}
	fclose(fptr);
	importtmp();
	return "tmp.csv";
}
mrklist **lts1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (mrklist**)malloc(sizeof(mrklist)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (mrklist*)malloc(sizeof(mrklist));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll < k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 3)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 < k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 4)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m2 < k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 5)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m3 < k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 6)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m4 < k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 7)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->avg < f)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 8)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 < f)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}

	return tmp;
}
mrklist **les1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (mrklist**)malloc(sizeof(mrklist)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (mrklist*)malloc(sizeof(mrklist));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll <= k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 3)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 <= k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 4)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m2 <= k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 5)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m3 <= k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 6)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m4 <= k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 7)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->avg <= f)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 8)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 <= f)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	return tmp;
}
mrklist **gts1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (mrklist**)malloc(sizeof(mrklist)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (mrklist*)malloc(sizeof(mrklist));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll > k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 3)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 > k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 4)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m2 > k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 5)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m3 > k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 6)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m4 > k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 7)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->avg > f)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 8)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 > f)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}

	return tmp;
}
mrklist **ges1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (mrklist**)malloc(sizeof(mrklist)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (mrklist*)malloc(sizeof(mrklist));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll >= k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 3)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 >= k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 4)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m2 >= k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 5)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m3 >= k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 6)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m4 >= k)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 7)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->avg >= f)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	else if (key == 8)
	{
		for (i = 0; value[i] != '\0'; i++){}
		f = atof(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->m1 >= f)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	return tmp;
}
mrklist **tmpsaves1(mrklist** mrg, mrklist** tmp, int *i, int *j)
{
	tmp[*j]->roll = mrg[*i]->roll;
	strcpy(tmp[*j]->name, mrg[*i]->name);
	tmp[*j]->m1 = mrg[*i]->m1;
	tmp[*j]->m2 = mrg[*i]->m2;
	tmp[*j]->m3 = mrg[*i]->m3;
	tmp[*j]->m4 = mrg[*i]->m4;
	tmp[*j]->avg = mrg[*i]->avg;
	tmp[*j]->cgpa = mrg[*i]->cgpa;
	(*j)++;
	return tmp;
}
mrklist **contains1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l)
{
	int i, j, k;
	tmp = (mrklist**)malloc(sizeof(mrklist)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (mrklist*)malloc(sizeof(mrklist));
	}
	if (key == 2)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (stcmp(mrg[i]->name, value) == 0)
			{
				tmp = tmpsaves1(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	return tmp;
}
mrklist **matches1(int key, mrklist** mrg, mrklist** tmp, char *value, int *l)
{
	int i, j, k;
	tmp = (mrklist**)malloc(sizeof(mrklist)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (mrklist*)malloc(sizeof(mrklist));
	}
	if (key == 2)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (stcmp(mrg[i]->name, value) == 0)
			{
				tmp = tmpsaves3(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	return tmp;
}

char *operats2(int *arr, char *oper, char *value, int key)
{
	int i, c, lines, l, k;
	char buff[50000];
	char *tmp = (char*)malloc(sizeof(char) * 100);
	info **mrg;
	FILE *fp;
	lines = 0;
	char *filename = "csvi.csv";
	fp = fopen(filename, "r+");
	fscanf(fp, "%[^\0]s", buff);
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			lines++;
		i++;
	}
	c = i;
	lines++;
	mrg = (info**)malloc(sizeof(info)*lines);
	for (i = 0; i < lines; i++)
	{
		mrg[i] = (info*)malloc(sizeof(info));
	}
	l = i = 0;
	while (buff[i] != '\0' && c != i)
	{
		while (buff[i] != '\n' && buff[i] != '\0')
		{
			k = 0;
			csr(buff, tmp, &k, &i);
			mrg[l]->roll = char_to_int(tmp, k);
			strcpy(tmp, "\0");
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(mrg[l]->phone, tmp);
			free(tmp);
			tmp = (char*)malloc(sizeof(char) * 100);
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(mrg[l]->address, tmp);
			free(tmp);
			tmp = (char*)malloc(sizeof(char) * 100);
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(mrg[l]->city, tmp);
			free(tmp);
			tmp = (char*)malloc(sizeof(char) * 100);
			k = 0; i++;
			csr(buff, tmp, &k, &i);
			strcpy(mrg[l]->pin, tmp);
			if (buff[i] == '\n')
			{
				i++;
				break;
			}
		}
		l++;
		if (buff[i] == '\0')
			break;
		if (c == i)
			break;
	}

	info **tmparr;
	tmparr = NULL;
	if (stcmp(oper, "lt"))
	{
		tmparr = lts2(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "le"))
	{
		tmparr = les2(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "gt"))
	{
		tmparr = gts2(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "ge"))
	{
		tmparr = ges2(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "matches"))
	{
		tmparr = matches2(key, mrg, tmparr, value, &l);
	}
	else if (stcmp(oper, "contains"))
	{
		tmparr = contains2(key, mrg, tmparr, value, &l);
	}
	FILE *fptr = fopen("tmp.csv", "w");
	c == 0;
	if (arr[0])
	{
		for (i = 0; i < l; i++)
		{
			fprintf(fptr, "%d,%s,%s,%s,%s\n", tmparr[i]->roll,tmparr[i]->phone, tmparr[i]->address, tmparr[i]->city, tmparr[i]->pin);
		}
	}
	else
	{
		for (i = 0; i < l; i++)
		{
			if (arr[1])
			{
				fprintf(fptr, "%d", tmparr[i]->roll);
				c++;
			}
			if (arr[9])
			{
				if (c)
					fprintf(fptr, ",%s", tmparr[i]->phone);
				else
				{
					fprintf(fptr, "%s", tmparr[i]->phone);
					c++;
				}
			}
			if (arr[10])
			{
				if (c)
					fprintf(fptr, ",%s", tmparr[i]->address);
				else
				{
					fprintf(fptr, "%s", tmparr[i]->address);
					c++;
				}
			}
			if (arr[11])
			{
				if (c)
					fprintf(fptr, ",%s", tmparr[i]->city);
				else
				{
					fprintf(fptr, "%s", tmparr[i]->city);
					c++;
				}
			}
			if (arr[12])
			{
				if (c)
					fprintf(fptr, ",%s", tmparr[i]->pin);
				else
				{
					fprintf(fptr, "%s", tmparr[i]->pin);
					c++;
				}
			}
			if (i == l - 1)
				fprintf(fptr, "\0");
			else
				fprintf(fptr, "\n");
		}
	}
	fclose(fptr);
	importtmp();
	return "tmp.csv";
}
info **lts2(int key, info** mrg, info** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (info **)malloc(sizeof(info)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (info*)malloc(sizeof(info));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll < k)
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}

	return tmp;
}
info **les2(int key, info** mrg, info** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (info **)malloc(sizeof(info)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (info*)malloc(sizeof(info));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll <= k)
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}

	return tmp;
}
info **gts2(int key, info** mrg, info** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (info **)malloc(sizeof(info)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (info*)malloc(sizeof(info));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll > k)
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}

	return tmp;
}
info **ges2(int key, info** mrg, info** tmp, char *value, int *l)
{
	int i, j, k;
	float f;
	tmp = (info **)malloc(sizeof(info)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (info*)malloc(sizeof(info));
	}
	if (key == 1)
	{
		for (i = 0; value[i] != '\0'; i++){}
		k = char_to_int(value, i);
		j = i = 0;
		while (i<(*l))
		{
			if (mrg[i]->roll >= k)
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}

	return tmp;
}
info **tmpsaves2(info** mrg, info** tmp, int *i, int *j)
{
	tmp[*j]->roll = mrg[*i]->roll;
	strcpy(tmp[*j]->phone, mrg[*i]->phone);
	strcpy(tmp[*j]->address, mrg[*i]->address);
	strcpy(tmp[*j]->city, mrg[*i]->city);
	strcpy(tmp[*j]->pin, mrg[*i]->pin);
	(*j)++;
	return tmp;
}
info **contains2(int key, info** mrg, info** tmp, char *value, int *l)
{
	int i, j, k;
	tmp = (info**)malloc(sizeof(info)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (info*)malloc(sizeof(info));
	}
	if (key == 9)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (substr(mrg[i]->phone, value))
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 10)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (substr(mrg[i]->address, value))
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 11)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (substr(mrg[i]->city, value))
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 12)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (substr(mrg[i]->pin, value))
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	return tmp;
}
info **matches2(int key, info** mrg, info** tmp, char *value, int *l)
{
	int i, j, k;
	tmp = (info**)malloc(sizeof(info)*(*l));
	for (i = 0; i < (*l); i++)
	{
		tmp[i] = (info*)malloc(sizeof(info));
	}
	if (key == 9)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (stcmp(mrg[i]->phone, value))
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 10)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (stcmp(mrg[i]->address, value))
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 11)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (stcmp(mrg[i]->city, value))
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	if (key == 12)
	{
		j = i = 0;
		while (i<(*l))
		{
			if (stcmp(mrg[i]->pin, value))
			{
				tmp = tmpsaves2(mrg, tmp, &i, &j);
			}
			i++;
		}
		*l = j;
	}
	return tmp;
}

/*dym* create(char *quer,dym *dyn,int *indp)
{
	//create schema s4 m1:int m2 :int
	int i,k,j,inc,cc,fc,c;
	char scnm[20];
	char types[100];
	char vars[100];
	for (i = 0; quer[i] != ' '; i++){}
	i++;
	while (quer[i] != ' '){ i++; }
	i++;
	k = 0;
	while (quer[i] != ' ')
	{

		scnm[k++] = quer[i++];
	}
	scnm[k] = '\0';
	j = k = 0;
	while (quer[i] != '\0')
	{
		i++;
		while (quer[i] != ':' && quer[i] != '\0')
		{
			vars[j++] = quer[i++];
		}
		vars[j++] = ' ';
		i++;
		while (quer[i] != ',' && quer[i] != '\0')
		{
			types[k++] = quer[i++];
		}
		types[k++] = ' ';
	}
	inc = fc = cc = 0;
	vars[j] = '\0';
	types[k] = '\0';
	typescount(types, &inc, &cc, &fc);
	//printf("%d,%d,%d", inc, cc, fc);
	strcpy(dyn->sch_name[*indp], scnm);
	dyn->detail[*indp] = (dyndetail*)malloc(sizeof(dyndetail));
	k = 0;
	for (i = 0; i < (inc + cc + fc) && vars[k]!='\0'; i++)
	{
		j = 0;
		while (vars[k] != ' ' && vars[k] != '\0')
		{
			scnm[j++] = vars[k++];
		}
		scnm[j] = '\0';
		strcpy((dyn->detail[*indp])->vars[i], scnm);
		if (vars[k] == ' ')
			k++;
	}
	k = 0;
	for (i = 0; i < (inc + cc + fc) && types[k] != '\0'; i++)
	{
		j = 0;
		while (types[k] != ' ' && types[k] != '\0')
		{
			(dyn->detail[*indp])->types[i][j++] = types[k++];
		}
		(dyn->detail[*indp])->types[i][j] = '\0';
		if (types[k] == ' ')
			k++;
	}
	(dyn->detail[*indp])->varcnt[*indp] = (inc + cc + fc);
	(dyn->detail[*indp])->intcnt = inc;
	(dyn->detail[*indp])->charscnt = cc;
	(dyn->detail[*indp])->flocnt = fc;
	(*indp)++;
	return dyn;
}
*/
void typescount(char *types, int *inc, int *cc, int *fc)
{
	int i,k;
	char tmpar[100];
	i = 0;
	while (types[i] != '\0')
	{
		k = 0;
		while (types[i] != ' ' && types[i] != '\0')
		{
			tmpar[k++] = types[i++];
		}
		tmpar[k] = '\0';
		if (stcmp(tmpar, "int"))
		{
			(*inc)++;
		}
		else if (stcmp(tmpar, "string"))
		{
			(*cc)++;
		}
		else if (stcmp(tmpar, "float"))
		{
			(*fc)++;
		}
		if (types[i] == ' ')
			i++;
	}
}
/*dym *insert(char* quer, dym* dyn, int *indp)
{
	//insert filename schema
	int i,j,f,col,lines,vc,inc,cc,fc,k,val;
	int ia, ca, fa,ir,cr,fr;
	char filename[20];
	char schema[5];
	char buff[10000];
	char varnm[10];
	char *tmp = (char *)malloc(sizeof(char) * 30);
	for (i = 0; quer[i] != ' '; i++){}
	i++;
	j = f = col = 0;
	while (quer[i] != ' ')
	{
		filename[j++] = quer[i++];
	}
	filename[j] = '\0';
	i++;
	j = 0;
	while (quer[i] != '\0')
	{
		schema[j++] = quer[i++];
	}
	schema[j] = '\0';
	i++;
	for (i = 0; i < *indp; i++)
	{
		if (dyn->sch_name[i], schema)
			f = i;
	}
	FILE *fp = fopen(filename, "r");
	fscanf(fp, "%[^\0]%", buff);
	for (i = 0; buff[i] != '\n'; i++)
	{
		if (buff[i] == ',')
			col++;
	}
	col++;
	i = lines = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			lines++;
		i++;
	}
	lines++;
	vc = (dyn->detail[f])->varcnt[f];
	inc=(dyn->detail[f])->intcnt;
	cc=(dyn->detail[f])->charscnt;
	fc=(dyn->detail[f])->flocnt;
	((dyn->detail[f])->inarr) = (int**)calloc(inc,sizeof(int));
	for (i = 0; i < inc; i++)
	{
		((dyn->detail[f])->inarr[i]) = (int*)calloc(lines,sizeof(int));
	}
	(dyn->detail[f])->farr = (float**)malloc(sizeof(float*)*lines);
	for (i = 0; i < fc; i++)
	{
		((dyn->detail[f])->farr[i]) = (float*)malloc(sizeof(float)*lines);
	}
	(dyn->detail[f])->carr = (char***)malloc(sizeof(char)*cc);
	for (i = 0; i < cc; i++)
	{
		(dyn->detail[f])->carr[i] = (char**)malloc(sizeof(char)*lines);
		for (j = 0; j < lines; j++)
		{
			(dyn->detail[f])->carr[i][j] = (char*)malloc(sizeof(char)*30);
		}
	}
	i = ir = cr = fr = 0;
	while (buff[i] != '\0')
	{
		k = ia = fa = ca = 0;
		while (k < col)
		{
			j = 0;
			strcpy(tmp, "\0");
			csr(buff, tmp, &j, &i);
			strcpy(varnm, (dyn->detail[f])->types[k]);
			if (stcmp(varnm, "int"))
			{
				(dyn->detail[f])->inarr[ia++][ir] = char_to_int(tmp, j);
			}
			else if (stcmp(varnm, "float"))
			{
				(dyn->detail[f])->farr[fa++][fr] = atof(tmp, j);
			}
			else if (stcmp(varnm, "string"))
			{
				strcpy((dyn->detail[f])->carr[ca++][cr], tmp);
			}
			if (buff[i] != '\0')
				i++;
			k++;
		}
		cr++,fr++,ir++;
	}
	k = inc = fc = ca = 0;
	for (i = 0; i < lines;i++)
	{
		inc = fc = cc=0;
		printf("%d,", (dyn->detail[f])->inarr[inc++][i]);
		printf("%s,", (dyn->detail[f])->carr[cc++][ca]);
		//printf("%s", (dyn->detail[f])->carr[cc++][ca]);
		printf("%d,", (dyn->detail[f])->inarr[inc++][i]);
		printf("%d,", (dyn->detail[f])->inarr[inc++][i]);
		printf("%d,", (dyn->detail[f])->inarr[inc++][i]);
		printf("%d,", (dyn->detail[f])->inarr[inc++][i]);
		printf("%f,", (dyn->detail[f])->farr[fc++][i]);
		printf("%f", (dyn->detail[f])->farr[fc++][i]);
		printf("\n");
		ca++;
	}
	return dyn;
}
*/