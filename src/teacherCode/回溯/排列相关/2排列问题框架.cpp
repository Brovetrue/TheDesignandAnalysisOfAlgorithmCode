#include<stdio.h>
int n=3;
int a[100];//a[i] ��¼���ŵĵ�i���� 
int tag[100]={0};//tag[i]=1  ��ʾ��i���ֹ��ˣ� tag[i]=0��ʾ��iû���ֹ��� 
int check(int i){//���check������������û�е��ã���������� 
	for(int j=1;j<=i-1;j++)
	  if(a[i]==a[j]) return 0;	  
	return 1;
}
void output(){
	for(int i=1;i<=n;i++)
	  printf("%3d",a[i]);
	printf("\n");  
}
void trackBack2(int i){	//���������ݣ�//pailie(1)    1 - i-1���Ѿ��ź��ˣ������ŵ�i�� 
	if(i==n+1){
		output();
		return ;
	}	
	for(a[i] = 1;a[i]<=n;a[i]++){
		if(tag[a[i]]==0){//�㷨��Ч�� ��ȡ���ڼ�֦������Ч�� 
			tag[a[i]]=1;
			trackBack2(i+1);
			tag[a[i]]=0;//����		
		}	
   }
	return ; 
}
int main(){
	printf("��1-n�����У�������n��ֵ\n"); 
	scanf("%d",&n); 
	trackBack2(1);		
	return 0;
} 
