#include "combinedfragment.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;

CombinedFragment::CombinedFragment()
{
    this->condition = vector<string>();
    this->noOfNodes = vector<int>();
}

CombinedFragment::CombinedFragment(string condition)
{
    this->condition = vector<string>();
    this->noOfNodes = vector<int>();

    this->condition.push_back(condition);
    this->noOfNodes.push_back(1);
}

CombinedFragment::CombinedFragment(string condition, int noOfNodes)
{
    this->condition = vector<string>();
    this->noOfNodes = vector<int>();

    this->condition.push_back(condition);
    this->noOfNodes.push_back(noOfNodes);
}

void CombinedFragment::display()
{
    cout<<"[CombinedFragment]"<<endl;
    cout<<"= = = = = = = B E G I N = = = = = = ="<<endl;

    if(getNoOfPartitions() == 1)
    {
        cout<<"Condition: "<<(this->condition)[0]<<endl;
    }
    else
    {
        unsigned int i;
        for(i = 0 ; i<(this->condition).size(); i++)
        {
            cout<<"Partition "<<(i+1)<<" ::Condition: "<<(this->condition)[i]<<" | No Of Nodes: "<<(this->noOfNodes)[i]<<endl;
        }
        if((unsigned)getNoOfPartitions() > i)
        {
            cout<<"Partition "<<(i+1)<<" :: No Of Nodes: "<<(this->noOfNodes)[i]<<endl;
        }
    }
    SequenceDiagram::display();
    cout<<"= = = = = = = E N D = = = = = = ="<<endl;
}

string CombinedFragment::getID()
{
    return this->xmi_id;
}

int CombinedFragment::getNoOfPartitions()
{
    return (this->noOfNodes).size();
}

int CombinedFragment::getType()
{
    return this->type;
}

string CombinedFragment::getCondition(int index)
{
    return (this->condition)[index];
}

int CombinedFragment::getNoOfNodes(int index)
{
    return (this->noOfNodes)[index];
}

string CombinedFragment::getCondition()
{
    return (this->condition)[0];
}

int CombinedFragment::getNoOfNodes()
{
    return (this->noOfNodes)[0];
}

void CombinedFragment::setID(string xmi_id)
{
    this->xmi_id = xmi_id;
}

void CombinedFragment::setCondition(string condition)
{
    (this->condition).push_back(condition);
}

void CombinedFragment::setType(int type)
{
    this->type = type;
}

void CombinedFragment::setNoOfNodes(int noOfNodes)
{
    (this->noOfNodes).push_back(noOfNodes);
}

void CombinedFragment::addNewPartition(string condition, int noOfNodes)
{
    (this->condition).push_back(condition);
    (this->noOfNodes).push_back(noOfNodes);
}

void CombinedFragment::addNewPartition(int noOfNodes)
{
    (this->noOfNodes).push_back(noOfNodes);
}
