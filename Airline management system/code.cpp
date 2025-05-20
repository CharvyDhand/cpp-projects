#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<vector>
using namespace std;
class Airlines{
    private:
    string flight,destination,departure;
    int seats;
    public:
    Airlines(string fl,string des,string dep,int st){
        flight=fl;
        destination=des;
        departure=dep;
        seats=st;
    }
    string getflight(){
        return flight;
    }
    string getdes(){
        return destination;
    }
    string getdep(){
        return destination;
    }
    int getseat(){
        return seat;
    }
    void update(string fl){
      
    }
};
void display(){
    file.open("loginData.txt", ios::in);
    string line;
    while(getline(file,line)) {
        cout<<line<<endl;
    }
}
int main(){
    Airlines flight1("f101","India","UAE",20);
    Airlines flight2("f102","India","USA",2);
    Airlines flight3("f103","India","CANADA",10);
    file.open("flightdetails.txt", ios::out | ios::app);
    file<<flight1.getflight()<<"*"<<flight1.getdes()<<"*"<<flight1.getdep()<<"*"<<flight1.getseat()<<"\n";
    file<<flight2.getflight()<<"*"<<flight2.getdes()<<"*"<<flight2.getdep()<<"*"<<flight2.getseat()<<"\n";
    file<<flight3.getflight()<<"*"<<flight3.getdes()<<"*"<<flight3.getdep()<<"*"<<flight3.getseat()<<"\n";
    char choice;
    do{
    cout<<"1. Reserve a seat\n2. exit\n";
    cout<<"Enter your choice:";
    getline(in,choice);
    cin.ignore();
    switch(choice){
        case '1':
        display();
        string f;
        cout<<"Enter your choice:";
        getline(in,f);
        switch(f){
            case 'a':
            if(flight1.getseat()>0){

            }
            break;
            case 'b':
            break;
            case 'c':
            break;
            default:
            cout<<"invalid input!\n";
        }
        break;
        case '2':
        break;
        default:
        cout<<"default value\n";
    }
}while(choice!='2');
return 0;
}