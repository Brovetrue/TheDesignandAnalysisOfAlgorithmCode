#include<stdio.h>
const int N =100;
int n;
int a[N];
int choose[N];//choose[i] =1 表示第i个元素在子集中， choose[i] =0表示第i个元素不在子集中 
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
void sub(){//蛮力：枚举法 
	for(choose[1]=0;choose[1]<=1;choose[1]++){
		for(choose[2]=0;choose[2]<=1;choose[2]++){
			for(choose[3]=0;choose[3]<=1;choose[3]++){				
				printsub();				
			}
			
		}
		
	} 
}
void sub(int i){//sub(1)   ;蛮力：回溯 1 - i-1个已经做了选择，现在对第i个做选择 
	
		for(choose[i]=0;choose[i]<=1;choose[i]++){				
			if(i==n){//4
				printsub();
			}
			else 
			   sub(i+1)	;		
		}		
	
	
	 
}
void sub2(int i){//蛮力：回溯 1 - i-1个已经做了选择，现在对第i个做选择 
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
void trackBack(int i){//蛮力：回溯 1 - i-1个已经做了选择，现在对第i个做选择 
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
void sub4(int i){//蛮力：回溯 1 - i-1个已经做了选择，现在对第i个做选择 
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
	choose[i] =0;//第i个元素不选入子集中 
	dfs(i+1);
	choose[i]=1;//第i个元素选入子集中 
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
