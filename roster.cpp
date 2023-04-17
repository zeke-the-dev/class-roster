//
// Created by ezekielnwafor on 4/8/23.
//
using namespace std;
#include "roster.h"
#include "student.h"
#include <string>
#include "degree.h"


namespace roster {

    //parse data input for record creation
    void roster::parse(string studentData) {

        /* I need to find a way to "move" my starting point from one delimiter to another:
        *
        * find the position where the first delimiter occurs
        *
        * create a sub string from the 0th position of the string to the first instance of the delimiter then do the following:
        *
        * 1)Process the substring
        *
        * 2)set a "new 0th" position to be the most recent occurrence of my chosen delimiter
        *
        * 3)Create a substring ranging from my "new 0th" position to the next occurrence of my delimiter
        *
        * repeat this until done
        * */

        //delimiter used to split a string
        string del = {","};

        //int representation for the right hand side position of the string to be processed
        int rightHandSide;

        //int representation for the left hand side position of the string to be processed
        int leftHandSide;

        //student ID number
        string idNum;

        //first name
        string fName;

        //last name
        string lName;

        //email address
        string email;

        //student age
        int studentAge;

        //days in class one
        int daysInClassOne;

        //days in class two
        int daysInClassTwo;

        //days in class three
        int daysInClassThree;

        //student's enrolled program
        DegreeProgram enrolledProgram;

        //parse from left to right and find the desired delimiter (comma)
        rightHandSide = studentData.find(del);

        //create a sub-string to get student id
        idNum = studentData.substr(0, rightHandSide);

        //set position of the left-hand side to the position of the current delimiter - this is the new starting point
        leftHandSide = rightHandSide;

        //traverse right to find next delimiter
        rightHandSide = studentData.find(del, leftHandSide + 1);

        //create substring to process students first name
        fName = studentData.substr(leftHandSide,  (rightHandSide - 1) - leftHandSide);

        //set new position of the left-hand side
        leftHandSide = rightHandSide;

        //traverse to find next delimeter
        rightHandSide = studentData.find(del, leftHandSide+1);

        //create substring to process students last name
        lName= studentData.substr(leftHandSide, (rightHandSide-1)-leftHandSide);

        //set position of the left-hand side to the position of the current delimiter - this is the new starting point
        leftHandSide = rightHandSide;

        //traverse right to find next delimiter
        rightHandSide = studentData.find(del, leftHandSide + 1);

        //create substring to process students email
        email = studentData.substr(leftHandSide, (rightHandSide-1)-leftHandSide);

        //set position of the left-hand side to the position of the current delimiter - this is the new starting point
        leftHandSide = rightHandSide;

        //traverse right to find next delimiter
        rightHandSide = studentData.find(del, leftHandSide + 1);

        //create substring to find the student age
        studentAge = stoi(studentData.substr(leftHandSide, (rightHandSide-1) - leftHandSide));

        //set position of the left-hand side to the position of the current delimiter - this is the new starting point
        leftHandSide = rightHandSide;

        //traverse right to find next delimiter
        rightHandSide = studentData.find(del, leftHandSide + 1);

        //process the days in class one
        daysInClassOne = stoi(studentData.substr(leftHandSide, (rightHandSide -1) - leftHandSide));

        //set position of the left-hand side to the position of the current delimiter - this is the new starting point
        leftHandSide = rightHandSide;

        //traverse right to find next delimiter
        rightHandSide = studentData.find(del, leftHandSide + 1);

        //process the days in class two
        daysInClassTwo = stoi(studentData.substr(leftHandSide, (rightHandSide - 1) - leftHandSide));

        //set position of the left-hand side to the position of the current delimiter - this is the new starting point
        leftHandSide = rightHandSide;

        //traverse right to find next delimiter
        rightHandSide = studentData.find(del, leftHandSide + 1);

        //process the days in class three
        daysInClassThree = stoi(studentData.substr(leftHandSide, (rightHandSide - 1) - leftHandSide));

        //process the students degree program
        if(studentData.back() == 'y'){
            enrolledProgram = SECURITY;
        } else if (studentData.back() == 'k'){
            enrolledProgram = NETWORK;
        } else{
            enrolledProgram = SOFTWARE;
        }

        //add student record
        roster::add(idNum, fName, lName, email, studentAge, daysInClassOne, daysInClassTwo, daysInClassThree, enrolledProgram);

    }

    //add a student record to a roster
    void roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
                     int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

        //make sure the roster isn't full
        if(rosterCt < 5){
            classRosterArray[rosterCt] = new student::student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
        }
        rosterCt++;
    }

    void roster::remove(string studentID) {

        for(int s = 0; s < 5; s++){
            if(classRosterArray[s]->getStudentId() == studentID){
                cout<<"Student with id " <<studentID<<" has been found. Deleting..."<<endl;
                cout<<endl;
                delete classRosterArray[s];
                classRosterArray[s] = nullptr;
                rosterCt--;
                cout<<"Record deleted successfully!"<<endl;
                cout<<endl;
            } else{
                cout<<"Student with ID: "<<studentID<<"Does not exist"<<endl;
                cout<<endl;
            }
        }

    }

    void roster::printAll() {
        for(int s = 0; s < 5; s++){
            classRosterArray[s]->print();
        }
    }

    void roster::printAverageDaysInCourse(string studentID){
        int ave;

        for(int s = 0; s < 5; s++){
            if(classRosterArray[s]->getStudentId() == studentID){
               ave=+ classRosterArray[s]->getDaysToCompletion()[0];

               ave=+ classRosterArray[s]->getDaysToCompletion()[1];

               ave=+ classRosterArray[s]->getDaysToCompletion()[2];

               ave = ave/3;
            }
        }
        cout<<"The average class completion time for student with ID " << studentID << " is " << ave <<endl;
        cout<<endl;
    }

    void roster::printInvalidEmails() {

        string emailToCheck;

        int problemPos;
        int missingAtSymbol;
        int missingDot;
        int spacesFound;

        for(int s=0; s < 5; s++){
            emailToCheck = classRosterArray[s]->getEmailAddress();

            missingAtSymbol = emailToCheck.find("@");
            problemPos = missingAtSymbol;

            if(missingAtSymbol == -1){
                cout<<"Invalid email addrress - missing \'@' for the email address "<< emailToCheck <<endl;
                cout<<endl;
            }else{
                missingDot = emailToCheck.find(".");
                problemPos = missingDot;

                if(missingDot == -1){
                    cout<<"Invalid email addrress - missing \'.' for the email address "<< emailToCheck <<endl;
                    cout<<endl;
                }else{
                    spacesFound = emailToCheck.find(" ");
                    problemPos = spacesFound;

                    if(problemPos >= 0){
                        cout<<"Invalid email addrress - spaces were found for the email address "<< emailToCheck <<endl;
                        cout<<endl;
                    }
                }
            }
        }
        if(problemPos == -1){
            cout<<"No invalid emails found"<<endl;
            cout<<endl;
        }
    }

    void roster::printByDegreeProgram(DegreeProgram degreeProgram) {
        for (int i = 0; i < 5; ++i) {
            if(classRosterArray[i]->getDegreeProgram() == degreeProgram){
                classRosterArray[i]->print();
            }
        }
    }

    roster::~roster() {
        for(int s =0; s < 5; s++){
            delete classRosterArray[s];
            classRosterArray[s] = nullptr;
            rosterCt --;
        }
    }

} // roster