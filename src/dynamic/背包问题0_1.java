package dynamic;

import java.util.Scanner;

public class 背包问题0_1 {
    static int n=0,c;

    //0-1背包问题
    static void solvedp(int w[],int v[],int dp[][]){
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for (int j=1;j<=c;j++){
                if(w[i]>j) dp[i][j] = dp[i-1][j];
                else dp[i][j]=dp[i-1][j]>=dp[i-1][j-w[i]]+v[i]?dp[i-1][j]:dp[i-1][j-w[i]]+v[i];
                       //         不选               选
            }
        }
    }
    static void trackPath(int i,int j,int dp[][],int w[]){
        if(dp[i][j] == 0) return;

        if(dp[i][j]==dp[i-1][j]){
            //printf("物品%d不选\n",i);
            trackPath(i-1,j,dp,w);
        }else{
            //sout 放前面输出的顺寻会不一样
            trackPath(i-1,j-w[i],dp,w);
            System.out.printf(String.valueOf(i)+" ");
        }

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String [] values = line.split(" ");
        n = Integer.parseInt(values[0]);
        c = Integer.parseInt(values[1]);
        int w[] = new int[n+1];
        int v[] = new int[n+1];
        int dp[][] = new int[n+1][c+1];
        dp[n][c] = -1;
        for (int i = 1; i < n+1; i++) {
            line = sc.nextLine();
            values = line.split(" ");
            w[i] = Integer.parseInt(values[0]);
            v[i] = Integer.parseInt(values[1]);
        }
        for (int j=0;j<w.length;j++){
            System.out.print(w[j]);
        }
        System.out.println();
        System.out.println();
        for (int j=0;j<w.length;j++){
            System.out.print(v[j]);
        }
        System.out.println();
        System.out.println();
        solvedp(w,v,dp);
        for(int i=0;i<n+1;i++) {
            for (int j = 0;j<=c; j++) {
                System.out.printf(String.valueOf(dp[i][j]));
            }
            System.out.println();
        }
        trackPath(n,c,dp,w);
        if(dp[n][c]==0){
            System.out.print("No");
        }
        System.out.print("\n"+dp[n][c]);
    }


}
