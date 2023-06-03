package recursion;


import java.util.Scanner;

public class 快速排序 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        quickSort(a,0,n-1);
        for (int i = 0;i<n;i++){
            System.out.print(a[i]);
            System.out.printf("");
        }
    }
    public  static void quickSort(int arr[],int left,int right){
        int i=left,j=right,temp;
        if(left<right){
            temp = arr[i];
            while(i!=j){
                while(j>i&&arr[j]>=temp) j--;
                arr[i]=arr[j];
                while(j>i&&arr[i]<=temp) i++;
                arr[j]=arr[i];
            }
            arr[i] = temp;

            quickSort(arr,left,i-1);
            quickSort(arr,i+1,right);
        }

    }
}
