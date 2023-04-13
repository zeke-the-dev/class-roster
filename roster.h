//
// Created by ezekielnwafor on 4/8/23.
//

#ifndef CLASS_ROSTER_ROSTER_H
#define CLASS_ROSTER_ROSTER_H

#include "student.h"
#include <string>

namespace roster {

    class roster {

        //generic constructor declaration
        roster();


        //public function declarations
        public:
            student::student* classRosterArray[5];

            void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

            void remove(string studentID);

            void printAll();

            void printAverageDaysInCourse(string studentID);

            void printInvalidEmails();

            void printByDegreeProgram(DegreeProgram degreeProgram);


    };

} // roster

#endif //CLASS_ROSTER_ROSTER_H
