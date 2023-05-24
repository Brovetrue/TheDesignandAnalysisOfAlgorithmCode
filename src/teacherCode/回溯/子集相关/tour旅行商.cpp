#include<stdio.h>
int n=8;//
int adj[N][N];//存图 
int a[100] = {0,2};// 
void output(){
	for(int i=1;i<=n;i++)
	  printf("%3d",a[i]);
	printf("\n");  
}
int count=0; 
int  check(int i){
     //1  a[i] 对应的顶点是否出现过，  
	 //2   a[i]  a[i-1] 之间是否有边 
}
void trackBackQueue(int i){	//蛮力：回溯，//pailie(1)    1 - i-1个已经排好了，现在排第i个 
	if(i==n+1){
		//求当前这条回路的长度，看是否是目前的最短路 
		return ;
	}	
	for(a[i] = 1;a[i]<=n;a[i]++){	
	    if(check(i)){	
		    //剪枝函数:		
			trackBackQueue(i+1)	;
		}	
    }
	return ; 
}
int main(){
	trackBackQueue(2);	
	printf("%d",count);	
	return 0;
} 
