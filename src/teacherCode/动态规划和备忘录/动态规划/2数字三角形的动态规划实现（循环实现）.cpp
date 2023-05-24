#include<stdio.h>               
const int n=5; 
int data[n+1][n+1]={{0},
                    {0,9},
					{0,12,15},
					{0,10,6,8},
                    {0,2,18,9,5},
					{0,19,7,10,4,16}};
                  //��¼ԭʼ���� 
int dp[n+1][n+1];//��¼���ŵĽ�� 
//                dp[i][j]��¼��data[][]�ߵ���ײ�����·������ 


int solvedp(){
  for(int i=1;i<=n;i++)
     dp[n][i]=data[n][i];//���²��dpֵ
	  
  for(int i=n-1;i>=1;i--){//�ӵ�����2�㵽��1�㣬����������dp[i][j] 
  	  for(int j=1;j<=i;j++){
  	  	  int m = dp[i+1][j]>=dp[i+1][j+1]?dp[i+1][j]:dp[i+1][j+1];
  		  dp[i][j] = data[i][j]+m;
	  }
	  
  }
  
}
void output(){  
  for(int i=1;i<=n;i++){      
      for(int j=1;j<=i;j++)
         printf("%3d",dp[i][j]);
      printf("\n");   
  }
}
void trackPath(){
	int i=1,j=1;
	do{	
	    printf("%d  ",data[i][j]);
	    if(i == n) break;
	    if(dp[i][j]==dp[i+1][j]+data[i][j]){
	        i=i+1;j=j;        
	    }
	    else {
	      i=i+1;j=j+1;       
	    }    
	}while(1)  ;
}
int main(){  
   solvedp();
   output();
   printf("���·���ĺ�ֵ��%d\n",dp[1][1]);
   trackPath();
}
