#include <iostream>
#include "my_Queue.h"
using namespace std;

int main() {
    int max_tickets;
    cout << "Enter the maximum number of pending tickets allowed: ";
    cin >> max_tickets;

    my_Queue<int> ticketQueue(max_tickets);

    while (true) {
        cout << "\nCustomer Support Ticket System\n";
        cout << "1. Add a new ticket\n";
        cout << "2. Resolve the next ticket\n";
        cout << "3. View the next ticket to resolve\n";
        cout << "4. Display all pending tickets\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {  // Enqueue
            if (ticketQueue.isFull()) {
                cout << "Queue is full! Cannot add more tickets.\n";
                break;
            }
            int ticket_id;
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket_id;
            if (ticket_id < 1000 || ticket_id > 9999) {
                cout << "Invalid Ticket ID! Must be 4 digits.\n";
                break;
            }
            ticketQueue.enQueue(ticket_id);
            cout << "Ticket ID " << ticket_id << " added to the queue.\n";
            break;
        }
        case 2: {  // Dequeue
            if (ticketQueue.isEmpty()) {
                cout << "No tickets to resolve!\n";
                break;
            }
            int resolved_ticket = ticketQueue.deQueue();
            cout << "Resolved Ticket ID: " << resolved_ticket << endl;
            break;
        }
        case 3: {  // Front
            if (ticketQueue.isEmpty()) {
                cout << "No pending tickets!\n";
                break;
            }
            cout << "Next Ticket to Resolve: " << ticketQueue.Front() << endl;
            break;
        }
        case 4:  // Display
            ticketQueue.display();
            break;
        case 5:  // Exit
            cout << "Exiting system. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}