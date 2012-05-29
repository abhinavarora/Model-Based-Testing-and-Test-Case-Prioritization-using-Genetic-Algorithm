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
        bool operator == (const CombinedFragment&) const;
        bool operator != (const CombinedFragment&) const;
        void display();
        string getID();
        int getNoOfPartitions();
        int getType();
        string getCondition(int);
        int getNoOfNodes(int);
        string getCondition() const;
        int getNoOfNodes() const;
        void setID(string);
        void setCondition(string);
        void setType(int);
        void setNoOfNodes(int);
        void addNewPartition(string,int);
        void addNewPartition(int);
        int getCount();

    private:
        vector<string> condition;
        vector<int> noOfNodes;
        int type;
        string xmi_id;
        int condition_count;

};

#endif // COMBINEDFRAGMENT_H
