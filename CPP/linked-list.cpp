/* Linked List
 * By Param Siddharth.
 * https://www.paramsid.com
 */

#include <iostream>
#include <cstdio>

namespace Param {

	// Node class
	template <class T>
	class Node {
		public:
			T INFO;
			Node<T>* NEXT;
			Node(T info = 0, Node<T>* next = nullptr)
				: INFO(info), NEXT(next) {}
	};

	// Linked list class
	template <class T>
	class List {
		private:
			// First node
			Node<T>* HEAD;
		public:
			// Constructor
			List(Node<T>* head = nullptr)
				: HEAD(head) {}

			// Destructor
			virtual ~List() {
				Node<T>* temp;
				while (HEAD != nullptr) {
					temp = HEAD;
					HEAD = HEAD->NEXT;
					std::free(temp);
				}
			}

			// Check if list is empty
			bool isEmpty() { return HEAD == nullptr; }

			// Insert at the end of the list
			void insertEnd(T info) {
				if (HEAD == nullptr)
					HEAD = (Node<T>*)std::malloc(sizeof(Node<T>));
				Node<T>* temp = HEAD;
				while (temp->NEXT != nullptr)
					temp = temp->NEXT;
				temp->NEXT = (Node<T>*)std::malloc(sizeof(Node<T>));
				temp->NEXT->NEXT = nullptr;
				temp->NEXT->INFO = info;
			}

			// Delete from the end of the list
			void deleteEnd() {
				if (HEAD != nullptr) {
					Node<T>* temp = HEAD;
					while (temp->NEXT != nullptr)
						temp = temp->NEXT;
					std::free(temp->NEXT);
					temp->NEXT = nullptr;
				}
			}

			// Insert at the beginning of the list
			void insertBeginning(T info) {
				Node<T>* temp = (Node<T>*)std::malloc(sizeof(Node<T>));
				temp->NEXT = HEAD;
				temp->INFO = info;
				HEAD = temp;
			}

			// Delete from the beginning of the list
			void deleteBeginning() {
				if (HEAD != nullptr) {
					Node<T>* temp = HEAD;
					HEAD = HEAD->NEXT;
					std::free(temp);
				}
			}

			// Insert at a specific index
			void insertIndex(int index, T info) {
				if (HEAD == nullptr) {
					Node<T>* temp = (Node<T>*)std::malloc(sizeof(Node<T>));
					temp->NEXT = nullptr;
					temp->INFO = info;
				} else if (index == 0)
						insertBeginning(info);
				else {
					Node<T>* temp = (Node<T>*)std::malloc(sizeof(Node<T>)),
					       * current = HEAD,
						   * previous = nullptr;
					while (index > 0 && current->NEXT != nullptr) {
						index--;
						previous = current;
						current = current->NEXT;
					}
					temp->INFO = info;
					temp->NEXT = current;
					previous->NEXT = temp;
				}
			}

			// Delete from a specific index
			void deleteIndex(int index) {
				if (index == 0) 
					deleteBeginning();
				else {
					Node<T>* temp  = HEAD,
						   * previous = nullptr;
					while (index > 0 && temp->NEXT != nullptr) {
						index--;
						temp = temp->NEXT;
					}
					previous->NEXT = temp->NEXT;
					std::free(temp);
				}
			}

			// Get the value at a particular index (returns reference to support assignment)
			T& getIndex(int index) {
				Node<T>* temp = HEAD,
				       * previous = nullptr;
				if (HEAD == nullptr) {
					HEAD = (Node<T>*)malloc(sizeof(Node<T>));
					HEAD->NEXT = nullptr;
					return HEAD->INFO;
				}
				if (index == 0)
					return HEAD->INFO;
				while (index > 0 && temp != nullptr) {
					index--;
					previous = temp;
					temp = temp->NEXT;
				}
				if (temp == nullptr) {
					previous->NEXT = (Node<T>*)malloc(sizeof(Node<T>));
					previous->NEXT->NEXT = nullptr;
					return previous->NEXT->INFO;
				}
				return temp->INFO;
			}

			// Overload for the [] operator
			T& operator [](int index) { return getIndex(index); }
			
			// Returns the size of the list
			int size() {
				int sizeValue = 0;
				Node<T>* temp = HEAD;
				while (temp != nullptr) {
					temp = temp->NEXT;
					sizeValue++;
				}
				return sizeValue;
			}

			// Displays the list
			void show() {
				Node<T>* temp = HEAD;
				std::cout << '<';
				while (temp != nullptr) {
					std::cout << ' ' << temp->INFO;
					temp = temp->NEXT;
				}
				std::cout << " >" << std::endl;
			}
	};
}
