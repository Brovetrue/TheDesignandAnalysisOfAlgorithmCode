#include <stdio.h>
#include <string.h>
int n;
int num[10][10];
int memory[10][10];//后面用备忘录的备忘
#define inf 0x7fffffff
//v1 v2.....Vn
//dp(i,j)
/*
	i+2=j  -> s(i,i+1,j)
	i+2<j  -> max(dp(i,k)+dp(k,j)+s(i,k,j))  k>i&&k<j
	其他   -> 0 
*/

int s(int i,int j,int k){
    return num[i][j]+num[j][k]+num[k][i];
}
int dp(int i,int j){
    if(memory[i][j]!=-1) return memory[i][j];
    //只有三条边，i+2=j
    if(i+2==j) return s(i,i+1,j);//三边之和
    else if(i+2<j){
        //大于三条边 vi---vj
        int min=inf;
        for(int k=i+1;k<j;k++){
            int border = dp(i,k)+dp(k,j)+s(i,k,j);
            if(border<min) min=border;

        }
        return memory[i][j]=min;
    }
    else if(i+1==j){
        return memory[i][j]=0;
    }
}
int main(){
    scanf("%d",&n);
    memset(memory,-1,sizeof(memory));
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            scanf("%d",&num[i][j]);
            num[j][i]=num[i][j];
        }
    }
    printf("%d",dp(1,n));
    return 0;
}