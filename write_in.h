#ifndef WRITE_IN_H
#define WRITE_IN_H
#include<string>
using namespace std;

class write_in
{
public:
    write_in(){}
    void write_player(string fileName);
    void write_ground(string fileName);
    void write_plant(string fileName);
    void write_stone(string fileName);
    void write_flower(string fileName);
    void write_grave(string fileName);
    void write_end(string fileName);


    void write_all(string fileName){
        write_player(fileName);
        write_ground(fileName);
        write_plant(fileName);
        write_stone(fileName);
        write_flower(fileName);
        write_grave(fileName);
        write_end(fileName);
    }
};

#endif // WRITE_IN_H
