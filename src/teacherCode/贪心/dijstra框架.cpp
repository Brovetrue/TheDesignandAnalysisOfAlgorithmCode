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
void dijstra(v0){
   //��ʼ��S��V-S   
   //��ʼ��dist����¼V-S�����н����������·��
   for(int i=1;i<=n-1;i++){
   	   ��V-S�е�dist[u]ѡ����С��u 
   	   ��u����S��
	   �����µ�V-S�еĽ���distֵ 
   }	
}           
int main() {
	dijstra(v0);
}
