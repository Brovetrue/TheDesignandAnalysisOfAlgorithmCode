#include<stdio.h>
const int n=4;
//int adj[n+1][n+1]={{0},{0,0,1,1,0},{0,1,0,1,1},{0,1,1,0,1},{0,1,1,1,0}}; //�ĸ��������ȫͼ 
int adj[n+1][n+1]={{0},{0,0,1,1,0},{0,1,0,1,0},{0,1,1,0,1},{0,0,0,1,0}};// 
int choose[n+1];//
int max = 1; //��¼����ź��Ķ����� 
void outputSub();
void dfs(int i);
int main(){	 
	dfs(1);
	printf("max=%d",max); 
} 
int isTuan(){
  for(int i=1;i<=n;i++)	
    if(choose[i]==1){	
	    for(int j=1;j<=i-1;j++){
	    	if(choose[j]==1 && adj[i][j]==0) 
			         return 0;//adj[i][j]==0��vi,vj��������֮��û�бߣ������� 
		} 
	}
  return 1;//���� 
}
int daxiao(){
  int s=0;
  for(int i=1;i<=n;i++)	
    if(choose[i]==1){	
	    s++;
	}
  return s;
}
void dfs(int i){//��ҿ��ԸĽ����㷨��ʹ�ü�֦���� 
	if(i==n+1){
		if(isTuan()==1){//��ǰ���Ӽ������� 
		    int s = daxiao();//ͳ�Ƶ�ǰ�ŵĴ�С�����Ӽ�Ԫ�ظ��� 
			if(s>max) max=s; 
	    }
		return;	
	}	
	//if(isTuan(i))//����i������ǰ���ܷ񹹳��ţ����ܾͼ�֦ 
	choose[i]=1;
	dfs(i+1);
	choose[i]=0;
	dfs(i+1);
}
