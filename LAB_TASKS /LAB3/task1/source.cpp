
#include "derivedclass.h"

int main() {
    List<int>* ptr = new Work<int>(10, 0);  

    cout << "ading element at first  "<<endl;
    ptr->addElementAtFirstIndex(5);
    ptr->display();
    cout << "ading at last " << endl;
    ptr->addElementAtLastIndex(10);
    ptr->display();
    cout << "removing from end  " << endl;
    ptr->removeElementFromEnd(); 
    ptr->display();
    cout << "removing from start  " << endl;
    ptr->  removeElementFromStart();
    ptr->display();
    delete ptr;  // Clean up memory

    return 0;
}
