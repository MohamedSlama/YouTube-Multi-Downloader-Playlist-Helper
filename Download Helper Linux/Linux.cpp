#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string convert(string str){
	string str2 = "";
	int count=0;
	for (unsigned int i = 0; i < str.length() && count !=2; i++){
		if (str[i] == '\'')
		{
			count ++;
			continue;
		}
		str2 += str[i];
	}
	return str2;
}

int main()
{
	
	ifstream file;
	string x, y = "";
	int num = 0;
	string path1, path2;
	int from, to;
	cout << "From : ";
	cin >> from;
	cout << "To : ";
	cin >> to;
	cin.ignore();
	cout << "Directory 1 : ";
	getline(cin, path1);
	cout << "Directory 2 : ";
	path1 = convert(path1);
	getline(cin, path2);
	path2 = convert(path2);
	file.open(path1.c_str());
	while (!file.eof())
	{
		getline(file, x);
		num++;
		if (num >= from && num <= to)
			y = y + x + "\n";
		if (num == to)break;
	}
	file.close();


	ofstream in;
	in.open(path2.c_str());
	in << y;
	in.close();
	return 0;
}
