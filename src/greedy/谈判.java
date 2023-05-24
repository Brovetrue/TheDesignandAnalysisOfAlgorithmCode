package greedy;

import java.util.Arrays;
import java.util.Scanner;

public class 谈判 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int []arr=new int[n];
        for (int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        long sum=0;
        for (int i=0;i<n-1;i++){
            sum+=arr[i]+arr[i+1];
            arr[i+1]+=arr[i];//产生的新部落的人数
            arr[i]=0;//旧部落人数归零
            Arrays.sort(arr);//选完以后重新排序
        }
        System.out.println(sum);
    }
}
