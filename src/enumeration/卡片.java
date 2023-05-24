package enumeration;

public class 卡片 {
    public static void main(String[] args) {
        int value=0;
        for(int i=0;;i++) {
            String str = i + " ";
            for(int j=0;j<str.length();j++) {
                if(str.charAt(j)=='1') {
                    value++;
                }
            }
            if(value==2021) {
                value = i;
                break;
            }
            if(value>2021) {
                value = i-1;
                break;
            }
        }
        System.out.println(value);
    }
}
