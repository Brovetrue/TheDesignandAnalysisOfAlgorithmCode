package enumeration;

public class 阶乘求和 {
    static long result = 0;
    static long sum=0;
    public static long f(long n){

        if(n==1){
            return 1;
        }else {
            result = f(n-1) * n;
            return result;
        }
    }

    public static long add(long n){

        for(int i=1;i<=n;i++){
            sum = sum+f(i);
        }
        return sum;
    }

    public static void main(String[] args) {
        long n = 2023;
        long s = add(n);
        System.out.println(s);
    }
}
