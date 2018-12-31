#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

class Node{
public:
	Node* next;
	Node* prev;
	float value;
	
	Node(float v=0) {
		next = { nullptr };
		prev = { nullptr };
		value = v;
	}

	void push_back(Node* NewNode) {
		if (this->next != nullptr)
			this->next->push_back(NewNode);
		else {
			this->next = NewNode;
			NewNode->prev = this;
			NewNode->next = nullptr;
		}
	}

	void push_front(Node* NewNode) {
		NewNode->next = this->next;
		NewNode->prev = this;
		this->next = NewNode;
		NewNode->next->prev = NewNode;
	}

	void show() {
		cout << this->value << " ";
		if (this->next != nullptr)
			this->next->show();

	}

	void find_max(float& currentMax, Node*& current,int itr) {
		
		while (itr > 1) {
			if (this->value > currentMax) {
				current = this;
				currentMax = this->value;
			}
			itr--;
			this->next->find_max(currentMax, current,itr);
			
		}
	}

	int size(int n=0) {
		if (this->next != nullptr) this->next->size(++n);
		else return n;
	}

	void SortByValue() {
		int amount = this->size();
		Node* temp;
		float val=-FLT_MAX;
		while (amount-2) {
			val = -FLT_MAX;
			find_max(val, temp, amount--);
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			this->push_back(temp);
		}
	}

	
};


int main() {
	Node* root=new Node(0);
	for (int i = 0; i < 1; i++) {
		root->push_back(new Node((float)rand()));
	}
	root->show();
	root->SortByValue();
	root->show();

	cin.ignore();
	getchar();
	return 0;
}