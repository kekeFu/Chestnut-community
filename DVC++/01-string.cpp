/*
 �ַ���
 �Ƚϡ�ƴ�ӡ�����
 �Ӵ�����ȡ�����ң���λ�����滻������
 ƥ�� 

*/ 
#include <stdio.h>

// C���ԣ����룬��������ջ���� 
int main(){
//	�ַ�ָ�� 
	char *str = "Hello world";
	printf("%p\n",str);  
	// 0000000000404000
	char *str2 = "Hello world";
	printf("%p\n",str2); 
	// 0000000000404000
	
//	�ַ����� 
	char s3[] = "Hello";
	printf("%p\n",s3); 
	//  000000000062FE00
	// �������ڶ��� 
	
	return 0; 
} 
