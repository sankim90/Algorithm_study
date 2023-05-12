#include "stl_test.h"

#include <iostream>
#include <list>
using namespace std;

template <typename T>
void print_list(list<T>& lst) {
	cout << "[";

	for (auto itr = lst.begin(); itr != lst.end(); itr ++){
		cout <<*itr <<" ";
	}
	cout << "]"<<endl;

}
void list_test() { //이중연결리스트와 같음
  list<int> lst;

  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);
  lst.push_back(40);

  cout<<"원래 값"<<endl;
  print_list(lst);


  for (auto iter = lst.begin(); iter != lst.end(); iter++){
	  if(*iter == 20)
		  lst.insert(iter, 50);
  }

  cout<<"20위치에 50 추가"<<endl;
  print_list(lst);

  for (auto iter = lst.begin(); iter != lst.end(); iter++){
	  if(*iter == 30){
		  lst.erase(iter);
		  //iter = lst.begin();
		  break;
	  }

  }

  cout<<"30제거 "<<endl;
  print_list(lst);


}
