
#include"matrix.h"



int main()
{

cout<<"Please enter the file name as 'name.csv'\n";
QVector<link_list*>vector;
file reading_info(&vector);
matrix matrix(&vector,reading_info.row,reading_info.column,reading_info.name);


int number,row,col,value;
bool  again =true;
do
{
    cout<<"\n0) insert\n1) delete\n2) search\n3) update\n4) print\n5) save file\n6) exit\nplease enter a number:\n\nnumber:";
    cin>>number;
    switch (number)
    {
     case 0:
       {
          cout<<"\nplease enter row,column and value\nrow:";
          cin>>row;
          cout<<"column:";
          cin>>col;
          cout<<"value:";
          cin>>value;
          cout<<"\n";
          matrix.insert(row,col,value);
          break;

       }
     case 1:
       {
          cout<<"\nplease enter row and column\nrow:";
          cin>>row;
          cout<<"column:";
          cin>>col;
          cout<<"\n";
          matrix.remove(row,col);
          break;
       }
     case 2:
       {
         cout<<"\nPlease enter the value you want to search\nvalue:";
         cin>>value;
         cout<<"\n";
         matrix.search(value);
         break;
       }
     case 3:
       {
        cout<<"\nplease enter row,column and value\nrow:";
        cin>>row;
        cout<<"column:";
        cin>>col;
        cout<<"value:";
        cin>>value;
        cout<<"\n";
        matrix.update(row,col,value);
        break;
       }
     case 4:
       {
        int tmp;
        cout<<"\nplease select printing method(enter code):\n0) print as 2D array\n1) print as compressed list\ncode:";
        cin>>tmp;
        cout<<"\n";
        matrix.print(tmp);
        cout<<"\n";
        break;
       }
     case 5:
       {
         matrix.save_file();
         cout<<"Successfully saved\n";
         break;
       }
     case 6:
       {
          again=false;
          cout<<"\n";
          break;
       }
    }

}while (again) ;

    return 0;
}
