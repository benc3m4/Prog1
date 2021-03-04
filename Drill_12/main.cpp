/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one (double) {return 1;}

double square(double x) {return x*x;}


int main()
try{ 
   using namespace Graph_lib;

   Point tl{100,100};
   
   int xmax = 1280;
   int ymax = 720;
   
   int x_orig = xmax/2;
   int y_orig = ymax/2;
   
   int rmin = -11;
   int rmax = 11;
   
   int n_points = 400;
   Simple_window win {Point{100,100}, x_orig, y_orig, "My window"};
	
   Point origo {x_orig, y_orig};
   
   int xlength = xmax -40;
   int ylength = ymax -40;
   
   int xscale = 30, yscale = 30;
   
   Function sine {sin,0,100,Point{20,150},1000,50,50};
   Function s (one, rmin, rmax, origo, n_points, xscale , yscale);
   Function sq (square, rmin, rmax, origo, n_points, xscale , yscale);
   
   
   Axis x {Axis::x, Point{20,y_orig}, xlength, xlength/xscale, "x"};
   Axis y {Axis::y, Point{x_orig,ylength + 20}, ylength, ylength/yscale, "y"};
   Line l (Point{500,151},Point{530,151});
   

   

   Rectangle r {Point{200,200}, 100, 50};
   r.set_color(Color::blue);
   Rectangle r2 {Point{100,100},100, 30};
   
   r.set_fill_color(Color::yellow);
   //r.set_style(Line_style(Line_style::dash, 4));
   
   Text t {Point{500,200}, "Hello grapics!"};
   t.set_font(Font::times_bold);
   t.set_font_size(20);
   Text t2 {Point{130,120},"Howdy!"};
   Text t3 {Point{500,150},"MB"};


   Image ii {Point{500,500}, "badge.jpg"};
   //ii.move(1,1);
   
   Circle c {Point{600,600}, 100};
   //Ellipse e {Point{100,200},75,25};
   //e.set_color(Color::dark_red);
   Mark m {Point{100,200},'x'};

   
   
   Polygon poly;
   poly.add(Point{300,200});
   poly.add(Point{350,100});
   poly.add(Point{400,200});

   Closed_polyline poly_rect;
   poly_rect.add(Point{100,50});
   poly_rect.add(Point{200,50});
   poly_rect.add(Point{200,100});
   poly_rect.add(Point{100,100});
   poly_rect.add(Point{50,75});

   poly.set_color(Color::red);
   //poly.set_style(Line_style::dash);
   
   y.set_color(Color::cyan);
   y.label.set_color(Color::dark_red);
   poly_rect.set_style(Line_style(Line_style::dash,2));
   poly_rect.set_fill_color(Color::green);



   sine.set_color(Color::blue);

   win.attach(l);
   win.attach(t3);
   win.attach(t2);
   win.attach(r2);
   win.attach(m);
   win.attach(poly_rect);
   win.attach(poly);
   win.attach(sine);
   win.attach(c);
   win.attach(ii);
   win.attach(x);
   win.set_label("Canvas");
   win.attach(y);
   win.attach(sq);
   win.attach(r);
   win.attach(t);

   win.wait_for_button();
   
   return 0;
}
catch(exception& e){
	return 1;
}
catch(...){
	return 2;
}
