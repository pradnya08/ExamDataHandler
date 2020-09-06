//minor seating arrangement
//pradnya asundi 350
//adil mohsin 354







#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<exception>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct MyException:public exception
{
    const char * what() const throw()
    {
        return "input exception";
    }
};



class seat
{
public:
    int seatNo;
    seat(int i)
    {
        seatNo=i;
    }
    void putDataSE()
    {
        cout<<"Seat number is: "<<seatNo<<endl;
    }

};



class Stud
{
public:
    int studId;
    char studName[10];
    char dept[10];
    int sem;
    char div[1];
    seat s={0};

    void putStud()
    {
        cout<<"Student Id: "<<studId<<"\t";
        cout<<"Student name: "<<studName<<"\t";
        cout<<"Dept: "<<dept<<"\t";
         cout<<"Div: "<<div<<"\t";
        cout<<"Sem: "<<sem<<"\t";
        cout<<"Seat No:"<<s.seatNo<<"\t";
    }

};


class room
{
public:
    string roomName;
    int numhand;
    seat se[30]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
     Stud st[30];

    void putdataR()
    {
        cout<<"Room name: "<<roomName<<endl;
    }
};


class block:public room
{
public:
    int blockNo;
    int numhand;
    seat se[30]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
     Stud st[30];
     block(int num)
     {
         blockNo=num;
     }
     void putdatab()
     {
        for(int i=0;i<30;i++)
        {
            se[i].seatNo;
        }
     }

};
class Admin
{
public:
    int id;
    string name;

    block bl={0};

Admin(int idd,string n)
{
    id=idd;
    name=n;

}
void putdataAd()
{
    cout<<"Name of Admin: "<<name<<endl;
    cout<<"Admin id"<<id<<endl;
}


};

class UnivDB
{
public:
    string Uname;
    static int cnt;
    room *r[20];
    Stud s[600];
    block  b2[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    Admin a={0,"a"};
UnivDB(string n)
{
  Uname=n;

}

int allocation(int bno,int no_stud)
{
    int i,x,noH=0;
    string rname;

    for(i=0;i<bno;i++)
    {
        cout<<"Enter roomname"<<endl;
        cin>>rname;
        r[i]=&b2[i];
        r[i]->roomName=rname;

    }

    for(int j=0;j<bno;j++)
   {

    for(int k=cnt,x=0;k<(cnt+30);k++,x++)
    {  if(noH==no_stud)
       break;
       else
        {
          r[j]->st[x]=s[k];
          r[j]->st[x].s=r[j]->se[x];
          noH++;
        }
    }
    r[j]->numhand=noH-cnt;
    cnt=noH;


   }
   if(no_stud>bno*30)
    return(1);
    else
    return(0);
}

int addblock(int bno,int no_stud)
{
  string rname;
  int need,total_b,noH,x;
  noH=cnt;
  total_b=no_stud/30;
  if(total_b%30!=0)
  {
    total_b=total_b+1;
  }
  need=total_b-bno;
  cout<<"There are excess students compared to available blocks"<<endl;
  cout<<"need to add "<<need<<" blocks"<<endl;
  for(int i=bno;i<(bno+need);i++)
  {
      cout<<"Enter roomname"<<endl;
        cin>>rname;
        r[i]=&b2[i];
        r[i]->roomName=rname;

  }

  for(int j=bno;j<bno+need;j++)
  {
      for(int k=cnt,x=0;k<(cnt+30);k++,x++)
      {
          if(noH==no_stud)
       break;
       else
        {
          r[j]->st[x]=s[k];
          r[j]->st[x].s=r[j]->se[x];
          noH++;
        }
      }

       r[j]->numhand=noH-cnt;
      cnt=noH;

  }

  return(total_b);


}

void getdivarrang(char d[],int s,int total_b,int no_stud)
{
     for(int j=0;j<total_b;j++)
     {

        for(int k=0;k<r[j]->numhand;k++)
     {
         if(strcmp(r[j]->st[k].div,d)==0 && r[j]->st[k].sem==s)
           { r[j]->st[k].putStud();
            cout<<"Roomname: "<<r[j]->roomName<<"\tBlock Num: "<<j+1<<"\n"<<endl;
           }
     }
     }


}
void getblockarrang(int bno,int no_stud)
{   cout<<"Students in block are: \n";
    for(int k=0;k<r[bno-1]->numhand;k++)
     {

            r[bno-1]->st[k].putStud();
            cout<<"Roomname:"<<r[bno-1]->roomName<<"\n"<<endl;
     }
}
void getPersonalSeatdata(Stud s,int no_stud,int total_b)
{
    for(int j=0;j<total_b;j++)
        for(int k=0;k<r[j]->numhand;k++)
        {

             if(r[j]->st[k].studId==s.studId && strcmp(r[j]->st[k].dept,s.dept)==0)
            {
              r[j]->st[k].putStud();
              cout<<"Roomname: "<<r[j]->roomName<<"\tBlock num: "<<j+1<<"\n"<<endl;
            }
        }
}

};


int UnivDB::cnt;

int main()
{
       string name;
      int excess,bno;
      int adminLogincnt=0,id;
      int no_of_stud=75;
      int total_blocks;

      UnivDB un("KLETECH");

       FILE *fp;

        fp=fopen("sample.csv","r");
        for(int i=0;i<no_of_stud;i++)
        {
fscanf(fp,"%d\t%s\t%s\t%s\t%d\n",&un.s[i].studId,un.s[i].studName,un.s[i].div,un.s[i].dept,&un.s[i].sem);

        }


       int flag=0,f=0;
       while(f==0)
       {

       try{
              cout<<"\t\t\t\t\t"<<"Admin login :"<<endl;
       cout<<"Please enter admin name"<<endl;
       cin>>name;
       cout<<"Please enter admin 4 digit pincode"<<endl;
       cin>>id;
         if( id<0 || id>1234 || id<1234)
              {
                 throw MyException();
              }

    }
    catch(MyException& e)
    {
        cout<<"Exception caught"<<endl;
        cout<<e.what()<<endl;
    }
    catch(exception& e)
    {

    }

Admin a(id,name);
       if(a.id==1234 && a.name=="admin")
          {
              un.a=a;
          cout<<"Enter approx no of blocks"<<endl;
          cin>>bno;
          total_blocks=bno;
      excess=un.allocation(bno,no_of_stud);
       if(excess)
         total_blocks=un.addblock(bno,no_of_stud);

          f=1;
          }


       else
       {
           cout<<"Incorrect password or invalid admin name"<<endl;
       }

       }
       while(1)
{   Stud s;int ch=0;
      try{


          cout<<"\n\n\t\t\t\t\t"<<"Student login :"<<endl;
       cout<<"Enter USN"<<endl;
        //all entries are read
        cin>>s.studId;
        cout<<"Enter DEPT"<<endl;
        cin>>s.dept;
        cout<<"Enter SEM"<<endl;
        cin>>s.sem;


      if(s.studId<1|| s.dept[0]=='0'||s.dept[0]=='1'||s.dept[0]=='2'||s.dept[0]=='3'||s.dept[0]=='4'||s.dept[0]=='5'||s.dept[0]=='6'||s.dept[0]=='7'||s.dept[0]=='8'||s.dept[0]=='9'||s.sem<1||s.sem>8|| s.dept[1]=='0'||s.dept[1]=='1'||s.dept[1]=='2'||s.dept[1]=='3'||s.dept[1]=='4'||s.dept[1]=='5'||s.dept[1]=='6'||s.dept[1]=='7'||s.dept[1]=='8'||s.dept[1]=='9')
                      throw MyException();
    }
    catch(MyException& e)
    {
        cout<<"Exception caught"<<endl;
        cout<<e.what()<<endl;
    }
    catch(exception& e)
    {
        //other exception
    }

             for(int i=0;i<no_of_stud;i++)
             if(s.studId==un.s[i].studId && strcmp(s.dept,un.s[i].dept)==0 && s.sem==un.s[i].sem)
                {
                  flag=1;
                         //choice to search is read and switch case is called



                  while(ch<=3)
               {

                   cout<<"\n\n1:Displaying student arrangement of given division"<<endl;
                   cout<<"2:Displaying student arrangement of given block"<<endl;
                   cout<<"3:Displaying student arrangement of student logged in"<<endl;
                   cout<<"4:Logout"<<endl;
                   try{
                       cout<<"Enter choice:"<<endl;
                   cin>>ch;
                   if(ch>4 || ch<=0)
                      throw MyException();
    }
    catch(MyException& e)
    {
        cout<<"Exception caught"<<endl;
        cout<<e.what()<<endl;
    }
    catch(exception& e)
    {
        //other exception
    }






                  switch(ch)
               {
                   case 1:
        char d[1];
                                  int sem;
                                  try{
                                      cout<<"\nEnter div: ";
                                  cin>>d;
                                  cout<<"\nEnter sem: ";
                                  cin>>sem;
    if(d[0]!='A' && d[0]!='B' && d[0]!='C' && d[0]!='D' || sem<1 ||sem >8)
                                    throw MyException();
                                   }
                                    catch(MyException& e)
                                     {
                                         cout<<"Exception caught"<<endl;
                                         cout<<e.what()<<endl;
                                     }
                                     catch(exception& e)
                                     {
                                       //other exception
                                     }


                                  un.getdivarrang(d,sem,total_blocks,no_of_stud);
                                   break;

                     case 2:
                                 int bNo;
                                 try{ cout<<"\nenter block no:";
                                 cin>>bNo;
                                 if(bNo<1)
                                    throw MyException();
                                   }
                                    catch(MyException& e)
                                     {
                                         cout<<"Exception caught"<<endl;
                                         cout<<e.what()<<endl;
                                     }
                                     catch(exception& e)
                                     {
                                       //other exception
                                     }


                                 un.getblockarrang(bNo,no_of_stud);
                                 break;
                   case 3:
                                 un.getPersonalSeatdata(s,no_of_stud,total_blocks);
                                 break;



               }


            }



}
if(flag==0)
     cout<<"NOT valid data";
else
      flag=0;
}
}


