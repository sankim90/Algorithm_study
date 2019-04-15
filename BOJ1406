#include <iostream>
#include <string>
#include <list>
using namespace std;
int main() {
    
    string s;
	getline(cin, s);
	int param_num;

	//cout << "input param num\n";
	cin >> param_num;
	cin.ignore();

	list<char> str_list;
	string cmd;

	for (int i = 0; i < s.size(); i++) {
		str_list.push_back(s[i]);
	}
	auto itr = str_list.end();

	//cout << "input cmd\n";
	for (int i = 0; i < param_num; i++) {
		
		getline(cin, cmd);

		if (cmd.at(0) == 'L' && itr != str_list.begin()) {
			itr--;
		}
		else if (cmd.at(0) == 'D' && itr != str_list.end()) {
			itr++;
		}
		else if (cmd.at(0) == 'B' && itr != str_list.begin()) {
			itr--;
			itr = str_list.erase(itr);		
			
		}
		else if (cmd.at(0) == 'P') {
			char ch = cmd.at(cmd.size() - 1);
			str_list.insert(itr, ch);
			
		}
	}



	
	//for (list<char>::iterator itr = str_list.begin(); itr != str_list.end(); itr++) {
	for(auto itr = str_list.begin(); itr != str_list.end(); itr++){
		cout << *itr;
	}

	cout << endl;
	


}
