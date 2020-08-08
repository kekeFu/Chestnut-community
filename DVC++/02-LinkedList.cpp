#include <stdio.h>
#include <stdlib.h>

/* 
head pointer  ����ɾ����Ӱ��ͷָ��
  |
 ??? [ ] -> [ ] -> [ ]

head node  ���÷�������ͷָ��Ϊ�� 
[x] -> [ ] -> [ ]
*/ 

struct Node {
	int data;
	struct Node* next;
};

//typedef struct Node* LList; ȡ����


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
//	���ҵ�k-1 ��λ��
		p = findKth(*phead, k-1);
		/*
			printf("\n��k-1λ�õ�ֵ��%d\n",p->data);
			������Ϊp->data �� p Ϊ��ʱΪ�գ�

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
	printf("����");
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
// �ж�Խ������·���ֵ�� 
	int k1 = insert(&head, 5, 13);
	printf("%d\n", k1);
	printList(head);

	int x;
	removeNode(&head, 1 ,&x);
	printf("\nɾ����ֵ��%d\n",x);
	printList(head);

	int k = getLength(head); //��ȡ������ֵ����ı��
	printf("\n����ĳ���Ϊ��%d\n",k);

	return 0;
}



