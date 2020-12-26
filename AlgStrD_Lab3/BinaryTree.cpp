#include "BinaryTree.h"
#include "Iterator.h"
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
#include <stdexcept>

using namespace std;

BinaryTree::BinaryTree() {
	begin = nullptr;
}

bool BinaryTree::contains(int FindElement) {
	Node* this_branch = begin;
	while (this_branch != nullptr) {
		if (FindElement < this_branch->data) {
			this_branch = this_branch->left_branch;
		}
		else
			if (FindElement > this_branch->data) {
				this_branch = this_branch->right_branch;
			}
			else
				if (FindElement == this_branch->data) {
					return true;
				}
	}
	return false;
}

void BinaryTree::insert(int FindElement) {

	if (begin == nullptr) {
		begin = new Node(FindElement);
	}
	else {
		Node* this_branch = begin;
		while (!((this_branch->left_branch == nullptr) && !(FindElement > this_branch->data)) && !((this_branch->right_branch == nullptr) && !(FindElement < this_branch->data))) {
			if (this_branch == nullptr) {
				break;
			}
			if (!(FindElement > this_branch->data)) {
				this_branch = this_branch->left_branch;
			}
			else {
				if (!(FindElement < this_branch->data)) {
					this_branch = this_branch->right_branch;
				}
			}
		}
		if (this_branch != nullptr) {
			if ((FindElement < this_branch->data) && (this_branch->left_branch == nullptr)) {
				this_branch->left_branch = new Node(FindElement, nullptr, nullptr, this_branch, nullptr);
			}
			if ((FindElement > this_branch->data) && (this_branch->right_branch == nullptr)) {
				this_branch->right_branch = new Node(FindElement, nullptr, nullptr, this_branch, nullptr);
			}
		}
	}
}

void BinaryTree::remove(int FindElement) {
	if (begin == nullptr) {
		throw out_of_range("Tree is empty");
	}
	else {
		if (begin->left_branch == nullptr) {
			if (begin->right_branch == nullptr) {
				if (begin->data == FindElement) {
					begin = nullptr;
				}
				else {
					throw out_of_range("Impossible to find");
				}
			}
		}
		else {
			Node* this_branch = begin;
			Node* next_branch = nullptr;
			while (this_branch != nullptr) {
				if (this_branch->data == FindElement) {
					if (this_branch->left_branch == nullptr) {
						if (this_branch->right_branch == nullptr) {
							if ((this_branch->previous_branch)->left_branch == this_branch) {
								(this_branch->previous_branch)->left_branch = nullptr;
							}
							else {
								(this_branch->previous_branch)->right_branch = nullptr;
							}
							delete this_branch;
						}
					}
					else {
						if (this_branch->left_branch != nullptr) {
							if (this_branch->right_branch == nullptr) {
								next_branch = this_branch->left_branch;
								this_branch->left_branch = next_branch->left_branch;
								this_branch->right_branch = next_branch->right_branch;
								this_branch->data = next_branch->data;
								if (this_branch->left_branch != nullptr) {
									this_branch->left_branch->previous_branch = this_branch;
								}
								if (this_branch->right_branch != nullptr) {
									this_branch->right_branch->previous_branch = this_branch;
								}
								delete next_branch;
							}
						}
						else {
							if (this_branch->left_branch == nullptr) {
								if (this_branch->right_branch != nullptr) {
									next_branch = this_branch->right_branch;
									this_branch->left_branch = next_branch->left_branch;
									this_branch->right_branch = next_branch->right_branch;
									this_branch->data = next_branch->data;
									if (this_branch->left_branch != nullptr)
										this_branch->left_branch->previous_branch = this_branch;
									if (this_branch->right_branch != nullptr)
										this_branch->right_branch->previous_branch = this_branch;
									delete next_branch;
								}
							}
							else {
								if (this_branch->left_branch != nullptr) {
									if (this_branch->right_branch != nullptr) {
										next_branch = this_branch->right_branch;
										if (next_branch->left_branch == nullptr) {
											this_branch->right_branch = next_branch->right_branch;
											if (next_branch->right_branch != nullptr) {
												(next_branch->right_branch)->previous_branch = this_branch;
											}
										}
										else {
											while ((next_branch->left_branch != nullptr) && (next_branch != nullptr)) {
												next_branch = next_branch->left_branch;
											}
											(next_branch->previous_branch)->left_branch = next_branch->right_branch;
											if (next_branch->right_branch != nullptr) {
												next_branch->right_branch->previous_branch = next_branch->previous_branch;
											}
										}
										this_branch->data = next_branch->data;
										delete next_branch;
									}
								}
							}
							return;
						}
					}
				}
				else {
					if (this_branch->data > FindElement) {
						this_branch = this_branch->left_branch;
					}
					else {
						this_branch = this_branch->right_branch;
					}
				}
			}
			throw out_of_range("Impossible to find");
		}
	}
}

BinaryTree::~BinaryTree() {
	while (begin != nullptr) {
		remove(begin->data);
	}
	delete begin;
}


