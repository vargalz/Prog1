#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <numeric>


template<typename K, typename V>
void print(const std::map<K, V>& m){
	//for(auto& i : m){
	for(std::pair<K,V> i : m){
		std::cout<<i.first<<'\t'<<i.second<<std::endl;
	}
}

void read_map(std::map<std::string, int>& m){
	std::string s;
	int i=0;
	while(m.size()<10){
		std::cin >> s >> i;
		m[s]=i;
		//m.insert(std::make_pair(s,i));
	}
}

int main()
try{
	std::map<std::string, int> msi;
	msi["a"]=1;
	msi["b"]=3;
	msi["ab"]=7;
	msi["kjkl"]=98;
	msi["lk"]=76;
	msi["redsr"]=61;
	msi["efh"]=60;
	msi["xc"]=23;
	msi["qwewr"]=11;
	msi["ads"]=1;
	
	std::cout<<"MSI map: "<<std::endl;
	print(msi);
	
	msi.erase("a");
	std::cout<<std::endl<<"Egy elem törlése után"<<std::endl;
	print(msi);
	
	msi.erase(msi.begin(),msi.end());
	std::cout<<std::endl<<"Teljes törlés után"<<std::endl;
	print(msi);
	
	std::cout<<std::endl<<"Adj meg 10 párt"<<std::endl;
	read_map(msi);
	std::cout<<std::endl<<"Beolvasás után"<<std::endl;
	print(msi);
	
	int total= std::accumulate(msi.begin(), msi.end(), 0,
			[](int sum, const std::pair<std::string, int>& p)
			{return sum += p.second;}
			);
	
	int total2=0;
	for(std::pair<std::string, int> a :msi){
		total2+=a.second;
	}
	
	std::cout<<"Sum of ints: "<<total<<'\t'<<total2<<std::endl;
	
	std::map<int, std::string> mis;
	for(std::pair<std::string, int> i :msi){
		mis[i.second]=i.first;
	}
	
	std::cout<<std::endl<<"mis map: "<<std::endl;
	print(mis);

}catch(std::exception& e){
	std::cerr<<"Exception: "<<e.what()<<'\n';
	return 1;
} catch(...){
	std::cerr<<"Unknown exception"<<'\n';
	return 2;
}

