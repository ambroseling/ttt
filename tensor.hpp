#ifndef TENSOR_HPP
#define TENSOR_HPP
#include <iostream>
#include <vector>
#include <string>

struct Storage{
    float* buffer; // the pointer to the buffer in memory
    std::vector<int> stride; // the stride used to look at this memory
    int size; // size of underlying storage buffer in bytes
    int ref_count; // number of references pointing to the buffer
    Storage():size(0),ref_count(0),buffer(nullptr){}
    Storage(int input_size){};
    void allocateBuffer();
    void initializeBuffer(std::string init);
    void copyDataIntoBuffer();
    void freeBuffer();

};


struct Tensor{
    Storage data;
    std::vector<int> shape;
    Tensor(auto input_data){};
    Tensor(std::vector<int> shape,std::string init){};
    void getTensorElement();
    void printTensor();
    Tensor copyTensor();
    void sliceTensor(std::vector<int>indices);
    void reshapeTensor();
    void transposeTensor();
};

#endif