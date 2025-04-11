# include <iostream>
# include <stack>
# include <string>

using namespace std;


class car_parking {

private: 
	
	string car_no  ;  
	

public: 
// default constructor 

	car_parking()
	{
		car_no = "unknown";
	}
	
	// adding a car 
	void add_Car(const string no, stack <string> & mystack)
	{
		int size = mystack.size();
		if (size < 8)
		{
			mystack.push(no);
		}
		else
		{
			cout << "the car parking is already full" << endl; 
		}
	}
		
	void show_Cars( stack <string > & mystack)
	{

		string temp[8];
		int size = mystack.size();
		int count = 0; 
		int i = 0; 

		while (!mystack.empty())
		{

			temp[i] = mystack.top();
			mystack.pop();
			count++; 
			i++; 
		}
		cout << "DISPLAYING CARS :" << endl; 
		for (int i = 0; i < count; i++)
		{
			cout << "car " << i + 1 << " : " << temp[i] << endl;
			mystack.push(temp[i]);
		}
			

	}
	
	
	void exit_car(string car,  stack <string> & mystack)
	{
	
		int size = mystack.size();

		string *temp;
		temp = new string[size];
		int i = 0; 
		int count = 0; 
		while (!mystack.empty())
		{


			temp[i] = mystack.top();
			mystack.pop();
			count++;

		}

		for (int i = 0; i < count; i++)
		{
		     
			if (temp[i] != car)
			{
				mystack.push(temp[i]);
			}
			else
			{

			}
		}

	}



};



int main()
{
	
	stack <string> mystack;
	car_parking c1; 


	cout << "=======PAKING MANAGMENT SYSTEM ===========" << endl; 
	bool check = true; 

	while (check == true)
	{

		cout << "press 1 to enter a car :"<<endl;
		cout << "press 2 to display all cars :"<<endl;
		cout << "press 3 to exit a car with its number  :"<<endl;
		cout << "press 66 to exit the system :"<<endl;
		int input = 0;
			cin >> input; 
			if (input == 1)
			{
				cout << "enter car number : etc (leg-17-909) : ";
				string n; 
				cin >> n; 
				c1.add_Car( n, mystack);
				
			}
			else if (input == 2)
			{
				cout << "DISPLAYING ALL CARs :" << endl;
				c1.show_Cars(mystack);

			}
			else if (input == 3)
			{
				cout << "enter a car number to exit the car from parking " << endl; 
				string car_no;
				cin >> car_no; 
				c1.exit_car(car_no,mystack);
			}
			else if (input == 66)
			{
				check = false;
				break;
			}


	}
	
	return 0;
}
