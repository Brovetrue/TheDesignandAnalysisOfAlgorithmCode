#include<stdio.h>
int board[64][64] ;
int tile =1;
void chessBoard(int tr, int tc, int dr, int dc, int size){   
      if (size == 1) return;
      int t = tile++,  // L�͹��ƺ�
        s = size/2;  // �ָ�����
      // �������Ͻ�������
      if (dr < tr + s && dc < tc + s){//��������ڵ�һ���������С� 
      	       //�м��ĸ����ӣ������������� 
                //board [tr+s-1][tc+s-1] 
                board [tr+s-1][tc+s] =t ;
                board [tr+s][tc+s-1] =t ;
                board [tr+s][tc+s] =t ;
               //Ȼ��ֳ��ĸ�С�������� 
                chessBoard(tr,tc,dr,dc,s);
                chessBoard(tr,tc+s,tr+s-1,tc+s,s);
                chessBoard(tr+s,tc,tr+s,tr+s-1,s);
                chessBoard(tr+s,tc+s,tr+s,tc+s,s);
      }  // .......��������������в���
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
   chessBoard(1,1,4,5,8);//���������4��5�е�λ�á� 
   output(8);

}
