package backtracking;

import java.util.Scanner;

public class 全排列字典序_swap法 {
    public static void perm(int arr[],int p,int q){
        if(p==q){
            printArray(arr);
        }

        for(int i=p;i<=q;i++){
            swap(arr,p,i);
            perm(arr, p+1, q);
            swapback(arr,p,i);
        }
    }

    public static void swapback(int[] arr, int p, int i) {
        int temp = arr[p];
        for (int k=p;k<=i-1;k++){
            arr[k] = arr[k+1];
        }
        arr[i]=temp;
    }

    public static void swap(int[] arr, int p, int i) {
        int temp = arr[i];
        for (int k=i;k>=p+1;k--){
            arr[k]=arr[k-1];
        }
        arr[p] = temp;
    }

    public static void printArray(int[] arr) {
        for (int j=0;j<arr.length;j++){
            System.out.print(arr[j]+" ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=0;
        n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        perm(arr,0,n-1);
    }
}
