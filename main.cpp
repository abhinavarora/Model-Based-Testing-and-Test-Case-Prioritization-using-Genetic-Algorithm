#include "tinyxml.h"
#include <iostream>
#include <string>
#include <vector>

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
vector<TiXmlElement*> list;
list=root->GetElementsByTagName("message",list);
for(int i=0;i<list.size();i++)
    cout<<list[i]->Attribute("xmi:id")<<endl;
//getchar();
return 0;
}
