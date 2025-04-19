
# include "myStack.h"

int menu1(myStack <int> & obj1, myStack <int>& obj2,int & MAX_size);
void menu2(myStack <int>& obj1, myStack <int>& obj2, int& MAX_size);


int main() {

	int size = 0;
	int MAX_size = 8;
	myStack <int> obj1 (MAX_size);    // first stack for enqueue 
	myStack <int> obj2 (MAX_size);    //second stack to dequeue 


	size =menu1(obj1 ,obj2 , MAX_size);
	 int i = 0;
	 while (i < size)
	 {
		 obj2.push(obj1.pop());
		 i++;
	 }
	 menu2(obj1, obj2, MAX_size);
	


	return 0;
}


void copy_stack(myStack <int>& obj1, myStack <int>& obj2,int & MAX_size)
{
	


}

int menu1(myStack <int>& obj1, myStack <int>& obj2, int & MAX_size)
{
  
	bool stop = false;
	int choice, element;
	int size = 0;

	cout << "==================INSTRUCTIONS============" <<endl<< "first use the enqueue commands then other commands " << endl;
	while (!stop)
	{

	
		cout << "press 1 to enqueue an element from queue" << endl
			<< "press 99 to proceed on the more commands like deque/front/display  :" << endl;
		cin >> choice;
	
		if (choice == 1)
		{
			size++;
			cout << "enter the element to enqueue :" << endl;
			cin >> element;
			obj1.push(element);

		//	obj2.push(obj1.pop());

		}
		
		else if (choice == 99)
		{
			stop = true;
		}

	}
	return size;


}

void menu2(myStack <int>& obj1, myStack <int>& obj2, int& MAX_size)
{

	bool stop = false;
	int choice =0, element=0;
	int size = 0;


	while (!stop)
	{

		cout << "press 2 to dequeue an element from queue " << endl
			<< "press 3 to display the top element from queue " << endl
			<< "press 4 to display all the element from queue " << endl
			<< "press 99 to exit  :" << endl;
		cin >> choice;

		
		if (choice == 2)
		{


			cout << obj2.pop() << " element has dequeued " << endl;
			size--;

		}
		else if (choice == 3)
		{
			obj2.push(obj1.pop());
			cout << obj2.top() << "is the element at the front " << endl;
		}
		else if (choice == 4)
		{

			cout << "displaying all the elements in the queue " << endl;
			obj2.display();
		}
		else if (choice == 99)
		{
			stop = true;
		}
	}


}
