#include <iostream>

using namespace std;

template <class T>
struct node
{
    T value;
    node *nextNode;
};

template <class T>
class List
{
    node<T> *startNode;
    node<T> *currentNode;
    node<T> *lastNode;

public:
    int count;

    void addValue(T value)
    {
        if (startNode == NULL)
        {
            startNode = new node<T>();
            startNode->value = value;
            lastNode = startNode;
            currentNode = startNode;
        }
        else
        {
            node<T> *newNode = new node<T>();
            newNode->value = value;
            lastNode->nextNode = newNode;
            lastNode = newNode;
        }
        count++;
    }

    bool hasNextValue()
    {
        if (currentNode == NULL)
            return false;
        else
        {
            currentNode = currentNode->nextNode;
            return currentNode == NULL ? false : true;
        }
    }

    T getCurrentValue()
    {
        return currentNode->value;
    }
};

int main()
{
    List<int> *list = new List<int>();
    list->getCurrentValue();
    list->addValue(3);
    list->addValue(5);
    list->addValue(7);

    do
    {
        cout << list->getCurrentValue();
    } while (list->nextValue());
}
