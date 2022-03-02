//
//  Person.h
//  Try it Out: Stacks and Queues 7.2
//
//  Created by Coleton Watt on 3/1/22.
//
#pragma once


#include <iostream>
#include <string>
using namespace std;
 
class Person {
public:
    Person(): name("None"), amount(0) {}
    Person(string name, int amount) : name(name), amount(amount) {}
     bool operator >( const Person &g);
     bool operator ==( const Person &g);
     bool operator >=( const Person &g);
     bool operator <=( const Person &g);
     bool operator <( const Person &g);
     bool operator !=( const Person &g);
      bool operator >(int x);
     bool operator ==(int x);
     bool operator >=(int x);
     bool operator <=(int x);
     bool operator <(int x);
     bool operator !=(int x);
    friend bool operator >(int x, const Person &g);
    friend bool operator ==(int x, const Person &g);
    friend bool operator >=(int x, const Person &g);
    friend bool operator <=(int x, const Person &g);
    friend bool operator <(int x, const Person &g);
    friend bool operator !=(int x, const Person &g);
   // void operator = (const Person& list);


    int getAmount() const;
    friend ostream& operator <<(ostream &out, const Person &g);
private:
    string name;
    int amount;
};

bool Person::operator >(const Person &g) {
 return amount > g.amount;
}
bool Person::operator ==( const Person &g){
    return amount == g.amount;
}
bool Person::operator >=( const Person &g){
    return amount >= g.amount;
}
bool Person::operator <=( const Person &g){
    return amount <= g.amount;
}
bool Person::operator <( const Person &g){
    return amount < g.amount;
}

bool Person::operator !=( const Person &g){
    return amount != g.amount;
}
bool Person::operator >(int x){
    return amount > x;
}
bool Person::operator ==(int x){
    return amount == x;
}
bool Person::operator >=(int x){
    return amount >= x;
}
bool Person::operator <=(int x){
    return amount <= x;
}
bool Person::operator <(int x){
    return amount < x;
}
bool Person::operator !=(int x){
    return amount != x;
}

bool operator >(int x, const Person &g){
    return x > g.amount;
}
bool operator ==(int x, const Person &g){
    return x == g.amount;
}
bool operator >=(int x, const Person &g){
    return x >= g.amount;
}
bool operator <=(int x, const Person &g){
    return x <= g.amount;
}
bool operator <(int x, const Person &g){
    return x < g.amount;
}
bool operator !=(int x, const Person &g){
    return x != g.amount;
}





int Person::getAmount() const {
 return amount;
}
ostream& operator <<(ostream &out, const Person &g) {
 out << g.name << ": " << g.amount;
 return out;
}
