/*
 字符串
 比较、拼接、复制
 子串：截取、查找（定位）、替换、计数
 匹配 

*/ 
#include <stdio.h>

// C语言：代码，常量区，栈，堆 
int main(){
//	字符指针 
	char *str = "Hello world";
	printf("%p\n",str);  
	// 0000000000404000
	char *str2 = "Hello world";
	printf("%p\n",str2); 
	// 0000000000404000
	
//	字符数组 
	char s3[] = "Hello";
	printf("%p\n",s3); 
	//  000000000062FE00
	// 数组存放在堆中 
	
	return 0; 
} 
