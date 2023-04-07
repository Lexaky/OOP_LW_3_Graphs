#include <iostream>
#include "header.h"
using namespace std;


/*
    Код без разделений на файлы работает на OnlineGDB.
    Если делить на файлы, OnlineGDB пишет ошибку линковщика.
    В realis не очищаю память в некоторых методах; код работает.
*/
int main()
{
    setlocale(LC_ALL, "rus");
     Graph <int> *g_map1 = new Graph <int>();
    Node <int> *noda = new Node<int>();
    for (int i = 1; i < 9; i = i + 1)
    {
        noda = new Node<int>();
        noda->id = i;
        noda->data = i*2;
        g_map1->addNode(noda);
    }
    Node <int> *n1 = new Node<int>();
    Node <int> *n2 = new Node<int>();
    n1->id = 1;
    n2->id = 3;
    g_map1->conNode(n1, n2);
    n2->id = 4;
    g_map1->conNode(n1, n2);


    for (int i = 1; i <= 4; i++)
    {
        n1 = new Node<int>();
        n2 = new Node<int>();
        n1->id = i;
        n2->id = i*2;
        g_map1->conNode(n1, n2);
    }

       for (int i = 1; i <= 2; i++)
       {
        n1 = new Node<int>();
        n2 = new Node<int>();
        n1->id = i;
        n2->id = i*2;
        g_map1->delConNode(n1, n2);
       }
    n1 = new Node<int>();
    n1->id = 1;
    g_map1->delNode(n1);

    g_map1->printMap(); 
    
    
    
    /*
    Graph <char> *g_map1 = new Graph <char>();
    Node <char> *noda = new Node<char>();
    
    noda->id = 'a';
    noda->data = '+';
    g_map1->addNode(noda);
    
    Node <char> *noda2 = new Node<char>();
    noda2->id = 'b';
    noda2->data = '-';
    g_map1->addNode(noda2);
    g_map1->conNode(noda, noda2);
    g_map1->conNode(noda2, noda);
    Node <char> *noda3 = new Node<char>();
    noda3->id = 'z';
    noda3->data = '@';
    g_map1->addNode(noda3);
            g_map1->conNode(noda, noda3);
    g_map1->delConNode(noda, noda2);
    g_map1->delNode(noda3);
        g_map1->printMap();
    */
}
