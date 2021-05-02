#include <stdio.h>
int f1(int *a, int b)
{
	*a = *a / b;
	return *a++;
}
int f2(int* p)
{
	int b;
	b=*p++;
	b++;
	b=*p++;
	return b;
}
void f3(char *p)
{
	*(p+3)='A';
	*p++='A';
	p+=3;
	*p='A';
}
int main()
{
	int A[4]={100,101,102,103};
	int B[3][3]={1,2,3,4};
	char c[]="Sarajevo";
	int b=1,a=1;
	b=B[0][2]+*(A+2);
	printf("%d\n",b);
	b=f1(B+1,b+1);
	printf("%d\n",b);
	b=f2(B);
	printf("%d\n",b);
	f1(&a,a);
	printf("%d\n",a);
	f3(c);
	printf("%s\n",c);
	return 0;
}
