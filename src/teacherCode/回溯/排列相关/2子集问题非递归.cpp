#include<stdio.h>
const int N =100;
int n=3;
int a[N]={0,11,22,33};
int choose[N];//choose[i] 
void printsub(){
	for(int i=1;i<=n;i++){
		if(choose[i]==1){
			printf("%d ",a[i]);
		}
	}
	printf("\n");
}
void sub(){
	int i=1;
	choose[i]=-1;
	while(i>0){		
		choose[i]++;
		if(choose[i]==2) {		   
		   i--;
		}
		else{
			if(i==n){
				printsub();
			}else{			
			   i++;
			   choose[i]=-1;
			}
		}
	} 
}

void dfs(int i){
	if(i==n+1){
		printsub();
		return;
	}
	//for(choose[i]=0;choose[i]<=1;choose[i]++){
			  //dfs(i+1);			
	//}
	choose[i] =0;//第i个元素不选入子集中 
	dfs(i+1);
	choose[i]=1;//第i个元素选入子集中 
	dfs(i+1);
}
main(){
	sub();
	//dfs(1);
} 
