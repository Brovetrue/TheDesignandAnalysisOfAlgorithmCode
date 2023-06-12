//https://www.cnblogs.com/xumenger/p/4311970.html
#include<stdio.h>
int n=8;//4皇后问题 
int a[11];//a[i] 记录安排的第i个皇后放在第i行的a[i]中 
int lietag[11];//大家可以不看这个
int zhutag[22];//大家可以不看这个
int futag[22];//大家可以不看这个
void output(){
    for(int i=1;i<=n;i++)
        printf("%3d",a[i]);
    printf("\n");
}
int count=0;
int check(int i){
    //测试第i个皇后的位置（i,a[i]） 和
    //前面的i-1个皇后的位置 （1,a[1]） ....... （i-1,a[i-1]）是否冲突了
    //不同列，不同主对角，不同副对角
    for(int j=1;j<=i-1;j++){
        // （i,a[i]）  （j,a[j]）
        if(a[i]==a[j]||i-a[i]==j-a[j]|| i+a[i]==j+a[j])return 0;

    }
    return 1;
}
void trackBackQueue(int i){	//蛮力：回溯，//pailie(1)    1 - i-1个已经排好了，现在排第i个
    if(i==n+1){
        count++;
        return ;
    }
    for(a[i] = 1;a[i]<=n;a[i]++){
        if(check(i)){
            trackBackQueue(i+1)	;
        }
        //下面使用了另一种方法来check，标记法。
        //if(lietag[a[i]]==0 && zhutag[i-a[i]+n]==0 && futag[i+a[i]-1]==0){
        //剪枝函数:约束条件
        //shdetag[a[i]]=zhutag[i-a[i]+n]=futag[i+a[i]-1]=1;
        //trackBackQueue(i+1)	;
        // lietag[a[i]]=zhutag[i-a[i]+n]=futag[i+a[i]-1]=0;
        //}
    }
    return ;
}
int main(){
    while(~scanf("%d",&n)){
        count=0;
        trackBackQueue(1);
        printf("%d\n",count);
    }
    return 0;
}