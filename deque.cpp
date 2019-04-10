#include <iostream>
#include <string>
#include <deque>

using namespace std;

void DQ_test(){

	deque<int> DQ;
	string S;
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cout <<"input your number\n";
	int param_num;
	cin >> param_num;

	for(int i = 0; i < param_num;  i++){
		cin >> S;
		if(S == "push_back"){
			int item;
			cin >> item;
			DQ.push_back(item);
		}
		else if(S == "push_front"){
			int item;
			cin >> item;
			DQ.push_front(item);
		}
		else if(S == "front"){
			if(DQ.empty())
				cout<<"-1\n";
			else{
				cout<<DQ.front()<<'\n';
			}
		}
		else if(S == "back"){
			if(DQ.empty())
				cout<<"-1\n";
			else{
				cout<<DQ.back()<<'\n';
			}
		}
		else if(S == "pop_front"){
			if(DQ.empty())
				cout<<"-1\n";
			else{
				cout<<DQ.front()<<'\n';
				DQ.pop_front();
			}

		}
		else if(S == "pop_back"){
			if(DQ.empty())
				cout<<"-1\n";
			else{
				cout<<DQ.back()<<'\n';
				DQ.pop_back();
			}
		}
		else if(S == "size"){
			cout<<DQ.size()<<'\n';
		}
		else if(S == "empty"){
			cout<<DQ.empty()<<'\n';
		}
	}
}
