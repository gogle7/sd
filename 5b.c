#include<stdio.h>

int main(int argc,char *argv[])
{
	char c;
	FILE *fpt1,*fpt2;
	if(argc<3)
	{
		printf("File name is not provided as command line arguments.\n");
		return;
	}
	
	fpt1=fopen(argv[1],"r");
	fpt2=fopen(argv[2],"w");
	if(fpt1==NULL)
	{
		printf("FILE NOT FOUND.");
		return;
	}
	while(!feof(fpt1))
	{
		c=fgetc(fpt1);
		fputc(c,fpt2);
	}
	fclose(fpt1);
	fclose(fpt2);
	fpt2=fopen(argv[2],"r");
	printf("The contents after copy.\n");
	while((c=fgetc(fpt2))!=EOF)
	{
		printf(" %c",c);
	}
	fclose(fpt2);	
}
