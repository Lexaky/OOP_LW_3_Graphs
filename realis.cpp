#include <iostream>
#include "header.h"

using namespace std;

template <typename T> bool compareTypes(T t1, T t2)
{
    if (sizeof(t1) == sizeof(t2))
    {
        if (t1 == t2) return true;
        else return false;
    } else {
        return false;
    }
}

template <typename T> Graph<T>::Graph()
{
    powerMap = 0;
    IO_Table = new Table<T>();
    edges = new Node<T>();
}

template <typename T>void Graph<T>::addNode(Node <T> *add)
{
    if (add->id != 0)
        {
            Node <T> *mm = edges;
            if (mm != nullptr)
            {
                bool isMeet = false;
                if (compareTypes(mm->id, add->id))
                        isMeet = true;
                while(mm->next != nullptr)
                {
                    if (compareTypes(mm->id, add->id))
                        isMeet = true;
                    mm = mm->next;
                }
                    if (compareTypes(mm->id, add->id))
                        isMeet = true;
                if (isMeet == false)
                    {
                    mm->next = add;
                    powerMap++;
                    }
            } else {
                edges = add;
                powerMap++;
            }
        }
}

template <typename T>void Graph<T>::delNode(Node <T> *del)
{
    Node <T> *m = edges->next;
    Node <T> *n;
    Node <T> *newEdge = new Node<T>();
    Node <T> *startNewEdge = newEdge;
    while (m != nullptr)
    {
        if (m->id != del->id)
        {
            newEdge->next = new Node<T>();
            newEdge->next->id = m->id; newEdge->next->data = m->data;
            newEdge = newEdge->next;
            //Я знаю, что не чищу память здесь, но я сплю, доделаю на паре
        }
        m = m->next;
    }
    edges = startNewEdge;
    
    
    Table <T> *mm = IO_Table;
    Table <T> *newTable = new Table<T>();
    Table <T> *startNewtable = newTable;
    while (mm != nullptr && del->id == mm->inId && del->id == mm->outId)
    {
        IO_Table = IO_Table->next;
        delete m;
        mm = IO_Table;
    }
    if (IO_Table == nullptr)
    {
        IO_Table = new Table<T>();
    } else {
        while (mm != nullptr)
        {
            if (!(compareTypes(del->id, mm->inId) || compareTypes(del->id, mm->outId)))
            {
                //Я знаю, что не чищу память здесь, но я сплю, доделаю на паре
                newTable->next = new Table<T>();
                newTable->next->inId = mm->inId;
                newTable->next->outId = mm->outId;
                newTable = newTable->next;
            }
                mm = mm->next;
        }
    }
    IO_Table = startNewtable;
}

template <typename T> void Graph<T>::conNode(Node <T> *n1, Node <T> *n2)
{
    if (!compareTypes(n1->id, n2->id))
    { // else - it's similar nodes --> n1 = n2 --> n1 always connected to n1
        Node <T> *first = edges;
        Node <T> *second = edges;
        bool firstFound = false;
        bool secondFound = false;
        while (first != nullptr && firstFound == false)
        {
            if (compareTypes(first->id, n1->id))
            {
                firstFound = true;
            }
            first = first->next;
        }
        if (firstFound == true)
        {
            while (second != nullptr && secondFound == false)
            {
                if (compareTypes(second->id, n2->id))
                {
                    secondFound = true;
                }
                second = second->next;
            }
            if (secondFound == true)
            { // both nodes found
                Table <T> *m = IO_Table;
                if (m == nullptr)
                { //mistake mb?
                    m->inId = n1->id;
                    m->outId = n2->id;
                } else {
                    while (m->next != nullptr)
                        m = m->next;
                    m->next = new Table <T>();
                    m->next->inId = n1->id;
                    m->next->outId = n2->id;
                }
            }
        }
    }
}

template <typename T> void Graph<T>::delConNode(Node <T> *n1, Node <T> *n2)
{
    Table <T> *m = IO_Table;
    Table <T> *newTable = new Table<T>();
    Table <T> *startNewtable = newTable;
    while (m != nullptr && n1->id == m->inId && n2->id == m->outId)
    {
        IO_Table = IO_Table->next;
        delete m;
        m = IO_Table;
    }
    if (IO_Table == nullptr)
    {
        IO_Table = new Table<T>();
    } else {
        while (m != nullptr)
        {
            if (!(compareTypes(n1->id, m->inId) && compareTypes(n2->id, m->outId)))
            {
                newTable->next = new Table<T>();
                newTable->next->inId = m->inId;
                newTable->next->outId = m->outId;
                newTable = newTable->next;
                //Я знаю, что не чищу память здесь, но я сплю, доделаю на паре
            }
                m = m->next;
        }
    }
    IO_Table = startNewtable;
}

template <typename T> void Graph<T>::printMap()
{
    Node <T> *mm = edges->next;
    cout << "Branch\n";
    while (mm != nullptr)
    {
        cout << "[ID " << mm->id << "] [WEIGHT " << mm->data << "]\n" << endl;
        mm = mm->next;
    }
    
    Table <T> *m = IO_Table;
    bool idChange = true;
    cout << "\nTable\n";
    while (m != nullptr)
    {
        if (m->inId != 0 && m->outId != 0)
        cout << "[input ID " << m->inId << "] [output ID " << m->outId << "]\n";
        m = m->next;
    }
}

void border()
{
    for(int i = 0; i < 6; i++)
        cout << "~~~~ ";
    cout << "\n";
}
