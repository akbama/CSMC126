/*Alyanna Krista V. Bama
2020-09745

sample code*/

#include <iostream>
#include <cstdlib>

using namespace std;
/*Initialize a queue that can hold 2 integers*/
struct node {
	int data;
	int data1;
	struct node * next;
}*front=NULL, *rear = NULL;
/*Adding new order to the back of the queue*/
void enqueue (int studentCode, int orderCode) {
	struct node * newnode = (struct node*)malloc(sizeof(struct node));
	newnode -> data = studentCode;
	newnode -> data1 = orderCode;
	newnode -> next = NULL;
	
	if (front == NULL && rear == NULL){
		front = rear = newnode;
	}
	else {
		rear -> next = newnode;
		rear = newnode;
	}
}
/*Serving the current order at the top of the queue*/
void dequeue () {
	if (front == NULL){
		cout << "\nThe QUEUE is EMPTY. No orders to serve" << endl;
		return; 
	}
	struct node * temp = front;
	cout << "\nNow serving order code " << temp -> data1 << " to customer with student code "<< temp -> data <<"."<< endl;
	if (front -> next == NULL){
		front = NULL;
		rear = NULL;
		return;
	}
	(front) = (front) -> next;
	free (temp);
}
/*Returns what is the next order on the queue or the one at the top*/
void Front () {
	if (front == NULL) {
		cout << "\nThe QUEUE is EMPTY. No order to serve." << endl; 
		return;
	}
	cout << "\nNext order: order code " << front -> data1 << " of customer with student code " << front -> data << "." << endl;
}
/*Evaluates whether the queue is empty or not*/
bool Empty() {
	if (front == NULL) {
	return true;
	}
	return false;
}
/*Displays the Menu*/
void Menu () {
	cout << "--------------------------------------" << endl;
	cout << "|  Genshin Impact Merchandise Menu:  |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "|  [1] Fall in Line                  |" << endl;
	cout << "|  [2] Serve Order                   |" << endl;
	cout << "|  [3] Next Order                    |" << endl;
	cout << "|  [4] Closing Time                  |" << endl;
	cout << "|  [5] Exit                          |" << endl;
	cout << "--------------------------------------" << endl;
}

int main() {
	int menuChoice, studentCode, orderCode;
	char goBack;
	
	do {
		Menu();
		/*Evaluates if the input for choice is correct*/
		do {
			cout << "Choice: ";
			cin >> menuChoice;
			
			if (menuChoice>5||menuChoice<0){
				cout << "\nInvalid Input. Please try again\n" << endl;
			}
		} while (menuChoice > 5||menuChoice < 0);
		/*Adds order to the back of the queue*/
		if (menuChoice == 1){
			cout << "\nStudent Code: ";
			cin >> studentCode;
			cout << "Order Code: ";
			cin >> orderCode;
			
			enqueue (studentCode, orderCode);
		}
		/*Serve the order at the top of the queue*/
		if (menuChoice == 2){
			dequeue ();
		}
		/*Check what order is at the top of the queue*/
		if (menuChoice == 3){
			Front ();
		}
		/*Serve all the order in the queue*/
		if (menuChoice == 4){
			if (Empty () == true){
				cout << "\nThe QUEUE is EMPTY. No order to serve" << endl;
			}
			else {
				while (Empty () == false){
					dequeue ();
				}
				cout << "\nAll orders have been served. " << endl;
			}
		}
		/*Exit*/
		if (menuChoice == 5){
			exit (0);
		}
		/*Go back to Menu*/
		do {
			cout << "\nPress [M] to go back to the Menu: ";
			cin >> goBack;
			if (!(goBack == 'M')){
				cout << "Invalid Input. Please try again\n" << endl;
			}
		} while (!(goBack == 'M'));
		system ("cls");
	} while (goBack == 'M');
}
