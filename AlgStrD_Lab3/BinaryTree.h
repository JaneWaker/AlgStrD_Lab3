#pragma once
#include "Iterator.h"
#include "Node.h"
#include "Queue.h"
#include "Stack.h"

class BinaryTree
{
private:
	Node* begin;

public:
	BinaryTree();
	bool contains(int);
	void insert(int);
	void remove(int);
	~BinaryTree();
	

	Iterator* create_dft_iterator();
	Iterator* create_bft_iterator();

	class dft_Iterator : public Iterator {
	public:
		dft_Iterator(Node* begin_dft);
		int next() override;
		bool has_next() override;
	private:
		Stack* Stack_elem;
	};

	class bft_Iterator : public Iterator {
	public:
		bft_Iterator(Node* begin_bft);
		int next() override;
		bool has_next() override;
	private:
		Queue* Queue_elem;
	};
};

