#include<stdio.h>
#include<string.h>
char BigInt1[10001];
char BigInt2[10001];
char BigInt3[10001];
void inv(char str[]){
	int L = strlen(str);
	int i,j;
	for(i=0,j=L-1;i<j;i++,j--){
		char t = str[i];
		str[i]=str[j];
		str[j]=t;
	}	
}
void add(char BigInt1[],char BigInt2[],char BigInt3[]){
	inv(BigInt1);inv(BigInt2);
     int i=0;
     int t = 0;
     while(BigInt1[i]!='\0'&&BigInt2[i]!='\0'){
     	 int k= BigInt1[i]-'0'+BigInt2[i]-'0'+t;//16   8
     	 BigInt3[i] = k%10+'0';
     	 t = k/10;
     	 i++;
	 }
	 while(BigInt1[i]!='\0'){
     	 int k= BigInt1[i]-'0'+t;//16   8
     	 BigInt3[i] = k%10+'0';
     	 t = k/10;
     	 i++;
	 }
	 while(BigInt2[i]!='\0'){
     	 int k= BigInt2[i]-'0'+t;//16   8
     	 BigInt3[i] = k%10+'0';
     	 t = k/10;
     	 i++;
	 }
	 if(t!=0){
	 	BigInt3[i] = t+'0';
	 }

     inv(BigInt3);
}
int main(){
	scanf("%s",BigInt1);
	scanf("%s",BigInt2);	
	add(BigInt1,BigInt2,BigInt3);	
	printf("%s",BigInt3);
	
	
	return 0;
}
