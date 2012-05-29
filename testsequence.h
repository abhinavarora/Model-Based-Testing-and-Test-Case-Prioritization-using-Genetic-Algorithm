#ifndef TESTSEQUENCE_H
#define TESTSEQUENCE_H
#define RETURN_MESSAGE_PRI 0
#define MESSAGE_PRI 1
#define LOOP_PRI 20
#define ALT_PRI 9
#define OPT_PRI 6
#define BREAK_PRI 12
#include "message.h"
#include "combinedfragment.h"
#include<vector>
#include<map>
#include<sstream>
extern map<string,CombinedFragment*>  Message_List;
extern map<string,int>  Partitions;
extern map<string,int> Num_Part;
extern vector<string> SeqD_conditions;
class TestSequence
{
    public:
        /** Default constructor */
        TestSequence();
        /** Copy constructor
         *  \param other Object to copy from
         */
        TestSequence(const TestSequence&);
        bool operator < (const TestSequence&) const;
        void display();
        int getLength();
        int compareTo(TestSequence);
        int getPriority() const;
        void setPriority(int);
        void incrementPriority(int);
        void decrementPriority(int);
        void addMessage(Message);
        Message getLastMessage();
        vector<Message> getTestSequence() const;
        void appendSequence(TestSequence);
        map<string,int> getConditions() const;
        void evalConditions();
        void setNum(int);
        int getNum() const;

    private:
        vector<Message> message;
        int priority;
        map<string,int> conditions;
        int number;

};

#endif // TESTSEQUENCE_H
