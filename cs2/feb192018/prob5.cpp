#include <iostream>
#include <string>
using namespace std;

class zipCode{

	private:

	string container;
	string zip[5];
	string postCode[5];
	string array[5];
	string array2[5];
	string codes[10];
	void divideArrayP(string post)
		{
		array[0] = post.substr(1,5);
		array[1] = post.substr(6,10);
		array[2] = post.substr(11,15);
		array[3] = post.substr(16,20);
		array[4] = post.substr(21,25);
		}
	void divideArrayZ(string zipC)
		{
		array2[0] = zipC.substr(0,0);
		array2[1] = zipC.substr(1,1);
		array2[2] = zipC.substr(2,2);
		array2[3] = zipC.substr(3,3);
		array2[4] = zipC.substr(4,4);
		}

	void decodezip()
		{
		string zipC;
	        cout << "input your zipcode: ";
	        cin >> zipC;

		divideArrayZ(zipC);
		for(int i = 0; i < 10; i++)
			{
			for(int j = 0; j < 5; j++)
				{
				container = to_string(i);
				if(array2[j] == container)
					postCode[j] = codes[i];
				}
			}
		cout << endl << "your POSTNET tracking code is: " << "1";
		for(int x = 0; x < 5; x++)
			{
			cout << postCode[x];
			}
		cout << "1" << endl;
		}

	void decodepost()
		{
		string postC;
	        cout << "input a POSTNET tracking code: ";
	        cin >> postC;

		divideArrayP(postC);
		for(int i = 0; i<5; i++)
			{
			for(int j = 0; j<10; j++)
				{
				if(array[i] == codes[j])
					{
					container = to_string(j);
					zip[i] = container;
					}
				}
			}
		cout << endl << "your zip is: " << zip << endl;
		}
	public:
		zipCode(string zipC, int i)
		{
		codes[0] = "11000";
		codes[1] = "00011";
		codes[2] = "00101";
		codes[3] = "00110";
		codes[4] = "01001";
		codes[5] = "01010";
		codes[6] = "01100";
		codes[7] = "10001";
		codes[8] = "10010";
		codes[9] = "10100";

		decodezip(); 
		}

	zipCode(string postC)
		{
		codes[0] = "11000";
       		codes[1] = "00011";
        	codes[2] = "00101";
     		codes[3] = "00110";
                codes[4] = "01001";
                codes[5] = "01010";
                codes[6] = "01100";
                codes[7] = "10001";
                codes[8] = "10010";
                codes[9] = "10100";

        	decodepost();
		}
	};

int main()
	{
	zipCode one("s");
	zipCode two("s",1);
	return 0;
	}
