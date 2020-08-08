#include <stdio.h>
#include <stdlib.h>

/* 
head pointer  插入删除会影响头指针
  |
 ??? [ ] -> [ ] -> [ ]

head node  常用方法，即头指针为空 
[x] -> [ ] -> [ ]
*/ 

struct Node {
	int data;
	struct Node* next;
};

//typedef struct Node* LList; 取别名


void init(struct Node** phead ) {
	*phead = NULL;
}

struct Node* createNode(int x) {
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->next = NULL;
	t->data = x;
	return t;
}

struct Node* findKth(struct Node* head, int k) {
	int count =1;
	struct Node* p;
	p = head;
	while(p && count <k) {
		p = p->next;
		count++;
	}
	return p;
}

int insert(struct Node** phead, int k, int x ) {
	if (k<0) {
		return 0;
	} else if(k==1) {
		struct Node* t;
		t = createNode(x);
		t->next = *phead;
		*phead = t;
		return 1;
	} else {
		struct Node* p;
//	先找第k-1 个位置
		p = findKth(*phead, k-1);
		/*
			printf("\n第k-1位置的值是%d\n",p->data);
			出错！因为p->data 在 p 为空时为空！

		*/
		if(p) {
			struct Node* t;
			t = createNode(x);
			t->next = p->next;
			p->next = t;
			return 1;
		} else {
			return 0;
		}
	}

}

int removeNode(struct Node** phead, int k, int *px) {
	if (k<0) {
		return 0;
	} else if(k==1) {
		if(*phead) {
			*px = (*phead)->data;
			*phead = (*phead)->next;
			return 1;
		} else {
			return 0;
		}
	} else {
		struct Node* p;
		p = findKth(*phead, k);

		if (p==NULL || p->next==NULL) {
			return 0;
		}
		struct Node* t;
		t = p->next;
		p->next = t->next;
		*px = t->data;
		free(t);
		return 1;
	}
}

int getLength(struct Node* head) {
	int len = 0;
	while(head) {
		len++;
		head = head->next;
	}
	return len;
}

void printList(struct Node* head) {
	printf("链表：");
	while(head) {
		printf("%d,", head->data);
		head = head->next;
	}
	printf("\n");
}

int main() {
	struct Node* head;
	init(&head);

	insert(&head, 1, 11);
	printList(head);
	insert(&head, 1, 2);
	printList(head);
	insert(&head, 2, 13);
	printList(head);
// 判断越界情况下返回值！ 
	int k1 = insert(&head, 5, 13);
	printf("%d\n", k1);
	printList(head);

	int x;
	removeNode(&head, 1 ,&x);
	printf("\n删除的值：%d\n",x);
	printList(head);

	int k = getLength(head); //获取表长，传值不会改变表长
	printf("\n链表的长度为：%d\n",k);

	return 0;
}



