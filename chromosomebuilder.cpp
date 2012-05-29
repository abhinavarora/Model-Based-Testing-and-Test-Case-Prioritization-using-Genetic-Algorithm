#include "chromosomebuilder.h"
#include<iostream>
using namespace std;
ChromosomeBuilder::ChromosomeBuilder()
{
    //ctor
}

ChromosomeBuilder::ChromosomeBuilder(const ChromosomeBuilder& other)
{
    //copy ctor
    this->population = other.getPopulation();
    this->count = other.getCount();
}

void ChromosomeBuilder::setCount(int n)
{
    this->count = n;
}

int ChromosomeBuilder::getCount() const
{
    return this->count;
}

vector<Chromosome> ChromosomeBuilder::getPopulation() const
{
    return this->population;
}

void ChromosomeBuilder::generate(vector<TestSequence> TSList, int mcount)
{
    int size = TSList.size();
    this->setCount(size);
    Chromosome C;
    for(int i =0; i<size; i++)
    {
        C.generate(TSList,mcount);
       // cout<<"     "<<C[i].getWeight()<<"    "<<C[i].getFitness()<<"  "<<C[i].getMessageCount()<<endl<<endl;;
        (this->population).push_back(C);
    }

}
