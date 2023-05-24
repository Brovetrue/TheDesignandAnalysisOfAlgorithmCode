package recursion;

import java.util.Scanner;

public class 第k小问题 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m,k;
        m = sc.nextInt();
        k = sc.nextInt();
        int arr [] = new int[m];
        QuickSelect(arr,0,m-1,k);
    }

    public static void QuickSelect(int[] arr, int left, int right, int k) {
          int i=left,j=right,temp;


    }


}
