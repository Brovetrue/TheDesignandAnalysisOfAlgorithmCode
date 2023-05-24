package teacherCode.递归和带备忘的递归;

public class Mainfeibo {
    static int [] memory=new int[100];
    static int count1=0;//��¼f1�����õĴ���
    static int count2=0;//��¼f2�����õĴ���
	public static void main(String[] args) {
		  int n =5;
		  f(5);
		  f1(8);
		  f2(8);
          System.out.println(count1);
          System.out.println(count2);
	}
	static int f(int n){
		int []a =new int [n];
		a[0]=1;a[1]=1;
		for(int i=2;i<n;i++)//T(n)=O(n)
			a[i] = a[i-1]+a[i-2];
	    return a[n-1];
	}
	static int f2(int n){//T(n)=O(n)
		count2++;
		if(memory[n]!=0){
			return memory[n];//�����ظ�����
		}
		if(n==1 || n==2) return 1;
		return memory[n]=f2(n-1)+f2(n-2);
	}
	static int f1(int n){//T(n)=O(2^n)	
		count1++;
		if(n==1 || n==2) return 1;
		return f1(n-1)+f1(n-2);
	}
}
