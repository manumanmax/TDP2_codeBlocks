#include "assignment.h"


Request::Request(vector< vector<int> > blocks, string name){
    for(auto block : blocks){
        this->blocks.push_back(Block(block[0],block[1]));
    }
    this->name = name;
}

vector<int> Request::hours(){
    vector<int> hours;
    for(auto block : blocks){
        for(auto h : block.hours())
            hours.push_back(h);
    }
    return hours;
}

