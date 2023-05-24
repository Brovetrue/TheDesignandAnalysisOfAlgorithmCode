#include<stdio.h>
int board[64][64] ;
int tile =1;
void chessBoard(int tr, int tc, int dr, int dc, int size){   
      if (size == 1) return;
      int t = tile++,  // L型骨牌号
        s = size/2;  // 分割棋盘
      // 覆盖左上角子棋盘
      if (dr < tr + s && dc < tc + s){//特殊格子在第一个子棋盘中。 
      	       //中间四个格子，覆盖其中三个 
                //board [tr+s-1][tc+s-1] 
                board [tr+s-1][tc+s] =t ;
                board [tr+s][tc+s-1] =t ;
                board [tr+s][tc+s] =t ;
               //然后分成四个小棋盘问题 
                chessBoard(tr,tc,dr,dc,s);
                chessBoard(tr,tc+s,tr+s-1,tc+s,s);
                chessBoard(tr+s,tc,tr+s,tr+s-1,s);
                chessBoard(tr+s,tc+s,tr+s,tc+s,s);
      }  // .......其他三种情况自行补充
      else if(dr < tr + s && dc >= tc + s){
                board [tr+s-1][tc+s-1]=t; 
                //board [tr+s-1][tc+s] =t ;
                board [tr+s][tc+s-1] =t ;
                board [tr+s][tc+s] =t ;
                chessBoard(tr,tc,tr+s-1,tc+s-1,s);
                chessBoard(tr,tc+s,dr,dc,s);
                chessBoard(tr+s,tc,tr+s,tr+s-1,s);
                chessBoard(tr+s,tc+s,tr+s,tc+s,s);
      } 
      else if(dr >= tr + s && dc < tc + s){
                board [tr+s-1][tc+s-1]=t; 
                board [tr+s-1][tc+s] =t ;
                //board [tr+s][tc+s-1] =t ;
                board [tr+s][tc+s] =t ;
                chessBoard(tr,tc,tr+s-1,tc+s-1,s);
                chessBoard(tr,tc+s,tr+s-1,tc+s,s);
                chessBoard(tr+s,tc,dr,dc,s);
                chessBoard(tr+s,tc+s,tr+s,tc+s,s);
      } else if(dr >= tr + s && dc >= tc + s){
                board [tr+s-1][tc+s-1]=t; 
                board [tr+s-1][tc+s] =t ;
                board [tr+s][tc+s-1] =t ;
                //board [tr+s][tc+s] =t ;
                chessBoard(tr,tc,tr+s-1,tc+s-1,s);
                chessBoard(tr,tc+s,tr+s-1,tc+s,s);
                chessBoard(tr+s,tc,tr+s,tr+s-1,s);
                chessBoard(tr+s,tc+s,dr,dc,s);
      } 
}
void output(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%3d",board[i][j]);
		}
		printf("\n");
	}
}
int main(){
   chessBoard(1,1,4,5,8);//特殊格子在4行5列的位置。 
   output(8);

}
