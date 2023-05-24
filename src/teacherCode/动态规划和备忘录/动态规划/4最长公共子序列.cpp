//dp(i,j)=0;                                           i=0或j=0
//dp(i,j)=dp(i-1,j-1)+1                          X[i-1]==Y[j-1]
//dp(i,j)=max(dp(i-1,j), dp(i,j-1))      X[i-1]!=Y[j-1]
#include<stdio.h>
const int n=7;//行=n+1 
const int m=6;//列=m+1 
char X[n+1]="ABCBDAB";
char Y[m+1]="BDCABA";
int dp[n+1][m+1] ;  // dp[7][6] 
void solvedp(){
	for(int i=0;i<m+1;i++)
	  dp[0][i]=0;
	for(int i=0;i<n+1;i++)
	  dp[i][0]=0;  
    for(int i=1;i<n+1;i++)
	   for(int j=1;j<m+1;j++){
	   	  if(X[i-1] == Y[j-1]) dp[i][j]=dp[i-1][j-1]+1;
		  else {
		  	   int m= dp[i-1][j]>=dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
		  	   dp[i][j]=m;
		  }	
	   } 
	        
}
void output(){
	printf("%4c",' ');
	for(int j=0;j<m;j++){
	   	  printf("%2c",Y[j]);
	} printf("\n"); 
    for(int i=0;i<n+1;i++){
	   if(i==0) printf("%2c",' ');
       if(i>0) printf("%2c",X[i-1]);
	   for(int j=0;j<m+1;j++){
	   	  printf("%2d",dp[i][j]);
	   }	
	   printf("\n"); 
	}        
}
void LCS(int i,int j){
	if(dp[i][j]==0) return;	
	if(X[i-1]==Y[j-1]){		
		LCS(i-1,j-1);
		printf("%c",X[i-1]);
	}else{
		if(dp[i][j]==dp[i-1][j]){
			LCS(i-1,j);
		}
		else{
			LCS(i,j-1);
		}
	
	}
}
void LCSreverse(){
    int i=n,j=m;
	while(dp[i][j]!=0){		
		if(X[i-1]==Y[j-1]){		
				printf("%c",X[i-1]);
				i = i-1;j = j-1;
		
		}else{
			if(dp[i][j]==dp[i-1][j]){
				i = i-1;
				//j = j;
			}
			else{
				//i = i-1;
				j = j-1;
			}
		
		}
	}
}
int main(){
	solvedp();
	output();
	printf("%d\n",dp[7][6]) ;
	LCS(7,6); 
	printf("\n\n") ;
	printf("\n公共子序列的逆序:") ;
	LCSreverse();
}

