#include <iostream>
using namespace std;

class student
{
	
	private:
		string name;
		int id;
	public:
		string getName(){
		return name;
		}
		void setName(string x){
		name = x;
		}
};

int main()
{
	student bob;
	bob.setName("bob");
	cout << bob.getName() << endl;
	return 0;
}
