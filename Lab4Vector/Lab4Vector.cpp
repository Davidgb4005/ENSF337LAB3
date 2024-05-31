/*
* File Name: Lab4Vector.cpp
* Assignment: Lab 4 Exercise D
* Lab section: Summer
* Completed by: David Burgoin
* Development Date: May 31/2024
*/

/*
 NOTES ON MEMORY ALLOCATION POLICIES FOR SimpleVector OBJECT:
 
 - If vector objects are supposed to be empty storageM will be NULL and the values
   of sizeM and capacityM must be set to zero.
 - If the objects of vector are supposed to be initialize with supplied values of
   an array, the size a and values in the dynamically memory space for storageM
   must be identical to the size and values in the supplied array. And, the
   values of sizeM and capacityM should be both set to the exact size of array.
 
- If any member function need to resize the vector, it should check the values of
  sizeM and capacityM:
  - If sizeM is equal to capacityM and vector is empty (i.e. capaictyM is equal to
    zero), capcityM should be changed to 2.
  - Otherwise, if sizeM is equal to capacityM, and capacityM is not zero (i.e.
    vector is NOT empty), the value of capacityM should be doubled up
  EXAMPLE: if capacityM is 5 and sizeM is also 5:
     1. the value of capacityM should be changed to 10.
     2. the dynamically allocated memory space for storageM should be reallocated
        to 10.
     3. The current values in the vector should be preserved and any unnecessary
        dynamically allocated memory must to deallocated.
*/

#include "simpleVector.h"
#include <cassert>
using namespace std;

SimpleVector::SimpleVector(const TYPE *arr, int n) {
        if (n <= 0){
    this->storageM = nullptr;
    this->capacityM = 0;
    this->sizeM = 0;
    }
    else{
    storageM = new TYPE[n];
    sizeM = n;
    capacityM = n;
    for(int i =0; i < sizeM; i++)
        storageM[i] = arr[i];
    }
}
TYPE& SimpleVector::at(int i) {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}

const TYPE& SimpleVector::at(int i)const {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}


// The followng member function should follow the above-mentioned memory
// management policy to resize the vector, if necessary. More specifically:
//   - If sizeM < capacityM it doesn't need to make any changes to the size of
//     allocated memory for vector
//   - Otherwise it follows the above-mentioned memory policy to create additionl
//     memory space and adds the new value, val, to the end of the current vector
//     and increments the value of sizeM by 1
void SimpleVector::push_back(TYPE val) {
if (this->capacityM==this->sizeM){
    if (this->capacityM == 0){
        delete []this->storageM;
        this->capacityM = 2;
        this->sizeM= 1;
        this->storageM = new TYPE[2];
        }
    else if (this->capacityM > 0){
        TYPE * buffer_array = new TYPE[this->capacityM*2];
        for (int i=0;i<this->sizeM;i++){
            buffer_array[i] = this->storageM[i];
            }
        buffer_array[this->sizeM]=val;
        delete []this->storageM;
        this->storageM = buffer_array;
        buffer_array = nullptr;
        this->capacityM = this->sizeM*2;
        this->sizeM = this->sizeM+1;
        }
    else{
        //Undefined behavior
    }
}
else{
    this->storageM[sizeM]=val;
    this->sizeM++;
    }
}


SimpleVector::SimpleVector(const SimpleVector& source) {
    if (source.capacityM <= 0){
        this->storageM = nullptr;
        this->capacityM = 0;
        this->sizeM = 0;
    }
    else{
    this->storageM = new TYPE[source.size()];
    for (int i=0;i<source.size();i++){
        this->storageM[i]=source.storageM[i];
    }
    this->capacityM = source.size();
    this->sizeM = source.size();
    }
}

SimpleVector& SimpleVector::operator= (const SimpleVector& rhs ){

    if (rhs.capacityM <= 0){
    this->storageM = nullptr;
    this->capacityM = 0;
    this->sizeM = 0;
    }
    else{
    TYPE * buffer_array = new TYPE[rhs.sizeM];
    for (int i=0;i<rhs.sizeM;i++){
        buffer_array[i] = rhs.storageM[i];
    }
    delete [] this->storageM;
    this->storageM = buffer_array;
    buffer_array = nullptr;
    this->capacityM = rhs.sizeM;
    this->sizeM = rhs.sizeM;
    }


    return *this;
}
