/* 7-1�����ڴ�����
��һ��Ϊ����������20��������M��N���м��һ�񣬱�ʾ��άƽ����M�С�N�С�
������M�У�ÿ����N��0����#�ַ�������#��ʾ���ڸ��������ӡ�
I
������һ�У�����һ��������400��������k����ʾ�����ڵ���������
���k�У�ÿ�а��������ڵ�����������x��y (0��x<M��0��y<N)��֮����һ���ո�����
�����ʽ:
��Ӧ�����k���ڵ����������k�У���i�м���i���ڵ��������������
��������:
5 6
00#00#
000###
00#000
000000
00#000
 2
 1 2
 1 4
 
���������
 0
 2
 
ʵ�������
 1 2
0
 1 4
2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int board[20][20];
int M,N;

int bang(int x, int y, int kill) {
	if((x>=0 && x<M) && (y>=0 && y<N) && board[x][y]>0) {
		board[x][y] -= kill;
		if(board[x][y]<=0) {
			return 1;
		} else return 0;
	} else return 0;
}

int main() {

//	��ȡ���ӵ�λ��
	scanf("%d%d",&M, &N);
	getchar();
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			board[i][j] = getchar() == '0' ? 0:2;
		}
		getchar();
	}

	int k;
	scanf("%d",&k);
	for(int i=0; i<k; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		int count;
		count = 0;
		count += bang(x,y, 2);
		count += bang(x-1,y,1);
		count += bang(x+1,y,1);
		count += bang(x,y-1,1);
		count += bang(x,y+1,1);
		printf("%d\n", count);
	}

//  ���Դ���
//	for(int i=0; i<M; i++) {
//		for(int j=0; j<N; j++) {
//			printf("%d",board[i][j]);
//		}
//		putchar('\n');
//	}


	return 0;

}
