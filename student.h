//
// Created by ezekielnwafor on 4/8/23.
//
using namespace std;
#include <iostream>
#include <string>
#ifndef CLASS_ROSTER_STUDENT_H
#define CLASS_ROSTER_STUDENT_H


namespace student {

    class student {

        //class member declaration (requirement D.1):
        private:
            string studentId;
            string firstName;
            string lastName;
            string emailAddress;
            string age;
            string degreeProgram;
            string daysToCompletion[3];

        public:
            string print();

            //accessor method declaration (requirement D.2.A):
            string getStudentId();
            string getFirstName();
            string getLastName();
            string getEmailAddress();
            string getAge();
            string getDaysToCompletion();
            string getDegreeProgram();

            //mutator method declaration (requirement D.2.B):
            void setStudentId(string newId);
            void setFirstName(string newFirstName);
            void setLastName(string newLastName);
            void setEmailAddress(string newEmailAddress);
            void setAge(string newAge);
            void setDegreeProgram(string newDegreeProgram);
            void setCompletionDays(int pos, string days);

            //default constructor declaration (requirement D.2.D):
            student();

            //parameterized constrictor declaration (requirement D.2.D):
            student(string studentId, string firstName, string lastName, string emailAddress, string age, string completionDays[3], string degreeProgram);


    };

} // student

#endif //CLASS_ROSTER_STUDENT_H
