#include<stdio.h>
const int n=7;//n�еķ���������
 
int tri[n+1][n+1];// ��ȷ����һ��tri[1][] 

int count=0;//��¼�Ϸ������� 
void dfs(int i);
int main(){	 
	dfs(1);//��ҿ���ȥ�Ľ�����ķ��� 
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
		        s++;	//ͳ�����ŵĸ���	   
		}
	}
    return s; 
} 
void dfs(int i){//��ҿ��ԸĽ��¸÷��� 

	if(i==n+1){//�����������������ֵ 
		qiuzhi(); //ȷ���˵�һ�еķ��ź������е�ֵ��ȷ���ˣ�ͨ������������		
		int num = tongji();//ͳ���������е����ŵĸ���		 
		if(num == n*(n+1)/2-num){//���ŵĸ����������ܵĸ�����ȥ���ŵĸ��� 
		    count++;	//printf("%d\n",count);	
		}
		return;			
	}
		
	tri[1][i]='+';
	dfs(i+1);
	tri[1][i]='-';
	dfs(i+1);
}
