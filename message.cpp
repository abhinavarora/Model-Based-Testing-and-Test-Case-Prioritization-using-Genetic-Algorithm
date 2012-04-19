#include "message.h"
#include<string>
#include<iostream>
#include "combinedfragment.h"
using namespace std;
class CombinedFragment;
Message::Message()
{

}

Message::Message(int num,string xmi_id,string name,string from, string to,int type)
{
    this->num = num;
    this->from = from;
    this->to = to;
    this->name = name;
    this->xmi_id = xmi_id;
    this->type = type;
}

Message::Message(const Message& another)
{
    this->num = another.num;
    this->xmi_id = another.xmi_id;
    this->from = another.from;
    this->to = another.to;
    this->name = another.name;
    this->type = another.type;
    this->frag = another.frag;
}

bool Message::operator < (const Message& temp) const
{
    return ((this->getNum()) < (temp.getNum()));
}


CombinedFragment Message::getFrag()
{
    return *(this->frag);
    }


string Message::getID()
{
    return this->xmi_id;
}

int Message::getNum() const
{
    return this->num;
}

int Message::getType()
{
    return this->type;
}

string Message::getName()
{
    return this->name;
}

string Message::getFrom()
{
    return this->from;
}

string Message::getTo()
{
    return this->to;
}

void Message::setID(string xmi_id)
{
    this->xmi_id=xmi_id;
}

void Message::setFrom(string from)
{
    this->from=from;

}

void Message::setTo(string to)
{
    this->to=to;
}

void Message::setName(string name)
{
    this->name=name;
}

void Message::setNum(int num)
{
    this->num=num;
}

void Message::setType(int type)
{
    this->type=type;
}


void Message::setFrag(CombinedFragment* frag)
{
    this->frag=frag;
}


void Message::display()
{
    cout<<"[Message ID: "<<this->num<<" | Name: "<<this->name<<" | From: "<<this->from<<" | To: "<<this->to<<"]";
}
