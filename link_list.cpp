#include "link_list.h"

link_list::link_list()
{

   trailer=new node(0,-1,nullptr);
   header=new node(0,-1,trailer);
   tail=nullptr;


}
link_list::~link_list()
{

    while(header->get_next()!=trailer)
    {
        node * tp=header->get_next();
        header->set_next(tp->get_next());
        delete tp;

    }
    delete trailer;
    delete header;

}
void link_list::add(int data,int column)
{
    node * tmp=new node(data,column,trailer);
    if(tail==nullptr)
    {
        header->set_next(tmp);
        tail=tmp;
        return;
    }
    tail->set_next(tmp);
    tail=tmp;

}
node * link_list::find(int column)
{
    node * tp=header;
    while (tp->get_next()!=trailer)
    {
       if(tp->get_next()->get_column()==column)
           return tp;
       tp=tp->get_next();
    }
    return nullptr;
}
