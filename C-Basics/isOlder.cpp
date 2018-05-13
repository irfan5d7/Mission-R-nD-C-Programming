/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int isOlder(char *dob1, char *dob2) {
	int i = 0, len1,len2, s = 0;
	while (dob1[i] != '\0')
	{
		i++;
	}
	len1 = i;
	i = 0;
	while (dob2[i] != '\0')
	{
		i++;
	}
	len2 = i;
	if (len1 != 10 || dob1[2] != 45 || dob1[5] != 45)
		return -1;
	else if (len2 != 10 || dob2[2] != 45 || dob2[5] != 45)
		return -1;
	else
	{
		int dd1, mm1, yy1,dd2,mm2,yy2,j=1;
		for (i = 9; i >= 6; i--)
		{
			s = s + ((dob1[i]-48) * j);
			j = j * 10;
		}
		yy1 = s;
		s = 0, j = 1;
		for (i = 9; i >=6; i--)
		{
			s = s + ((dob2[i]-48) * j);
			j = j * 10;
		}
		yy2 = s;
		s = 0, j = 1;
			for (i = 4; i >= 3; i--)
			{
				s = s + ((dob1[i] - 48) * j);
				j = j * 10;
			}
			mm1 = s;
			s = 0, j = 1;
			for (i = 4; i >= 3; i--)
			{
				s = s + ((dob2[i] - 48) * j);
				j = j * 10;
			}
			mm2 = s;
			s = 0, j = 1;
			for (i = 1; i >= 0; i--)
			{
				s = s + ((dob1[i] - 48) * j);
				j = j * 10;
			}
			dd1 = s;
			s = 0, j = 1;
			for (i = 1; i >= 0; i--)
			{
				s = s + ((dob2[i] - 48) * j);
				j = j * 10;
			}
			dd2 = s;
			if (mm1 > 12 || mm2 > 12)
				return-1;
			else
			{
				if (mm1 == 2 && dd1==29)
					if (!(yy1 % 400 == 0 || yy1 % 100 == 0 || yy1 % 4 ==0))
						return -1;
				if (mm2 == 2 && dd2 == 29)
					if (!(yy2 % 400 == 0 || yy2 % 100 == 0 || yy2 % 4 ==0))
						return -1;
				if (dd1 == 31)
					if (!(mm1 == 1 || mm1 == 3 || mm1 == 5 || mm1 == 7 || mm1 == 8 || mm1 == 10 || mm1 == 12))
						return -1;
				if (dd2 == 31)
					if (!(mm2 == 1 || mm2 == 3 || mm2 == 5 || mm2 == 7 || mm2 == 8 || mm2 == 10 || mm2 == 12))
						return -1;
				if (yy1 < yy2)
					return 1;
				if (yy1 > yy2)
					return 2;
				if (yy1 == yy2)
				{
					if (mm1 < mm2)
						return 1;
					if (mm1 > mm2)
						return 2;
					if (mm1 == mm2)
					{
						if (dd1 < dd2)
							return 1;
						else if (dd1 > dd2)
							return 2;
						else
							return 0;

					}
				}
			}


	}
}