#include "assignment.h"

void Semester::AddRoom(string name){
    rooms.push_back(Room(name));
}
vector<int> Semester::AssignRoom(Request &request){
    vector<int> unbooked;
    vector<int> hours = request.hours();
    vector<int> res;
    // TODO: add free hours size = hours
    //check if a room has all the hours
    for(auto room = rooms.begin(); room != rooms.end(); room++){
        if(room->freeHours().size() >= hours.size()){
            return room->book(hours,request.name);
        }
    }
    if(rooms.size() > 0){
        unbooked = rooms[0].book(hours,request.name);
        for(auto room = rooms.begin()+1; room != rooms.end(); room++){
            res = room->book(unbooked, request.name);
            unbooked = res;
        }
    }
    return unbooked;
}
std::ostream & operator <<( std::ostream &os, Semester &semester ){
    os << semester.printRooms() << endl;
    return os;
}

set<string> Semester::CheckAvailability(Block b){
    vector<int> hours = b.hours();
    set<string> teachers;
    for(auto room : rooms){
        for(auto h: hours){
            teachers.insert(room.check(h));
        }
    }

    return teachers;

    /*
    string s;
    if(teachers.size() == 0){
        return "";
    }else if(teachers.size() == 1){
        return *teachers.begin();
    }else{
        s.append(*teachers.begin());
        for(auto teacher = ++teachers.begin(); teacher != teachers.end(); teacher++){
            if(*teacher != "")
                s.append(" & " + *teacher);
        }
        return s;
    }
   */
}


const string Semester::printRooms(){
    string s;

    for(auto room: rooms){
        s.append(room.printRoom());
    }
    return s;

}
