#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
using namespace std;
int gettimeofday(struct timeval *tv,struct timezone *tz);
int main(){
	
	FILE *f1;
	char *mem;
	int filesize=200*1024*1024;
	mem=(char*)malloc(4*1024);
	struct timeval start;
	struct timeval end;
	struct timeval n;
	unsigned long diff;
	srand(time(NULL));
	f1=fopen("./write.txt","r");
	
	gettimeofday(&start, &n);
	for(int i = 0;i < 50000 ; i++){
		int offset=(rand()%filesize)+1;
		fseek(f1,offset,SEEK_SET);
		fread(mem,sizeof(char), 4*1024 / sizeof(char), f1);
	}
	gettimeofday(&end, &n);
	diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	printf("the difference is %ld (us)\n", diff);
	fclose(f1);
	return 0;
}

