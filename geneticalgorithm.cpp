#include "geneticalgorithm.h"
#include<iostream>
using namespace std;
GeneticAlgorithm::GeneticAlgorithm()
{
    //ctor
}

vector<Chromosome> GeneticAlgorithm::mutation(vector<Chromosome>& input)
{
    int pos1, pos2;
    vector<TestSequence> TS1, TS2;
    TS1 = input[0].getSequence();
    TS2 = input[1].getSequence();
    pos1 = rand() % TS1.size();
    pos2 = TS1.size() - pos1;

    TestSequence temp;
    temp = TS1[pos1];
    TS1[pos1] = TS1[pos2];
    TS1[pos2] = temp;

    temp = TS2[pos1];
    TS2[pos1] = TS2[pos2];
    TS2[pos2] = temp;

    input[0].setSequence(TS1);
    input[1].setSequence(TS2);

    return input;
}

vector<Chromosome> GeneticAlgorithm::crossover(vector<Chromosome>& input)
{
    int cross_point = (rand() % (input[0].getSize()- 2))+1;
    vector<TestSequence> TS1, TS2,O1,O2;
    TS1 = input[0].getSequence();
    TS2 = input[1].getSequence();
    for(int i=0; i<=cross_point; i++)
    {
        O1.push_back(TS1[i]);
        O2.push_back(TS2[i]);
    }

    for(unsigned int i = cross_point+1; i<TS1.size(); i++ )
    {
        O1.push_back(TS2[i]);
        O2.push_back(TS1[i]);
    }

    Chromosome C1,C2;
    C1.create(O1);
    C2.create(O2);

    vector<Chromosome> output(2);
    output.push_back(C1);
    output.push_back(C2);
    return output;
}

vector<TestSequence> GeneticAlgorithm::generate(vector<TestSequence> TSList, int mcount)
{
    int total = SeqD_conditions.size();
    ChromosomeBuilder C;
    C.generate(TSList,mcount);
    vector<Chromosome> initial_pop = C.getPopulation();
    sort(initial_pop.begin(),initial_pop.end());
    vector<Chromosome> temp;
    temp.push_back(initial_pop[initial_pop.size()-1]);
    temp.push_back(initial_pop[initial_pop.size()-2]);
    //vector<Chromosome> temp2;
    do
    {
        this->crossover(temp);
        this->mutation(temp);
        //temp = temp2;
    }while(temp[0].getCount()!=total || temp[1].getCount()!=total);
    sort(temp.begin(),temp.end());


    cout<<"     "<<temp[1].getCount()<<"    "<<temp[1].getFitness()<<endl;
    vector<TestSequence> t = temp[1].getSequence();
    for(unsigned int i =0; i<t.size(); i++)
{
    cout<<"TS : "<<t[i].getPriority()<<"   ";
    vector<Message> tt = t[i].getTestSequence();
    for(unsigned j=0; j<tt.size(); j++)
        cout<<tt[j].getName()<<"  ";
    cout<<endl;
}
    return temp[1].getSequence();
}
