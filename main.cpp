#include <iostream>

class Parent{
	public :
    virtual void show() = 0;

    // void show(int a){
    //     std::cout << "CCC" << std::endl;
    // }
};

class Child : public Parent{
	public :
    void show(){
        std::cout << "BBB" << std::endl;
    }
};

int main(){
    Parent * c = new Child;
    c->show();
    // c->show(10); // Error!
}