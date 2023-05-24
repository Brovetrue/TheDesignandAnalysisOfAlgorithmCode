#include<stdio.h>
int board[100][100];
void init(int n){
	for(int i=1;i<=n;i++){
		board[i][1]=i;
	}
}
void output(int n){
	int i,j;
	for(i=1;i<=n;i++){	
	  for(j=1;j<=n;j++)
	      printf
		  ("%2d",board[i][j]);
	  printf("\n");
	}      
}
void copy(int r1,int c1,int r2,int c2,int s){
	int i1,j1,i2,j2;
	for(i1=r1,i2=r2;i1<r1+s;i1++,i2++)
	  for(j1=c1,j2=c2;j1<c1+s;j1++,j2++)
	      board[i2][j2]=board[i1][j1];
}
void anpai(int tr,int tc,int n){
	if(n==1) return;	
	anpai(tr,tc,n/2);
	anpai(tr+n/2,tc,n/2);
	copy(tr,tc,tr+n/2,tc+n/2,n/2);
	copy(tr+n/2,tc,tr,tc+n/2,n/2);
}
int main(){
	int n = 4;
	init(8);
	anpai(1,1,n);
	output(n);
}
	
