import java.util.*;

public class Main {
	static int[][] arr; 
	static int[][] temp ;
	static int[][] temp2;
	static int[] dx = {1,-1,0,0};
	static int[] dy = {0,0,1,-1};
	static int n,m,tick;
	static boolean flag;
	
	public static void main(String[] args){     
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		arr = new int[110][110];
		
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		
		while(true) {
			temp = new int[110][110];
			flag = false;
			fill_air(0,0);
			if(flag == false) break;
			tick++;
			temp2 = new int[110][110];
			melt();
		}
		System.out.println(tick);
	}
	
	static void fill_air(int x,int y) {
		if(arr[x][y] == 1) {flag = true ; return;}
		
		temp[x][y] = 2;
		
		for(int i=0;i<4;i++) {
			if (x + dx[i] >= 0 && x + dx[i] <= n + 1 && y + dy[i] >= 0 && y + dy[i] <= n + 1 && temp[x+dx[i]][y+dy[i]] == 0)
				fill_air(x + dx[i], y + dy[i]);
		}
		
	}
	
	static void melt() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 0; k < 4; k++) {
					if (temp[i+dx[k]][j+dy[k]] == 2) {
						temp2[i][j]++;
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (temp2[i][j] >= 2)
					arr[i][j] = 0;
			}
		}
	}
}
