#include "sequencediagramtester.h"
#include<vector>
#include "combinedfragment.h"
#include<iostream>
using namespace std;
SequenceDiagramTester::SequenceDiagramTester(SequenceDiagram sd)
{
    //ctor
    this->seq = sd.getStartNode();
    }

int getPriority(int type)
{
    switch(type)
    {
        case MESSAGE:
            return MESSAGE_PRI;
        case RETURN_MESSAGE:
            return RETURN_MESSAGE_PRI;
        case LOOP:
            return LOOP_PRI;
        case BREAK:
            return BREAK_PRI;
        case ALT:
            return ALT_PRI;
        case OPT:
            return OPT_PRI;
        default:
            return 0;
    }
}

void SequenceDiagramTester::duplicateElements(vector<TestSequence>& ts, int n)
{
    vector<TestSequence> tmp;
    for(unsigned int i=0; i<ts.size(); i++)
    {
        tmp.push_back(ts[i]);
    }

    for(unsigned int i =0; i<tmp.size(); i++)
    {
        TestSequence tmp_ts = tmp[i];
        for(int j=0; j<n; j++)
        {
            ts.push_back(tmp_ts);
        }
    }

}

vector<TestSequence> SequenceDiagramTester::generate()
{
    vector<TestSequence> TSList;
    TestSequence temp;
    TSList.push_back(temp);
    this->generate(TSList);
    return TSList;
}

void SequenceDiagramTester::generate(vector<TestSequence>& TSList)
{
    Node nptr;
    for(unsigned int x =0; x<(this->seq).size(); x++)
    {
        nptr = (this->seq)[x];
        switch(nptr.getType())
        {
            case MESSAGE:
                {
                    int tmp_pri = getPriority(nptr.getType());
                    Message tmp_msg = nptr.getmFrag();
                    for(unsigned i =0; i<TSList.size(); i++)
                    {
                        TSList[i].addMessage(tmp_msg);
                        TSList[i].incrementPriority(tmp_pri);
                    }
                    break;
                }
            case RETURN_MESSAGE:
                break;

            case LOOP:
            case BREAK:
            case ALT:
            case OPT:
            {
                vector<TestSequence> tmp_TSList;
                int ndup, beg;
                if(nptr.getType()== ALT)
                {
                    CombinedFragment alt_cf = nptr.getcFrag();
                    vector<TestSequence> tmp_tmp_TSList;
                    TestSequence tmp_ts;
                    vector<Node> alt_itr = (alt_cf.getStartNode());
                    for(int i=0,y=0; i<alt_cf.getNoOfPartitions(); i++)
                    {
                        vector<Node> alt_seq;

                        for(int j=0; j<alt_cf.getNoOfNodes(i); j++)
                        {
                            Node temp_node = alt_itr[y++];
                            alt_seq.push_back(temp_node);
                        }

                        SequenceDiagram alt_sd(alt_seq);
                        SequenceDiagramTester alt_sdt(alt_sd);
                        tmp_tmp_TSList = alt_sdt.generate();

                        vector<TestSequence> list_itr = tmp_tmp_TSList;

                        for(unsigned int z=0; z<list_itr.size();)
                        {
                            tmp_ts = list_itr[z++];
                            //list_itr++;
                            tmp_ts.incrementPriority(ALT_PRI * i);
                            if(i == (alt_cf.getNoOfPartitions()-1))
                                tmp_ts.decrementPriority(ALT_PRI);
                            tmp_TSList.push_back(tmp_ts);
                        }
                    }
                    ndup = tmp_TSList.size()-1;
                    beg =0;
               }
                else
                {
                    CombinedFragment tmp_cf = nptr.getcFrag();
                    SequenceDiagram tmp_sd(tmp_cf.getStartNode());
                    SequenceDiagramTester tmp_sdt(tmp_sd);
                    tmp_TSList = tmp_sdt.generate();

                    ndup = tmp_TSList.size();
                    beg = TSList.size();
                }
                this->duplicateElements(TSList,ndup);

                for(unsigned int i =0; i<TSList.size(); i++)
                {
                    if(i<(unsigned)beg)
                    {
                        if(nptr.getType()== ALT)
                        {
                            CombinedFragment alt_cf = nptr.getcFrag();
                            int tmp_partition = alt_cf.getNoOfPartitions()-1;
                            TSList[i].incrementPriority(ALT_PRI * tmp_partition-1);
                        }
                        else
                        {
                            int tmp_prio = getPriority(nptr.getType());
                            TSList[i].incrementPriority(tmp_prio);
                        }
                    }
                    else
                    {
                        for(unsigned int j =0; j<tmp_TSList.size(); j++)
                        {
                            TSList[i].appendSequence(tmp_TSList[j]);
                            int tmp_prio = getPriority(nptr.getType());
                            TSList[i].incrementPriority(tmp_prio);
                            tmp_prio = tmp_TSList[j].getPriority();
                            TSList[i].incrementPriority(tmp_prio);
                            i++;
                        }
                        if(tmp_TSList.size() > 0)
                            i--;
                    }
                }
                break;
            }

        }
    }
}
