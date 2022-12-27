import java.util.*;

public class Main {
    static int N,ans,temp;
    static PriorityQueue<Integer> pq;
    static public void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        ans = 0;
        pq = new PriorityQueue<Integer>();
        for(int i = 0 ; i < N ;i++)
            pq.add(sc.nextInt());

        while(pq.size() > 1){
            temp = pq.poll() + pq.poll();
            pq.add(temp);
            ans += temp;
        }
        System.out.println(ans);
    }
}
