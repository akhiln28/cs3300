#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** getList(char *args,int *n)
{
	int i;
	//size of list
	int l = strlen(args);
	*n = 1;
	for(i = 0;i < l;i++)
	{
		if(args[i] == ',')
		{
			(*n)++;
		}
	}
	char **list = (char**)malloc((*n)*sizeof(char*));
	for(i = 0;i < *n;i++)
	{
		list[i] = (char*)malloc((l)*sizeof(char));
	}
	int j = 0,k = 0;
	for(i = 0;i < l;i++)
	{
		if(args[i] == ',')
		{
			list[j][k] = '\0';
			k = 0;
			j++;
		}
		else
		{
			list[j][k] = args[i];
			k++;
		}
	}
	return list;
}
int main(int argc, char const *argv[])
{
	char args[] = {"akhil,nkdf,kdsfj,sdkl,adsfj"};
	int n;
	char **list = getList(args,&n);
	int i = 0;
	printf("%d\n", n);
	for(i = 0;i < n;i++)
	{
		int j = 0;
		while(list[i][j] != '\0')
		{
			printf("%c",list[i][j]);
			j++;
		}
		printf("\n");
	}
	char str[] = "akhil";
	for(i = 0;i < n;i++)
	{
		if(strcmp(str,list[i]) == 0)
		{
			printf("succes\n");
			return 0;
		}
	}
	printf("failure\n");
	return 0;
}