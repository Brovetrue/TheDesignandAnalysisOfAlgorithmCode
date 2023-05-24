#include<stdio.h>
const int inf = 0x7fffff;
const int N = 100;
int n =5;
char vername[N][10]={"v0","v1","v2","v3","v4"}; 
int w[N][N]={{0,10,inf,30,inf},
	          {inf,0,50,inf,inf}, 
              {inf,inf,0,inf,10},
              {inf,inf,20,0,60},
              {inf,inf,inf,inf,0}
            };
int v0 = 0;//��¼Դ������� 
int dist[N];
int pre[N];//pre[i] ��¼vi��·����ǰһ���ڵ�ı�� 

int tag[N];//tag[i]��ʾ���i�Ƿ���S�У�������V-S��
int selectMin() {
	int min=inf;
	int u;
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(min>dist[i]){
      	     min=dist[i];
			   u = i;
         }
	  }
	return u;
}
void tiaozheng(int u){  //u�Ǹռ���S�Ķ���  
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(dist[i] > dist[u]+w[u][i]){		   
      	     dist[i]=dist[u]+w[u][i];
      	     pre[i] = u;
		 }
	  }
}
void dijstra(int v0){
   //��ʼ��S��V-S   
   for(int i=0;i<n;i++) 
     tag[i] = 0;
   tag[v0]=1;
   //��ʼ��dist����¼V-S�����н����������·��
   for(int i=0;i<n;i++){    
       dist[i] =w[v0][i];
       pre[i] = v0;
   }
   for(int i=1;i<=n-1;i++){
   	  // ��V-S�е�dist[u]ѡ����С��u 
   	   int u = selectMin();
   	   //��u����S��
   	   tag[u]=1;
	   //�����µ�V-S�еĽ���distֵ 
	   tiaozheng(u);//���ݸռ���Ķ���u���������Ķ��� 
   }	
} 
void print(){
	printf("  Դ��    �յ�     �յ��ǰһ��    ���·��ֵ\n");
	for(int i=0;i<n;i++) 
       printf("%6d %6d    %8d           %d\n",v0,i,pre[i],dist[i]);
}          
int main() {
	dijstra(v0);
	print(); 
}
