#ifndef MATRIX_H
#define MATRIX_H
#include "file.h"



class matrix
{
    QVector<link_list*>* vector;
    int row,column;
    string name;
public:
    matrix(QVector<link_list*>* vector,int row,int column,string name);
    void insert(int row, int col, int value);
    void remove(int row, int col);
    void search(int value);
    void update(int row, int col, int value);
    void print(bool type);
    void save_file();
};

#endif // MATRIX_H
