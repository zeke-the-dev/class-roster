//
// Created by ezekielnwafor on 4/8/23.
//

#include "roster.h"
#include <iostream>
#include <string>
#include "student.h"

using namespace std;



namespace roster {

    //parse data input for record creation
    void roster::parse(string studentData) {

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
        DegreeProgram::DegreeProgram enrolledProgram;


        int rhs = studentData.find(",");
        idNum = studentData.substr(0, rhs);

        int lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        fName = studentData.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        lName = studentData.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        email = studentData.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        studentAge = stoi(studentData.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        daysInClassOne = stoi(studentData.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        daysInClassTwo = stoi(studentData.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        daysInClassThree = stoi(studentData.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);

        //process the students degree program
        enrolledProgram = DegreeProgram::SOFTWARE;
        if (studentData.back() == 'Y')
            enrolledProgram = DegreeProgram::SECURITY;
        else if (studentData.back() == 'K') enrolledProgram = DegreeProgram::NETWORK;

        //add student record
        roster::add(idNum, fName, lName, email, studentAge, daysInClassOne, daysInClassTwo, daysInClassThree, enrolledProgram);

    }

    //add a student record to a roster
    void roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
                     int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram::DegreeProgram degreeprogram) {

        //make sure the roster isn't full
        if (rosterCt < 5)
            classRosterArray[rosterCt] = new student::student (studentID, firstName, lastName, emailAddress, age,
                                                              daysInCourse1, daysInCourse2, daysInCourse3,
                                                              degreeprogram);
        rosterCt++;
    }

    void roster::remove(string studentID) {

        bool match = false;

        for(int s = 0; s < 5; s++){
            if(classRosterArray[s]->getStudentId() == studentID){
                match = true;
                cout<<"Student with id " <<studentID<<" has been found. Deleting..."<<endl;
                cout<<endl;
                delete classRosterArray[s];
                classRosterArray[s] = nullptr;
                rosterCt--;
                cout<<"Record deleted successfully!"<<endl;
                cout<<endl;
            }
        }
        if(match){
            cout<<"Student with ID: "<<studentID<<" Does not exist"<<endl;
            cout<<endl;
        }
    }

    void roster::printAll() {
        for(int s = 0; s < 5; s++){
            classRosterArray[s]->print();
        }
        cout<<endl;
    }

    void roster::printAverageDaysInCourse(string studentID){
        int ave = 0;

        for(int s = 0; s < 5; s++){
            if(classRosterArray[s]->getStudentId() == studentID){
               ave= ave+ classRosterArray[s]->getDaysToCompletion()[0];

               ave= ave+ classRosterArray[s]->getDaysToCompletion()[1];

               ave= ave+ classRosterArray[s]->getDaysToCompletion()[2];

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
    }

    void roster::printByDegreeProgram(DegreeProgram::DegreeProgram degreeProgram) {
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

    roster::roster() = default;

} // roster