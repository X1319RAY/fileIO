#include <stdio.h>

#define BUFSIZE 1024

int main(int argc, char* argv[]){
	
	// コマンドライン引数のチェック
	if(argc != 2){
		fprintf(stderr, "引数の数が間違っています．\n");
		fprintf(stderr, "./fgets input.txt\n");
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
	
	// fscanf()で書式指定で1行ずつ読み込む
	char tmp[BUFSIZE];
	int num;
	int sum = 0;
	while(fscanf(fp, "%s %d", tmp, &num) != EOF){
		// ここでtmpを煮るなり焼くなりする
		printf("%s %d\n", tmp, num); // そのまま出力
		// 値をsumに加算
		sum += num;
	}
	
	printf("\nsum: %d\n", sum);
	
	// ファイルを閉じる
	fclose(fp);
	return 0;
}
