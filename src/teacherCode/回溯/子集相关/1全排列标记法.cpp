#include<stdio.h>
int n=3;
int a[100];//a[i] 记录安排的第i个数 
int tag[100]={0};//tag[i]=1  表示数i出现过了， tag[i]=0表示数i没出现过了 
void output(){
	for(int i=1;i<=n;i++)
	  printf("%3d",a[i]);
	printf("\n");  
}
int check(int i){
	for(int j=1;j<=i-1;j++)
	  if(a[i]==a[j]) return 0;	  
	return 1;
}
void pailie3(){	//枚举：1-3排列 
	for(a[1] = 1;a[1]<=n;a[1]++){
		for(a[2] = 1;a[2]<=n;a[2]++){
		   if(a[2]!=a[1]){
		   	   for(a[3] = 1;a[3]<=n;a[3]++){
		          if(a[3]!=a[1] && a[3]!=a[2]){		   	
		   	          output();   	
		          } 	   
	           }}}}	
}

void pailie(int i){	//pailie(1)    1 - i-1个已经排好了，现在排第i个 
	for(a[i] = 1;a[i]<=n;a[i]++){
		if(check(i)){//剪枝函数 
			if(i==n){
				output();
			}else{
				pailie(i+1);
			}
		}	
	}	
}
void trackBack(int i){	//蛮力：回溯，//pailie(1)    1 - i-1个已经排好了，现在排第i个 
	if(i==n+1){
		output();
		return ;
	}	
	for(a[i] = 1;a[i]<=n;a[i]++){
		if(check(i)){//算法的效率 还取决于剪枝函数的效率 			
			trackBack(i+1);			
		}	
   }
	return ; 
}
void trackBack2(int i){	//蛮力：回溯，//pailie(1)    1 - i-1个已经排好了，现在排第i个 
	if(i==n+1){
		output();
		return ;
	}	
	for(a[i] = 1;a[i]<=n;a[i]++){
		if(tag[a[i]]==0){//算法的效率 还取决于剪枝函数的效率 
			tag[a[i]]=1;
			trackBack2(i+1);
			tag[a[i]]=0;//回溯		
		}	
   }
	return ; 
}
int main(){
        printf("求1-n的排列，请输入n的值\n"); 
	scanf("%d",&n); 
	trackBack(1);		
	return 0;
} 
