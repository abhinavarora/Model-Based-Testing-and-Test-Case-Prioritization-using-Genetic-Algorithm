#include "sequencediagram.h"
#include<iostream>
#include<string>
#include<vector>
#include "node.h"
#include "actor.h"
#include "message.h"
#include "combinedfragment.h"
#include "sequencediagrambuilder.h"
using namespace std;
SequenceDiagram::SequenceDiagram()
{
    this->seq = vector<Node>();//ctor
}

SequenceDiagram::SequenceDiagram(vector<Node> seq)
{
    this->seq = seq;
}

SequenceDiagram::SequenceDiagram(string inputFile)
{
    this->seq = vector<Node>();
    this->actorList = vector<Actor>();
    SequenceDiagramBuilder sdb = SequenceDiagramBuilder(inputFile);
    sdb.build(*this);
}

vector<Actor> SequenceDiagram::getActorList()
{
    return this->actorList;
}

void SequenceDiagram::display()
{
    Node nodeRef;
    Message msgRef;
    CombinedFragment fragRef;
    for(unsigned int i =0; i<(this->seq).size(); i++)
    {
        nodeRef = seq[i];
        switch(nodeRef.getType())
        {
            case RETURN_MESSAGE:
                cout<<"Return Message"<<endl;
                msgRef = nodeRef.getmFrag();
                msgRef.display();
                break;

            case MESSAGE:
                cout<<"Single Message"<<endl;
                msgRef = nodeRef.getmFrag();
                msgRef.display();
                break;

            case ALT:
                cout<<"ALT"<<endl;
                fragRef = nodeRef.getcFrag();
                fragRef.display();
                break;

            case OPT:
                cout<<"OPT"<<endl;
                fragRef = nodeRef.getcFrag();
                fragRef.display();
                break;

            case LOOP:
                cout<<"LOOP"<<endl;
                fragRef = nodeRef.getcFrag();
                fragRef.display();
                break;

            case BREAK:
                cout<<"BREAK"<<endl;
                fragRef = nodeRef.getcFrag();
                fragRef.display();
                break;


        }
    }
}

vector<Node> SequenceDiagram::getStartNode()
{
    return this->seq;
}

void SequenceDiagram::push_seq(Node temp)
{
    (this->seq).push_back(temp);
}

