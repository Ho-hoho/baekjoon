#include <stdio.h>

typedef struct Exp {
	int x;
	int y;
}EXP;

int dx[4] = {0,-1,1,0 }; 
int dy[4] = {-1,0 ,0,1}; 
int n,sh_size = 2,sh_ate = 0 ,time =0;
EXP shark;
int arr[30][30] = { 0 };
int print_arr() {
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= n ; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("time = %d size = %d\n", time, sh_size);
	return 0;
}
int bfs(EXP pos){	
	int front = -1, rear = -1;	
	EXP queue[1500],foundexp[1500];
	int visited[21][21] = { 0 };
	int vis = 1;
	rear++;
	queue[rear] = pos;
	visited[pos.y][pos.x] = 1;
	int foundvis = 10000, foundlen = 0;;
	while (front < rear) {
		front++;
		int idx = front;
		EXP nextExp = queue[front],tmpexp;
		for (int i = 0; i < 4; i++) {
			int newy = nextExp.y + dy[i];
			int newx = nextExp.x + dx[i];
			if (!visited[newy][newx] && arr[newy][newx] >= 0 && arr[newy][newx] <= sh_size) {								
				rear++;
				if (visited[nextExp.y][nextExp.x] + 1 > foundvis) {
					front = rear;
					//printf("BREAK?\n");
					break;
				}
				visited[newy][newx] = visited[nextExp.y][nextExp.x] + 1;
				//printf("queue inserted %d %d vis = %d foundvis= %d\n",newy, newx, visited[newy][newx],foundvis);
				
				queue[rear].y = newy;
				queue[rear].x = newx;
				if (arr[newy][newx] >= 1 && arr[newy][newx] < sh_size) {
					foundvis = visited[newy][newx];
					foundexp[foundlen].y = newy;
					foundexp[foundlen].x = newx;
					foundlen++;
					//printf("found %d %d foundvis = %d\n", newy, newx,foundvis);
				}
			}
		}
	}
	//printf("HERE?\n");
	if (foundlen) {
		EXP minexp = foundexp[0];
		//printf("1 :minexp = %d %d\n", minexp.y, minexp.x);
		for (int i = 0; i < foundlen; i++) {
			if (foundexp[i].y == minexp.y) {
				if (foundexp[i].x < minexp.x) {
					minexp = foundexp[i];
					//printf(" 2: minexp = %d %d\n", minexp.y, minexp.x);
				}
			}
			else if (foundexp[i].y < minexp.y) {
				minexp = foundexp[i];
				//printf("3 : minexp = %d %d\n", minexp.y, minexp.x);
			}
		}
		arr[shark.y][shark.x] = 0;
		shark.y = minexp.y; shark.x = minexp.x;
		time += visited[minexp.y][minexp.x] - 1;
		arr[shark.y][shark.x] = 9;
	}
	return 0;
}
int find() {
	while (1) {
		//printf("\n\n");
		//print_arr();
		EXP tmp = shark;
		bfs(shark);
		//printf("FIN?\n");
		if (tmp.y == shark.y && tmp.x == shark.x) {
			//printf("BREAK?\n");
			break;
		}
		else {
			sh_ate++;
			if (sh_ate == sh_size) {
				sh_size++;
				sh_ate = 0;
			}
		}
		
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 9) {
				shark.y = i;
				shark.x = j;
			}				
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		arr[i][0] = -1;
		arr[0][i] = -1;
		arr[i][n+1] = -1;
		arr[n+1][i] = -1;
	}
	find();
	printf("%d\n", time);
}
