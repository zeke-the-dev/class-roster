//
// Created by ezekielnwafor on 4/8/23.
//
using namespace std;
#include <iostream>
#include <string>
#include "student.h"

namespace student {

    //default constructor definition
    student::student() {
    }

    //parameterized constructor definition
    student::student(string studentId, string firstName, string lastName, string emailAddress, string age, string completionDays[3], string degreeProgram) {
        studentId = this->studentId;
        firstName = this->firstName;
        lastName = this->lastName;
        emailAddress = this->emailAddress;
        age = this->age;
        completionDays = this->daysToCompletion;
        degreeProgram = this->degreeProgram;
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

    string student::getAge(){
        return this->age;
    }

    string student::getDaysToCompletion(){
        string days;
        for(string d: this->daysToCompletion){
            days = d + ", ";
        }
        return days;
    }

    string student::getDegreeProgram(){
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

    void student::setAge(string newAge){
        this->age = newAge;
    }

    void student::setDegreeProgram(string newDegreeProgram){
        this->degreeProgram = newDegreeProgram;
    }

    void student::setCompletionDays(int pos, string days){
        this->daysToCompletion[pos] = days;
    }

    string student::print(){
        cout<<getStudentId()<<"\t"<<"First name:"<<getFirstName()<<"Last Name:"<<getLastName()<<"\t"<<"Age:"<<getAge()<<"\t"<<"daysInCourse:"<<"{"<<getDaysToCompletion()<<"}"<<"\t"<<"Degree Program:"<<getDegreeProgram()<<endl;
    }


} // student