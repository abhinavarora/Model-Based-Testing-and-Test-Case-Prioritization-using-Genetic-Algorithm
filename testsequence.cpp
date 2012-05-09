#include "testsequence.h"
#include<iostream>
using namespace std;

TestSequence::TestSequence()
{
    //ctor
    this->message = vector<Message>();
    this->priority = 0;
}

TestSequence::TestSequence(const TestSequence& another)
{
    //copy ctor
    this->message = another.getTestSequence();
    this->priority = another.getPriority();
}

void TestSequence::display()
{
    Message msg;
    cout<<"Test Sequence : ";
    for(unsigned int i =0; i<(this->message).size(); i++)
    {
        msg = (this->message)[i];
        cout<<msg.getID()<<" ";
    }
    cout<<" | Priority: "<<(this->priority)<<endl;
}

int TestSequence::getLength()
{
    return (this->message).size();
}

int TestSequence::compareTo(TestSequence ts)
{
    int k = ts.getPriority() - (this->getPriority());
    if(k==0)
        return ((this->getLength() < ts.getLength()) ? (this->getLength()) : ts.getLength());
    else
        return k;
}

int TestSequence::getPriority() const
{
    return (this->priority);
}

void TestSequence::setPriority(int priority)
{
    this->priority = priority;
}

void TestSequence::incrementPriority(int k)
{
    this->priority += k;
}

void TestSequence::decrementPriority(int k)
{
    this->priority -= k;
}

void TestSequence::addMessage(Message message)
{
    (this->message).push_back(message);
}

Message TestSequence::getLastMessage()
{
    return (this->message)[(this->message).size() -1];
}

vector<Message> TestSequence::getTestSequence() const
{
    return this->message;
}

void TestSequence::appendSequence(TestSequence ts)
{
    vector<Message> temp = ts.getTestSequence();
    (this->message).insert((this->message).end(), temp.begin(), temp.end());
}

bool TestSequence::operator < (const TestSequence& temp) const
{
    return((this->getPriority()) > temp.getPriority());
}
