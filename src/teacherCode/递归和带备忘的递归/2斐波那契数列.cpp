#include<stdio.h>
int f1(int n){
	int a[100]={1,1};//s(n) = ����ռ���Զ�̬���� 
	for(int i =2;i<n;i++)
	  a[i]=a[i-1]+a[i-2];
	return a[n-1];
}
int count1 =0; //��¼�ݹ麯��f2�ĵ��ô���
int f2(int n){
//�������ظ����� 
//T(n)=O(2^n)   S(n) =O(n)
    count1++;
	if(n==1||n==2) return 1;
	return f2(n-1)+f2(n-2);
}
int count2=0;//��¼�ݹ麯��f3�ĵ��ô��� 
//�������ĵݹ飬����¼ ���ռ任ʱ�� 
int memory[100] ; //1 :��¼���� 
int f3(int n){
//T(n)=O(n)   S(n) =O(n)
	count2++;
	if(memory[n]!=0) // 3 �ж��Ƿ���� 
	   return memory[n]; //  4ʹ��ʹ�� 
	if(n==1||n==2) return 1;
	return memory[n]=f3(n-1)+f3(n-2);//2 �� 
}
int main(){
	printf("f5=%d\n",f1(5));
	printf("f5=%d\n",f2(5));
	printf("%d\n",count1);
	printf("f5=%d\n",f3(5));
	printf("%d\n",count2);
	return 0;
} 
