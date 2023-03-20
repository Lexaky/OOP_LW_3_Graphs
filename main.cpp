#include <iostream>

template <typename newType>
class Node
{
private:
    newType weight;
    int id;
public:
    Node *next;
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
template <typename newType>
class Graph
{
private:
    /*
    Локальный смежный список содержит информацию о всех взаимосвязях между узлами.
    Т.к. смежный список - это последовательность узлов в виде очереди, а каждый узел
    ссылается на первый связанный с ним узел (который, в свою очередь, ссылается
    на следующий узел, с которым имеет связь исходный рассматриваемый узел), то существует необходимость
    реализовывать узлы с указателем в теле private, а в графе - двумерный динамический массив
    из узлов.
    */
    Node <newType> **tops;
    bool haveElements; //Имеются ли узлы в графе
    int countOfElements; //Количество узлов в графе
public:
    Graph ()
    {
        haveElements = false;
        countOfElements = 0;
    }
    Graph (Node <newType> anotherElement)
    {
        haveElements = true;
        *tops = &anotherElement;
        countOfElements = 1;
    }

    void addNode(Node <newType> *newNode)
    {
        tops = (*newType)malloc(sizeof(newType));
        *tops->next = &newNode;
    }
    void connectNodes(int id1, int id2)
    {
        if (id1 == id2)
        {
            std::cout << "Connected" << "\n"; //Соединение узла с самим собой 
        } else {
        
            Node <newType> *n1 = tops;
            Node <newType> *n2 = tops;
            while (n1->getID() != id1)
            {
                n1 = n1 + sizeof(Node <newType>);
            }
            while (n2->getID() != id2)
            {
                n2 = n2 + sizeof(Node <newType>);
            }
            n1->next = n2;
        }
    }
    void deleteNode();
    void searchNode();
    void printNodesConnects()
    {
        for (int i = 0; i < countOfElements; i++)
        {
            std::cout << tops[i][0].getWeight() << "\n";   
        }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Node <int> *n1 = new Node(1, 4);
    std::cout << n1->getWeight() << std::endl;
    //Node <char> *n2 = new Node(2, 'a');
    Node <int> *n2 = new Node(2, 2);
    //n1->next = n2;
    
    std::cout << n1->next->getWeight() << "\n";
    
    Graph <int> *g_map = new Graph(*n1);
    g_map->addNode(n2);
    g_map->connectNodes(1, 2);
    
    
    delete g_map;
    delete n1;
    delete n2;
    //Graph <newType> *g_map = new Graph();
    //*g_map->printNodesConnects();
    return 0;
}
