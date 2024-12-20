#include "tensor.hpp"
#include <malloc>
#include <stdio.h>
#include <cassert>
#include <cstdio.h>
#include <random>

#define ZERO_MEAN 0.0
#define UNIT_VAR 1.0

using namespace std;

void traverse()

Storage::Storage(int input_size){
   size = input_size; ref_count +=1; 
}

Storage::allocateBuffer(){
    buffer = (float*)malloc(sizeof(float)*size);
    if (buffer != NULL){return;}
    else{ cout << "(TTT) AllocationError: Could not allocate tensor of cardinality " << size << ", ("<< size*4 << " bytes)";}
}

Storage::copyDataIntoBuffer(auto input_data){
 assert(input_data.size() == data->size); 
 memcpy(buffer,input_data.data(),input_data.size()*sizeof(float));
 // input.data() returns a pointer to the memory array used to store the elements
}

Storage::initializeBuffer(string init){
    if (init == "zero"){
        
    }
    else if (init == "randn"){
        std::normal_distribution<double> distribution(ZERO_MEAN,UNIT_VAR);
        
    }
}

Storage::freeBuffer(){
free(buffer);
delete buffer;
}

Tensor::Tensor(auto input_data){ 
 data = new Storage(input_data.size());
 data.allocateBuffer();
 data.copyDataIntoBuffer(input_data);
}

Tensor::Tensor(vector<int> shape,string init){
int size = 0;
for (int i=0;i<shape.size();i++){size*=shape[i];}
data = new Storage(size);
data.allocateBuffer();
if (init == "zero"){ data.initializeBuffer("zero");}
else if (init == "randn"){data.initializeBuffer("randn");}
}

Tensor::getTensorElement(std::vector<int>index){
assert(index.size() == shape.size());
int offset = 0; int sub_offset = 1; int i = 0;
while (i < index.size()){
    ASSERT(index[i] <= shape[i], "Index Out of Bounds When Accessing Tensor Element");
    offset += index[i] * (sub_offset); 
    sub_offset *= shape[i];
    i++;
}
return *(data->buffer+offset);
// shape: [3,4,5,6]
// j + i*4 + k * (3*4) + l *(3*4*5)

}

Tensor::printTensor(){
while (){
    
}
}