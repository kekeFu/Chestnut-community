/* 7-1高射炮打蚊子
第一行为两个不超过20的正整数M和N，中间空一格，表示二维平面有M行、N列。
接下来M行，每行有N个0或者#字符，其中#表示所在格子有蚊子。
I
接下来一行，包含一个不超过400的正整数k，表示发射炮弹的数量。
最后k行，每行包括—发炮弹的整数坐标x和y (0≤x<M，0≤y<N)，之间用一个空格间隔。
输出格式:
对应输入的k发炮弹，输出共有k行，第i行即第i发炮弹消灭的蚊子数。
输入样例:
5 6
00#00#
000###
00#000
000000
00#000
 2
 1 2
 1 4
 
输出样例：
 0
 2
 
实际输出：
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

//	读取蚊子的位置
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

//  测试代码
//	for(int i=0; i<M; i++) {
//		for(int j=0; j<N; j++) {
//			printf("%d",board[i][j]);
//		}
//		putchar('\n');
//	}


	return 0;

}
