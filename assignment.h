#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <string>


using std::vector;
using std::string;
using namespace std;

struct Block{
    int start;
    int end;
    Block(int start, int end) : start(start), end(end){};
    vector<int> hours(){
        vector<int> hours;

        for(int i = start; i <= end; i++){
            hours.push_back(i);
        }

        return hours;
    }
};



class Request{
public:
    vector< Block > blocks;
    string name;
    vector<int> hours();
    Request(vector< vector<int> > blocks, string name);
};

class Room{
public:
    Room(string name):name(name){};
    const string printRoom();
    vector<int> freeHours();
    string check(int h);
    vector<int> book(vector<int> &blocks,const string teacher);
private:
    string name;
    map<int, string> reserved;
    const vector<int> reservedHours();
    bool in(int hour, vector<int> hours);

};


class Semester{
public:
    Semester(){}
    void AddRoom(string name);
    vector<int> AssignRoom(Request &request);
    set<string> CheckAvailability(Block b);
    const string printRooms();
private:
    vector<Room> rooms;
    friend std::ostream & operator <<( std::ostream &os, Semester &semester );

};






#endif // ASSIGNMENT_H

