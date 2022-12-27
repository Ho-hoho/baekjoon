import java.util.*;

public class Main {
    static int N,M;
    static int[][] mat;
    static int[] city;
    static boolean ans = true;
    static public void main(String[] args){
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        mat = new int[N+1][N+1];
        city = new int[M];
        for(int i = 1 ; i <= N ;i ++){
            for(int j = 1 ; j <= N ;j++) {
                mat[i][j] = sc.nextInt();
            }
            mat[i][i] = 1;
        }
        for(int i = 0 ; i < M ; i++){
            city[i] = sc.nextInt();
        }

        for(int k = 1 ; k <= N ;k++){
            for(int i = 1 ; i <= N ; i++){
                for(int j = 1 ; j <= N ;j++){
                    if(mat[i][j] == 0){
                        if(mat[i][k] == 1 && mat[k][j] == 1)
                            mat[i][j] = 1;
                    }
                }
            }
        }

        for(int i = 0 ; i < M - 1 ; i++) {
            if (mat[city[i]][city[i + 1]] != 1) {
                ans = false;
                break;
            }
        }
        if(ans)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
