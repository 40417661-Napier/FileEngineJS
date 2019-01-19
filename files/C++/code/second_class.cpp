#include <iostream>
#include <string>
#include <vector>

using namespace std;

class mydata
{
  private:
    string name;
    vector<char> grades;

  public:
    mydata(string inName) { this->name = inName; }

    string getName(void) { return name; }
    void addGrade(char newGrade);
    string getGrades(void);
};

void mydata::addGrade(char newGrade)
{
    grades.push_back(newGrade);
}

string mydata::getGrades(void)
{
    string result;
    for (auto a : grades)
    {
        result += a;
        result += " ";
    }
    return result;
}

int main()
{
    vector<mydata> myStudents;
    string tempString;
    int i = 1;

    while (true)
    {
        cout << "Enter name of student " << i << " (N to quit) : " << endl;
        cin >> tempString;

        if (tempString == "N")
        {
            break;
        }
        mydata tempStudent(tempString);

        while (true)
        {
            cout << "Enter grade, N to quit : ";
            cin >> tempString;
            if (tempString != "N")
            {
                tempStudent.addGrade(tempString[0]);
            }
            else
            {
                break;
            }
        }
        myStudents.push_back(tempStudent);
        i++;
    }




    for (auto a : myStudents)
    {
        cout << a.getName() << "'s grades are : " << a.getGrades() << endl;
    }

    return 0;
}

/* 
Modify second_class.cpp so that after entering a number of students and their grades, the 
user can print the grade of any individual student identified by name. If no data has been 
entered for a student of the name given, the program should give an appropriate warning 
and continue running
 */