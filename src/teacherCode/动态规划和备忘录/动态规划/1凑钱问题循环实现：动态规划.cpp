#include<stdio.h>               
const int n=3; 
const int inf = 9999999; 
int money[n]={11,5,1};
                  //��¼ԭʼ���� 
int f[n];//��¼���ŵĽ�� 
//       f[i]��¼�ճ�iԪǮ�����ٵ����� 
int w=15;

int solvef(){
  f[0]=0;//���������� 
	  
  for(int i=1;i<=w;i++){//�ӵ�����2�㵽��1�㣬����������f[i][j] 
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
   printf("������Ҫ%d��\n",f[w]);
  
}
