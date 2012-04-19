#include "combinedfragmentbuilder.h"
#include "node.h"
#include<conio.h>
#include<iostream>
CombinedFragmentBuilder::CombinedFragmentBuilder()
{
    //ctor
}

CombinedFragment CombinedFragmentBuilder::build(TiXmlElement * ele_frag, vector<Message> msglist)
{
    int nm,nf;
    CombinedFragment cf;
    string type = ele_frag->Attribute("interactionOperator");
    string xmi_id = ele_frag->Attribute("xmi:id");
    if(ele_frag->Attribute("interactionOperator")==NULL)
     {
         cout<<"ERROR combinedfragmentbuilder.cpp";
         getch();
         exit(45);
     }
    if(type == string("loop"))
        cf.setType(LOOP);
    else if(type == string("opt"))
        cf.setType(OPT);
    else if(type == string("alt"))
        cf.setType(ALT);
    else if(type == string("break"))
        cf.setType(BREAK);

    cf.setID(xmi_id);

}
