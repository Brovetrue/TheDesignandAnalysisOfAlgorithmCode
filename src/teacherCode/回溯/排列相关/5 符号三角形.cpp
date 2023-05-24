#include<stdio.h>
const int n=7;//n行的符号三角形
 
int tri[n+1][n+1];// 先确定第一行tri[1][] 

int count=0;//记录合法的种数 
void dfs(int i);
int main(){	 
	dfs(1);//大家可以去改进下面的方法 
	printf("%d\n",count); 
} 
void qiuzhi(){
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(tri[i-1][j]==tri[i-1][j+1])
		        tri[i][j] ='+';
		    else 
			    tri[i][j] ='-';
		}
	}
} 
int  tongji(){
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(tri[i][j] =='+')
		        s++;	//统计正号的个数	   
		}
	}
    return s; 
} 
void dfs(int i){//大家可以改进下该方法 

	if(i==n+1){//求符号三角形其他的值 
		qiuzhi(); //确定了第一行的符号后，其他行的值就确定了，通过这个函数求出		
		int num = tongji();//统计三角形中的正号的个数		 
		if(num == n*(n+1)/2-num){//符号的个数，等于总的个数减去正号的个数 
		    count++;	//printf("%d\n",count);	
		}
		return;			
	}
		
	tri[1][i]='+';
	dfs(i+1);
	tri[1][i]='-';
	dfs(i+1);
}
