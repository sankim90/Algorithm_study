#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

template <typename K>
void print_set(multiset<K>& s){
	// 셋의 모든 원소 출력

	for(auto itr = s.begin(); itr != s.end(); itr ++){
		cout << *itr << endl;
	}

}

template <typename K, typename V>
void print_map(multimap<K,V>& m){
	for(auto itr = m.begin(); itr != m.end(); itr++){
		cout << itr->first <<" " << itr->second <<endl;
	}
}

void mutiset_test(){
	multiset<string> s;

	s.insert("a");
	s.insert("b");
	s.insert("a");
	s.insert("c");
	s.insert("d");
	s.insert("c");

	print_set(s);

}

void mutimap_test(){
	//multimap<double, string> m;
	multimap<string, double> m;

	m.insert(make_pair("진산", 2.5));
	m.insert(make_pair("병일", 1.5));
	m.insert(make_pair("병일", 35.3));
	m.insert(make_pair("희준", 9.5));
	m.insert(make_pair("정호", 9.5));
	print_map(m);

	cout << "--------------------" << endl;
	cout << m.find("병일")->second << endl; // 1.5, 35.3 무엇이든 나올수 있음, find 하지 못하면 m.end() 리턴
	cout << "--------------------" << endl;

	auto range = m.equal_range("병일");
	for (auto itr = range.first; itr != range.second; itr++){
		cout << itr->first << " " << itr->second << endl;
	}

}
