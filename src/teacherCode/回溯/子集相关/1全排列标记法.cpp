#include<stdio.h>
int n=3;
int a[100];//a[i] ��¼���ŵĵ�i���� 
int tag[100]={0};//tag[i]=1  ��ʾ��i���ֹ��ˣ� tag[i]=0��ʾ��iû���ֹ��� 
void output(){
	for(int i=1;i<=n;i++)
	  printf("%3d",a[i]);
	printf("\n");  
}
int check(int i){
	for(int j=1;j<=i-1;j++)
	  if(a[i]==a[j]) return 0;	  
	return 1;
}
void pailie3(){	//ö�٣�1-3���� 
	for(a[1] = 1;a[1]<=n;a[1]++){
		for(a[2] = 1;a[2]<=n;a[2]++){
		   if(a[2]!=a[1]){
		   	   for(a[3] = 1;a[3]<=n;a[3]++){
		          if(a[3]!=a[1] && a[3]!=a[2]){		   	
		   	          output();   	
		          } 	   
	           }}}}	
}

void pailie(int i){	//pailie(1)    1 - i-1���Ѿ��ź��ˣ������ŵ�i�� 
	for(a[i] = 1;a[i]<=n;a[i]++){
		if(check(i)){//��֦���� 
			if(i==n){
				output();
			}else{
				pailie(i+1);
			}
		}	
	}	
}
void trackBack(int i){	//���������ݣ�//pailie(1)    1 - i-1���Ѿ��ź��ˣ������ŵ�i�� 
	if(i==n+1){
		output();
		return ;
	}	
	for(a[i] = 1;a[i]<=n;a[i]++){
		if(check(i)){//�㷨��Ч�� ��ȡ���ڼ�֦������Ч�� 			
			trackBack(i+1);			
		}	
   }
	return ; 
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
	trackBack(1);		
	return 0;
} 
