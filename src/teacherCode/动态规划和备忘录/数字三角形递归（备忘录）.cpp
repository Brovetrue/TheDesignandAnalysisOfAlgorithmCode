#include<stdio.h>
const int N = 64;
int n = 4;
/*
9
12  15
10  6   8
2   18  9   5
*/ 
int data[N+1][N+1];
void input(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
		   scanf("%d",&data[i][j]);
	}
}
int memory[N+1][N+1];//
int dp(int i,int j){
	if(memory[i][j]!=0) return memory[i][j];
    //dp(1,1) 
	if(i==n) return memory[n][j]=data[n][j];
	
	int d1 =dp(i+1,j);
	int d2 =dp(i+1,j+1);
	int m = d1>=d2?d1:d2;
	return memory[i][j]=data[i][j] +m;
	
}
void path(int i,int j){	
	printf("%3d",data[i][j]);
	if(i==n) return ;	
	if(memory[i+1][j]>=memory[i+1][j+1])
		path (i+1,j);
	else 
	    path(i+1,j+1);
	
	
}
int main(){
	input();//data‘ÿ»Î 
	
	printf("%d\n",dp(1,1));
	printf("path:");
	path(1,1);
	
	
}
