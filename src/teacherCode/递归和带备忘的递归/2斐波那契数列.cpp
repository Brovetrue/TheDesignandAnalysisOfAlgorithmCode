#include<stdio.h>
int f1(int n){
	int a[100]={1,1};//s(n) = 这个空间可以动态分配 
	for(int i =2;i<n;i++)
	  a[i]=a[i-1]+a[i-2];
	return a[n-1];
}
int count1 =0; //记录递归函数f2的调用次数
int f2(int n){
//大量的重复计算 
//T(n)=O(2^n)   S(n) =O(n)
    count1++;
	if(n==1||n==2) return 1;
	return f2(n-1)+f2(n-2);
}
int count2=0;//记录递归函数f3的调用次数 
//带备忘的递归，备忘录 ，空间换时间 
int memory[100] ; //1 :记录数组 
int f3(int n){
//T(n)=O(n)   S(n) =O(n)
	count2++;
	if(memory[n]!=0) // 3 判断是否算过 
	   return memory[n]; //  4使用使用 
	if(n==1||n==2) return 1;
	return memory[n]=f3(n-1)+f3(n-2);//2 记 
}
int main(){
	printf("f5=%d\n",f1(5));
	printf("f5=%d\n",f2(5));
	printf("%d\n",count1);
	printf("f5=%d\n",f3(5));
	printf("%d\n",count2);
	return 0;
} 
