#include<iostream>
#include<string>
#include <conio.h>
#include <stdlib.h>
#include"lib.cpp"
#include"mainmenu.cpp"
using namespace std;
//***************************************************************
//                   Function for Adjustment
//****************************************************************
void gotoxy(int x, int y)
{
	cout << setw(x);  //horizontal

	for (;y > 0;y--)   //vertical
	{
		cout << endl;
	}
}
//***************************************************************
//                   Function for front display
//****************************************************************
void front()
{
	system("CLS");
	gotoxy(64, 3);
	cout << "Project CS101-B";
	gotoxy(60, 3);
	cout << "LIBRARY";
	gotoxy(62, 3);
	cout << "MANAGEMENT" << endl;
	gotoxy(60, 2);
	cout << "SYSTEM" << endl;
	cout << "\nDeveloper :: Ezaz Hussain" << endl;
    cout << "RegNo :: 2019121" <<endl;
    cout << "Co-Developer :: Hassan Ubaid" << endl;
    cout << "RegNo :: 2019175" <<endl;
    cout << "GroupNo :: 20" <<endl;
     cout << "Section :: B" <<endl;
	cout << "Press Enter to continue.." << endl;
	getch();

}





/*


                                                                                Main                                                


*/

int main(){
    front ();
	mainmenu();
system("cls");
cout<<"\n\tQuit\n\n";
    return 0;
}