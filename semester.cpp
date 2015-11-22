#include "assignment.h"

void Semester::AddRoom(string name){
    rooms.push_back(Room(name));
}
vector<int> Semester::AssignRoom(Request request){
    vector<int> unbooked;
    vector<int> hours = request.hours();
    vector<int> res;
    bool teacherOnTheBlock = 0;
    // TODO: add free hours size = hours
    //check if a room has all the hours
    for(auto room = rooms.begin(); room != rooms.end(); room++){
        if(room->freeHours().size() >= hours.size()){
            for(auto h : hours){ // checking if the block is available
                if(room->check(h) != ""){
                    teacherOnTheBlock = 1; // if there is a teacher on the block we don't book
                }
            }
            if(!teacherOnTheBlock)
                return room->book(hours,request.name);
            teacherOnTheBlock = 0;
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
    string teacherName = "";
    for(auto room : rooms){
        for(auto h: hours){
            teacherName = room.check(h);
            if(teacherName != "")
                teachers.insert(teacherName);
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


unsigned int Semester::NumberRooms(){
    return this->rooms.size();
}

const string Semester::printRooms(){
    string s;

    for(auto room: rooms){
        s.append(room.printRoom());
    }
    return s;

}
