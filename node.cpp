#include "node.h"


 node ::node(int data,int column,node * next)
{
    this->data=data;
    this->column=column;
    this->next=next;
}
void node:: set_data(int d)
{
    data=d;
}
int node::get_data()
{
    return data;
}
void node:: set_next(node * n)
{
   next=n;
}
node *node:: get_next()
{
   return next;
}
void node::set_column(int c)
{
   column=c;
}
int node:: get_column()
{
   return column;
}
