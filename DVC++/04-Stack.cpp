/*
��ʼ����������/������
push������β����/����ͷ����
pop������βɾ��/����ͷɾ��
top�� ������β/����ͷ

*/
#include <stdio.h>
#include <stdlib.h>
struct Stack {
	int *data;
	int capacity;
	int top;
};

void init(struct Stack *ps, int capacity) {
	ps->capacity = capacity;
	ps->data = (int *)malloc(sizeof(int)*capacity);
	printf("%d\n",ps->data);
	ps->top = 0; 
	// -1 Ҳ�У������岻ͬ
}

int isFull(const struct Stack *ps) {
//	�ж�ջ�Ƿ�����
	return ps->top == ps->capacity;
}

int isEmpty(const struct Stack *ps) {
//	�ж�ջ�Ƿ�Ϊ��
	return ps->top == 0;
}

int push(struct Stack *ps, int x) {
//	ѹջ 
	if(isFull(ps)) {
		return 0;
	} else {
		ps->data[ps->top++] = x;
		return 1;
	}
}

int pop(struct Stack *ps, int *px) {
//	��ջ 
	if (isEmpty(ps)) {
		return 0;
	} else {
		*px = ps->data[--(ps->top)];
		return 1;
	}
}

int top(const struct Stack *ps, int  *px) {
//	����ջ��Ԫ�� 
	if (isEmpty(ps)) {
		return 0;
	} else {
		*px = ps->data[ps->top-1];
		return 1;
	}
}

void destroy(struct Stack *ps){
//	�ͷſռ� 
	free(ps->data);
}

int main() {
	struct Stack st;
	init(&st, 5);
	push(&st, 13);
	push(&st, 13);
	push(&st, 12);
	push(&st, 1);
	int x;
	top(&st, &x);
	printf("%d\n",x);
	pop(&st, &x);
	printf("%d\n",x);
	top(&st, &x);
	printf("%d\n",x);
	destroy(&st);
	
	return 0;
}





