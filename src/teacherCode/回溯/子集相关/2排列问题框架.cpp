#include<stdio.h>
int n=3;
int a[100];//a[i] 记录安排的第i个数 
int tag[100]={0};//tag[i]=1  表示数i出现过了， tag[i]=0表示数i没出现过了 
int check(int i){//这个check方法，程序中没有调用，方便大家理解 
	for(int j=1;j<=i-1;j++)
	  if(a[i]==a[j]) return 0;	  
	return 1;
}
void output(){
	for(int i=1;i<=n;i++)
	  printf("%3d",a[i]);
	printf("\n");  
}
void trackBack2(int i){	//蛮力：回溯，//pailie(1)    1 - i-1个已经排好了，现在排第i个 
	if(i==n+1){
		output();
		return ;
	}	
	for(a[i] = 1;a[i]<=n;a[i]++){
		if(tag[a[i]]==0){//算法的效率 还取决于剪枝函数的效率 
			tag[a[i]]=1;
			trackBack2(i+1);
			tag[a[i]]=0;//回溯		
		}	
   }
	return ; 
}
int main(){
	printf("求1-n的排列，请输入n的值\n"); 
	scanf("%d",&n); 
	trackBack2(1);		
	return 0;
} 
