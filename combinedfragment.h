#ifndef COMBINEDFRAGMENT_H
#define COMBINEDFRAGMENT_H
#include<string>
#include<vector>
#include "sequencediagram.h"
using namespace std;

class CombinedFragment : public SequenceDiagram
{
    public:
        /** Default constructor */
        CombinedFragment();
        CombinedFragment(string);
        CombinedFragment(string,int);
        void display();
        string getID();
        int getNoOfPartitions();
        int getType();
        string getCondition(int);
        int getNoOfNodes(int);
        string getCondition();
        int getNoOfNodes();
        void setID(string);
        void setCondition(string);
        void setType(int);
        void setNoOfNodes(int);
        void addNewPartition(string,int);
        void addNewPartition(int);

    private:
        vector<string> condition;
        vector<int> noOfNodes;
        int type;
        string xmi_id;

};

#endif // COMBINEDFRAGMENT_H
