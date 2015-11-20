//File: InCollection.h
//Author: Jasmine Farrell
//Date: Nov. 15th, 2015
//Course: cs110b


#ifndef INTCOLLECTION_H
#define INTCOLLECTION_H

//allocate memory in chunks of ints of this size
const int CHUNK_SIZE = 5;

class IntCollection
{
    private:
        //number of ints currently stored in the int collection
        int size;
        //total number of elements available for storage in the data array
        int capacity;
        //a pointer to the dynamically allocated data array
        int* data;
        //a private member function to allocate more memory if necessary
        void addCapacity();
    public:
        //constructor
        IntCollection();
        //deconstructor
        ~IntCollection();
        //copy constructor performs a deep copy of the argument object
        IntCollection( const IntCollection &c);
        void add(int value);
        int get(int index);
        int getSize();
        //assignment operator perform a deep copy of the argument object by referencing it's self
        IntCollection& operator=(const IntCollection &c);
        // equal operator returns return true if the argument object has the same size as the receiving object
        bool operator==(const IntCollection &c);
        // insertion operator should add the int parameter into the receiving IntCollection
        IntCollection& operator<<(int value);

};

#endif
