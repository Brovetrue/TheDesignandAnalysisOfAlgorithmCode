#include<stdio.h>
const int inf = 0x7fffff;
const int N = 100;
int n =6;
int w[N][N]={{0,6,1,5,inf,inf},
	          {6,0,5,inf,3,inf}, 
              {1,5,0,5,6,4},
              {5,inf,5,0,inf,2},
              {inf,3,6,inf,0,6},
              {inf,inf,4,2,6,0}
            };
int v0 = 0;//��¼Դ������� 
int lowcost[N];
int pre[N]; 
int tag[N];//tag[i]��ʾ���i�Ƿ���S�У�������V-S��
int selectMin() {
	int min=inf;
	int u;
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(min>lowcost[i]){
      	     min=lowcost[i];
			   u = i;
         }
	  }
	return u;
}
void tiaozheng(int u){  //u�Ǹռ���S�Ķ���  
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(lowcost[i] > w[u][i]){      	 
      	     lowcost[i] = w[u][i];
      	     pre[i]=u;
		  }
	  }
	

}
void prim(int v0){
   //��ʼ��S��V-S   
   for(int i=0;i<n;i++) 
     tag[i] = 0;
   tag[v0]=1;
   //��ʼ��S ��V-S�����н�����С�ı� 
   for(int i=0;i<n;i++){    
      lowcost[i] =w[v0][i];
	 //lowcost��¼������������֮��ģ�V-S����С�ı�Ȩ 	 
	  pre[i]=v0;//v0 �� vi 
   }
   for(int i=1;i<=n-1;i++){
   	  // ��V-S�е�lowcost[u]ѡ����С��u 
   	   int u = selectMin();
		  //ѡ��ߣ�(pre[u] , u������� 
	   printf("v%d--v%d\n",pre[u]+1,u+1);
   	   //��u����S��
   	   tag[u]=1;
	   //�����µ�V-S�еĽ���lowcostֵ 
	   tiaozheng(u);//���ݸռ���Ķ���u���������Ķ��� 
   }	
}           
int main() {
	prim(v0);
	//print(); 
}
