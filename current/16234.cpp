import java.util.*;
public class Main {
    static int[][] mat;
    static boolean[][] vis;
    static int[][] team;
    static int[][] dp;
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,-1,1};
    static int N,L,R;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();
        R = sc.nextInt();
        mat = new int[N][N];

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N; j++){
                mat[i][j] = sc.nextInt();
            }
        }
        int date = 0,idx;
        while(true){
            vis = new boolean[N][N];
            team = new int[N][N];
            idx = 1;
            for(int i = 0 ; i < N ;i++){
                for(int j = 0 ; j < N ;j++){
                    if(!vis[i][j])
                        dfs(i,j,idx++);
                }
            }
            if(idx == N * N + 1) break;
            dp = new int[N*N][2];
            for(int i = 0 ; i < N; i++){
                for(int j = 0; j < N ; j++){
                    dp[team[i][j]][0]+= mat[i][j];
                    dp[team[i][j]][1]++;
                }
            }
            for(int i = 0 ; i < N; i++){
                for(int j = 0; j < N ; j++){
                    mat[i][j] = dp[team[i][j]][0] / dp[team[i][j]][1];
                }
            }
            date++;
        }
        System.out.println(date);
    }

    static void dfs(int x, int y,int idx){
        team[x][y] = idx;
        vis[x][y] = true;
        for(int k = 0 ; k < 4 ;k++){
            if(x + dx[k] >= 0 && x + dx[k] < N && y + dy[k] >= 0 && y + dy[k] < N) {
                if (!vis[x + dx[k]][y + dy[k]]) {
                    int val = Math.abs(mat[x][y] - mat[x + dx[k]][y + dy[k]]);
                    if ( val >= L && val <= R)
                        dfs(x + dx[k], y + dy[k], idx);
                }
            }
        }
        return;
    }
}
