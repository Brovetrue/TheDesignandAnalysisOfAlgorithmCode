#include<stdio.h>
int n=8;//4皇后问题 
int a[100];//a[i] 记录安排的第i个皇后放在第i行的a[i]中 
void output(){
	for(int i=1;i<=n;i++)
	  printf("%3d",a[i]);
	printf("\n");  
}
int count=0; 
int  check(int i){
 //测试第i个皇后的位置（i,a[i]） 和
 //前面的i-1个皇后的位置 （1,a[1]） ....... （i-1,a[i-1]）是否冲突了 
 //不同列，不同主对角，不同副对角 
    for(int j=1;j<=i-1;j++){
    	// （i,a[i]）  （j,a[j]） 
    	if(a[i]==a[j]||i-a[i]==j-a[j]|| i+a[i]==j+a[j])return 0;
    	
	} 
	return 1;
}
void trackBackQueue(int i){	//蛮力：回溯，//pailie(1)    1 - i-1个已经排好了，现在排第i个 
	if(i==n+1){
		count++;
		return ;
	}	
	for(a[i] = 1;a[i]<=n;a[i]++){	
	    if(check(i)){	
		    //剪枝函数:约束条件	,百度下（标记法）		
			trackBackQueue(i+1)	;
		}	
    }
	return ; 
}
int main(){
	trackBackQueue(1);	
	printf("%d",count);	
	return 0;
} 
