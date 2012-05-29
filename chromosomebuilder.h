#ifndef CHROMOSOMEBUILDER_H
#define CHROMOSOMEBUILDER_H
#include "chromosome.h"

class ChromosomeBuilder
{
    public:
        /** Default constructor */
        ChromosomeBuilder();
        /** Copy constructor
         *  \param other Object to copy from
         */
        ChromosomeBuilder(const ChromosomeBuilder& other);
        vector<Chromosome> getPopulation() const;
        void setCount(int);
        int getCount() const;
        void generate(vector<TestSequence>,int);

    private:
        vector<Chromosome> population;
        int count;
};

#endif // CHROMOSOMEBUILDER_H
