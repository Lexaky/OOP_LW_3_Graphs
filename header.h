#ifndef HEADER_H // include guard
#define HEADER_H

template <typename T>

struct Node
{
    T id;
    T data;
    Node *next = nullptr;
};

template <typename T>
struct Table
{
    T inId;
    T outId;
    Table *next = nullptr;
};

template <typename T> class Graph
{
private:
    Table <T> *IO_Table;
    Node <T> *edges;
    int powerMap;

public:

    Graph();
    void addNode(Node <T> *add);
    void delNode(Node <T> *del);
    void conNode(Node <T> *n1, Node <T> *n2);
    void delConNode(Node <T> *n1, Node <T> *n2);
    void printMap();
    ~Graph();
};

#endif /* MY_CLASS_H */
