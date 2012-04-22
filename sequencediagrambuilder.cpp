#include "sequencediagrambuilder.h"
#include "actorbuilder.h"
#include "messagebuilder.h"
#include "combinedfragmentbuilder.h"
#include "node.h"
#include <iostream>

using namespace std;

SequenceDiagramBuilder::SequenceDiagramBuilder(string inputFile)
{
    (this->doc).LoadFile();
    if(! (this->doc.LoadFile(inputFile.c_str())))
	{
		cerr << doc.ErrorDesc() << endl;
	}
    (this->docEle) = (this->doc).FirstChildElement();
}

void SequenceDiagramBuilder::build(SequenceDiagram& sd)
{
    CombinedFragment cf_null(string(""),-1);
    vector<Message> msgList;
    vector<Actor> actorList = sd.getActorList();

    ActorBuilder acb;
    acb.build(actorList,(this->docEle));

    for(unsigned int i =0; i < actorList.size(); i++)
    {
        string var = actorList[i].toString();
        cout<<var<<endl;
    }

    MessageBuilder mb;
    mb.build(actorList,msgList,(this->docEle));

    vector<CombinedFragment> fragList;
    vector<TiXmlElement*> ele_fragList;
    ele_fragList = (this->docEle)->GetElementsByTagName("fragment",ele_fragList);
    if(ele_fragList.size()>0)
    {
        for(unsigned int i =0; i<ele_fragList.size(); i++)
        {
            if(ele_fragList[i]->Attribute("xmi:type")!=NULL && ele_fragList[i]->Attribute("xmi:type") == string("uml:CombinedFragment"))
            {
                CombinedFragment cf;
                CombinedFragmentBuilder cfb;
                cf = cfb.build(ele_fragList[i],msgList);
                fragList.push_back(cf);
            }
        }
    }

    vector<TiXmlElement*> nl;
    nl = (this->docEle)->GetElementsByTagName("uml:DiagramElement",nl);

    for(unsigned int i=0; i<nl.size(); i++)
    {
        if(nl[i]->Attribute("preferredShapeType")!= NULL && nl[i]->Attribute("preferredShapeType") == string("Message"))
        {
            for(unsigned int j =0; j<msgList.size(); j++)
            {
                if(nl[i]->Attribute("subject")!= NULL && nl[i]->Attribute("subject") == msgList[j].getID() && msgList[j].getFrag()==cf_null)
                {
                    Node temp(msgList[j].getType(),msgList[j]);
                    sd.push_seq(temp);
                }
            }
        }

        else if(nl[i]->Attribute("preferredShapeType")!= NULL && nl[i]->Attribute("preferredShapeType") == string("CombinedFragment"))
        {
            for(unsigned int j =0; j<fragList.size(); j++)
            {
                if(nl[i]->Attribute("subject")!= NULL && nl[i]->Attribute("subject") == fragList[j].getID())
                {
                    CombinedFragment *tem = new CombinedFragment;
                    *tem = fragList[j];
                    Node temp(tem->getType(),tem);
                    sd.push_seq(temp);
                }
            }
        }
    }

}
