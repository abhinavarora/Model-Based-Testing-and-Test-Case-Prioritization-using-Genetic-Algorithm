#include "messagebuilder.h"
#include<vector>
#include<algorithm>
#include<sstream>
#include "tinyxml.h"
#include "message.h"
#include "actor.h"
#include<iostream>
void MessageBuilder::build(vector<Actor>& actorList, vector<Message>& msgList,TiXmlElement* docEle)
{
    vector<TiXmlElement*> msg;
    msg=docEle->GetElementsByTagName("message",msg);
    string check = string("uml:Message");
    if(msg.size()>0)
    {
        for(int i = 0; i < msg.size(); i++)
        {
            if(msg[i]->Attribute("xmi:type")!=NULL && msg[i]->Attribute("xmi:type") == string("uml:Message"))
            {

                Message m = this->getMsg(msg[i],docEle,actorList);
                msgList.push_back(m);
            }
        }
    }
    sort(msgList.begin(),msgList.end());
}

Message MessageBuilder::getMsg(TiXmlElement* mes,TiXmlElement* docEle,vector<Actor>& actorList)
{
    int type,num;
    string name = mes->Attribute("name");
    string xmi_id = mes->Attribute("xmi:id");
    string receiveEvent = mes->Attribute("receiveEvent");
    string sendEvent = mes->Attribute("sendEvent");
    string from = this->getActorName(actorList,docEle,sendEvent);
    string to = this->getActorName(actorList,docEle,receiveEvent);
    string msgtype = mes->Attribute("messageSort");
    if(msgtype==string("reply"))
        type=0;
    else
        type=1;

    vector<TiXmlElement*> n;
    n = mes->GetElementsByTagName("number",n);
    string temp = n[0]->Attribute("xmi:value");
    istringstream(temp)>>num;
    Message m = Message(num,xmi_id,name,from,to,type);
    return m;
}

string MessageBuilder::getActorName(vector<Actor>& actorList,TiXmlElement* docEle,string event)
{
    int index = 0;
    vector<TiXmlElement*> n;
    n = docEle->GetElementsByTagName("fragment",n);
    if(n.size()>0)
    {
        for(int i = 0; i<n.size(); i++)
        {
            string frag_id = n[i]->Attribute("xmi:id");
            if(frag_id==event)
            {
                string actor_id = n[i]->Attribute("covered");
                for(int j = 0; j<actorList.size(); j++ )
                {
                    if(actorList[j].getID()==actor_id)
                    {
                        index=j;
                        break;
                    }
                }
            }
        }
    }
    return actorList[index].getName();
}
