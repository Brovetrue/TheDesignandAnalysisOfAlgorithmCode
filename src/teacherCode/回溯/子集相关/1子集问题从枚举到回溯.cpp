#include<stdio.h>
const int N =100;
int n;
int a[N];
int choose[N];//choose[i] =1 ��ʾ��i��Ԫ�����Ӽ��У� choose[i] =0��ʾ��i��Ԫ�ز����Ӽ��� 
void printsub(){
	printf("{ ");
	for(int i=1;i<=n;i++){
		if(choose[i]==1){
			printf("%d ",a[i]);
		}
	}
	printf("} ");
	printf("\n");
}
void sub(){//������ö�ٷ� 
	for(choose[1]=0;choose[1]<=1;choose[1]++){
		for(choose[2]=0;choose[2]<=1;choose[2]++){
			for(choose[3]=0;choose[3]<=1;choose[3]++){				
				printsub();				
			}
			
		}
		
	} 
}
void sub(int i){//sub(1)   ;���������� 1 - i-1���Ѿ�����ѡ�����ڶԵ�i����ѡ�� 
	
		for(choose[i]=0;choose[i]<=1;choose[i]++){				
			if(i==n){//4
				printsub();
			}
			else 
			   sub(i+1)	;		
		}		
	
	
	 
}
void sub2(int i){//���������� 1 - i-1���Ѿ�����ѡ�����ڶԵ�i����ѡ�� 
	if(i==n+1){//4
		printsub();
		//return ;
	}else{		
		for(int t=0;t<=1;t++){	
		    choose[i]=t;			
			sub2(i+1);		
		}
	}		
	
	
	 
}
void trackBack(int i){//���������� 1 - i-1���Ѿ�����ѡ�����ڶԵ�i����ѡ�� 
	if(i==n+1){//4
		printsub();
		//return ;
	}else{		
		//for(t=0;t<=1;t++){	
		    choose[i]=0;			
			trackBack(i+1);
				
			choose[i]=1;			
			trackBack(i+1);	
		//}
	} 
}
void sub4(int i){//���������� 1 - i-1���Ѿ�����ѡ�����ڶԵ�i����ѡ�� 
	if(i==n+1){//4
		printsub();
		//return ;
	}else{		
		//for(t=0;t<=1;t++){	
		    choose[i]=1;			
			sub4(i+1);
			
			choose[i]=0;			
			sub4(i+1);	
				
		//}
	} 
}
void dfs(int i){
	if(i==n+1){
		printsub();
		return;
	}
	//for(choose[i]=0;choose[i]<=1;choose[i]++){
			  //dfs(i+1);			
	//}
	choose[i] =0;//��i��Ԫ�ز�ѡ���Ӽ��� 
	dfs(i+1);
	choose[i]=1;//��i��Ԫ��ѡ���Ӽ��� 
	dfs(i+1);
}
main(){
	scanf("%d",&n); //4
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]) ;
	}
	sub4(1);
	//dfs(1);
} 
