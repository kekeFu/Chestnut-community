// 输入半径求圆形的面积 
#include <stdio.h>
//#define PI=3.14159265358979323


int main(){
	int r;
	double PI=3.14159265358979323;
	scanf("%d",&r);
	if(r>=1 && r<=10000){
	printf("%.7f", PI*r*r);
	}
	
	return 0;
} 


