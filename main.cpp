#include "tinyxml.h"
#include "actorbuilder.h"
#include "combinedfragment.h"
#include "messagebuilder.h"
#include "message.h"
#include "node.h"
#include <iostream>
#include <string>
#include <vector>
class CombinedFragment;
using namespace std;

int main(int argc, char* argv[])
{
    TiXmlDocument doc;
	if(!doc.LoadFile("C:/Users/Abhinav/Desktop/BTP/Model Based Testing/test.xml"))
	{
		cerr << doc.ErrorDesc() << endl;
		return 0;
	}
	TiXmlElement* root = doc.FirstChildElement();
	if(root == NULL)
	{
		cerr << "Failed to load file: No root element." << endl;
		doc.Clear();
		return 0;
	}
//TiXmlElement* elem = root->FirstChildElement()->NextSiblingElement();
//cout<<elem->Attribute("att");
vector<Actor> list;
vector<Message> mlist;
ActorBuilder acb;
acb.build(list,root);
//list=root->GetElementsByTagName("message",list);
for(unsigned int i=0;i<list.size();i++)
    cout<<list[i].toString()<<endl<<endl;
MessageBuilder mb;
mb.build(list,mlist,root);
cout<<mlist.size();
for(unsigned int i=0;i<mlist.size();i++,cout<<endl)
  {
     mlist[i].display();
     cout<<mlist[i].getType()<<endl;
  }

Message xyz;
Node var(23,xyz);
CombinedFragment cf_null(string(""),-1);
if(var.getcFrag()!=cf_null)
    cout<<"Phew!!";
//getchar();
return 0;
}
