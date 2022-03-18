#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;


double one(double x){return 1;}
double slope(double x){return x/2;}
double square(double x){return x*x;}
double sloping_cos(double x){return slope(x)+cos(x);}


int main(){
	try{
	
		Point t1{100,100};
		Simple_window win{t1, 600, 400, "Function graphs"};
		
		Axis xa {Axis::x, Point{100,300}, 400, 20, "1 == 20 pixels"};
		win.attach(xa);
		Axis ya{Axis::y, Point{300,500}, 400, 20, "1 == 20 pixels"};
		win.attach(ya);
		
		Function double_one(one, -10, 11, Point{300,300}, 400, 20, 20);
		win.attach(double_one);
		
		int min=-10, max=11, l=400 ,x_scale=20, y_scale=20;
		Point p1{300,300};
		
		Function double_slope(slope, min, max, p1, l, x_scale, y_scale);
		win.attach(double_slope);
		Text slope_label{Point{double_slope.point(0).x,double_slope.point(20).y},"x/2"};
		win.attach(slope_label);
		
		Function double_square(square, min, max, p1, l, x_scale, y_scale);
		win.attach(double_square);
		
		Function cosine(cos, min, max, p1, l, x_scale, y_scale);
		cosine.set_color(Color::blue);
		win.attach(cosine);
		
		Function slope_cos(sloping_cos, min, max, p1, l, x_scale, y_scale);
		win.attach(slope_cos);
			
		
		win.wait_for_button();	
																
	}catch(exception& e){
		cerr <<"exception: " << e.what() << '\n';
		return 1;
	}catch(...){
		cerr <<"error\n";
		return 2;
	}
}
