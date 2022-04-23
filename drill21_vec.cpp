#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

struct Item {
	string name;
    	int iid;
    	double value;
};

istream& operator>>(istream& is, Item& it){
	string s;
    	int i;
    	double d;
    	is >> s >> i >> d;
    	Item item {s, i, d};
    	it = item;
    	return is;
}

template<typename C>
void print(const C& c, char sep =' '){	
	for(const auto& elem: c){
		cout<< elem << sep;
	}
	
	cout << std::endl;
}

ostream& operator<<(ostream& os, const Item& it)
{
	return os << it.name << '\t'<< it.iid << '\t'<< it.value <<'\n';
}

class Cmp_by_name {
    	string name;
public:
    	Cmp_by_name(const string& nn) : name{nn} { }
    	bool operator()(const Item& x) const { return x.name == name; }
};

class Cmp_by_iid {
    	int iid;
public:
    	Cmp_by_iid(int id) : iid{id} { }
    	bool operator()(const Item& x) const { return x.iid == iid; }
};


int main()
try{

	const string iname {"items.txt"};
	ifstream ifs {iname};
	if(!ifs) throw runtime_error("Could not read file: "+ iname);

	vector<Item> vi;
    	for (Item i; ifs >> i;){
        	vi.push_back(i);
        }
        
	list<Item> li(vi.size());
        copy(vi.begin(),vi.end(),li.begin());
        
        cout<<"vi"<<'\n';
        print(vi);
        
	cout<<"sort by name"<<'\n';
    	sort(vi.begin(), vi.end(),
            	[](const Item& a, const Item& b) { return a.name < b.name;});
        print(vi);

	cout<<"sort by iid"<<'\n';
    	sort(vi.begin(), vi.end(),
            	[](const Item& a, const Item& b) { return a.iid < b.iid;});
        print(vi);
	
	cout<<"sort by value"<<'\n';
    	sort(vi.begin(), vi.end(),
            	[](const Item& a, const Item& b) { return a.value > b.value;});
        print(vi);
                       
        vi.insert(vi.end(),Item{"horse shoe",99,12.34});
        vi.insert(vi.end(),Item{"Canon S400",9988,499.55});
        
        cout<<"insert"<<'\n';
        print(vi);
        
        vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_name("horse shoe")));
        vi.erase(std::find_if(vi.begin(), vi.end(), Cmp_by_name("w")));
        cout<<"erase by name"<<'\n';
        print(vi);
        
	vi.erase(std::find_if(vi.begin(), vi.end(), Cmp_by_iid(3)));
    	vi.erase(std::find_if(vi.begin(), vi.end(), Cmp_by_iid(1)));    
    	cout<<"erase by iid"<<'\n';
	print(vi);
	
	//listára
	cout<<"li"<<'\n';
        print(li);
        
        cout<<"sort by name"<<'\n';
    	li.sort([](const Item& a, const Item& b) { return a.name < b.name;});
        print(li);

	cout<<"sort by iid"<<'\n';
    	li.sort([](const Item& a, const Item& b) { return a.iid < b.iid;});
        print(li);
	
	cout<<"sort by value"<<'\n';
    	li.sort([](const Item& a, const Item& b) { return a.value > b.value;});
        print(li);
                       
        li.insert(li.end(),Item{"horse shoe",99,12.34});
        li.insert(li.end(),Item{"Canon S400",9988,499.55});
        
        cout<<"insert"<<'\n';
        print(li);
        
        li.erase(find_if(li.begin(), li.end(), Cmp_by_name("horse shoe")));
        li.erase(std::find_if(li.begin(), li.end(), Cmp_by_name("w")));
        cout<<"erase by name"<<'\n';
        print(li);
        
	li.erase(std::find_if(li.begin(), li.end(), Cmp_by_iid(3)));
    	li.erase(std::find_if(li.begin(), li.end(), Cmp_by_iid(1)));    
    	cout<<"erase by iid"<<'\n';
	print(li); 

	

} catch(std::exception& e){
	std::cerr << e.what()<<'\n';
	return 1;
} catch (...){
	std::cerr << "Unknown error"<<'\n';
	return 2;
}
