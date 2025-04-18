
# include "my_Queue.h"
# include <iostream>
using namespace std;


void check(my_Queue<int> & obj ) ;
int main() {

	int size=8; 
	my_Queue<int> obj(size); 


	check(obj);





	return 0;
}


void check(my_Queue<int> & obj )
{
	cout << "==================MENUE ===============" << endl << endl; 
	bool stop = false;
	int option; 
	while (!stop)
	{
		cout << "press 1 to enqueue " << endl;
		cout << "press 2 to edqueue  " << endl;
		cout << "press 3 to display all the elements :" << endl; 
		cout << "press 4 to stop :"<<endl;
		cout << "enter your choice : "; 
		
		cin >> option; 
		if (option == 1)
		{
			int j; cin >> j;
			obj.enQueue(j);
		}
		else if (option == 2)
		{
			cout << obj.deQueue() << endl;
		}
		else if (option == 3)
		{
			obj.display();
		}
		else if (option == 4)
		{
			stop = true;
		}
		
	}

}
