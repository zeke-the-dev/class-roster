//
// Created by ezekielnwafor on 4/8/23.
//
using namespace std;
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

namespace student {

    //default constructor definition
    student::student() {
    }

    //parameterized constructor definition
    student::student(string studentId, string firstName, string lastName, string emailAddress, int age,  int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
        studentId = this->studentId;
        firstName = this->firstName;
        lastName = this->lastName;
        emailAddress = this->emailAddress;
        age = this->age;
        degreeProgram = this->degreeProgram;
        this->daysToCompletion[0] = daysInCourse1;
        this->daysToCompletion[1] = daysInCourse2;
        this->daysToCompletion[2] = daysInCourse3;
    }

    //accessor method definitions:
    string student::getStudentId(){
        return this->studentId;
    }

    string student::getFirstName(){
        return this->firstName;
    }

    string student::getLastName(){
        return this->lastName;
    }

    string student::getEmailAddress(){
        return this->emailAddress;
    }

    int student::getAge(){
        return this->age;
    }

    int* student::getDaysToCompletion(){
        return this->daysToCompletion;
    }

    DegreeProgram student::getDegreeProgram(){
        return this->degreeProgram;
    }

    //Mutator method definitions:
    void student::setStudentId(string newId){
        this->studentId = newId;
    }

    void student::setFirstName(string newFirstName){
        this->firstName = newFirstName;
    }

    void student::setLastName(string newLastName){
        this->lastName = newLastName;
    }

    void student::setEmailAddress(string newEmailAddress){
        this->emailAddress = newEmailAddress;
    }

    void student::setAge(int newAge){
        this->age = newAge;
    }

    void student::setDegreeProgram(DegreeProgram newDegreeProgram){
        this->degreeProgram = newDegreeProgram;
    }

    void student::setCompletionDays(int pos, int days){
        this->daysToCompletion[pos] = days;
    }

    string student::print(){
        cout<<getStudentId()<<"\t"<<"First name:"<<getFirstName()<<"Last Name:"<<getLastName()<<"\t"<<"Age:"<<getAge()<<"\t"<<"daysInCourse:"<<"{"<<getDaysToCompletion()<<"}"<<"\t"<<"Degree Program:"<<getDegreeProgram()<<endl;
    }


} // student