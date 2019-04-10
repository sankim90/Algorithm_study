#include <iostream>
#include <set>
#include <string>
using namespace std;

template <typename T, typename C>
void print_set(set<T,C>& s) {

	cout << "[ " <<endl;
	for(auto itr = s.begin(); itr != s.end(); itr++) {
		cout << *itr << endl;
	}

	cout << "] " <<endl;
}

class Todo {
	int priority;
	string job_desc;

public:
	Todo(int priority, string job_desc) : priority(priority), job_desc(job_desc) {}

	/*
	bool operator<(const Todo& t) const { //셋 내부적으로 정렬 시에 상수 반복자를 사용하기에 const
		if (priority == t.priority) {
			return job_desc < t.job_desc;
		}
		return priority > t.priority;
	}*/
	friend struct TodoCmp;
	friend ostream& operator<<(ostream& o, const Todo& td);


};

struct TodoCmp {
	bool operator()(const Todo& t1, const Todo& t2) const {
		if (t1.priority == t2.priority) {
			return t1.job_desc < t2.job_desc;
		}
		return t1.priority > t2.priority;
	}
};

ostream& operator<<(ostream& o, const Todo& td){
	o << "[중요도: " << td.priority << "] " << td.job_desc;
	return o;
}

void set_test(){
	/*
	set<int> s;

	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);
	s.insert(30);
	//값이 중복되면 무시됨, ex) 10, 10, 10, 40, 30 -> 10 30 40

	cout << "오름차순 정렬되어 출력됨" << endl;

	print_set(s);

	cout << "20이 s의 원소인가? ::" << endl;
	auto itr = s.find(20);
	if (itr != s.end()){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
//s.find는 만일 해당하는 원소가 존재한다면 이를 가리키는 반복자를 리턴하고 (set<>::iterator 타입입니다) 만일 존재하지 않는다면 s.end() 를 리턴하게 되지요.

	cout << "25이 s의 원소인가? ::" << endl;
	itr = s.find(25);
	if (itr != s.end()){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
*/
	set<Todo, TodoCmp> todos;

	todos.insert(Todo(1, "농구하기"));
	todos.insert(Todo(2, "수학"));
	todos.insert(Todo(1, "프로그래밍"));
	todos.insert(Todo(3, "친구만나"));
	todos.insert(Todo(2, "영화봐"));

	print_set(todos);

	cout << "-----------------------------------" << endl;
	cout << "숙제를 끝냈다" <<endl;
	todos.erase(todos.find(Todo(2,"수학")));

	print_set(todos);

}
