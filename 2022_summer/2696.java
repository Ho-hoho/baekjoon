import java.util.*;

public class Main {
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        Integer tc;
        tc = sc.nextInt();
        while(true){
            if(tc-- == 0) break;
            PriorityQueue<Integer> lpq = new PriorityQueue<>(Collections.reverseOrder());
            PriorityQueue<Integer> rpq = new PriorityQueue<>();
            ArrayList<Integer> mid = new ArrayList<>();
            Integer n,a,b,pivot;
            n = sc.nextInt();
            pivot = sc.nextInt();
            mid.add(pivot);

            for(int i=2;i<=n;i+=2){
                a = sc.nextInt();
                b = sc.nextInt();

                if(a >=pivot) rpq.add(a);
                else lpq.add(a);

                if(b >= pivot) rpq.add(b);
                else lpq.add(b);

                if(lpq.size() != rpq.size()){
                    if(lpq.size() > rpq.size()){
                        rpq.add(pivot);
                        pivot = lpq.poll();
                    }
                    else{
                        lpq.add(pivot);
                        pivot = rpq.poll();
                    }
                }
                mid.add(pivot);
            }
            System.out.println(mid.size());
            for (int i = 0; i < mid.size(); i++) {
                System.out.print(mid.get(i) + " ");
                if (i % 10 == 9 ) System.out.println();
            }
            System.out.println();
        }
    }
}
