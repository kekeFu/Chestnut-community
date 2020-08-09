/*
初始化：空数组/空链表
push：数组尾插入/链表头插入
pop：数组尾删除/链表头删除
top： 看数组尾/链表头

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
	// -1 也行，但意义不同
}

int isFull(const struct Stack *ps) {
//	判断栈是否满了
	return ps->top == ps->capacity;
}

int isEmpty(const struct Stack *ps) {
//	判断栈是否为空
	return ps->top == 0;
}

int push(struct Stack *ps, int x) {
//	压栈 
	if(isFull(ps)) {
		return 0;
	} else {
		ps->data[ps->top++] = x;
		return 1;
	}
}

int pop(struct Stack *ps, int *px) {
//	弹栈 
	if (isEmpty(ps)) {
		return 0;
	} else {
		*px = ps->data[--(ps->top)];
		return 1;
	}
}

int top(const struct Stack *ps, int  *px) {
//	访问栈顶元素 
	if (isEmpty(ps)) {
		return 0;
	} else {
		*px = ps->data[ps->top-1];
		return 1;
	}
}

void destroy(struct Stack *ps){
//	释放空间 
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





