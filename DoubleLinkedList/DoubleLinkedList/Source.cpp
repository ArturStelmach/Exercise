#include <iostream>

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
		}
	}

	void push_front(Node* NewNode) {
		this->prev = NewNode;
		NewNode->next = this;
	}


};


int main() {



	cin.ignore();
	getchar();
	return 0;
}