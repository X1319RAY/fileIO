#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
	using namespace std;
	
	// コマンドライン引数のチェック
	if(argc != 2){
		cerr << "引数の数が間違っています．" << endl;
		cerr << "./extraction input.txt" << endl;
		return 1;
	}
	
	// C++のファイル入力のための準備
	ifstream ifs(argv[1], ios::in);
	// ファイルを開くのに失敗したときの処理
	if(!ifs){
		cerr << "Error: file not opened." << endl;
		return 1;
	}
	
	string str;
	int num;
	int sum = 0;
	// 抽出演算子>>を使ってデリミタで区切られた単語，値を読み込む
	while(ifs >> str >> num){
		// ここで格納した文字列や変数を煮るなり焼くなりする
		cout << str << " " << num << endl; // そのまま出力
		sum += num; // 値をsumに加算
	}
	
	cout << "\nsum: " << sum << endl;
	
	// ファイルを閉じる
	ifs.close();
	return 0;
}