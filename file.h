#ifndef FILE_H
#define FILE_H
#include<QFile>
#include<QTextStream>
#include<QStringList>
#include "link_list.h"


class file
{
    QVector<link_list*> * vector;


public:
   int row,column;
   string name;
    file(QVector<link_list*> * v);
    ~file();
   void save_to_list(QFile * file);

};

#endif // FILE_H
