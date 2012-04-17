#ifndef MESSAGEBUILDER_H
#define MESSAGEBUILDER_H
#include<vector>
#include<string>
#include "tinyxml.h"
#include "message.h"
#include "actor.h"
using namespace std;

class MessageBuilder
{
    public:
        void build(vector<Actor>&,vector<Message>&,TiXmlElement*);
        string getActorName(vector<Actor>&,TiXmlElement*,string);

    private:
        Message getMsg(TiXmlElement*,TiXmlElement*,vector<Actor>&);
};

#endif // MESSAGEBUILDER_H
