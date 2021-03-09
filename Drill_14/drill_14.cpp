#include "std_lib_facilities.h"

class B1 {
public:
	virtual void vf() {cout << "B1::vf\n"; }
	void f() { std::cout << "B1::f\n"; }
	virtual void pvf(){};
};

class D1 : public B1 {
public:	
	void vf() override {cout << "D1::vf\n"; }
	void f() { std::cout << "D1::f\n"; }
	
};

class D2 : public D1 {
public:	
	void pvf() override {cout<<"D2::pvf\n"; }
};

class B2 {
public:	
	virtual void pvf(){cout<<"B2::pvf\n";}
};

class D21 : public B2 {
public:	
	void pvf() override {cout<<data<<std::endl;}
private:	
	string data = "D21::pvf";
};

class D22 : public B2 {
public:
	void pvf() override {cout<<"D"<<data2<<"::pvf\n";}
private: 
	int data2 = 22;
};


void f(B2& b2_ref){
	b2_ref.pvf();

}
int main()
try{
	B1 b1;
	D1 d1;
	B1& bref = d1;
	D2 d2;

	b1.vf();
	b1.f();
	cout<<endl;

	d1.vf();
	d1.f();
	cout<<endl;

	bref.vf();
	bref.f();
	cout<<endl;
	
	d2.vf();
	d2.f();
	d2.pvf();
	cout<<endl;	

	D21 d21;
	D22 d22;

	f(d21);
	f(d22);

	return 0;
}catch(exception& e){
	cout<<e.what()<<endl;
}catch(...){
	cout<<"Something is wrong"<<endl;
}