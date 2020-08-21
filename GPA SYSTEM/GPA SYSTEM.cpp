// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
// #include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include<fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <stdlib.h>

using namespace std;

void clearscreen() {
    system("cls");
}

void gotoxy(int x, int y);
void front();
void mainmenu();
void showallusers();


string DatabaseFileName = "Users.db";





void exitter() {
    string exit;
    cout << "Enter to return ";
    cin >> exit;
}

int randomnum(int low, int high) {
    srand((unsigned int)time(NULL));
    if (low > high)
        return high;
    return low + (rand() % (high - low + 1));
}




int genrandomid() {
    return randomnum(100000, 999999);
}









int strtoint(string str) {
    string idstr = str;
    int inte;
    istringstream iss(idstr);
    iss >> inte;
    return inte;
}


string inttostr(int inte) {

    string out_string;
    stringstream ss;
    ss << inte;
    out_string = ss.str();
    return out_string;
}





void tokenize(string const& str, const char delim, vector<string>& out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}










//-------------------------------------------
// COurse Class
//-------------------------------------------
class Course {
public:

    string courseName;
    string courseCode;
    int creditHours;
    string courseGrade;


    Course() {

    }

    void createcourse() {
        cout << "Enter Course: " << endl;
        cin >> courseName;
        cout << "Enter Course Code: " << endl;
        cin >> courseCode;
        cout << "Enter Credit Hours: " << endl;
        cin >> creditHours;
        cout << "Enter Course Grade:" << endl;
        cin >> courseGrade;
    }


    void showCourseInfo() {

        cout << "Course Name: " << courseName << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << "Course Credit Hours: " << creditHours << endl;
        cout << "Course Grade: " << courseGrade << endl;
    }





};




//-------------------------------------------
// Student Class
//-------------------------------------------

class Student

{

public:
    vector<Course> CoursesVector;
    int myId = 0;
    string name;
    char tutionpaid = 'N';
    int numberofCourse = 0;

    Student() {

    }

    // void editstudent(int dbid, string dbname,char dbtutionpaid, int dbcourses ){
    //     myId=dbid;
    //     name=dbname;
    //     tutionpaid=dbtutionpaid;
    //     numberofCourse=dbcourses;

    // }



    void createstudent() {

        myId = genrandomid();

        cout << "User ID " << myId << endl;

        cout << "Enter Students Name" << endl;
        cin >> name;
        cout << "Pay Tution Fees Y/N " << endl;
        cin >> tutionpaid;





        cout << "How many courses you want to add" << endl;
        cin >> numberofCourse;


        for (int i = 1; i <= numberofCourse; i++) {
            addCourse();

        }



        saveuser();
        cout << "----------------------------" << endl;

    }


    void showUserInfo() {

        cout << "-----------------Student ID: " << myId << "-----------------" << endl;
        cout << "Student Name: " << name << endl;
        cout << "Number of Courses Enrolled: " << numberofCourse << endl;

        if (tutionpaid == 'Y') {

            double totalcredithour = 0;
            double totalgrades = 0;


            for (auto& acourse : CoursesVector) {

                cout << "Course Name: " << acourse.courseName << endl;
                cout << "Course Code: " << acourse.courseCode << endl;
                cout << "Course Credit Hours: " << acourse.creditHours << endl;
                totalcredithour = totalcredithour + acourse.creditHours;
                cout << "Course Grade: " << acourse.courseGrade << endl;
                if (acourse.courseGrade == "A") {
                    totalgrades = totalgrades + (4 * acourse.creditHours);
                }
                else if (acourse.courseGrade == "B") {
                    totalgrades = totalgrades + (3 * acourse.creditHours);
                }
                else if (acourse.courseGrade == "C") {
                    totalgrades = totalgrades + (2 * acourse.creditHours);
                }
                else if (acourse.courseGrade == "D") {
                    totalgrades = totalgrades + (1 * acourse.creditHours);
                }
                else if (acourse.courseGrade == "F") {
                    totalgrades = totalgrades + (0 * acourse.creditHours);
                }
                else {
                    cout << "Wrong Course Grade" << endl;
                }


            }

            double finalgpa = totalgrades / totalcredithour;

            cout << "Total Number of credits: " << totalcredithour << endl;
            cout << "Mid Sem GPA: " << finalgpa << endl;



        }
        else {

            cout << "Tution Fees not Paid" << endl;

        }




        cout << "----------------------------" << endl;
        cout << "Type and Enter 'Y' Key to see next ID" << endl;
        exitter();



    }



    void addCourse() {
        Course tempcourse;
        tempcourse.createcourse();

        CoursesVector.push_back(tempcourse);
    }



    void saveuser() {

        string usrstr = "\n" + name + "|" + inttostr(myId) + "|" + tutionpaid + "|" + inttostr(numberofCourse);
        ofstream usrout(DatabaseFileName, ios::app);
        usrout << usrstr;
        usrout.close();


        for (auto& acourse : CoursesVector) {

            string courstr = "\n" + acourse.courseName + "|" + acourse.courseCode + "|" + inttostr(acourse.creditHours) + "|" + acourse.courseGrade;
            ofstream courseout(DatabaseFileName, ios::app);
            courseout << courstr;
            courseout.close();

        }

    }









};









vector<Student> StudentsDB = {};







void setup() {

    StudentsDB.clear();


    ifstream usersif(DatabaseFileName);


    string line;

    getline(usersif, line);

    Student tempstudent;





    while (!usersif.eof()) {

        getline(usersif, line);
        vector<string> Linevector;
        tokenize(line, '|', Linevector);

        if (Linevector[2] == "Y" || Linevector[2] == "N") {

            if (!(tempstudent.myId == 0)) {
                StudentsDB.push_back(tempstudent);
            }


            tempstudent.CoursesVector = {};

            tempstudent.myId = strtoint(Linevector[1]);
            tempstudent.name = Linevector[0];
            tempstudent.tutionpaid = Linevector[2][0];
            tempstudent.numberofCourse = strtoint(Linevector[3]);




        }
        else {

            Course tempcourse;

            tempcourse.courseName = Linevector[0];
            tempcourse.courseCode = Linevector[1];
            tempcourse.creditHours = strtoint(Linevector[2]);
            tempcourse.courseGrade = Linevector[3][0];
            tempstudent.CoursesVector.push_back(tempcourse);

        }







    }


    StudentsDB.push_back(tempstudent);


    usersif.close();

}





















void gotoxy(int x, int y)
{
    cout << setw(x);

    for (; y > 0; y--)
    {
        cout << endl;
    }
}






void saveusers() {
    int userentries;
    cout << "How Many Users you Want to Add??" << endl;
    cin >> userentries;

    for (int i = 1; i <= userentries; i++) {
        Student tempstudent;
        tempstudent.createstudent();
        StudentsDB.push_back(tempstudent);
    }

}





void showallusers() {
    clearscreen();
    for (auto& auser : StudentsDB) {
        auser.showUserInfo();
    }
}

























void front()
{
    clearscreen();
    gotoxy(72, 3);
    cout << "CS102L-B :: Final Exam Task";
    gotoxy(60, 3);
    cout << "Grading";
    gotoxy(59.5, 3);
    cout << "System" << endl;
    cout << "\nDeveloper :: Ezaz Hussain" << endl;
    cout << "RegNo :: 2019121" << endl;
    cout << "Section :: B" << endl;
    cout << "Press Enter to continue.." << endl;


}

void mainmenu() {

    bool notexit = true;


    while (notexit) {
        clearscreen();

        cout << "\n\n\t Grading System \n";


        cout << "\n\t Main Menu\n\n";
        cout << "\t1 Add Student Info\n";
        cout << "\t2 Display Student Info\n";
        cout << "\t3 EXIT\n";


        char ch;
        cout << "\t ";
        cin >> ch;

        switch (ch) {
        case '1':
            saveusers();
            break;
        case '2':
            showallusers();
            break;
        case '3':
            notexit = false;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }

    }

}




int main() {
    setup();
    front();
    mainmenu();
    clearscreen();
    cout << "\n\tQuit\n\n";
    return 0;
}