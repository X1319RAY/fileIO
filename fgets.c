#include <stdio.h>
#include <ctype.h>

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
	
	// fgets()で1行ずつ読み込む
	char tmp[BUFSIZE]; // fgets()はchar型配列に格納
	int num = 0;
	int sum = 0;
	while(fgets(tmp, BUFSIZE, fp) != NULL){
		// ここでtmpを煮るなり焼くなりする
		printf("%s", tmp); // そのまま出力
		// tmpの中身を確認
		for(int i = 0; i < BUFSIZE; i++){
			// 数字ならnumに数として格納
			if(isdigit(tmp[i])){
				num = num * 10; // 位を1つ大きくする
				num += tmp[i] - '0'; // 一の位に値を入れる
			}
			else{
				// 数字が終わった直後ならnumがsumに加算される
				// その後numを0にしているので直後以外はsumに0を加算
				sum += num;
				num = 0;
			}
			if(tmp[i] == '\n') break;
		}
	}
	
	printf("\nsum: %d\n", sum);
	
	// ファイルを閉じる
	fclose(fp);
	return 0;
}
