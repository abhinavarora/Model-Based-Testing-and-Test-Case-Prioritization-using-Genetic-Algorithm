#include "tinyxml.h"
#include "actorbuilder.h"
#include "combinedfragmentbuilder.h"
#include "messagebuilder.h"
#include "node.h"
#include "sequencediagramtester.h"
#include "sequencediagrambuilder.h"
#include "chromosomebuilder.h"
#include "geneticalgorithm.h"
#include <iostream>
#include <sstream>
#include <vector>
#include<map>
#include<algorithm>
#include<time.h>
class CombinedFragment;
using namespace std;
map<string,CombinedFragment*>  Message_List;
map<string,int>  Partitions;
map<string,int> Num_Part;
vector<string> SeqD_conditions;
int main(int argc, char* argv[])
{
srand (time(NULL));
SequenceDiagram seqD("C:/Users/Abhinav/Desktop/BTP/Model Based Testing/test.xml");
//seqD.display();

// Generate List of conditions

for(map<string, CombinedFragment*>::iterator i = Message_List.begin(); i!=Message_List.end(); i++)
{
    if(i->second){
        string id = i->second->getID();
        if((!Num_Part[id]) || Num_Part[id] < Partitions[i->first] )
            Num_Part[id] = Partitions[i->first];
    }
}

for(map<string,int>::iterator i =Num_Part.begin(); i!=Num_Part.end();i++)
    for(int j =1; j<=i->second;j++)
    {
        ostringstream temp;
        temp<<j;
        SeqD_conditions.push_back(i->first+(temp.str()));
    }

// Condition Vector Generated


/*for(unsigned int i =0; i<SeqD_conditions.size();i++)
    cout<<SeqD_conditions[i]<<endl;
*/

// Create List of Test Sequences
SequenceDiagramTester sdt(seqD);
vector<TestSequence> TSList =sdt.generate();
sort(TSList.begin(), TSList.end());
for(unsigned int i =0; i<TSList.size(); i++)
{
    TSList[i].evalConditions();
    TSList[i].setNum(i);
}
//Test Sequence List created

/*
Chromosome C;
C.generate(TSList,2);
cout<<"     "<<C.getWeight()<<"    "<<C.getFitness()<<"  "<<C.getMessageCount()<<endl<<endl;;
*/


/*map<string,int> t = C.getConditionHash();

for(map<string,int>::iterator i =t.begin(); i!=t.end(); i++)
    cout<<i->first<<endl;*/
/*for(unsigned int i =0; i<TSList.size(); i++)
{
    cout<<"TS : "<<TSList[i].getPriority()<<"   ";
    vector<Message> tt = TSList[i].getTestSequence();
    for(unsigned j=0; j<tt.size(); j++)
        cout<<tt[j].getName()<<"  ";
    cout<<endl;
 }*/
/*
 for(unsigned int i =0; i<temp.size(); i++)
{
    cout<<"TS-"<<temp[i].getNum()<<" : "<<temp[i].getPriority()<<"  ";
    vector<Message> tt = temp[i].getTestSequence();
    for(unsigned j=0; j<tt.size(); j++)
        cout<<tt[j].getName()<<"  ";
    cout<<endl;
 }
*/


/*ChromosomeBuilder C;
C.generate(TSList,5);
vector<Chromosome> lis = C.getPopulation();
for(unsigned s = 0; s<2; s++)
{
        cout<<"     "<<lis[s].getCount()<<"    "<<lis[s].getFitness()<<endl<<endl;;
    vector<TestSequence> temp =lis[s].getSequence();
     for(unsigned int i =0; i<temp.size(); i++)
{
    cout<<"TS-"<<temp[i].getNum()<<" : "<<temp[i].getPriority()<<"  ";
    vector<Message> tt = temp[i].getTestSequence();
    for(unsigned j=0; j<tt.size(); j++)
        cout<<tt[j].getName()<<"  ";
    cout<<endl;
 }
}

cout<<endl<<endl<<"Genetic Algo "<<endl;
GeneticAlgorithm GA;
vector<Chromosome> t =GA.crossover(lis[0],lis[1]);
sort(t.begin(),t.end());
 for(unsigned s = 0; s<t.size(); s++)
{
        cout<<"     "<<t[s].getCount()<<"    "<<t[s].getFitness()<<endl<<endl;;
    vector<TestSequence> temp =t[s].getSequence();
     for(unsigned int i =0; i<temp.size(); i++)
{
    cout<<"TS-"<<temp[i].getNum()<<" : "<<temp[i].getPriority()<<"  ";
    vector<Message> tt = temp[i].getTestSequence();
    for(unsigned j=0; j<tt.size(); j++)
        cout<<tt[j].getName()<<"  ";
    cout<<endl;
 }
}

t =GA.mutation(t);
 for(unsigned s = 0; s<t.size(); s++)
{
        cout<<"     "<<t[s].getCount()<<"    "<<t[s].getFitness()<<endl<<endl;;
    vector<TestSequence> temp =t[s].getSequence();
     for(unsigned int i =0; i<temp.size(); i++)
{
    cout<<"TS-"<<temp[i].getNum()<<" : "<<temp[i].getPriority()<<"  ";
    vector<Message> tt = temp[i].getTestSequence();
    for(unsigned j=0; j<tt.size(); j++)
        cout<<tt[j].getName()<<"  ";
    cout<<endl;
 }
}*/

GeneticAlgorithm GA;
GA.generate(TSList,5);
return 0;
}
