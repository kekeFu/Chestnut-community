// ��ά���� 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(int (*)[5], int);
void func(int (*p)[5], int k) {
	// int array[][5] ��int (*p)[5] �ȼ�
//	 putchar();

}

//void funMean()

int main() {
//	int array[3][5]={12,31};
//	array[2][4]=11;
//	int (*p)[5];
//	p=array;
//	func(array, 3);
//	printf("%d\n", sizeof(array)/sizeof(array[0][0]));
//	printf("%d\n",(*p)[3]);
//	putchar((*p)[2]);


//	����ÿ����ܽ�ˮ������ƽ����ˮ������ƽ����ˮ��
	int a=0;
	float rain[5][12];
	char s[]="                    ";
	printf("%s�����꽵ˮ����\n",s);
	for(int i=0; i<5; i++) {
		for(int j=0; j<12; j++) {
			rain[i][j]=1.0*(i+1)*(j+1);
			printf("%6.1f",rain[i][j]);
			a+=1;
			if(a%12==0) {
				printf("\n");
			}
		}
	}

	a=0;
	float t=0.0;
	printf("\n%s����ÿ���ܽ�ˮ��\n", s);
	float sum[5],all=0.0;
	for(int i=0; i<5; i++) {
//		i �� j ����������ڵ�ǰ��forѭ����
		for(int j=0; j<12; j++) {
			t +=rain[i][j];
			a +=1;
			if(a%12==0) {
				sum[i]=t;
				all += sum[i];
				printf("��%d�꣺%6.1f\n",i+1,sum[i]);
				t=0.0;
			}
		}
	}
	printf("��ƽ����ˮ��: %6.1f\n", all/5);

	a=0,all=0.0;
	printf("\n%s5����ÿ��ƽ����ˮ��\n",s);
	float month[12]= {0.0};
	for(int j=0; j<12; j++) {
		for(int i=0; i<5; i++) {
			month[j] +=rain[i][j];
			a++;
			if(a%5==0) {
				all += month[j];
				printf("%d��ƽ����ˮ��: %6.1f\n",j+1, month[j]/5);
			}
		}
	}
	printf("��ƽ����ˮ��: %6.1f\n",all/12);


	return 0;
}
