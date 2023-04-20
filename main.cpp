#include <iostream>
#include "roster.h"
using namespace std;

int main() {

    //array of student data. Personal info added to end (requirement a)
    const string studentData[] =

            {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Ezekiel,Nwafor,enwafo1@student.wgu.edu,31,10, 21, 2,SOFTWARE"};

    roster::roster classRoster;

    for(string s : studentData){
        classRoster.parse(s);
    }

    classRoster.printAll();

    classRoster.printInvalidEmails();

    for(int s = 0; s < 5; s++){
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[s]->getStudentId());
    }

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    classRoster.remove("A3");

    classRoster.printAll();

    classRoster.remove("A3");

    return 0;
}
