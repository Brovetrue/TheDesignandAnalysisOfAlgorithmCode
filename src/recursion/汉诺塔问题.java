package recursion;

import java.util.Scanner;

public class 汉诺塔问题 {
    static int count;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        hanoi(num, 'A', 'C', 'B');//起始柱、辅助柱、目标柱默认为A、B、C
        System.out.println(count);
    }

    public static void hanoi(int n,char source,char target,char auxiliary){
        if (n==1){
            count++;
            System.out.println(source+"-->"+target);
        }else {
            hanoi(n-1,source,auxiliary,target);//将n-1个从source移动到target
            System.out.println(source+"-->"+target);
            count++;
            hanoi(n-1,auxiliary,target,source);//剩下的n-1个从auxilary移动到target
        }
    }
}
