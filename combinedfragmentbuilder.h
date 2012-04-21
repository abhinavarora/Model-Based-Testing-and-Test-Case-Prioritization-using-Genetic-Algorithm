#ifndef COMBINEDFRAGMENTBUILDER_H
#define COMBINEDFRAGMENTBUILDER_H
#include "combinedfragment.h"
#include "message.h"
#include "tinyxml.h"
#include<vector>
#include<string>
class CombinedFragmentBuilder
{
    public:
        /** Default constructor */
        CombinedFragmentBuilder();
        CombinedFragment build(TiXmlElement *, vector<Message>);
        int addMsgNodes(CombinedFragment&);
        int addNestedFrag(CombinedFragment&);
        void setGuardCondition(TiXmlElement* ,CombinedFragment&);
        vector<Message> createNestedMsg(CombinedFragment&,vector<Message>,vector<TiXmlElement*>);
        void createNestedFrag(vector<Message>, vector<TiXmlElement *>);
        Message getMsg(string,vector<Message>,CombinedFragment&);
    private:
        vector<CombinedFragment> nestedFrag;
        vector<Message> nestedMsg;
};

#endif // COMBINEDFRAGMENTBUILDER_H
