#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
	try{
		Point t1{300,50};
		Simple_window win{t1,1000,800,"My window"};
		win.wait_for_button();
		
		int x_size=800;
		int y_size=800;
		Lines grid;
		
		for(int i=0;i<=800;i+=100)
		{
			grid.add(Point(i, 0), Point(i, y_size));
			grid.add(Point(0,i), Point(x_size, i));
		}
		win.attach(grid);
		win.wait_for_button();
		
		
		Vector_ref<Rectangle> vr;
		
		for(int i=0;i<=8;i++){
			vr.push_back(new Graph_lib::Rectangle(Point(i*100,i*100),101,101));
			vr[vr.size()-1].set_fill_color(Color::red);
			win.attach(vr[vr.size()-1]);
		}
		win.wait_for_button();
		
		
		
		//4.
		Image img1{Point(0,600),"GUI/badge.jpg"};
		win.attach(img1);
		img1.set_mask(Point(150,150),200,200);
		
		Image img2{Point(200,600),"GUI/badge.jpg"};
		win.attach(img2);
		img2.set_mask(Point(150,150),200,200);
		
		Image img3{Point(600,0),"GUI/badge.jpg"};
		win.attach(img3);
		img3.set_mask(Point(150,150),200,200);
		
		win.wait_for_button();
		
		
		//5.
		Image img{Point(0,0),"GUI/badge.jpg"};
		win.attach(img);
		img.set_mask(Point(200,200),100,100);
		win.wait_for_button();
		
		while(true)
		{
			for(int i=1;i<=7;i++){
				img.move(100,0);
				win.wait_for_button();
			}
		
			for(int i=1;i<=7;i++){
				img.move(0,100);
				win.wait_for_button();
			}
		
			for(int i=1;i<=7;i++){
				img.move(-100,0);
				win.wait_for_button();
			}
			
			for(int i=1;i<=7;i++){
				img.move(0,-100);
				win.wait_for_button();
			}
		}

	}catch(exception& e){
		cerr <<"exception: " << e.what() << '\n';
		return 1;
	}catch(...){
		cerr <<"error\n";
		return 2;
	}
}
