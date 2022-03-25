#include "GUI/GUI.h"

using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
	private:
	// data:
	Open_polyline lines;
	
	// widgets:
	Button next_button; // add (next_x,next_y) to lines
	Button quit_button; // end program
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button menu_button;
	Menu style_menu;
	Button style_button;
	
	void change(Color c) { lines.set_color(c); }
	void change_s(Line_style s) { lines.set_style(s); }
	
	void hide_menu() { color_menu.hide(); menu_button.show(); }
	void hide_style() { style_menu.hide(); style_button.show(); }
	
	// actions invoked by callbacks:
	void red_pressed() { change(Color::red); hide_menu(); }
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }
	void menu_pressed() { menu_button.hide(); color_menu.show(); }
	
	void dash_pressed() { change_s(Line_style::dash); hide_style(); }
	void dot_pressed() { change_s(Line_style::dot); hide_style(); }
	void style_pressed() { style_button.hide(); style_menu.show(); }
	
	void next();
	void quit();
	

};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    : Window{xy, w, h, title},
    next_button{Point{x_max() - 150, 0}, 70, 20, "Next point",
        [](Address, Address pw) { reference_to<Lines_window>(pw).next(); }},
    quit_button{Point{x_max() - 70, 0}, 70, 20, "Quit",
        [](Address, Address pw) { reference_to<Lines_window>(pw).quit(); }},
    next_x{Point{x_max() - 310, 0}, 50, 20, "next x:"},
    next_y{Point{x_max() - 210, 0}, 50, 20, "next y:"},
    xy_out{Point{100, 0}, 100, 20, "current (x,y):"},
    color_menu{Point{x_max() - 70, 30}, 70, 20, Menu::vertical, "color"},
    menu_button{Point{x_max() - 80, 30}, 80, 20, "color menu",
        [](Address, Address pw) { reference_to<Lines_window>(pw).menu_pressed(); }},
    style_menu{Point{10, 30}, 70, 20, Menu::vertical, "style"},
    style_button{Point{0, 30}, 80, 20, "style menu",
        [](Address, Address pw) { reference_to<Lines_window>(pw).style_pressed(); }}
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");
	color_menu.attach(new Button{Point{0,0},0,0,"red",
		[](Address, Address pw) { reference_to<Lines_window>(pw).red_pressed();}});
	color_menu.attach(new Button{Point{0,0},0,0,"blue",
		[](Address, Address pw) { reference_to<Lines_window>(pw).blue_pressed();}});
	color_menu.attach(new Button{Point{0,0},0,0,"black",
		[](Address, Address pw) { reference_to<Lines_window>(pw).black_pressed();}});
	style_menu.attach(new Button{Point{0, 0}, 0, 0, "dash",
			[](Address, Address pw) { reference_to<Lines_window>(pw).dash_pressed();}});
	style_menu.attach(new Button{Point{0, 0}, 0, 0, "dot",
			[](Address, Address pw) { reference_to<Lines_window>(pw).dot_pressed();}});
	attach(color_menu);
	color_menu.hide();
	attach(menu_button);
	attach(style_menu);
	style_menu.hide();
	attach(style_button);
	attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    
    xy_out.put(ss.str());

    redraw();
}


int main()
try {
	Lines_window win {Point{100,100},600,400,"lines"};
	return gui_main();
}catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
