#include <iostream>
#include <fstream>
#include <random>

int main(int argc, char* argv[]){
	using namespace std;
	
	random_device seed_gen; // 乱数のseedを生成
	mt19937 mt(seed_gen()); // メルセンヌ・ツイスターと呼ばれる乱数生成法
	
	ofstream out("input.txt", ios::out);
	
	uniform_int_distribution<> dista(1, 'a');
	out << "ant: " << dista(mt) << endl;
	
	uniform_int_distribution<> distb(1, 'b');
	out << "buffalo: " << distb(mt) << endl;
	
	uniform_int_distribution<> distc(1, 'c');
	out << "cat: " << distc(mt) << endl;
	
	uniform_int_distribution<> distd(1, 'd');
	out << "dog: " << distd(mt) << endl;
	
	out.close();
	
	return 0;
}