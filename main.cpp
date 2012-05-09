#include "tinyxml.h"
#include "actorbuilder.h"
#include "combinedfragmentbuilder.h"
#include "messagebuilder.h"
#include "node.h"
#include "sequencediagramtester.h"
#include "sequencediagrambuilder.h"
#include <iostream>
#include <string>
#include <vector>
#include<map>
#include<algorithm>
class CombinedFragment;
using namespace std;
map<string,CombinedFragment*>  Message_List;
int main(int argc, char* argv[])
{

SequenceDiagram seqD("C:/Users/Abhinav/Desktop/BTP/Model Based Testing/test.xml");

SequenceDiagramTester sdt(seqD);
seqD.display();
vector<TestSequence> TSList =sdt.generate();
sort(TSList.begin(), TSList.end());
for(unsigned int i =0; i<TSList.size(); i++)
{
    cout<<"TS : "<<TSList[i].getPriority()<<"  ";
    vector<Message> tt = TSList[i].getTestSequence();
    for(unsigned j=0; j<tt.size(); j++)
        cout<<tt[j].getName()<<"  ";
    cout<<endl;
 }
return 0;
}
