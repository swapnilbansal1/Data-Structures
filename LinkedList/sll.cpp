#include<iostream>
using namespace std;
struct node {
	int val;
	node *next;
};
class list {
private:
	node *head;
	node * tail;
public:
	list() {
		head = NULL;
		tail = NULL;
	}
	void createnode(int val) {
		node *temp = new node;
		temp->val = val;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
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

		node *curr = new node;
		curr = head;

		node *prev = new node;

		if (pos == 1)
		{
			//cout << "Insert at the Start\n";
			temp->next = head;
			head = temp;
		}
		else if (pos == 0)
		{
			//cout << "Insert at end\n";
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}
		else
		{
			for (int i = 1; i < pos; i++)
			{
				prev = curr;
				curr = curr->next;
			}
			prev->next = temp;
			temp->next = curr;
		}
	}

	void deletenode(int pos)
	{
		node * temp = new node;
		node *curr = new node;
		node *prev = new node;
		curr = head;

		if (pos == 1)
		{
			head = head->next;
			delete curr;
		}
		else if (pos == 0)
		{
			while (curr->next != NULL)
			{
				prev = curr;
				curr = curr->next;
			}
			prev->next = NULL;
			delete curr;
		}
		else
		{
			for (int i = 1; i < pos; i++)
			{
				prev = curr;
				curr = curr->next;
			}
			prev->next = curr->next;
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

	int countnodeRec(int v)
	{
		node *temp = new node;
		temp = head;
		if (temp == NULL)
			return 0;
		else if (temp->val == v)
		{
			temp = temp->next;
			return 1 + countnodeRec(v);
		}
		else {
			temp = temp->next;
			return countnodeRec(v);
		}
	}
};

int main()
{
	cout << "Single Linked List";
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
	cout << "--Counting number of nodes with same Value ---------";
	cout << "\n--------------------------------------------------\n";
	obj.countnode(50);
	cout << "\n--------------------------------------------------\n";
	int count = obj.countnodeRec(50);
	cout << "Number of nodes with Value 50 is " << count << ". \n";
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
