#include <iostream>
#include <string>
#include <vector>

using namespace std;

class mydata
{
  public:
    mydata(string inName) { this->name = inName; }
    vector<char> grades;
    string name;
    void addGrade(char newGrade);
    void addName(string newName);
    string getName(void) { return name; }
    string getGrade(void);
};

void mydata::addGrade(char newGrade)
{
    grades.push_back(newGrade);
}
void mydata::addName(string newName)
{
    name = newName;
}
string mydata::getGrade(void)
{
    string result;
    for (auto a : grades) {
        result += a;
        result += " ";
    }
    return result;
}

vector<mydata> students;

int main()
{
    while (true)
    {
        int i = 0;
        string tempNameString;
        cout << "Enter name of student, X to quit : " << endl;
        getline(cin, tempNameString);
        if (tempNameString != "X")
        {

            printf("0\n");
            mydata student(tempNameString);

            //students[i].addName(tempNameString);
            printf("1\n");

            while (true)
            {
                string tempString;
                cout << "Enter grade, 'N' to quit : ";
                getline(cin, tempString);
                if (tempString != "N")
                {
                    student.addGrade(tempString[0]);
                }
                else
                {
                    break;
                }
            }
            students.push_back(student);

            i++;
        }
        else
        {
            break;
        }
    }
    //traverse and print out
    cout << endl;
    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].getName() << " : " << endl;
        cout << "   " << students[i].getGrade() << endl;
    }
    return 0;
}

/* 
Modify first_class.cpp so that the user can input grades for an unlimited number of students, 
typing X to indicate that the input is complete; the programme should then output the list of 
all students entered, each with their grade. When complete and tested, compare your program 
to second_class.cpp.
 */