#include <iostream>
using namespace std;

int main()
{

int *pointr1 = NULL;
int *pointr2 = NULL;

pointr1 = new int[4];

*pointr1 = 9;
*(pointr1+1) = 8;
*(pointr1+2) = 7;
 pointr1[3] = 6;

pointr2 = &pointr1[3];

}
