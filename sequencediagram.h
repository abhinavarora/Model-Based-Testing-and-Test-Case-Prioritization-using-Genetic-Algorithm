#ifndef SEQUENCEDIAGRAM_H
#define SEQUENCEDIAGRAM_H
#include<string>
#include<vector>
#include "node.h"
#include "actor.h"
using namespace std;

class SequenceDiagram
{
    public:
        /** Default constructor */
        SequenceDiagram();
        SequenceDiagram(vector<Node>);
        SequenceDiagram(string);
        vector<Actor> getActorList();
        void display();
        vector<Node> getStartNode();
        void push_seq(Node);
    protected:
        vector<Node> seq;
    private:
        vector<Actor> actorList;
};

#endif // SEQUENCEDIAGRAM_H
