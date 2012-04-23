#include "combinedfragmentbuilder.h"
#include "node.h"
#include <algorithm>
#include<conio.h>
#include<iostream>
CombinedFragmentBuilder::CombinedFragmentBuilder()
{
    //ctor
}

CombinedFragment CombinedFragmentBuilder::build(TiXmlElement * ele_frag, vector<Message>& msgList)
{
    int nm,nf;
    CombinedFragment cf;
    string type = ele_frag->Attribute("interactionOperator");
    string xmi_id = ele_frag->Attribute("xmi:id");
    if(ele_frag->Attribute("interactionOperator")==NULL)
     {
         cout<<"ERROR combinedfragmentbuilder.cpp";
         getch();
         exit(45);
     }
    if(type == string("loop"))
        cf.setType(LOOP);
    else if(type == string("opt"))
        cf.setType(OPT);
    else if(type == string("alt"))
        cf.setType(ALT);
    else if(type == string("break"))
        cf.setType(BREAK);

    cf.setID(xmi_id);
    switch(cf.getType())
    {
        case LOOP:
        case OPT:
        case BREAK:
            {
            this->setGuardCondition(ele_frag,cf);

            TiXmlElement *ch = ele_frag->FirstChildElement();
            vector<TiXmlElement*> nl;
            nl = ch->GetChildNodes(nl);
            this->createNestedFrag(msgList,nl);
            this->nestedMsg = this->createNestedMsg(cf,msgList,nl);

            nm = this->addMsgNodes(cf,msgList);
            nf = this->addNestedFrag(cf);

            cf.setNoOfNodes(nm + nf);
            break;
            }
        case ALT:
            {
            vector<TiXmlElement*> n1;
            n1 = ele_frag->GetChildNodes(n1);
            for(unsigned int i = 0; i<n1.size(); i++)
            {
                if(n1[i]->Value()!=NULL && n1[i]->Value()== string("operand"))
                {
                    this->setGuardCondition(n1[i],cf);
                    vector<TiXmlElement*> n2;
                    n2 = n1[i]->GetChildNodes(n2);

                    this->createNestedFrag(msgList,n2);
                    this->nestedMsg = this->createNestedMsg(cf,msgList,n2);
                    nm = this->addMsgNodes(cf,msgList);
                    nf = this->addNestedFrag(cf);

                    cf.setNoOfNodes(nm + nf);
                }
            }
            break;
            }

    }

    return cf;
}

int CombinedFragmentBuilder::addMsgNodes(CombinedFragment& cf,vector<Message>& msgList)
{
    int nm = 0;
    CombinedFragment cf_null(string(""),-1);
    CombinedFragment *t = new CombinedFragment();
    *t = cf;
    for(unsigned int k = 0; k<(this->nestedMsg).size(); k++)
    {
        if(Message_List[(this->nestedMsg)[k].getID()]==NULL)
        {
            Node temp((this->nestedMsg)[k].getType(),(this->nestedMsg)[k]);
            cf.push_seq(temp);
            (this->nestedMsg)[k].setFrag(t);
            Message_List[(this->nestedMsg)[k].getID()] = t;
            nm++;
            string xmi_id = t->getID();
            for(unsigned int j =0; j<msgList.size(); j++)
            {
                if(msgList[j].getID()== xmi_id)
                {
                    msgList[j].setFrag(t);
                    break;
                }
            }
        }
    }
    return nm;
}


int CombinedFragmentBuilder::addNestedFrag(CombinedFragment& cf)
{
    int nf=0;
    for(unsigned int k =0; k< (this->nestedFrag).size(); k++)
    {
        CombinedFragment *t = new CombinedFragment();
        *t = (this->nestedFrag)[k];
        Node temp(t->getType(),t);
        cf.push_seq(temp);
        nf++;
    }
    return nf;
}

void CombinedFragmentBuilder::setGuardCondition(TiXmlElement *ele_frag, CombinedFragment& cf)
{
    vector<TiXmlElement*> n;
    n = ele_frag->GetElementsByTagName("specification",n);
    if(n.size()>0)
    {
        cf.setCondition(n[0]->Attribute("value"));
    }
    else
    {
        cf.setCondition("");
    }
}

vector<Message> CombinedFragmentBuilder::createNestedMsg(CombinedFragment& cf,vector<Message>& msgList,vector<TiXmlElement*> nl)
{
    int nm = 0;
    vector<Message> temp;
    for(unsigned int i = 0 ;i < nl.size(); i++)
    {
        if(nl[i]->Value()!=NULL && nl[i]->Value()== string("xmi:Extension"))
        {
            TiXmlElement *ele_mes = nl[i];
            vector<TiXmlElement*> n2;
            n2 = ele_mes->GetElementsByTagName("message",n2);
            nm = n2.size();
            for(unsigned int j =0; j<n2.size(); j++)
            {
                string xmi_id = n2[j]->Attribute("xmi:value");
                Message tm = this->getMsg(xmi_id,msgList,cf);
                temp.push_back(tm);
            }
            sort(temp.begin(),temp.end());
        }
    }
    return temp;
}

void CombinedFragmentBuilder::createNestedFrag(vector<Message>& msgList, vector<TiXmlElement*> nl)
{
    for(unsigned int i = 0; i<nl.size(); i++)
    {
        if(nl[i]->Value()!=NULL && nl[i]->Value()== string("packagedElement"))
        {
            TiXmlElement* nested_frag = nl[i];
            CombinedFragment nf;
            CombinedFragmentBuilder cfb;
            nf = cfb.build(nested_frag,msgList);
            (this->nestedFrag).push_back(nf);
        }
    }
}

Message CombinedFragmentBuilder::getMsg(string xmi_id, vector<Message>& msgList, CombinedFragment& cf)
{
    int index;
    for(unsigned int i = 0; i < msgList.size(); i++)
    {
        if(msgList[i].getID()== xmi_id)
        {
            index = i;
            break;
        }
    }
    return msgList[index];
}
