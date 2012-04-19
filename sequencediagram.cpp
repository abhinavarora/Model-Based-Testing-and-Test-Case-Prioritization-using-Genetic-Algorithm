#include "sequencediagram.h"
#include<string>
#include<vector>
#include "node.h"
#include "actor.h"
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
//    SequenceDiagramBuilder sdb = SequenceDiagramBuilder(inputFile);
//    sdb.build(this);
}

vector<Actor> SequenceDiagram::getActorList()
{
    return this->actorList;
}

void SequenceDiagram::display()
{

}

vector<Node> SequenceDiagram::getStartNode()
{
    return this->seq;
}
