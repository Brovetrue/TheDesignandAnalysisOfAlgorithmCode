#include<stdio.h>               
const int n=3; 
const int inf = 9999999; 
int money[n]={11,5,1};
                  //记录原始数据 
int f[n];//记录最优的结果 
//       f[i]记录凑出i元钱的最少的张数 
int w=15;

int solvef(){
  f[0]=0;//最容易求解的 
	  
  for(int i=1;i<=w;i++){//从倒数第2层到第1层，依次求解各层f[i][j] 
  	  int min=inf;
	  for(int j=0;j<n;j++){
  	  	  if(i>=money[j]){
  	  	  	  int g= f[i - money[j] ]+1;
  	  	  	  if(g< min) min=g;
		  }
	  }
	  f[i]=min;	  
  }
  
}
int main(){  
   solvef();   
   printf("最少需要%d张\n",f[w]);
  
}
