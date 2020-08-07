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
//		�����һ��Ԫ�ؿ�ʼ����Ų���ճ���k��λ���� 
		for(int i=p->length; i>=k; i--) {
			p->data[i+1] = p->data[i];
		}
		p->data[k] = x; // ����Ԫ�� x 
		p->length++;
		return 1;
	}
}

int erase(struct SList * p, int k, int *px) {
	if (k<0 || k>=p->length) {
		return 0;
	} else {
		// ��һ��ָ�����漴��ɾ����Ԫ�� 
		*px = p->data[k]; 
		// �ӵ�k+1����ʼ��ǰŲһ��λ�ã�
		// ����k+1����Ԫ��ǰ�Ƶ���k��λ�� �����һ��Ԫ��ǰ�Ƶ���length-1��λ�� 
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
	printf("\nɾ����Ԫ�أ�%d\n", x);

	return 0;
}
