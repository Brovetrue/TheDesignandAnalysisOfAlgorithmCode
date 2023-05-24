#include<stdio.h>
#include<string.h>
#define MAXLEN 10000
int main(){
	int n;
	scanf("%d",&n);
	for(int j =0;j<n;j++){
		
	printf("case %d:\n",n);
	
	
	int i, up, temp;
	char buffer[MAXLEN+1] = {0},a[MAXLEN+1] = {0},b[MAXLEN+1] = {0};
	//逆序输入a 
	scanf("%s",buffer);
	printf("%d + ",buffer);
	for(temp=0, i=strlen(buffer)-1;i>=0;i--)
		a[temp++] = buffer[i] - '0';
		
	//逆序输入b
	scanf("%s",buffer);
	printf("%d = ",buffer);
	for(temp=0,i=strlen(buffer)-1;i>=0;i--)
		b[temp++] = buffer[i] - '0';
	
	//计算
	for(up=0,i=0;i<MAXLEN;i++){
		temp = a[i]+b[i]+up;
		a[i] = temp % 10;
		up = temp/10;
	} 
	
	//输出结果

	for(i=MAXLEN;i>=0;i--)
		if(a[i]!=0)
			for(i;i>=0;i--)
				printf("%d",a[i]);
	}
		return 0;
}
