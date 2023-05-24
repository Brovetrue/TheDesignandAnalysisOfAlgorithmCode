#include<stdio.h>               
const int n=5; 
int data[n+1][n+1]={{0},
                    {0,9},
					{0,12,15},
					{0,10,6,8},
                    {0,2,18,9,5},
					{0,19,7,10,4,16}};
                  //��¼ԭʼ���� 
int record[n+1][n+1];

  //��¼���ŵĽ��   dp[1][1] ����9�����ߵ���� 
//                dp(i,j)��¼��data[i][j]�ߵ���ײ�����·������ 
                 //dp(1,1) ����9�����ߵ���� 
                 
//                dp(i,j) = data[i][j]  i = n���²㣬1<=j<=i; 

//                dp(i,j) = data[i][j]+max(dp(i+1,j),(i+1,j+1))
//                                          i=n-1,....,1; 1<=j<=i; 

int dp(int i,int j){
	if(record[i][j]!=0) return record[i][j];
	if(i==n)  return record[i][j]=data[i][j];
	int f1 =dp(i+1,j);
	int f2= dp(i+1,j+1);
	return record[i][j]=data[i][j]+(f1>=f2?f1:f2);	
	
}
void output(){  
  for(int i=1;i<=n;i++){      
      for(int j=1;j<=i;j++)
         printf("%3d",record[i][j]);
      printf("\n");   
  }
}
void trackPath(){
	int i=1,j=1;
	do{	
	    printf("%d  ",data[i][j]);
	    if(i == n) break;
	    if(record[i][j]==record[i+1][j]+data[i][j]){
	        i=i+1;j=j;        
	    }
	    else {
	      i=i+1;j=j+1;       
	    }    
	}while(1)  ;
}
int main(){  
   
   printf("���·���ĺ�ֵ��%d\n",dp(1,1));output();
   
   printf("���·��:");trackPath();
}
