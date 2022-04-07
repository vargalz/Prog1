#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

template<typename C>
void print(const C& c){
	for(auto& i:c){cout<<i<<' ';}
	cout<<endl;
}

template<typename C>
void inc(C& c, int n){
	for(auto& i:c){
		i+=n;
	}
}

template<typename Iter1, typename Iter2>
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p != e1; ++p){
		*f2++ =*p; //először = aztán ++
		
	}
	return f2;
}

int main()
try {

	constexpr int size=10; 
	
	int arr[size];
	for(int i=0;i<size;i++)arr[i]=i;
	cout<<"arr"<<endl;
	print(arr);
	
	array<int,size> ai;
	copy(arr,arr+size,ai.begin());
	cout<<"ai"<<endl;
	print(ai);
	
	vector<int> vi(size);
	copy(arr,arr+size,vi.begin());
	cout<<"vi"<<endl;
	print(vi);
	
	list<int> li(size);
	copy(arr,arr+size,li.begin());
	cout<<"li"<<endl;
	print(li);
	
	array<int, size>ai2=ai;
	vector<int>vi2=vi;
	list<int>li2=li;
	
	cout<<"ai2, vi2, li2:"<<endl;
	print(ai2);
	print(vi2);
	print(li2);
	
	inc(ai2, 2);
	inc(vi2, 3);
	inc(li2, 5);
	
	cout<<"inc:"<<endl;
	print(ai2);
	print(vi2);
	print(li2);
	
	orai_copy(ai2.begin(),ai2.end(),vi2.begin());
	orai_copy(li2.begin(),li2.end(),ai2.begin());
	
	cout<<"orai_copy ai2, vi2, li2:"<<endl;
	print(ai2);
	print(vi2);
	print(li2);
	
	vector<int>::iterator vit;
	vit = find(vi2.begin(), vi2.end(), 3);
	if(vit!=vi2.end()){
		cout<<"Found at: "<<distance(vi2.begin(),vit)<<endl;
	}else {
		cout<<"Not found"<<endl;
	}
	
	list<int>::iterator lit;
	lit = find(li2.begin(), li2.end(), 27);
	if(lit!=li2.end()){
		cout<<"Found at: "<<distance(li2.begin(),lit)<<endl;
	}else {
		cout<<"Not found"<<endl;
	}
	

	
}
catch (exception& e) {
		cerr<<"exception: "<<e.what()<<endl;
		return 1;
	} catch (...) {
		cerr<<"exception\n";
		return 2;
	}
