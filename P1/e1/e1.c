#include <stdio.h>

int g=3, z=4;

int f(int * x, int y){
	static int c=5;
	printf("c=%d\n",c );
	int a = *(x+1), c2 = (c++);
	printf("*(x+1)=%d y=%d (c++)=%d\n",a,y,c2 );
	return a+y+c2;
	//return (*(x+1))+y+(c++); //(1)
}

int main(void){
	int a[5]={1,2,3,4,5};
	int f1=f(a,a[0]), f2=f(&g,a[g]);
	printf("f1=%d\nf2=%d\n",f1,f2 );
	int r=f1+f2;
	printf("r=%d\n",r );
	return r;
}