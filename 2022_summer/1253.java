//package test;
import java.util.*;

public class Main{
	static int[] arr;
	static int N,cnt=0;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		arr = new int[N];
		for(int i = 0 ; i< N;i++) {
			arr[i] = sc.nextInt();
		}
		
		Arrays.sort(arr);
		
		for (int i = 0; i < N; i++) {
			int s = 0;
			int e = N - 1;
			while (s != e) {
				if (s == i) s++;
				else if (e == i) e--;
				else {
					int temp = arr[s] + arr[e];
					if (temp == arr[i]) {
						cnt++;
						break;
					}
					else if (temp > arr[i]) e--;
					else s++;
				}
			}

		}
		System.out.println(cnt);
	}
}
