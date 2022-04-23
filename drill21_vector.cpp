#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

class Less_than {
	double v;
	public:
		Less_than(double vv):v{vv}{}
		bool operator()(const double val) {return val<v;}
};

template<typename C>
void print(const C& c, char sep ='\n'){
	std::cout << "Container elements:\n";
	
	for(const auto elem: c){
		std::cout<< elem << sep;
	}
	
	std::cout << std::endl;
}

int main()
try{
	const std::string iname {"Input_float.txt"};
	std::ifstream ifs {iname};
	if(!ifs) throw std::runtime_error("Could not read file: "+ iname);
	
	std::vector<double> vd;
	for(double d; ifs >> d;){
		vd.push_back(d);
	}
	std::cout<<"vd"<< '\n';
	print(vd);
	
	std::vector<int> vi(vd.size());
	/*for(auto& d: vd){
		vi.push_back(d);
	}*/
	std::copy(vd.begin(), vd.end(), vi.begin());
	std::cout<<"vi"<< '\n';
	print(vi);
	
	std::cout<<"vd-vi párok:"<< '\n';
	
	for(int i=0; i<vd.size(); i++){
		std::cout<< vd[i] <<'\t' << vi[i] << '\n';
	}
	
	std::cout<<"sum:"<< '\n';
	
	double sum_vd= std::accumulate(vd.begin(),vd.end(),0.0);
	std::cout<< sum_vd<<'\n';
	
	double sum_vi =std::accumulate(vi.begin(),vi.end(),0.0);
	std::cout<< sum_vi<<'\n';
	
	double diff_sum = std::inner_product(vd.begin(),vd.end(),vi.begin(),0.0,std::plus<double>(),
				std::minus<double>());
	std::cout<<"diff: "<< sum_vd-sum_vi<<" "<<diff_sum<<std::endl;
	
	std::cout<<"reverse" << '\n';
	std::reverse(vd.begin(), vd.end());
	print(vd);
	
	double vd_mean = sum_vd / vd.size();
	std::cout <<"Mean value of vd: "<<vd_mean<<std::endl;
	
	std::vector<double> vd2(vd.size());
	
	auto it = std::copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(vd_mean));
	vd2.resize(std::distance(vd2.begin(), it));
	std::cout<<"vd2"<< '\n';
	print(vd2);
	
	std::cout<<"vd sort"<< '\n';
	std::sort(vd.begin(), vd.end());
	print(vd);
	
	
	
} catch(std::exception& e){
	std::cerr << e.what()<<'\n';
	return 1;
} catch (...){
	std::cerr << "Unknown error"<<'\n';
	return 2;
}

