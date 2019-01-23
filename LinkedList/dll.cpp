#include<iostream>
using namespace std;
struct node {
	int val;
	node *next;
	node *prev;
};
class list {
private:
	node *head;
	node *tail;
public:
	list() {
		head = NULL;
		tail = NULL;
	}
	void createnode(int val) {
		node *temp = new node;
		temp->val = val;
		temp->next = NULL;
		temp->prev = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}

	void displaynode()
	{
		node *temp = new node;
		temp = head;
		int count = 0;
		while (temp != NULL)
		{
			cout << temp->val << "\t";
			temp = temp->next;
			count = count + 1;
		}
		cout << "\nLenght of List is " << count;
	}

	void insertnode(int val, int pos)
	{
		node *temp = new node;
		temp->val = val;
		temp->next = NULL;
		temp->prev = NULL;

		node *curr = new node;
		curr = head;

		node *pre = new node;

		if (pos == 1)
		{
			//cout << "Insert at the Start\n";
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
		else if (pos == 0)
		{
			//cout << "Insert at end\n";
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		else
		{
			for (int i = 1; i < pos; i++)
			{
				pre = curr;
				curr = curr->next;
			}
			pre->next = temp;
			temp->prev = pre;
			temp->next = curr;
			curr->prev = temp;
		}
	}

	void deletenode(int pos)
	{
		node * temp = new node;
		node *curr = new node;
		node *pre = new node;

		if (pos == 1)
		{
			curr = head;
			head = head->next;
			head->prev = NULL;
			delete curr;
		}
		else if (pos == 0)
		{
			curr = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete curr;
		}
		else
		{
			curr = head;
			for (int i = 1; i < pos; i++)
			{
				pre = curr;
				curr = curr->next;
			}
			pre->next = curr->next;
			curr->next->prev = pre;
			delete curr;
		}
	}
	void countnode(int v)
	{
		int count = 0;
		node *temp = new node;
		temp = head;
		while (temp->next != NULL)
		{
			if (temp->val == v)
				count = count + 1;

			temp = temp->next;
		}
		cout << "Number of nodes with Value " << v << " is " << count << ". \n";
	}
};

int main()
{
	cout << "Double Linked List";
	list obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(50);
	obj.createnode(50);
	cout << "\n--------------------------------------------------\n";
	cout << "---------------Displaying All nodes---------------";
	cout << "\n--------------------------------------------------\n";
	obj.displaynode();
	cout << "\n--------------------------------------------------\n";
	cout << "-----------------Inserting At End-----------------";
	cout << "\n--------------------------------------------------\n";
	obj.insertnode(55, 0);
	obj.displaynode();
	cout << "\n--------------------------------------------------\n";
	cout << "----------------Inserting At Start----------------";
	cout << "\n--------------------------------------------------\n";
	obj.insertnode(50, 1);
	obj.displaynode();
	cout << "\n--------------------------------------------------\n";
	cout << "-------------Inserting At Particular--------------";
	cout << "\n--------------------------------------------------\n";
	obj.insertnode(50, 5);
	obj.insertnode(50, 6);
	obj.displaynode();
	cout << "\n--------------------------------------------------\n";
	cout << "-----Counting number of nodes with same Value -----";
	cout << "\n--------------------------------------------------\n";
	obj.countnode(50);
	obj.displaynode();
	cout << "\n--------------------------------------------------\n";
	cout << "----------------Deleting At Start-----------------";
	cout << "\n--------------------------------------------------\n";
	obj.deletenode(1);
	obj.displaynode();
	cout << "\n--------------------------------------------------\n";
	cout << "-----------------Deleing At End-------------------";
	cout << "\n--------------------------------------------------\n";
	obj.deletenode(0);
	obj.displaynode();
	cout << "\n--------------------------------------------------\n";
	cout << "--------------Deleting At Particular--------------";
	cout << "\n--------------------------------------------------\n";
	obj.deletenode(4);
	obj.displaynode();
	cout << "\n--------------------------------------------------\n";
	system("pause");
	return 0;

}
