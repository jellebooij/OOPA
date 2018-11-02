#pragma once
template<typename T>
class Queue {

private:
	
	struct Node {
	T value;
	Node* next;
	};
	
	Node* head;
	Node* tail;

public:

	Queue() {
		head = nullptr;
		tail = nullptr;
	}
	
	T PopFront() {
		
		if (!(head == nullptr)) {
			if (head->next != nullptr) {
				Node* temp = head->next;
				T tv = head->value;
				delete head;
				head = temp;
				return tv;
			}
			else {
				T tv = head->value;
				delete head;
				return tv;
			}
			
			
			
		}

		return 0;
	}

	void PushBack(T value) {
		
		

		Node* temp = new Node();
		
		temp->value = value;
		temp->next = nullptr;

		if (head == nullptr) {
			head = temp;
		}
		else
		{
			tail->next = temp; 
		}
		
		tail = temp;
	}
	
	void PrintList() {
		
		Node* current;
		current = head;

		while (current != nullptr) {
			std::cout << current->value << std::endl;
			current = current->next;
		}
	}
	

};