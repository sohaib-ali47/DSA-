# include <iostream>
using namespace std;
# include <string>

bool check(string str, int start , int size)
{

	if (size == start || size+1 ==start)
	{
		//means that they are on the center 
		return 1;
	}
	/*if (str[size - 1] != str[start - 1])
	{
		return 0;
	}*/


	if (str[start ] == str[size - 1])
	{
		return check(str, start + 1, size - 1);
	}
	else
	{
		return 0;
	}

}
int get_size(string str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
int main() {

	string str = "wolklow";
	int size = get_size(str);
	int start = 0;

	if (check(str, start, size))
	{
		cout<< str  << " is a palindrome" << endl;
	}
	else
	{
		cout <<  str << " ios not a palindrom " << endl ;
	}
	

		return 0;
}