#include<stdio.h>               
const int N=10;
int c1=0;
int f(int n){
  c1++;
  if(n==1 || n==2) return 1;
  return f(n-1)+f(n-2);
}

int c2=0;
int record[N+1]={0,1,1};//已知第1和第2项 
int f2(int n){
  c2++;
  if(record[n]!=0) return record[n];
  //if(n==1 || n==2) return 1;
  return record[n]=f2(n-1)+f2(n-2);
}
int main(){  
    
   printf("%d ",f(N));
   printf("%d\n",c1);
  
   printf("%d ",f2(N));
   printf("%d\n",c2);
}
