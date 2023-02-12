#include "matrix.h"


matrix::matrix(QVector<link_list*>* vector,int row,int column,string name)
{
    this->vector=vector;
    this->column=column;
    this->row=row;
    this->name=name;
}
void matrix::insert(int row, int col, int value)
{
    link_list* temp=(*vector)[row];
    node* tmp=new node(value,col);
    node * tp=temp->header;
    while (tp->get_next()!=temp->trailer && tp->get_next()->get_column()<col)
    {
        tp=tp->get_next();
    }

    tmp->set_next(tp->get_next());
    tp->set_next(tmp);
    if(tp==temp->tail||temp->tail==nullptr)
        temp->tail=tmp;
    cout<<"Successfully inserted\n";


}
void matrix::remove(int row, int col)
{
    link_list* temp=(*vector)[row];
     node * tp=temp->find(col);
    if(tp!=nullptr)
   {
    node*tmp=tp->get_next();
    tp->set_next(tmp->get_next());
    if(tmp==temp->tail)
    {
        if(temp->header->get_next()==temp->trailer)
            temp->tail=nullptr;
       else
            temp->tail=tp;
    }
    delete tmp;

    cout<<"Successfully deleted\n";
    return;
    }
   cout<<"There is no node with these specifications\n!";
}
void matrix::search(int value)
{
    if(value==0)
    {cout<<"This value exists in matrix\n";return;}

    for(int i=0;i<row;i++)
    {
        link_list* temp=(*vector)[i];
        node * tp=temp->header;
        while (tp->get_next()!=temp->trailer)
        {
            if(tp->get_next()->get_data()==value)
            {cout<<"value exists in matrix\n";return;}
            tp=tp->get_next();
        }
    }
    cout<<"This value does not exist in the matrix\n";
}
void matrix::update(int row, int col, int value)
{
    link_list* temp=(*vector)[row];
    node * tp=temp->find(col);
    if(tp!=nullptr)
    {
        tp->get_next()->set_data(value);
        cout<<"Successfully updated\n";
        return;
    }
    cout<<"There is no node with these specifications!\n";
}
void matrix::print(bool type)
{
   if(type)
   {
       for(int i=0;i<row;i++)
       {
           link_list* temp=(*vector)[i];
           node * tp=temp->header;
           while (tp->get_next()!=temp->trailer)
           {

               printf("%d %d %d \n",i,tp->get_next()->get_column(),tp->get_next()->get_data());
               tp=tp->get_next();

           }
       }
   }
   else
   {
       for(int i=0;i<row;i++)
       {
           link_list* temp=(*vector)[i];
           node * tp=temp->header;
           int tmp=-1;
           while (tp->get_next()!=temp->trailer)
           {
              int clmn=tp->get_next()->get_column();
              for(int j=tmp+1;j<clmn;j++)
              printf("0\t");
              printf("%d\t",tp->get_next()->get_data());
              tmp=clmn;
              tp=tp->get_next();

           }
           for(int j=tmp+1;j<column;j++)
               printf("0\t");
           printf("\n");
       }
   }
}
void matrix::save_file()
{
    QFile file(QString::fromStdString(name));
    if(! file.open(QIODevice::WriteOnly | QIODevice::Text))
       return ;
    QTextStream qst(&file);
    for(int i=0;i<row;i++)
    {
        link_list* temp=(*vector)[i];
        node * tp=temp->header;
        int tmp=-1;
        while (tp->get_next()!=temp->trailer)
        {
           int clmn=tp->get_next()->get_column();
           for(int j=tmp+1;j<clmn;j++)
           qst<<'0'<<",";
           qst<<QString::number(tp->get_next()->get_data())<<",";
           tmp=clmn;
           tp=tp->get_next();

        }
        for(int j=tmp+2;j<column;j++)
            qst<<'0'<<",";
       qst<<'0'<<"\n";
    }
    file.close();

}
