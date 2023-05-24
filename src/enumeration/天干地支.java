package enumeration;

import java.util.Scanner;

public class 天干地支 {
    public static void main(String[] args){
        //获取输入
        Scanner sc = new Scanner(System.in);
        int year = sc.nextInt();

        //声明一个数组，分别存储天干和地支的值
        String[] tianGan = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
        String[] diZhi = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};

        //因其天干地支可看作60年循环一次
        //对年份进行除余操作，方便后续计算
        year = year % 60;
        //天干10年循环一次
        int tian = year % 10;
        //地支12年循环一次
        int di = year % 12;

        //因公元纪年法从 1 开始，因此公元元年的天干地支：xinyou
        //在天干[7]地支[9]的下标都要-1，以进行匹配
        System.out.println(tianGan[((6+tian)%10)]+diZhi[((8+di)%12)]);
    }


}
