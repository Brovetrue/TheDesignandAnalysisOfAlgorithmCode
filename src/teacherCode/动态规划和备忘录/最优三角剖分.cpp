struct point {	
	double x;
	double y;
};
#define  N 100
struct point v[N]; //v[i].x  v[i].y 
int n=5;
double dp[N][N];
double d(int i,int j){	
    //求vi和vj的之间的距离distance 
	return sqrt((v[i].x-v[j].x)*(v[i].x-v[j].x)+
	(v[i].y-v[j].y)*(v[i].y-v[j].y));
}
double s(int i,int j,int k){
	double L1 = d(i,j);
	double L2 = d(i,k);
	double L3 = d(j,k);
	return L1+L2+L3;
	//周长等于三边之和 
}
void solvedp(){
	for(int i=0;?;i++)
       dp[i][i+1] = 0;
	for(int i=0;?;i++)
       dp[i][i+2] = s(i,i+1,i+1);
    for(int num = 4;?;num++){
    	for(int i=0;i<n-num+1;i++){
    		int j = i-num+1;
			//注意每条线上行号和列号的差值 
    		dp[i][j]=?;
			//找出那么多种情况的最小值
			//（k=i+1,....,j-1） 
			//dp[i] [k]+dp[k][j] + s(i,k,j) 
		}
	}
	
	
}
int main(){
	inputv();
	solvedp();
	print(dp[0][n-1]);
	//构造最优的剖分方案 
}
