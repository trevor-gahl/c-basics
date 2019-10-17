#include <stdio.h>

int main()
{
	char str_a[20];
	str_a[0] = 'H';
	str_a[1] = 'e';
	str_a[2] = 'l';
	str_a[3] = 'l';
	str_a[4] = 'o';
	str_a[5] = ' ';
	str_a[6] = 'W';
	str_a[7] = 'o';
	str_a[8] = 'r';
	str_a[9] = 'l';
	str_a[10] = 'd';
	str_a[11] = '\n';
	str_a[12] = 0;
	//printf(str_a);

	for(int i = 0; i <sizeof(str_a); i ++)
	{
	
		if(str_a[i]==0)
		{
			break;
		} else {
			printf("%c\n",str_a[i]);
		}
	}

}
