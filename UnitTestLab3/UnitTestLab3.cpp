#include "CppUnitTest.h"
#include "../AlgStrD_Lab3/Iterator.h"
#include "../AlgStrD_Lab3/BinaryTree.h"
#include "../AlgStrD_Lab3/Node.h"
#include "../AlgStrD_Lab3/Queue.h"
#include "../AlgStrD_Lab3/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab3
{
	TEST_CLASS(UnitTestLab3)
	{
	public:
		BinaryTree* check;

		TEST_METHOD_INITIALIZE(setUp) {
			check = new BinaryTree();
		}

		TEST_METHOD_CLEANUP(cleanUp) {
			delete check;
		}

		TEST_METHOD(check_contains_Find) {
			check->insert(1);
			check->insert(2);
			check->insert(3);
			check->insert(4);
			Assert::IsTrue(check->contains(3));
		}

		TEST_METHOD(check_contains_NotFind) {
			check->insert(1);
			check->insert(2);
			check->insert(4);
			check->insert(5);
			Assert::IsFalse(check->contains(3));
		}

		TEST_METHOD(check_insert) {
			check->insert(5);
			check->insert(7);
			check->insert(3);
			check->insert(4);
			Assert::IsTrue(check->contains(4));
		}

		TEST_METHOD(check_insert_IsEmpty) {
			check->insert(1);
			Assert::IsTrue(check->contains(1));
		}

		TEST_METHOD(check_insert_IsNotEmpty) {
			check->insert(3);
			check->insert(1);
			Assert::IsTrue(check->contains(1));
		}

		TEST_METHOD(check_remove) {
			check->insert(1);
			check->insert(3);
			check->insert(5);
			check->remove(3);
			Assert::IsFalse(check->contains(3));
		}

		TEST_METHOD(check_remove_begin) {
			check->insert(2);
			check->remove(2);
			Assert::IsFalse(check->contains(2));
		}

		TEST_METHOD(check_remove_IsEmpty) {
			try {
				check->remove(3);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Tree is empty", e.what());
			}
		}

		TEST_METHOD(check_remove_IsNotEmpty) {
			check->insert(6);
			check->insert(4);
			check->insert(5);
			check->insert(3);
			check->remove(2);
			Assert::IsFalse(check->contains(2));
		}

		TEST_METHOD(check_remove_impossible) {
			check->insert(2);
			try {
				check->remove(3);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Impossible to find", e.what());
			}
		}

		TEST_METHOD(dft_iterator) {
			int Array[] = { 6, 8, 3, 4 };
			int i = 0;
			Iterator* dft_iterator;
			check->insert(6);
			check->insert(8);
			check->insert(3);
			check->insert(4);
			dft_iterator = check->create_dft_iterator();
			while (dft_iterator->has_next()) {
				Assert::AreEqual(Array[i], dft_iterator->next());
				i++;
			}
		}

		TEST_METHOD(bft_iterator) {
			int Array[] = { 6, 3, 8, 4 };
			int i = 0;
			Iterator* bft_iterator;
			check->insert(6);
			check->insert(8);
			check->insert(3);
			check->insert(4);
			bft_iterator = check->create_bft_iterator();
			while (bft_iterator->has_next()) {
				Assert::AreEqual(Array[i], bft_iterator->next());
				i++;
			}
		}
	};
}