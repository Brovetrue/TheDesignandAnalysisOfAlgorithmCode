#include<stdio.h>
int N = 8;
int board[65][65];
void init(int n){
	for(int i=1;i<=n;i++){
		board[i][1] = i;
	}
}
void copy(int r1,int c1,int r2,int c2,int s){
//	int i,i2;
//	int j,j2;
//	for(i=r1,i2=r2;i<r1+s;i++,i2++)
//	  for(j=c1,j2=c2;j<c1+s;j++,j2++)
//	     board[i2][j2] =board[i][j];
	int i;
	int j;
	for(i=r1;i<r1+s;i++)
	  for(j=c1;j<c1+s;j++)
	     board[i+(r2-r1)][j+(c2-c1)] =board[i][j];
}
void anpai(int tr,int tc,int n){//每一块到左上格位置tr,tc,大小n 
    if(n==1) return ;   
     anpai(tr,tc, n/2);
     anpai(tr+n/2,tc, n/2);
     copy(tr,tc,tr+n/2,tc+n/2,n/2);
	 //把[tr,tc]为左上格大小为n/2的子块到数据 
	 //copy到
	 //[tr+n/2,tc+n/2]为左上格大小为n/2的子块 
     copy(tr+n/2,tc,tr,tc+n/2,n/2);
}
void output(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%2d",board[i][j]);
		}
		printf("\n");
	}
} 
int main(){
	init(N);
	anpai(1,1,N);
	output(N);
	
}


