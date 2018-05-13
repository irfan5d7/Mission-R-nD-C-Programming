#include"Header.h"
#include"utilfunc.h"
void console();
dym* create(char *quer, dym *dyn, int *indp);
dym* import(char* quer, dym* dyn, int indp);
dym* operate(char* quer, dym* dyn, int indp);
dyntmp* tmpsave(dym* dyn, dyntmp* tmp, int f, int i, int *k);
dyntmp* select(dym* dyn, dyntmp* dtmp, int si, char* key, char* operator, int vari,char* dtype);


int main()
{
	console();
}

void console()
{
	char command[100];
	char key[10];
	int i, k, j,indp, lines;
	indp = lines  = 0;
	dym *dyn = (dym*)malloc(sizeof(dym));
	printf("Create Syntax:create schema schema_name var:type,var:type,var:type \n---Example : create schema s1 roll:int,name:string,m1:int,avg:float,cgpa:float\n");
	printf("Import Syntax : import filename.csv schema_name\n---Example : import check.csv s1\n\n");
	printf("Select Syntax: select cols from schema_name where col operator value\n---Example:select * from s1 where roll le 5\n Select * from schema_name\n\n");
	while (1)
	{
		printf(">");
		scanf(" %[^\n]s", &command);
		strcpy(key, "\0");
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
		else if (stcmp(key, "create"))
		{
			dyn = create(command, dyn, indp);
			
		}
		else if (stcmp(key, "import"))
		{
			dyn = import(command, dyn, indp);
		}
		else if (stcmp(key, "select"))
		{
			dyn = operate(command, dyn, indp);
		}
	}
	return;
}

dym* create(char *quer, dym *dyn, int *indp)
{
	//create schema s4 m1:int m2 :int
	int i, k, j, inc, cc, fc, c;
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
	for (i = 0; i < (inc + cc + fc) && vars[k] != '\0'; i++)
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
	(dyn->detail[*indp])->varcnt = (inc + cc + fc);
	(dyn->detail[*indp])->intcnt = inc;
	(dyn->detail[*indp])->charscnt = cc;
	(dyn->detail[*indp])->flocnt = fc;
	(*indp)++;
	return dyn;
}

dym* import(char* quer, dym* dyn, int *indp)
{
	//insert filename schema
	int i, j, f, col, lines, vc, inc, cc, fc, k, val;
	int ia, ca, fa, ir, cr, fr;
	char filename[20];
	char schema[5];
	char buff[100000];
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
	for (i = 0; i < indp; i++)
	{
		if (stcmp(dyn->sch_name[i], schema))
			f = i;
	}
	FILE *fp = fopen(filename, "r");
	fscanf(fp, "%[^\0]s", buff);
	fclose(fp);
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
	vc = (dyn->detail[f])->varcnt;
	inc = (dyn->detail[f])->intcnt;
	cc = (dyn->detail[f])->charscnt;
	fc = (dyn->detail[f])->flocnt;
	(dyn->detail[f])->recordscnt = lines;
	((dyn->detail[f])->inarr) = (int**)calloc(inc, sizeof(int*));
	for (i = 0; i < inc; i++)
	{
		((dyn->detail[f])->inarr[i]) = (int*)calloc(lines, sizeof(int));
	}
	(dyn->detail[f])->farr = (float**)malloc(sizeof(float*)*lines);
	for (i = 0; i < fc; i++)
	{
		((dyn->detail[f])->farr[i]) = (float*)malloc(sizeof(float)*lines);
	}
	(dyn->detail[f])->carr = (char***)malloc(sizeof(char**)*cc);
	for (i = 0; i < cc; i++)
	{
		(dyn->detail[f])->carr[i] = (char**)malloc(sizeof(char*)*lines);
		for (j = 0; j < lines; j++)
		{
			(dyn->detail[f])->carr[i][j] = (char*)malloc(sizeof(char) * 30);
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
				strcpy((dyn->detail[f])->carr[ca][cr], tmp);
				ca++;
			}
			if (buff[i] != '\0')
				i++;
			k++;
		}
		cr++, fr++, ir++;
	}
	k = inc = fc = ca = 0;
	return dyn;
}
dym* operate(char* quer, dym* dyn, int *indp)
{
	char key[15];
	char schema[5];
	char varnm[10];
	char operator[10];
	char value[20];
	char display[100];
	char **disp; 
	char *type = (char*)malloc(sizeof(char) * 30);
	dyntmp* dtmp = NULL;
	int i, j, f, lines, k, val, vari,vc;
	char *tmp = (char *)malloc(sizeof(char) * 30);
	for (i = 0; quer[i] != ' '; i++){}
	i++;
	j = f = 0;
	strcpy(display, "\0");
	while (1)
	{
		while (quer[i] != ' ' && quer[i] != '\0')
		{
			display[j] = quer[i++];
			j++;
		}
		i++;
		if (j >= 5)
		{
			if (display[j - 1] == 'm' && display[j - 2] == 'o' && display[j - 3] == 'r' && display[j - 4] == 'f')
			{
				display[j-5] = '\0';
				f = 1;
			}
		}
		display[j++] = ',';
		if (f)
			break;
	}
	f = 0;
	strcpy(schema, "\0");
	j = 0;
	while (quer[i] != ' ' && quer[i] != '\0')
	{
		schema[j++] = quer[i++];
	}
	schema[j] = '\0';
	i++;
	for (j = 0; j < indp; j++)
	{
		if (stcmp(dyn->sch_name[j], schema))
			f = j;
	}
	if (quer[i-1] == '\0')
	{
		int inc, cc, fc;
		vc = (dyn->detail[f])->varcnt;
		inc = (dyn->detail[f])->intcnt;
		cc = (dyn->detail[f])->charscnt;
		fc = (dyn->detail[f])->flocnt;
		lines = (dyn->detail[f])->recordscnt;
		dtmp = (dyntmp*)malloc(sizeof(dyntmp));
		(dtmp->inarr) = (int**)malloc(sizeof(int*)*inc);
		for (i = 0; i < inc; i++)
		{
			((dtmp)->inarr[i]) = (int*)calloc(lines, sizeof(int*));
		}
		(dtmp)->farr = (float**)malloc(sizeof(float*)*lines);
		for (i = 0; i < fc; i++)
		{
			((dtmp)->farr[i]) = (float*)malloc(sizeof(float)*lines);
		}
		(dtmp)->carr = (char***)malloc(sizeof(char**)*cc);
		for (i = 0; i < cc; i++)
		{
			(dtmp)->carr[i] = (char**)malloc(sizeof(char*)*lines);
			for (j = 0; j < lines; j++)
			{
				(dtmp)->carr[i][j] = (char*)malloc(sizeof(char) * 30);
			}
		}
		k = 0;
		for (i = 0; i < lines; i++)
		{
			dtmp = tmpsave(dyn, dtmp, f, i, &k);
		}
		dtmp->recordscnt = k;
	}
	else
	{
		while (1)
		{
			strcpy(key, "\0");
			j = 0;
			while (quer[i] != ' ')
			{
				key[j++] = quer[i++];
			}
			key[j] = '\0';
			i++;
			if (stcmp(key, "where"))
				break;
		}
		strcpy(key, "\0");
		j = 0;
		while (quer[i] != ' ')
		{
			key[j++] = quer[i++];
		}
		key[j] = '\0';
		i++;
		strcpy(operator, "\0");
		j = 0;
		while (quer[i] != ' ')
		{
			operator[j++] = quer[i++];
		}
		operator[j] = '\0';
		i++;
		strcpy(value, "\0");
		j = 0;
		while (quer[i] != '\0')
		{
			value[j++] = quer[i++];
		}
		value[j] = '\0';
		i++;
		lines = (dyn->detail[f])->recordscnt;
		vc = (dyn->detail[f])->varcnt;
		for (i = 0; i < vc; i++)
		{
			if (stcmp((dyn->detail[f])->vars[i], key))
			{
				vari = i;
				break;
			}
		}
		j = vari;
		strcpy(type, (dyn->detail[f])->types[j]);
		dtmp = select(dyn, dtmp, f, key, operator,value, vari, type);

	}

		/*for (j = 0; j < dtmp->recordscnt; j++)
		{
			printf("\n%d,%s,%f\n", dtmp->inarr[0][j],dtmp->carr[0][j],dtmp->farr[0][j]);
		}
		*/
		i = val = 0;
		while (display[i] != '\0')
		{
			if (display[i] == ',')
				val++;
			i++;
		}
		val++;
		disp = (char**)malloc(sizeof(char*)*val);
		for (i = 0; i < val; i++)
		{
			disp[i] = (char*)malloc(sizeof(char)*10);
		}
		i = k = 0;
		while (display[i] != '\0')
		{
			strcpy(tmp, "\0");
			j = 0;
			csr(display, tmp, &j, &i);
			strcpy(disp[k], tmp);
			k++;
			if (display[i] != '\0')
				i++;
		}
		int iaa, caa, faa,tc,t,ia,ca,fa,ai,l;
		iaa = caa = faa = ia = ca = fa = ai = 0;
		tc = 0;
		t = ((dyn->detail[f])->intcnt) + ((dyn->detail[f])->charscnt) + ((dyn->detail[f])->flocnt);
		i = j= 0;
		if (val == 1 && stcmp("*", display))
		{
			while (j<dtmp->recordscnt)
			{
				iaa = faa = caa = tc = 0;
				while (tc<t)
				{
					if (stcmp((dyn->detail[f])->types[tc], "int"))
					{
						printf(" %d ", dtmp->inarr[iaa++][ia]);
					}
					else if (stcmp((dyn->detail[f])->types[tc], "string"))
					{
						printf(" %s ", dtmp->carr[caa++][ca]);
					}
					else if (stcmp((dyn->detail[f])->types[tc], "float"))
					{
						printf(" %f ", dtmp->farr[faa++][fa]);
					}
					tc++;
				}
				printf("\n");
				j++, ia++, ca++, fa++;
			}
		}
		else
		{
			i = j = 0;
			while (j<dtmp->recordscnt)
			{
				for (k = 0; k < val; k++)
				{
					strcpy(tmp, disp[k]);
					for (i = 0; i < t; i++)
					{
						if (stcmp(tmp, (dyn->detail[f])->vars[i]))
							break;
					}
					strcpy(tmp, (dyn->detail[f])->types[i]);
					if (stcmp(tmp, "int"))
					{
						ai = 0;
						for (l = 0; l < i; l++)
						{
							strcpy(tmp, "\0");
							strcpy(tmp,(dyn->detail[f])->types[l]);
							if (stcmp(tmp, "int"))
							{
								ai++;
							}
						}
						printf(" %d ", dtmp->inarr[ai][iaa]);
					}
					else if (stcmp(tmp, "float"))
					{
						ai = 0;
						for (l = 0; l < i; l++)
						{
							strcpy(tmp, "\0");
							strcpy(tmp, (dyn->detail[f])->types[l]);
							if (stcmp(tmp, "float"))
							{
								ai++;
							}
						}
						printf(" %f ", dtmp->farr[ai][faa]);
					}
					else if (stcmp(tmp, "string"))
					{
						ai = 0;
						for (l = 0; l < i; l++)
						{
							strcpy(tmp, "\0");
							strcpy(tmp, (dyn->detail[f])->types[l]);
							if (stcmp(tmp, "string"))
							{
								ai++;
							}
						}
						printf(" %s ", dtmp->carr[ai][caa]);
					}
				}
				j++, iaa++, faa++, caa++;
				printf("\n");
			}
		}
		free(dtmp);
		free(dyn);
		return;
}
dyntmp* select(dym* dyn, dyntmp* dtmp, int si, char* key, char* operator,char* value,int vari,char* dtype)
{
	int i, j,vc, inc, cc, fc, k, val,ai,lines;
	char tmp[15];
	int f = si;
	vc = (dyn->detail[f])->varcnt;
	inc = (dyn->detail[f])->intcnt;
	cc = (dyn->detail[f])->charscnt;
	fc = (dyn->detail[f])->flocnt;
	lines=(dyn->detail[f])->recordscnt;
	dtmp = (dyntmp*)malloc(sizeof(dyntmp));
	(dtmp->inarr) = (int**)malloc(sizeof(int*)*inc);
	for (i = 0; i < inc; i++)
	{
		((dtmp)->inarr[i]) = (int*)calloc(lines, sizeof(int*));
	}
	(dtmp)->farr = (float**)malloc(sizeof(float*)*lines);
	for (i = 0; i < fc; i++)
	{
		((dtmp)->farr[i]) = (float*)malloc(sizeof(float)*lines);
	}
	(dtmp)->carr = (char***)malloc(sizeof(char**)*cc);
	for (i = 0; i < cc; i++)
	{
		(dtmp)->carr[i] = (char**)malloc(sizeof(char*)*lines);
		for (j = 0; j < lines; j++)
		{
			(dtmp)->carr[i][j] = (char*)malloc(sizeof(char) * 30);
		}
	}
	ai = 0;
	if (stcmp(dtype, "int"))
	{
		val = char_to_int(value, strlen(value));
		for (i = 0; i < vari; i++)
		{
			strcpy(tmp, "\0");
			strcpy(tmp,(dyn->detail[f])->types[i]);
			if (stcmp(tmp, "int"))
			{
				ai++;
			}
		}
		k = 0;
		if (stcmp(operator,"le"))
		{
			for (i = 0; i < lines; i++)
			{
				if ((dyn->detail[f])->inarr[ai][i] <= val)
				{
					dtmp = tmpsave(dyn, dtmp, f, i, &k);
				}
			}
		}
		else if (stcmp(operator,"ge"))
		{
			for (i = 0; i < lines; i++)
			{
				if ((dyn->detail[f])->inarr[ai][i] >= val)
				{
					dtmp = tmpsave(dyn, dtmp, f, i, &k);
				}
			}
		}
		else if (stcmp(operator,"lt"))
		{
			for (i = 0; i < lines; i++)
			{
				if ((dyn->detail[f])->inarr[ai][i] < val)
				{
					dtmp = tmpsave(dyn, dtmp, f, i, &k);
				}
			}
		}
		if (stcmp(operator,"gt"))
		{
			for (i = 0; i < lines; i++)
			{
				if ((dyn->detail[f])->inarr[ai][i] > val)
				{
					dtmp = tmpsave(dyn, dtmp, f, i, &k);
				}
			}
		}
	}
	else if (stcmp(dtype, "float"))
	{
		val = atof(value, strlen(value));
		for (i = 0; i < vari; i++)
		{
			strcpy(tmp, "\0");
			strcpy(tmp,(dyn->detail[f])->types[i]);
			if (stcmp(tmp, "float"))
			{
				ai++;
			}
		}
		k = 0;
		if (stcmp(operator,"le"))
		{
			for (i = 0; i < lines; i++)
			{
				if ((dyn->detail[f])->farr[ai][i] <= val)
				{
					dtmp = tmpsave(dyn, dtmp, f, i, &k);
				}
			}
		}
		else if (stcmp(operator,"ge"))
		{
			for (i = 0; i < lines; i++)
			{
				if ((dyn->detail[f])->farr[ai][i] >= val)
				{
					dtmp = tmpsave(dyn, dtmp, f, i, &k);
				}
			}
		}
		else if (stcmp(operator,"lt"))
		{
			for (i = 0; i < lines; i++)
			{
				if ((dyn->detail[f])->farr[ai][i] < val)
				{
					dtmp = tmpsave(dyn, dtmp, f, i, &k);
				}
			}
		}
		else if (stcmp(operator,"gt"))
		{
			for (i = 0; i < lines; i++)
			{
				if ((dyn->detail[f])->farr[ai][i] > val)
				{
					dtmp = tmpsave(dyn, dtmp, f, i, &k);
				}
			}
		}
	}
	else if (stcmp(dtype, "string"))
	{
		for (i = 0; i < vari; i++)
		{
			strcpy(tmp, "\0");
			strcpy(tmp, (dyn->detail[f])->types[i]);
			if (stcmp(tmp, "string"))
			{
				ai++;
			}
		}
		k = 0;
		if (stcmp(operator,"matches"))
		{
			for (i = 0; i < lines; i++)
			{
				if (stcmp((dyn->detail[f])->carr[ai][i], value))
				{
					dtmp = tmpsave(dyn, dtmp, f, i, &k);
				}
			}
		}
		else if (stcmp(operator,"contains"))
		{
			for (i = 0; i < lines; i++)
			{
				if (substr((dyn->detail[f])->carr[ai][i], value))
				{
					dtmp = tmpsave(dyn, dtmp, f, i, &k);
				}
			}
		}
		
	}
	dtmp->recordscnt = k;
	return dtmp;
}
dyntmp* tmpsave(dym* dyn, dyntmp* tmp, int f, int i, int *k)
{
	int inc, cc, fc,vc,indx;
	vc = (dyn->detail[f])->varcnt;
	inc = (dyn->detail[f])->intcnt;
	cc = (dyn->detail[f])->charscnt;
	fc = (dyn->detail[f])->flocnt;
	for (indx = 0; indx < inc; indx++)
	{
		(tmp)->inarr[indx][*k] = (dyn->detail[f])->inarr[indx][i];
	}
	for (indx = 0; indx < fc; indx++)
	{
		(tmp)->farr[indx][*k] = (dyn->detail[f])->farr[indx][i];
	}
	for (indx = 0; indx < cc; indx++)
	{
		strcpy((tmp)->carr[indx][*k] ,(dyn->detail[f])->carr[indx][i]);
	}
	(*k)++;
	return tmp;
}
