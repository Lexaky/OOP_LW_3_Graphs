#include <iostream>
using namespace std;
struct Node
{
    int weight = 0;
    int id = 0;
    Node *right = nullptr;
    Node *down = nullptr;
};

class Graph
{
  private:
  Node *top;
  public:

  Graph()
  {
      top = new Node();
  }

  Graph(Node *n1)
  {
      top = n1;
  }

  void connectNodes(Node *n1, Node *n2)
  {
      Node *start = top;
      Node *move_ = top;
      Node *move1;
      Node *move2;
      bool connected = false;
      bool isSecondTopFound = false;
      while (move_ != nullptr && connected == false)
      {
          if (move_->id == n1->id)
          {
              move1 = move_;
              while(move1->right != nullptr)
                move1 = move1->right; //Нашёл место для вставки связи
          }
          if (move_->id == n2->id)
          {
              //Нашёл вторую связуемую вершину в списке
                isSecondTopFound = true;
          }
          if (isSecondTopFound == true && move1->right == nullptr)
          {
              move1->right = n2;
              connected = true;
          }
          move_ = move_->down;
      }
      top = start;

  }
  void addNode(Node *n1)
  {
      Node *move;
      move = top;
      bool analogy = false;
      while (move->down != nullptr)
      {
          if (move->id == n1->id) analogy = true;
          move = move->down;
      }
      if (analogy != true)
        move->down = n1;
  }
  void printNodes()
  {
      Node *moveRight;
      Node *move = top;
      while(move != nullptr)
      {
        moveRight = move;
        cout << "Current node: [id] " << move->id << "; [weight] " << move->weight << endl;
        cout << "Connected nodes:\n";
        while(moveRight != nullptr)
        {
            if (moveRight->id != move->id)
                cout << "[id] " << moveRight->id << "; [weight] " << moveRight->weight << endl;
            moveRight = moveRight->right;
        }
        cout << "~~~~~~" << endl;
        move = move->down;
      }
  }

};


int main()
{
    Graph *g_map = new Graph();
    Node *n = new Node();
    n->weight = 1;
    n->id = 2;
    g_map->addNode(n);
    Node *n1 = new Node();
    n1->weight = 5;
    n1->id = 55;
    g_map->addNode(n1);
    g_map->connectNodes(n, n1);
    Node *n2 = new Node();
    n2->id = 1488;
    n2->weight = 228;
    g_map->addNode(n2);
    g_map->connectNodes(n1, n);
    g_map->connectNodes(n2, n);
    g_map->connectNodes(n2, n1);
    g_map->printNodes();

    return 0;
}
