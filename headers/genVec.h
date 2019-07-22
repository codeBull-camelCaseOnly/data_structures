#pragma once
#include<sstream>
#include<vector>
#include<math.h>
#include <initializer_list>



class genVec
{
private:
    std::vector<double> coordinate;
    unsigned int size;
public:

genVec()   //by default 3-D vector
{
    coordinate.push_back(0.00);
    coordinate.push_back(0.00);
    coordinate.push_back(0.00);
    size = 3;
}

genVec(const std::initializer_list<double> &il)
{
    size = 0;
        for (auto x: il) 
        {
            coordinate.push_back(x);
            size++;
        }
}

genVec(int n)
{
    size = n;
    while(n--){
        coordinate.push_back(0.00);
    }
}

genVec(std::vector<double> a)
{
    int n = 0;
    while(n!=a.size()){
        coordinate.push_back(a[n]);
        n++;
    }
    size = n;
}

genVec(const genVec &d)
{
    coordinate = d.coordinate;
    size = coordinate.size();
}

genVec operator +(genVec a)
{
    if(size == a.coordinate.size())
    {
        genVec result(size);
        for(int i = 0; i < size; i++)
            result.coordinate[i] = coordinate[i] + a.coordinate[i];
        return result;
    }
    else throw "dimension of the vectors must be same for the operation!";
}

genVec operator -(genVec a)
{
    if(size == a.coordinate.size())
    {
        genVec result(size);
        for(int i = 0; i < size; i++)
            result.coordinate[i] = coordinate[i] - a.coordinate[i];
        return result;
    }
    else throw "dimension of the vectors must be same for the operation!";
}

genVec operator *(double d)
{
    genVec result(size);
        for(int i = 0; i < size; i++)
            result.coordinate[i] = coordinate[i] * d;
    return result;
}

genVec operator /(double d)
{
    genVec result(size);
        for(int i = 0; i < size; i++)
            result.coordinate[i] = coordinate[i] / d;
    return result;
}

genVec dot(genVec a)
{
    if(size == a.coordinate.size())
    {
        genVec result(size);
        for(int i = 0; i < size; i++)
            result.coordinate[i] = coordinate[i] * a.coordinate[i];
        return result;
    }
    else throw "dimension of the vectors must be same for the operation!";
}

double magnitude()
{
    double result = 0;
    for(int i = 0; i < size; i++)
        result += coordinate[i] * coordinate[i];
    return sqrt(result);    
}

genVec normalize()
{
    return *this/magnitude();
}

genVec tranform(double operation(double))
{
    genVec result;
    for(int i = 0; i < size; i++)
        result.coordinate.push_back(operation(coordinate[i]));
    return result;    
}

std::ostream &returnOut(std::ostream &out) const
{
    for(int i = 0; i < size-1; i++)
        out<<coordinate[i]<<"<x"<<i<<"> + ";
    out<<coordinate[size-1]<<"<x"<<size-1<<">";
    out<<"\n";
    return out;
}

};

std::ostream & operator << (std::ostream &out, const genVec &m )
{
	return m.returnOut(out);
}
