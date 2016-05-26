#ifndef A_H
#define A_H
 
class B;	//forward declaration
 
class A {
public:
	B* b;
};
#endif //A_H


#ifndef B_H
#define B_H
 
class A;	//forward declaration
 
class B {
public:
	A* a;
};
#endif //B_H


#include "a.h"
#include "b.h"
 
int main() {
	A a;
	B b;
	a.b = &b;
	b.a = &a;
}
