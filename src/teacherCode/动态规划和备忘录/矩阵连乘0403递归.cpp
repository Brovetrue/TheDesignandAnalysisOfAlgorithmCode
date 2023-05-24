#include<stdio.h>
//这个是四个字节最大的正整数 
const int inf = 0x7fffffff;
//0111 1111 1111 1111 1111 1111 1111 1111 
const int N =4;



int p[N+1]={30,35,15,5,10};

int mk[N+1][N+1];

int dp(int i,int j){
	if(i==j) return 0;
	if(i+1==j) return p[i-1]*p[i]*p[j];
	
	int min=inf;
	for(int k=i;k<=j-1;k++){
		int d1 = dp(i,k);
		int d2 = dp(k+1,j);
		int s = d1+d2+p[i-1]*p[k]*p[j];
		if(s<min) min =s;
	}
	return min;
	
	
	
}
int main(){
	solvedp();
	printf("%d\n",dp(1,6));
	//最优的计算顺序是什么？
	
	 
} 
