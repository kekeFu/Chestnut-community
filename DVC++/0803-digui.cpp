#include <stdio.h>

void t1(int N){
	if(N){
		t1(N-1);
		printf("%d\n",N);
	}
} 
void t2(int N){
	for(int i=0;i<N;i++){
		printf("%d\n",i);
	}
} 

int main(){
	int n;
	scanf("%d",&n);
	t1(n);
//	t2(n);
}
