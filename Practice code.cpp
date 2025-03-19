#include <iostream>
using namespace std;

template <typename Type>
class List
{
protected:
	Type* arr;
	int maxSize;
	int currentSize;

public:
	List(int maxSize = 10)
	{
		this->maxSize = maxSize;
		this->currentSize = 0;
		arr = new Type[maxSize];
	}

	virtual ~List()
	{
		delete[] arr;
	}

	virtual Type removeElementFromSpecificPositionList(int pos) = 0;
	virtual void firstRepeatingElement() = 0;
	virtual void firstNonRepeatingElement() = 0;
	virtual void findPairs(int target) = 0;
	virtual void findMissingNum() = 0;

	void addElement(Type element)
	{
		if (currentSize < maxSize)
		{
			arr[currentSize] = element;
			currentSize++;
			cout << "Element " << element << " added." << endl;
		}
		else
		{
			cout << "List is full!" << endl;
		}
	}

	void printList()
	{
		for (int i = 0; i < currentSize; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

template <typename Type>
class MyList : public List<Type>
{
public:
	MyList(int maxSize = 10) : List<Type>(maxSize) {}

	~MyList() {}

	void countFrequencyOfEachElement()
	{
		cout << "Counting Frequency of Each Element:" << endl;

		for (int i = 0; i < this->currentSize; i++)
		{
			bool found = false;
			for (int j = 0; j < i; j++)
			{
				if (this->arr[i] == this->arr[j])
				{
					found = true;
					break;
				}
			}
			if (!found)
			{
				int count = 0;
				for (int k = 0; k < this->currentSize; k++)
				{
					if (this->arr[i] == this->arr[k])
					{
						count++;
					}
				}
				cout << "Element " << this->arr[i] << " its frequency is " << count << endl;
			}
		}
	}

	void leftRotate(int rotateCount)
	{
		cout << "Left Rotate = " << rotateCount << endl;
		for (int i = 0; i < rotateCount; i++)
		{
			Type temp = this->arr[0];
			for (int j = 0; j < this->currentSize - 1; j++)
			{
				this->arr[j] = this->arr[j + 1];
			}
			this->arr[this->currentSize - 1] = temp;
		}
		this->printList();
	}

	void rightRotate(int rotateCount)
	{
		cout << "Right Rotate = " << rotateCount << endl;
		for (int i = 0; i < rotateCount; i++)
		{
			Type temp = this->arr[this->currentSize - 1];
			for (int j = this->currentSize - 1; j > 0; j--)
			{
				this->arr[j] = this->arr[j - 1];
			}
			this->arr[0] = temp;
		}
		this->printList();
	}

	Type removeElementFromSpecificPositionList(int pos) override
	{
		if (pos < 0 || pos >= this->currentSize)
		{
			cout << "Invalid position!" << endl;
			return Type();
		}

		Type removedElement = this->arr[pos];
		for (int i = pos; i < this->currentSize - 1; i++)
		{
			this->arr[i] = this->arr[i + 1];
		}
		this->currentSize--;
		return removedElement;
	}

	void firstRepeatingElement() override
	{
		for (int i = 0; i < this->currentSize; i++)
		{
			for (int j = i + 1; j < this->currentSize; j++)
			{
				if (this->arr[i] == this->arr[j])
				{
					cout << "First repeating element: " << this->arr[i] << endl;
					return;
				}
			}
		}
		cout << "No repeating element found!" << endl;
	}

	void firstNonRepeatingElement() override
	{
		for (int i = 0; i < this->currentSize; i++)
		{
			bool isRepeating = false;
			for (int j = 0; j < this->currentSize; j++)
			{
				if (i != j && this->arr[i] == this->arr[j])
				{
					isRepeating = true;
					break;
				}
			}
			if (!isRepeating)
			{
				cout << "First non-repeating element: " << this->arr[i] << endl;
				return;
			}
		}
		cout << "No non-repeating element found!" << endl;
	}

	void findPairs(int target) override
	{
		bool found = false;
		cout << "Pairs with sum " << target << ": ";

		for (int i = 0; i < this->currentSize; i++)
		{
			for (int j = i + 1; j < this->currentSize; j++)
			{
				if (this->arr[i] + this->arr[j] == target)
				{
					cout << "(" << this->arr[i] << "," << this->arr[j] << ") ";
					found = true;
				}
			}
		}

		if (!found)
		{
			cout << "No pairs found!" << endl;
		}
		else
		{
			cout << endl;
		}
	}

	void findMissingNum() override
	{
		int n = this->currentSize + 1;
		int expectedSum = n * (n + 1) / 2;
		int actualSum = 0;

		for (int i = 0; i < this->currentSize; i++)
		{
			actualSum += this->arr[i];
		}

		int missingNumber = expectedSum - actualSum;
		cout << "Missing Number: " << missingNumber << endl;
	}
};

int main()
{
	MyList<int> myList(10);

	myList.addElement(1);
	myList.addElement(2);
	myList.addElement(4);
	myList.addElement(5);
	cout << "Elements that were added: ";
	myList.printList();
	cout << endl;
	myList.findMissingNum();
	cout << endl;


	MyList<int> myList2(10);
	myList2.addElement(1);
	myList2.addElement(2);
	myList2.addElement(3);
	myList2.addElement(4);
	myList2.addElement(5);
	myList2.addElement(7);
	cout << "Elements that were added: ";
	myList2.printList();
	cout << endl;
	myList2.findMissingNum();
	cout << endl;

	myList2.countFrequencyOfEachElement();
	cout << endl;

	MyList<int> myList3(10);
	myList3.addElement(-4);
	myList3.addElement(-3);
	myList3.addElement(1);
	myList3.addElement(-2);
	myList3.addElement(1);
	myList3.addElement(1);
	myList3.addElement(-3);
	myList3.addElement(-5);
	cout << "Elements that were added: ";
	myList3.printList();
	cout << endl;
	myList3.countFrequencyOfEachElement();
	cout << endl;

	myList3.leftRotate(2);
	cout << endl;

	myList3.rightRotate(2);

	cout << endl;
	return 0;
}

// TASK 4
// TIME COMPLEXITY

// Code 1: O(1)
// Code 2: O(N)
// Code 3: O(N^2)
// Code 4: O(1)
// Code 5: O(N^2)
// Code 6: O(N^3)
// Code 7: O(N)