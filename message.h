#ifndef MESSAGE_H
#define MESSAGE_H
#include<string>
using namespace std;
class Message
{
    public:
        /** Default constructor */
        Message(int,string,string,string,string,int);
        Message(const Message&);
        bool operator < (const Message&) const;
//        CombinedFragment getFrag();
        string getID();
        int getNum() const;
        int getType();
        string getName();
        string getFrom();
        string getTo();
        void setID(string);
        void setFrom(string);
        void setTo(string);
        void setName(string);
        void setNum(int);
        void setType(int);
//        void setFrag(CombinedFragment);
        void display();
    private:
        int num;
        string xmi_id;
        string name;
        string from;
        string to;
        int type;
//        CombinedFragment frag;
};

#endif // MESSAGE_H
