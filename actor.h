#ifndef ACTOR_H
#define ACTOR_H
#include<string>
using namespace std;
class Actor
{
    public:
        /** Default constructor */
        Actor(int,string,string);
        int getNum();
        string getName();
        string getID();
        void setNum(int);
        void setName(string);
        void setID(string);
        string toString();
    private:
        int num ;
        string name;
        string id;
};

#endif // ACTOR_H
