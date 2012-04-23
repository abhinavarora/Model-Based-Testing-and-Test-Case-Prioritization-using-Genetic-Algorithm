#include "tinyxml.h"
#include "actorbuilder.h"
#include "combinedfragmentbuilder.h"
#include "messagebuilder.h"
#include "node.h"
#include "sequencediagrambuilder.h"
#include <iostream>
#include <string>
#include <vector>
#include<map>
class CombinedFragment;
using namespace std;
map<string,CombinedFragment*>  Message_List;
int main(int argc, char* argv[])
{

SequenceDiagram seqD("C:/Users/Abhinav/Desktop/BTP/Model Based Testing/test.xml");
seqD.display();
return 0;
}
