#include <iostream>
#include <cstdlib>
using namespace std;

class SimplePair{
private:

int one;
int two;

public:
SimplePair()
{
	one = 400 + rand() % 201;
	two = 400 + rand() % 201;
}
max(SimplePair x);
SimplePair(int x, int y)
{
	one = x;
	two = y;
}
void print()
{
cout << "the pair is: \t( " << one << " , " << two << " )" << endl;
}

int min()
{
	int mini = one;
	if(two < one)
	{
	mini = two;
	}
	return mini;
}
int SimplePair ::  max(SimplePair x)
{
	int maxi = one;
        if(two > one)
        {
        maxi = two;
        }

return max;
}
};

int main()
{
	SimplePair obj1;
	obj1.print();
	obj1.min();
	max(obj1);
	SimplePair obj2(10,50);
	obj2.print();
	obj2.min();
	max(obj2);
	return 0;

}
