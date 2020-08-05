#include <stdio.h>
#include <time.h>

clock_t start,stop;

double duration;

double f1(int n, double a[],double x){
	int i;
	double p=a[0];
	for (i=1;i<=n;i++){
		p +=(a[i]*pow(x,i));
	}
	return p;
}

double f2(int n, double a[],double x){
	int i;
	double p=a[n];
	for (i=n;i>0;i--){
		p = a[i-1] + x*p;
	}
	return p;
}

int main(){
	int n=9;
	double a[]=0;
	double x=1.1;
	
	start=clock();
	f1(n,a,x);
	stop=clock();
	duration=((double)(stop-start))/CLK_TCK;
	
	printf("t1%d\n",duration);
	
	return 0;
}
