#include "actor.h"
#include<string>
#include<iostream>
using namespace std;
Actor::Actor(int num, string name, string id)
{
    this->num=num;
    this->name=name;
    this->id=id;
}

int Actor::getNum()
{
    return this->num;
}

string Actor::getName()
{
    return this->name;
}

string Actor::getID()
{
    return this->id;
}

void Actor::setNum(int num)
{
    this->num=num;
}

void Actor::setName(string name)
{
    this->name=name;
}

void Actor::setID(string id)
{
    this->id=id;
}

string Actor::toString()
{
    string sb="Actor Details - ";
    sb.append("Number: " + getNum());
    sb.append(", ");
    sb.append("Name:" + getName());
    sb.append(", ");
    sb.append("Id:" + getID());
    return sb;
}
