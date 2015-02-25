//
//  Vector.h
//  PixelGameLocal
//
//  Created by Kris Temmerman on 21/10/13.
//
//

#ifndef PixelGameLocal_Vector_h
#define PixelGameLocal_Vector_h

#include "Array.h"

template<typename T, int C = 16>
class StackVector {
    size_t d_pntr; // pointer to first element (see eraseFirst)
    size_t d_size; // Stores no. of actually stored objects including erased objects

    const size_t d_capacity = C; // Allocated capacity
    Array<T, C> d_data; // Stores data

public:
    StackVector() : d_pntr(0), d_size(0) {} // Default constructor

    inline void clear()
    {
        d_pntr = 0;
        d_size = 0;
    }

    inline void push_back(T const &x)
    {
        assert_d(d_size < d_capacity);
        d_data[d_size++] = x;
    }

    inline T const &operator[](size_t idx) const { assert_d(idx < size()); return d_data[d_pntr+idx]; }
    inline T &operator[](size_t idx) { assert_d(idx < size()); return d_data[d_pntr+idx]; }

    inline void eraseFirst()
    {
        if (d_pntr+d_size < d_capacity-1)
        {
            d_pntr++;
        }
        else
        {
            for (unsigned int i=1; i<d_size; i++)
                d_data[i-1] = d_data[d_pntr+i];
            d_pntr = 0;
        }

        d_size--;
    }

    inline void resetAll() { d_data.resetAll(); }

    inline size_t size() const { return d_size-d_pntr; }
};


// Minimal class to replace std::vector
template<typename Data>
class Vector {
    size_t d_size; // Stores no. of actually stored objects
    size_t d_capacity; // Stores allocated capacity
    Data *d_data; // Stores data
public:
    Vector() : d_size(0), d_capacity(0), d_data(0) {} // Default constructor
    Vector(Vector const &other) : d_size(other.d_size), d_capacity(other.d_capacity), d_data(0)
    {
        d_data = (Data *)malloc(d_capacity*sizeof(Data));
        memcpy(d_data, other.d_data, d_size*sizeof(Data));
    } // Copy constuctor
    
    ~Vector()
    {
        free(d_data);
    } // Destructor

    inline void clear()
    {
        free(d_data);
        d_size = 0;
        d_capacity = 0;
        d_data = 0;
    }
    
    inline Vector &operator=(Vector const &other)
    {
        free(d_data);
        d_size = other.d_size;
        d_capacity = other.d_capacity;
        d_data = (Data *)malloc(d_capacity*sizeof(Data));
        memcpy(d_data, other.d_data, d_size*sizeof(Data));
        return *this;
    } // Needed for memory management
    
    
    inline void push_back(Data const &x)
    {
        if (d_capacity == d_size) resize();
        d_data[d_size++] = x;
    } // Adds new value. If needed, allocates more space
    
    
    
    inline size_t size() const
    {
        return d_size;
    } // Size getter
    
    
    inline Data const &operator[](size_t idx) const
    {
        return d_data[idx];
    } // Const getter
    inline Data &operator[](size_t idx) { return d_data[idx]; } // Changeable getter
    
    
    inline void eraseFirst()
    {
        if(d_size>=2)
        {
            d_size--;
            for(size_t i=0;i<d_size;i++)
                d_data[i]=d_data[i+1];
        }
    
    }

    inline void resetAll() {
        for (unsigned int i=0; i<size(); i++)
            if (d_data[i])
                d_data[i]->reset();
    }
    
private:
    inline void resize() {
        d_capacity = d_capacity ? d_capacity*2 : 1;
      
        Data *newdata = (Data *)malloc(d_capacity*sizeof(Data));
        memcpy(newdata, d_data, d_size * sizeof(Data));
        free(d_data);
        d_data = newdata;
    }// Allocates double the old space
};

#endif
