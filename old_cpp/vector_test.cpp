#include "stl_test.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

template <typename T>

void print_vector(vector<T>& vec) {
	//전체 벡터 출력

	//for (typename vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++)
	for(auto itr = vec.begin(); itr != vec.end(); itr++)
	{
		cout << *itr << endl;
	}
}

void vector_test() {
	vector <int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

/*
	cout << "처음 벡터 상태" << endl;
	print_vector(vec);
	cout << "------------------------------"<< endl;

	vec.insert(vec.begin() + 2, 15);
	print_vector(vec);

	cout << "----------------------------" << endl;

	vec.erase(vec.begin() + 3);
	print_vector(vec);
	*/

	auto itr = vec.rbegin();
	auto end_itr = vec.rend();

	//print_vector(vec);

    system_clock::time_point start = system_clock::now();

    /*
    for (; itr != vec.end(); itr++) {
      if (*itr == 20) {
        vec.erase(itr);
        itr = vec.begin();
      }
    }
    */

	for(; itr != end_itr; itr ++) {
		cout << *itr << endl;
		/*
		if(*itr == 20) {
			vec.erase(itr);
		}*/
	}

    system_clock::time_point end = system_clock::now();

    duration<double, milli> sec = duration_cast<duration<double, milli>> (end - start);

    //cout << sec.count() << endl;



	cout <<"값이 20인 원소 삭제" <<endl;
	print_vector(vec);

}
