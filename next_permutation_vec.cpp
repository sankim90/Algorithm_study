#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


template <typename T>
void print_vec(vector<T>& vec){
	for (auto itr = vec.begin(); itr != vec.end(); itr++)
		cout<<*itr<<endl;
}

void lower_test(){
	vector<int> vec, sort_vec, next_permutation_vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(7); // 1 2 2 2 2 3 5 6 7 7

	//print_vec(vec);

	//cout << "lower bound(6) " << lower_bound(vec.begin(), vec.end(), 6) - vec.begin() << endl;
	//cout << "lower bound(2) " << upper_bound(vec.begin(), vec.end(), 2) - vec.begin() << endl;

	sort_vec.push_back(1);
	sort_vec.push_back(6);
	sort_vec.push_back(3);
	sort_vec.push_back(2);
	sort_vec.push_back(1);
	sort_vec.push_back(6);
	sort_vec.push_back(9);

	//cout<<"정렬전 "<<endl;
	//print_vec(sort_vec);

	//sort(sort_vec.begin(), sort_vec.end());
	sort(sort_vec.begin(), sort_vec.end(), greater<int>());


	//cout<<"정렬후 "<<endl;
	//print_vec(sort_vec);

	next_permutation_vec.push_back(1);
	//next_permutation_vec.push_back(4);
	next_permutation_vec.push_back(2);
	next_permutation_vec.push_back(3);


	do {
		for(auto i = next_permutation_vec.begin();  i != next_permutation_vec.end(); i++)
			cout << *i <<" ";
		cout<<endl;
	}while(next_permutation(next_permutation_vec.begin(), next_permutation_vec.end()));




}
