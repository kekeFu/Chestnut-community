#include <stdio.h>
#define MAX 10
struct SList {
	int data[MAX];
	int length;
};

void init(struct SList * p) {
	p->length = 0;
}
void printList(const struct SList * p) {
	for(int i=0; i<p->length; i++) {
		printf("%d,",p->data[i]);
	}
	putchar('\n');
}

int insert(struct SList * p, int k, int x) {
	if (k<0 || k>p->length || p->length==MAX) {
		return 0;
	} else {
//		从最后一个元素开始往后挪，空出第k个位置来 
		for(int i=p->length; i>=k; i--) {
			p->data[i+1] = p->data[i];
		}
		p->data[k] = x; // 插入元素 x 
		p->length++;
		return 1;
	}
}

int erase(struct SList * p, int k, int *px) {
	if (k<0 || k>=p->length) {
		return 0;
	} else {
		// 用一个指针来存即将删除的元素 
		*px = p->data[k]; 
		// 从第k+1处开始往前挪一个位置，
		// 即第k+1处的元素前移到第k个位置 …最后一个元素前移到第length-1个位置 
		for(int i=k+1; i<p->length; i++) {
			p->data[i-1] = p->data[i]; 
		}
		p->length--; 
		return 1;
	}
}

int main() {
	struct SList a;
	init(&a);
	insert(&a, 0, 3);
	insert(&a, 0, 4);
	printList(&a);
	int x;
	erase(&a, 1, &x);
	printList(&a);
	printf("\n删除的元素：%d\n", x);

	return 0;
}
