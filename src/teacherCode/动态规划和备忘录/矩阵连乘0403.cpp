#include<stdio.h>
//这个是四个字节最大的正整数 
const int inf = 0x7fffffff;
//0111 1111 1111 1111 1111 1111 1111 1111 
const int N =4;



int p[N+1]={30,35,15,5,10};
int dp[N+1][N+1];
int mk[N+1][N+1];
void solvedp(){
	for(int i=1;i<=N;i++)
	   dp[i][i] = 0;
	for(int i=1;i<=N-1;i++) {
	 
	   dp[i][i+1] = p[i-1]*p[i]*p[i+1];
	   mk[i][i+1] = i;
	   
	} 
    for(int num =3;num<=N;num++){
	    //代表Ai*...*Aj中一共多少个矩阵 
    	for(int i =1;i<=N-num+1;i++){
    		//num个矩阵相乘的情况
			//一共有N-num+1种 (即有这么多行要求)
    		int j = i+num-1;
    		//行号和列号相差是num-1 
			int min=inf;//?
			int mink=-1;
    	    for(int k=i;k<=j-1;k++){			
    		   int d =dp[i][k] + dp[k+1][j]+ 
			          p[i-1]*p[k]*p[j];
			    if(d<min) {
				   min =d;
				   mink= k;
				}
    		}    		
			dp[i][j]=min;
			mk[i][j]=mink;
    		
		}
	}
}
void output(int a[][N+1]){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
		    printf("%6d",a[i][j]);
		printf("\n");
	}
}
void trackp(int i,int j){
     if(i==j){
     	 printf("A%d",i);return ; 
	 }	 
     int k = mk[i][j];
     if(i!=k)printf("(");
     trackp(i,k);
     if(i!=k)printf(")");
     
     if(k+1!=j)printf("(");
     trackp(k+1,j);
	 if(k+1!=j)printf(")");
}
int main(){
	solvedp();
	printf("%d\n",dp[1][6]);
	//最优的计算顺序是什么？
	output(dp);
	printf("\n");
	output(mk);
	trackp(1,6);
	 
} 
