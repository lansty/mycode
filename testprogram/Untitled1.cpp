#include<stdio.h>
#include<assert.h>
int main(void)
{
	 int i  = 2;
	 int *p = NULL;
	 int select = 0;
	 scanf("%d",&select);
	 if(select == 1) p = &i;
	 else p = NULL;
	 assert(p);
	 printf("this is test program!");
	return 0;
}
