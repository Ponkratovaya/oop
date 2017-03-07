#include <iostream>
using namespace std;
	class A {
    public:
       int a;
       int b;
	   int c;
	public:
		void An(int e,int d) {
			a= e;
			b=d;
			fun();
		}
		void fun(){
			a++;
			a*=b;
			c=a-b;
		}
		int get(){
			return c;
		}
};
int main() {
	int a,b;
	cin>>a;
	cin>>b;
	A m;
	m.An(a,b);
	cout<<m.get();
    return 0;
}
