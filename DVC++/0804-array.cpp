//����
#include <stdio.h>
#include <stdlib.h>

//	��������Ԫ�� �ĵ�ַ 
int findX(int * array, int size,int x){
	int index=-1; // ���Ԫ�ز������򷵻�-1 
	for(int i=0;i<size;i++){
		if (array[i]==x){
			index=i;
		}
	}
	return index;
} 

//	����ָ����ַ�� ����Ԫ�أ�
//  �ص������ж� y �Ƿ�Խ�磡 
int findY(int *array, int size, int y,int *px){
	int value=1;
	if (y<0 || y>=size){
		value=0;
	}else{
		*px =array[y];
		printf("%d", *px); //22
	}
	return value;
} 

//�������Ԫ��
int findMax(int *array,int size){
	int max;
	max=array[0];
	for (int i=0;i<size;i++){
		if(max<array[i]){
			max=array[i];
		}
	}
	return max;
}


int main(int argc,const char * argv[]){
	int array[100]={11,21,22,31};
	int *q = (int *)malloc(100*sizeof(int)); 	//[Error] invalid conversion from 'void*' to 'int*' [-fpermissive]
	printf("%d\n",*(array+1));
	printf("%1d\n",sizeof(array));
	
//	��������Ԫ�� �ĵ�ַ 
	int x;
	x = findX(array, 100, 22); 
//	printf("%d\n",x);
	
	int y,p;
	y = findY(array, 100, 2, &p);
	printf("\n%d, %d\n",y,p); 
//	1,22
	
//	�������ֵ
	int max=findMax(array, 100);
	printf("%d\n",max);
	
	return 0;
}






 
