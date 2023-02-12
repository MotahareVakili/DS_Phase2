#include "file.h"

file::file(QVector<link_list*>*v)
{
    this->vector=v;
    bool exist=false;
    string name;
    do
    {
        cin>>name;
        QFile file(QString::fromStdString(name));
       if( file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
           this->name=name;

           int size=name.size();
           int tmp_r=2,tmp_c=1;
           for(int i=0;i<size;i++)
           {
               if(name[i]=='(')
               {
                   while (name[i+tmp_r]!=',')
                   {
                       tmp_r++;
                   }
                   int tp=i+tmp_r+1;
                   while (name[tp+tmp_c]!=')')
                   {
                      tmp_c++;
                   }
                   string rw=name.substr(i+1,tmp_r-i);
                   string clmn=name.substr(tp,tmp_c);
                   this->row=stoi(rw);
                  this->column=stoi(clmn);
                   break;
               }
           }
           vector->reserve(row);
           save_to_list(& file);
           return;

       }
        else
       {
           exist=true;
           cout<<"There is no file with this name!please try again"<<endl;
       }
    }
    while (exist);


}
void file::save_to_list(QFile * file)
{


    QTextStream qst(file);
   while (!qst.atEnd())
    {
       QStringList qsl=qst.readLine().split(",");
        link_list * row_list=new link_list;
        int size=qsl.size();
        for(int i=0;i<size;i++)
        {
            if(qsl[i]!='0')
            {
                row_list->add(qsl[i].toInt(),i);
            }
        }
        vector->push_back(row_list);
    }
   file->close();

}
file::~file()
{
    for(int i=0;i<row;i++)
        delete (*vector)[i];
}
