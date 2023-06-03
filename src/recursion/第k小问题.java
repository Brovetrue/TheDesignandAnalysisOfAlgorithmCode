package recursion;

import java.util.Scanner;

public class 第k小问题 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m, k;
        m = sc.nextInt();
        k = sc.nextInt();
        int arr[] = new int[m];
        QuickSelect(arr, 0, m - 1, k);
    }

    public static int QuickSelect(int[] arr, int left, int right, int k) {
        int i = left, j = right, temp;
        if (left < right) {
            temp = arr[i];
            while (i != j) {
                while (j > i && arr[j] >= temp) j--;
                arr[i] = arr[j];
                while (j > i && arr[i] <= temp) i++;
                arr[j] = arr[i];
            }
            arr[i] = temp;
            if (k - 1 == i) return arr[i];
            else if (k - 1 < i) return QuickSelect(arr, left, i - 1, k);
            else return QuickSelect(arr, i + 1, right, k);
        } else if (left == right && left == k - 1) {
            return arr[k - 1];
        }
        return 0;
    }
}



