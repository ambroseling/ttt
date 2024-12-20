#include <stdio.h>
#include "tensor.hpp"
#include <vector>

int main(void){
    Tensor tensor = new Tensor({2,2},"randn");
    tensor.printTensor();
}