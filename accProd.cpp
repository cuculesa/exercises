// Filename: accProd.cpp

#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;

//given [1,2,3,4]
//output [2*3*4, 1*3*4, ...]

void print(vector<int> &input)
{
 vector<int>::iterator it;
 for(it = input.begin(); it != input.end(); ++it)
 {cout<<*it<<" ";} cout<<endl;
}

vector<int> calcProd(vector<int> input)
{
 vector<int> prod;
 vector<int>::iterator it;
 int tmpProd = 1;

 int countZeros = 0;
 countZeros = count(input.begin(), input.end(), 0);
 cout<<"zeros"<<countZeros<<endl;

 if( 0 == countZeros)  //if all elements are non-zero
 {
  for(it = input.begin(); it != input.end(); ++it)
  { tmpProd = tmpProd * (*it); }

  for(it = input.begin(); it != input.end(); ++it)
  { prod.push_back(tmpProd / (*it));}
 }
 else
 {
  for(int i=0; i<input.size(); i++)
  { prod.push_back(0);
  }
   //if 1 element is zero, output will have one non-null elem
   if(1 == countZeros)
   {  //calculate the only nonzero value
      for(it = input.begin(); it != input.end(); ++it)
      {
        if(0 != *it)
            tmpProd = tmpProd * (*it);
      }
      //calculate position of zero
      int zeroPos = distance( input.begin(), find( input.begin(), input.end(), 0 ) );
      cout<<"zeroPos"<<zeroPos<<endl;
      prod[zeroPos] = tmpProd;
    }
 }
 return prod;
}



int main()
{
 vector<int> in = {5,5,6,4,5,6,777,9}; // using C++11
 vector<int> out;
 print(in);
 out = calcProd(in);
 print(out);
 return 0;
}


