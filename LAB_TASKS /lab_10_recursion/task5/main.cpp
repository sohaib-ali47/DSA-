



# include "lab_10_l.s.h"




int main() {

	linked_list <int> l1;

	l1.add_at_tail(1);
	l1.add_at_tail(2);
	l1.add_at_tail(3);
	l1.add_at_head(4);
	l1.display();
	cout << "after ddeleting " << endl;
	l1.delete_by_value(4);
	l1.delete_at_position(3);
	l1.display();


	return 0;
}
