#include <iostream>
using namespace std;

template <typename newType>
class Node
{
private:
    newType weight;
    int id;
public:
    
    Node(int setID, newType setWeight_constructor)
    {
        id = setID;
        weight = setWeight_constructor;
    }   
    
    newType getWeight()
    {
        return weight;
    }
    
    int getID()
    {
        return id;
    }
    void setWeight(newType newWeight)
    {
        weight = newWeight;
    }
};

class Graph
{
private:
    Node **next; //Смежный список - локальный
    /*
    Локальный смежный список содержит информацию о всех взаимосвязях между узлами.
    Т.к. смежный список - это последовательность узлов в виде очереди, а каждый узел
    ссылается на первый связанный с ним узел (который, в свою очередь, ссылается
    на следующий узел, с которым имеет связь исходный рассматриваемый узел), то существует необходимость
    реализовывать узлы с указателем в теле private, а в графе - двумерный динамический массив
    из узлов.
    */
    bool haveElements; //Имеются ли узлы в графе
    int countOfElements; //Количество узлов в графе
public:
    Graph ()
    {
        haveElements = false;
        countOfElements = 0;
    }
    Graph (Node anotherElement)
    {
        **next = anotherElement;
        countOfElements = 1;
    }
    
    void addNode(Node newNode)
    {
        for (int i = 0; i < countOfElements; i++)
        { //Проверка на то, что не существует графа с тем же id, что и у добавляемого узла
            
        }
    }
    void connectNodes();
    void deleteNode();
    void searchNode();
    
};

int main()
{
    setlocale(LC_ALL, "rus");
    
    return 0;
}