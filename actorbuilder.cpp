#include "actorbuilder.h"
#include "actor.h"
#include "tinyxml.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;

ActorBuilder::ActorBuilder()
{

}

void ActorBuilder::build(vector<Actor>& actorList, TiXmlElement* docEle)
{
    vector<TiXmlElement*> act;
    act=docEle->GetElementsByTagName("lifeline",act);
    if(act.size()>0)
    {
        for(unsigned int i = 0 ; i<act.size() ; i++)
        {
                Actor a = getActor(i+1,act[i]);
                actorList.push_back(a);
        }
    }

}

Actor ActorBuilder::getActor(int num,TiXmlElement* act)
{
    string name = act->Attribute("name");
    string id = act->Attribute("xmi:id");
    Actor a = Actor(num,name,id);
    return a;
}
