#ifndef LINK_LIST_H
#define LINK_LIST_H
#include"node.h"
#include<iostream>
using namespace std;
#include <QVector>

class link_list
{
    friend class matrix;
    node * trailer;
    node * header;
    node * tail;


public:    

    link_list();
    ~link_list();
   void add(int data,int column);
   node * find(int column);


};


#endif // LINK_LIST_H
