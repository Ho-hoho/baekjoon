package test;
import java.util.*;

class Pair{
	private int first;
	private int second;
	public Pair(int f,int s) {
		this.first = f;
		this.second = s;
	}
	
	public int first() {
		return this.first;
	}
	public int second() {
		return this.second;
	}
	public void setFirst(int f) {
		this.first = f;
	}
	public void setSecond(int s) {
		this.second = s;
	}
}

public class Main {
	static int n,a,b,c;
	static ArrayList<Pair>[] arr = new ArrayList[100001]; 
	static Pair ans = new Pair(0,0);
	static boolean[] vis = new boolean[100001];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		for(int i=0;i<=n;i++) arr[i] = new ArrayList<Pair>();
		for(int i=1;i<=n;i++) {
			a = sc.nextInt();
			while(true) {
				b = sc.nextInt();
				if(b != -1) c = sc.nextInt();
				else break;
				arr[a].add(new Pair(b,c));
			}
		}
		dfs(1,0);
		ans.setSecond(0);
		dfs(ans.first(),0);
		System.out.println(ans.second());
		
	}
	
	public static void dfs(int node, int len) {
		vis[node] = true;
		for (Pair e : arr[node]) {
			if (!vis[e.first()]) {
				if (len + e.second() > ans.second()) {
					ans.setFirst(e.first());
					ans.setSecond(len + e.second());
				}
				dfs(e.first(), len + e.second());
			}
		}
		vis[node] = false;
		return;
	}
		
}
