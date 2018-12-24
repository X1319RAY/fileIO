#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]){
	
	// コマンドライン引数のチェック
	if(argc != 2){
		fprintf(stderr, "引数の数が間違っています．\n");
		fprintf(stderr, "./fgetc input.txt\n");
		return 1;
	}
	
	// C言語のファイル入力のための準備
	FILE* fp; // FILE型構造体
	// 読み込みモードでファイルを開く
	fp = fopen(argv[1], "r"); // 失敗するとNULLを返す
	// ファイルを開くのに失敗したときの処理
	if(fp == NULL){
		fprintf(stderr, "Error: file not opened.\n");
		return 1;
	}
	
	// fgetc()で1文字ずつ読み込む
	int tmp; // fgetc()はint型の文字コードを返す
	int num = 0;
	int sum = 0;
	while((tmp = fgetc(fp)) != EOF){
		// ここでtmpを煮るなり焼くなりする
		printf("%c", (char)tmp); // そのまま出力
		
		// 数字ならnumに数として格納
		if(isdigit(tmp)){
			num = num * 10; // 位を1つ大きくする
			num += tmp - '0'; // 一の位に値を入れる
		}
		else{
			// 数字が終わった直後ならnumがsumに加算される
			// その後numを0にしているので直後以外はsumに0が加算される
			sum += num;
			num = 0;
		}
	}
	
	printf("\nsum: %d\n", sum);
	
	// ファイルを閉じる
	fclose(fp);
	return 0;
}
