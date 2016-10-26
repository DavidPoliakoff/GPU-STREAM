
// Copyright (c) 2015-16 Tom Deakin, Simon McIntosh-Smith,
// University of Bristol HPC
//
// For full license terms please see the LICENSE file distributed with this
// source code

#pragma once

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "Stream.h"

#define IMPLEMENTATION_STRING "CUDA"

#define TBSIZE 1024
#define DOT_TBSIZE 4
#define DOT_NUM_BLOCKS 24

template <class T>
class CUDAStream : public Stream<T>
{
  protected:
    // Size of arrays
    unsigned int array_size;

    // Host array for partial sums for dot kernel
    T *sums;

    // Device side pointers to arrays
    T *d_a;
    T *d_b;
    T *d_c;
    T *d_sum;


  public:

    CUDAStream(const unsigned int, const int);
    ~CUDAStream();

    virtual void copy();
    virtual void add();
    virtual void mul();
    virtual void triad();
    virtual T dot();

    virtual void write_arrays(const std::vector<T>& a, const std::vector<T>& b, const std::vector<T>& c);
    virtual void read_arrays(std::vector<T>& a, std::vector<T>& b, std::vector<T>& c);

};
