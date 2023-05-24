
#include<stdio.h>
const int inf = 999999999;
const int N = 6;
int p[N+1]={30,35,15,5,10,20,25};
int dp[N+1][N+1];
//m[i][j]表示Ai*...*Aj 需要的最少数乘次数 
//m[i][j]  = min(m[i][k]+m[k+1][j]+pi-1*pk*pj  |  k=i,....,j-1)
//                   k就是将 Ai*..................*Aj
//                  //  分成 Ai*...*Ak      Ak+1*...*Aj 

 
int mink[N+1][N+1];
//mink[i][j] 记录上面的哪个k使得Ai*...*Aj数乘次数达到的最少

void output(int a[][N+1]){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
		   printf("%6d",a[i][j]) ;
	     printf("\n") ;	   
	}
}
void solveM(){
	for(int i=1;i<=N;i++)
	   dp[i][i] = 0;
	for(int i=1;i<=N-1;i++){	
	   dp[i][i+1] = p[i-1]*p[i]*p[i+1];
	   mink[i][i+1]=i;//上课没加这里 
	}
    for(int L = 2;L<=N-1;L++){
    	for(int i=1;i<=N-L;i++){
    		int j = i+L;
    		//m[i][j]=?
    		int min=inf;
    		int mk=-1;
    		for(int k=i;k<j;k++){
    			int f= dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
    			if(min>f) {
				   min =f;
				   mk=k;
				}
			}
			dp[i][j]=min; 
			mink[i][j] =mk;		
		}
	}
	   
	
}
void trackPath(int i,int j){
	if(i==j){
		printf("A%d",i);
		return ;
	}
	
	int k =mink[i][j];
	if(i!=k)printf("(");	
	trackPath(i,k) ; 
	if(i!=k)printf(")"); 
	printf("*");
	if(k+1!=j)printf("(");
	trackPath(k+1,j);
	if(k+1!=j)printf(")"); 
}

//A1*A2*A3*A4*A5*A6 

//(A1*A2*A3)*(A4*A5*A6) 
//(A1*(A2*A3))*((A4*A5)*A6) 
int main(){
	solveM();
	printf("%d\n",dp[1][6]);
	output(mink);
	printf("\n");
    output(dp);
	printf("\n");
	trackPath(1,6);//大家完成 
	
}
    
