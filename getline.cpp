#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]){
	using namespace std;
	
	// コマンドライン引数のチェック
	if(argc != 2){
		cerr << "引数の数が間違っています．" << endl;
		cerr << "./getline input.txt" << endl;
		return 1;
	}
	
	// C++のファイル入力のための準備
	ifstream ifs(argv[1], ios::in);
	// ファイルを開くのに失敗したときの処理
	if(!ifs){
		cerr << "Error: file not opened." << endl;
		return 1;
	}
	
	string tmp;
	string str;
	int num;
	int sum = 0;
	// getline()で1行ずつ読み込む
	while(getline(ifs, tmp)){
		// ここでtmpを煮るなり焼くなりする
		cout << tmp << endl; // そのまま出力
		stringstream ss;
		ss << tmp;
		ss >> str >> num; // str == "name:"; num == number;
		sum += num; // 値をsumに加算
	}
	
	cout << "\nsum: " << sum << endl;
	
	// ファイルを閉じる
	ifs.close();
	return 0;
}
