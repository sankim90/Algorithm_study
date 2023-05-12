#include <iostream>

#include <map>
#include <string>

using namespace std;

template <typename K, typename V>
void print_map(map<K, V>& m){

	for(auto itr = m.begin(); itr != m.end(); itr++){
		cout << itr->first <<" "<< itr->second << endl;
	}
}
//template <class T1, class T2>
//struct pair {
//  T1 first;
//  T2 second;
//};

template <typename K, typename V>
void serach_and_print(map<K, V>& m, K key){
	auto itr = m.find(key);
	if (itr != m.end()) {
		cout << key <<" --> " << itr->second << endl;
	}
	else {
		cout << "key not found " << endl;
	}
}

void map_test(){
	map<string, double> pitcher_list;

	/*
	//맵의 insert 함수는 pair 객체를 인자로 받음
	pitcher_list.insert(pair<string, double>("박세웅", 2.23));
	pitcher_list.insert(pair<string, double>("해커", 2.93));
	pitcher_list.insert(pair<string, double>("피어밴드", 2.95));

	//타입을 지정하지 않아도 간단히 make_pair 함수로 pair 객체를 만들 수 있음
	pitcher_list.insert(make_pair("차우찬", 3.04));
	pitcher_list.insert(make_pair("장원준", 3.05));
	pitcher_list.insert(make_pair("헥터", 3.09));

	//insert안쓰고 아래와 같이도 가능함
	pitcher_list["니퍼트"] = 3.56;
	pitcher_list["박종훈"] = 3.76;
	pitcher_list["캘리"] = 3.90;
*/
	//print_map(pitcher_list);

	//cout << "박세웅 박어율은? :" <<pitcher_list["박세웅"] << endl;
	//pitcher_list["오승환"] = 3.58;
	//pitcher_list["오승환"] = 4.58;
	pitcher_list.insert(make_pair("오승환", 3.58)); //insert는 역시 동일값은 무시됨
	pitcher_list.insert(make_pair("오승환", 3.8)); // pitcher_list["오승환"] = 4.58; 사용하면 덮어 쓰기 가능

	cout << "오승환 방어율은? " << pitcher_list["오승환"] << endl;

	//serach_and_print(pitcher_list, string("오승환"));
	//serach_and_print(pitcher_list, string("류현진"));
	//cout << "류현진 방어율은?" << pitcher_list["류현진"] << endl; // 0을 출력했으나 0또한 값이므로 에러 발생이 맞음

	cout << "-------------------------" << endl;
	//print_map(pitcher_list);
}
