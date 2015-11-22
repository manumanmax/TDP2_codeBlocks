//#include <QCoreApplication>

#include "assignment.h"



int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    Semester *A=new Semester();


    vector<Request> requests={
        Request({{1,3},{5,8}},"AAA"),   //Prof. AAA needs 8 slots
        Request({{0,2},{4,9}},"BBB"),   //Prof. BBB needs 9 slots
    };
    vector<string> rooms{"Ralph","Lisa","Bart"};

    for (auto room : rooms){
        A->AddRoom(room);
    }
    for (auto request : requests)
        A->AssignRoom(request);

    cout << *A << endl;

    //Prof. CCC would like block 1-2
    auto res1=A->CheckAvailability(Block(1,2));
    for (auto conflict: res1) cout << conflict << endl;
 /*   if (res1.size()!=A->NumberRooms())
        A->AssignRoom(Request({{1,2}},"CCC"));
    cout << *A << endl;

    //Prof. DDD would like block 1-2
    auto res2=A->CheckAvailability(Block(1,2));
    for (auto conflict: res2) cout << conflict << endl;
    if (res2.size()!=A->NumberRooms())
        A->AssignRoom(Request({{1,2}},"DDD"));
*/


    return 0;
}

