#include<stdio.h>

const int inf = 0x7fff;
const int N = 100;//���ڵ��� 
int n =5;
char vername[N][10]={"v0","v1","v2","v3","v4"}; 
int w[N][N]={{0,10,inf,30,inf},
	          {inf,0,50,inf,inf}, 
              {inf,inf,0,inf,10},
              {inf,inf,20,0,60},
              {inf,inf,inf,inf,0}
            };//�ڽӾ��� 
int v0 = 0;//��¼Դ�������
//��ʼ����

 
 
int dist[N];//��Դ�㵽����������������·��ֵ��
int pre[N];//pre[i]  vi�Ķ������̵�����·����
                   //��vi��ǰһ���ڵ� 
int tag[N];//tag[i] =1 ����vi��S�У�
              //tag[i] =0 ����vi��V-S�У�
//��ʶ���� 
//���ڼ�¼���̺�չ�ֽ��������
int selectMinDist(){//��V-S�е�dist[u]ѡ����С��u
    int min=inf;
    int u;
	for(int i=0;i<n;i++){
    	if(tag[i]==0){
    		if(dist[i]<min){
    			min = dist[i];
    			u = i;
			}
		}
	} 

    return u;

}
void tiaozheng(int u){
	//�����µ�V-S�еĽ���distֵ
	for(int i=0;i<n;i++){
    	if(tag[i]==0){
    		if(dist[i]>dist[u]+w[u][i]){
    			dist[i]=dist[u]+w[u][i];
    			pre[i]=u;
			}
		}
	} 
	
}
void dijstra(int v0){
   //��ʼ��S��V-S 
   for(int i=0;i<n;i++) 
      tag[i]=0;
   tag[v0] =1; 
   //��ʼ��dist����¼V-S�����н����������·��
   for(int i=0;i<n;i++) {   
      dist[i] =w[v0][i];//��ʼs��ֻ��һ��v0�������
	  pre[i]=v0; 
   }
   for(int i=1;i<=n-1;i++){
   	   //��V-S�е�dist[u]ѡ����С��u 
   	   int u =selectMinDist();
	   //��u����S��
   	   tag[u]=1;
	   //�����µ�V-S�еĽ���distֵ
	   tiaozheng(u); 
   }	
}  
void print(){
		//�����µ�V-S�еĽ���distֵ
    printf("%6s%6s%6s%12s\n","Դ��","pre","�յ�","���·��ֵ");
	for(int i=0;i<n;i++){
    	printf("%6s%6s%6s%12d\n",vername[v0],vername[pre[i]],vername[i],dist[i]);
	} 
	

}  
void input(){
	int e;
	scanf("%d",&n);
	//w ����ȫ����ʼ���� inf 
	for(int i=0;i<n;i++){ 
	  scanf("%s",vername[i]);
	  w[i][i]=0; 
	} 
	scanf("%d",&e);
	
	for(int i=0;i<e;i++){
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		w[a][b]=k;
		//w[a][b]=w[b][a]=k;
	}
}      
int main() {
	input();//�Գ�ʼ���ݽ������� 
	dijstra(v0);
	print();//������
	//printpath(); 
}
