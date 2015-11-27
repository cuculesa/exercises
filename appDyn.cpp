#include<iostream>
#include<vector>
using namespace::std;

// boys and girls line up on 2 lines according to their heights
// line them up according to duplicated heights.

//aligns unique heights versus duplicated heights
void alignUniqueHeights(int &b, int &g)
{

}

void print(vector<int> &input, string s)
{
    vector<int>::iterator i = input.begin();
    while(i != input.end())
    {
       cout<<s<<" : "<<*i<<endl;
       i++;
    }
}

int main()
{
    int boys[5]={1,4,5,6,7};
    int girls[6]={4,6,7,7,8,9};
    vector<int> dupes,uniq;

    int bn = sizeof(boys)/sizeof(boys[0]);
    int gn = sizeof(girls)/sizeof(girls[0]);
    int bx=0, gx=0; //indices


    while((bx<bn) && (gx<gn))
    {
100
        if(boys[bx] == girls[gx])
        {
            dupes.push_back(boys[bx]);
            bx++;
            gx++;
        }
        else if(boys[bx]<girls[gx])
        {
            uniq.push_back(boys[bx]);
            bx++;
        }
        else
        {
            uniq.push_back(girls[gx]);
            gx++;

        }
    }
    //print
    print(dupes, "duplicated heights");
    print(uniq, "unique heights");


    return 1;
}
