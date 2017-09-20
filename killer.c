//Kill all 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
	char template[512]={0};
	sprintf(template,"pgrep %s|xargs kill -9",argv[1]);
	system(template);
	return 0;	
}
