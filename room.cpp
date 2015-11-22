#include "assignment.h"

bool Room::in(int hour, vector<int> hours){
    for(auto vhour = hours.cbegin(); vhour != hours.cend(); vhour++){
        if(*vhour == hour) return true;
    }
    return false;
}


const string Room::printRoom(){
    string s;
    char buffer [33];
    s.append(name + " \n");
    for(auto pos = reserved.cbegin(); pos != reserved.cend(); pos++){
        sprintf(buffer,"%d",pos->first);
        s.append(string(buffer) + "-->" + pos->second + "\n");
    }

    return s;
}

const vector<int> Room::reservedHours(){
    vector<int> reservedHours;

    for(auto pos = reserved.cbegin(); pos != reserved.cend(); pos++){
        reservedHours.push_back(pos->first);
    }

    return reservedHours;
}

vector<int> Room::freeHours(){
    vector<int> fullhours = {0,1,2,3,4,5,6,7,8,9};
    vector<int> reservedHours = this->reservedHours();
    for(auto pos = fullhours.begin(); pos != fullhours.end(); pos++){
       for(auto hour = reservedHours.cbegin(); hour != reservedHours.cend(); hour++){
           if(*pos == *hour){
               fullhours.erase(pos); // erasing the booked hours of the planning
               break;
           }
       }
    }
    //can crash if the iterator is invalide after delete
    return fullhours;
}

vector<int> Room::book(vector<int> &blocks, string teacher){
    vector<int> unassignedHours;
    vector<int> freeHours = this->freeHours();

    for(auto h = blocks.begin(); h != blocks.end(); h++){

        if(in(*h, freeHours)){
            reserved[*h] = teacher; // filling the map with the name of the teacher
        }else{
            unassignedHours.push_back(*h); // adding the unassigned hours for semeter assigne function
        }
    }
    return unassignedHours;
}

string Room::check(int h){
    vector<int> reservedHours = this->reservedHours();

        if(in(h, this->reservedHours()))
            return reserved[h];

        return "";
}
