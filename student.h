//
// Created by ezekielnwafor on 4/8/23.
//
#include <string>
#include "degree.h"
using std::string;
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
            int age;
            DegreeProgram degreeProgram;
            int daysToCompletion[3]; //days spent in each course

        public:
            void print();

            //accessor method declaration (requirement D.2.A):
            string getStudentId();
            string getFirstName();
            string getLastName();
            string getEmailAddress();
            int getAge();
            int * getDaysToCompletion();
            DegreeProgram getDegreeProgram();

            //mutator method declaration (requirement D.2.B):
            void setStudentId(string newId);
            void setFirstName(string newFirstName);
            void setLastName(string newLastName);
            void setEmailAddress(string newEmailAddress);
            void setAge(int newAge);
            void setDegreeProgram(DegreeProgram newDegreeProgram);
            void setCompletionDays(int pos, int days);

            //default constructor declaration (requirement D.2.D):
            student();

            //parameterized constrictor declaration (requirement D.2.D):
            student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);


    };

} // student

#endif //CLASS_ROSTER_STUDENT_H
