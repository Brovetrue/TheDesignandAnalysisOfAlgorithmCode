package recursion;

import java.util.Scanner;

public class 全排列字典序_check法 {
    static int []a=new int[10];
    static int n;
    static int tag=0;
    static  StringBuffer re=new StringBuffer();
    static void output(int n){
        if(tag!=0)re.append("\n");
        for(int i=1;i<=n;i++)
            re.append(a[i] +" ");
        tag =1;
    }
    static int check(int i){
        for(int j=1;j<=i-1;j++){
            if(a[i]==a[j])  return 0;
        }
        return 1;
    }
    static void pailie(int i){//前面已经排了i-1个，现在排第i个
        if(i==n+1){
            output(n);
            return ;
        }
        for(a[i]=1;a[i]<=n;a[i]++){
            if(check(i)==1){
                pailie(i+1);
            }
        }
    }
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        pailie(1) ;//不是交换法
        System.out.print(re);

    }
}
