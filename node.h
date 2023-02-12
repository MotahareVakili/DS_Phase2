#ifndef NODE_H
#define NODE_H


class node
{
    int data;
    node * next;
    int column;
public:
    node(int data,int column,node * next=nullptr);
    void set_data(int d);

   int get_data();

   void set_next(node * n);

   node * get_next();

   void set_column(int c);

   int get_column();


};

#endif // NODE_H
