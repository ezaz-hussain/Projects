

#include<iostream>
#include<string>
// #include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;




void clearscreen(){
    system("clear");
}


void exitter(){
    string exit;
    cout<<"Enter to return ";
    cin>>exit;
}


int lastID = 1;

    int ID ()
    {
       
       return lastID ++;
    }


 class User
 {



    public:

    int myId;
	char name[20];
	char fname[20];
	int cnic;
	char contact[20];
	char address[20];
    bool challanpaid=false;
    int paidamount=0;

    User(): myId (ID ()){  



bool save=false;
char ch;
        while (!(save))
    {
        clearscreen();
        
                cout << "User ID " << myId << endl;
          
                cout << "Enter the name of a person" << endl;
                cin >> name;
                cout << "Enter the father's name" << endl;
                cin >> fname;
                cout << "Enter CNIC " << endl;
                cin >> cnic;
                cout << "Enter Contact Deatils" << endl;
                cin >> address;

                cout << "Enter Y to save" << endl;
                cin >> ch;
                if((ch=='Y') || (ch=='y')){
                    save=true;
                    
                }
               

    }
 cout<<"----------------------------"<<endl;



    }

    void showUserInfo(){


        cout<<"-----------------Challan number"<<myId<<"-----------------"<<endl;
        cout<<"Name "<<name<<endl;
        cout<<"Father name "<<fname<<endl;
        cout<<"cnic "<<cnic<<endl;
        cout<<"address "<<address<<endl;
        cout<<"Dues Paid "<<challanpaid<<endl;
        cout<<"Paidamount "<<paidamount<<endl;
         cout<<"----------------------------"<<endl;

    }


 };

vector<User> UsersDB;





void saveusers(){
        int userentries;
    cout<<"How Many Users you Want to Add??"<<endl;
    cin>>userentries;

    for(int i=1;i<=userentries;i++){
        UsersDB.push_back(User());
    }

}


void showallusers(){
     clearscreen();
 for (auto & auser : UsersDB) {
auser.showUserInfo();
 }
}



void paydues(){
int cnic;
int dues;
 clearscreen();
        cout << "Enter CNIC: " << endl;
        cin >> cnic;


                
          for (auto & auser : UsersDB) {
            //   cout<<"checking"<<auser.cnic<<endl;

               if(auser.cnic==cnic){
                   


                    if(auser.challanpaid== false){
                        auser.showUserInfo();
                                    cout << "Enter Monthly Installment Amount: " << endl;
                            cin >> dues;
                            auser.challanpaid=true;
                            auser.paidamount=dues;
                            exitter();

                    }else{

                        cout<<auser.name<<" have already Paid the Dues"<<endl;
                        exitter();
                    }




   
                }


        }


}



int random (int low, int high) {
    srand((unsigned int)time(NULL));
    if (low > high)
        return high;
    return low + (rand() % (high - low + 1));
}


void luckydraw(){

 clearscreen();
 
bool drawnow=false;

for (auto & auser : UsersDB) {
    if(auser.challanpaid==true){
        drawnow=true;
    }

}




if(!(drawnow)){

    cout<<"No one has paid their dues."<<endl;
    exitter();
    return;
}



    while(drawnow){

        
    int luckynumber;
    luckynumber=random(1,lastID-1);
    // cout<<luckynumber<<endl;
        if(luckynumber>0){



            for (auto & auser : UsersDB) {
                if(auser.challanpaid==true){

                    if(luckynumber==auser.myId){
                        cout<<"MotorCycle Luckydraw Winner is"<<endl;
                        auser.showUserInfo();
                        exitter();
                        drawnow=false;
                        return;
                    }
                   
                }else{
                     drawnow=true;
                }

            }




        }else{
            cout<<"No users"<<endl;
            exitter();
            drawnow=false;
        }


    }




}





void mainscreen(){
            bool notexit = true;
 

            while (notexit) {
                clearscreen();

                cout << "\n\t Prize Scheme \n\n";
                cout << "\t1 Create Users\n";
                cout << "\t2 Show all Users\n";
                cout << "\t3 Monthly Installment\n";
                cout << "\t4 Lucky Draw\n";
                cout << "\t5 Exit\n";


                char ch;
                cout << "\t ";
                cin >> ch;

                switch (ch) {
                case '1':
                    saveusers();
                    break;
                case '2':
                    showallusers();
                    exitter();
                    break;
                case '3':
                    paydues();
                    break;
                case '4':
                    luckydraw();
                    break;
                case '5':
                    notexit = false;
                    break;
                default:
                    cout << "Invalid Choice" << endl;
                

                }

        }

}





int main(){

mainscreen();

}