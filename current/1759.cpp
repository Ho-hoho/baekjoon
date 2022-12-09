import java.util.*;
public class Main {
    static int L,C;
    static String[] arr;
    static boolean[] vis;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        L = sc.nextInt();
        C = sc.nextInt();
        arr = new String[C];
        vis = new boolean[C];
        for(int i = 0 ; i < C ; i++) {
            arr[i] = sc.next();
        }
        Arrays.sort(arr);
        dfs(0,0,0);
    }
    static void dfs(int cur,int v, int c){
        if(cur == C || v + c == L){
            if(v + c == L && v >=1 && c>=2){
                for(int i = 0 ; i < C ; i++){
                    if(vis[i])
                        System.out.print(arr[i]);
                }
                System.out.println();
            }
            return ;
        }
        vis[cur] = true;
        if(arr[cur].equals("a") || arr[cur].equals("e") || arr[cur].equals("i") || arr[cur].equals("o") || arr[cur].equals("u"))
            dfs(cur+1,v + 1,c);
        else
            dfs(cur+1,v,c+1);
        vis[cur] = false;
        dfs(cur + 1,v,c);
    }
}
