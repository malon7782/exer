#include <stdio.h>

int is_valid(int board[8][8]){
	for(int i = 0; i < 8; i++){
		int sum1 = 0;
		int sum2 = 0;
		for(int j = 0; j < 8; j++){
			sum1 += board[i][j];
			sum2 += board[j][i];
		}
		if(sum1 > 1 || sum2 > 1) return -1;
	}
	for(int k = 0; k < 8; k++){
		int sum1 = 0;
		int sum2 = 0;
		int sum3 = 0;
		int sum4 = 0;
		for(int w = 0; w < k+1; w++){
			sum1 += board[k-w][w];
			sum2 += board[w][7-k+w];
			sum3 += board[7-k+w][7-w];
			sum4 += board[7-k+w][w];
		}
		if(sum1 > 1 || sum2 > 1 || sum3 > 1 || sum4 > 1) return -1;
	}
	return 0;
}

void print(int board[8][8]){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------------\n");
}

void placeQueen(int board[8][8], int column){
	if(column == 8){
		print(board);
		return;
	}
	for(int i = 0; i < 8; i++){
		board[i][column] = 1;
		if (is_valid(board) == 0){
			placeQueen(board, column + 1);
		}

		board[i][column] = 0;
	}
}

int main(){
	int board[8][8] = {0};
	placeQueen(board, 0);
	print(board);
	return 0;
}
