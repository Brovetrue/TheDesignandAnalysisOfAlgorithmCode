#include<stdio.h>
const int inf = 0x7fffff;
const int N = 100;
int n =6;
char vername[N][10]={"v1","v2","v3","v4","v5","v6"}; 
int w[N][N]={{0,6,1,5,inf,inf},
	          {6,0,5,inf,3,inf}, 
              {1,5,0,5,6,4},
              {1,inf,5,0,inf,2},
              {inf,3,6,inf,0,6},
              { inf ,inf,4,2,6,0}
            };
int v0 = 0;//��¼Դ������� 
int cost[N];//cost[i] vi��V-S�У���¼������������֮��ıߵ���С��һ�� 
int pre[N];//pre[i] ��¼vi��·����ǰһ���ڵ�ı�� 

int tag[N];//tag[i]��ʾ���i�Ƿ���S�У�������V-S��
int selectMin() {
	int min=inf;
	int u;
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(min>cost[i]){
      	     min=cost[i];
			   u = i;
         }
	  }
	return u;
}
void tiaozheng(int u){  //u�Ǹռ���S�Ķ���  
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(cost[i] >  w[u][i]){		   
      	     cost[i]=w[u][i];
      	     pre[i] = u;
		 }
	  }
}
void prim(int v0){
   //��ʼ��S��V-S   
   for(int i=0;i<n;i++) 
     tag[i] = 0;
   tag[v0]=1;
   //��ʼ��dist����¼V-S�����н����������·��
   for(int i=0;i<n;i++){    
       cost[i] =w[v0][i];
       pre[i] = v0;
   }
   for(int i=1;i<=n-1;i++){
   	  // ��V-S�е�cost[u]ѡ����С��u 
   	   int u = selectMin();
   	   printf("v%d->v%d:%d\n",pre[u]+1,u+1,cost[u]);//���������ѡ�ı� 
   	   //��u����S��
   	   tag[u]=1;
	   //�����µ�V-S�еĽ���distֵ 
	   tiaozheng(u);//���ݸռ���Ķ���u���������Ķ��� 
   }	
}           
int main() {
	prim(v0);
	//print(); 
}
