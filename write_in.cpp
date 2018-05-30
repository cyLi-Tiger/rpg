#include "write_in.h"
#include <iostream>
#include <fstream>
using namespace std;

extern fstream write;

void write_in::write_player(string fileName){
     write.open(fileName.c_str(),ios::app);
     write<<"player "<<5<<" "<<5<<endl;
     write.close();
}

void write_in::write_ground(string fileName){//铺满小界面
    write.open(fileName.c_str(),ios::app);
    for(int i=0;i<25;i++){
            for(int j=0;j<20;j++){
                write<<"ground "<<i<<" "<<j<<endl;
            }
        }
    write.close();
}


void write_in::write_plant(string fileName){//  i横坐标，j纵坐标,画出植物围成的 ‘5’字形
    write.open(fileName.c_str(),ios::app);
    for(int j=5;j<15;j++){
        write<<"plant "<<6<<" "<<j<<endl;
    }
    for(int i=7;i<13;i++){
        write<<"plant "<<i<<" "<<14<<endl;
    }
    for(int j=5;j<9;j++){
        write<<"plant "<<13<<" "<<j<<endl;
    }
    for(int j=10;j<15;j++){
        write<<"plant "<<13<<" "<<j<<endl;
    }
    for(int i=14;i<20;i++){
        write<<"plant "<<i<<" "<<5<<endl;
    }
    for(int j=5;j<15;j++){
        write<<"plant "<<20<<" "<<j<<endl;
    }
    for(int i=16;i<20;i++){
        write<<"plant "<<i<<" "<<14<<endl;
    }
    write.close();
}

void write_in::write_stone(string fileName){
    write.open(fileName.c_str(),ios::app);
    for(int j=7;j<12;j++){
        write<<"stone "<<8<<" "<<j<<endl;
    }
    for(int j=7;j<12;j++){
        write<<"stone "<<11<<" "<<j<<endl;
    }
    for(int i=16;i<19;i++){
        write<<"stone "<<i<<" "<<7<<endl;
    }
    for(int i=16;i<19;i++){
        write<<"stone "<<i<<" "<<9<<endl;
    }
    for(int i=16;i<19;i++){
        write<<"stone "<<i<<" "<<12<<endl;
    }
    for(int j=7;j<13;j++){
        write<<"stone "<<16<<" "<<j<<endl;
    }
    for(int i=1;i<24;i++){
        write<<"stone "<<i<<" "<<0<<endl;
        write<<"stone "<<i<<" "<<18<<endl;
    }
    for(int j=1;j<18;j++){
        write<<"stone "<<0<<" "<<j<<endl;
        write<<"stone "<<24<<" "<<j<<endl;
    }
    write.close();
}

void write_in::write_flower(string fileName){
    write.open(fileName.c_str(),ios::app);
    write<<"flower "<<13<<" "<<9<<endl;
    write<<"flower "<<9<<" "<<7<<endl;
    write<<"flower "<<10<<" "<<11<<endl;
    write<<"flower "<<16<<" "<<6<<endl;
    write<<"flower "<<17<<" "<<10<<endl;
    write.close();
}
void write_in::write_grave(string fileName){
    write.open(fileName.c_str(),ios::app);
    write<<"grave "<<8<<" "<<13<<endl;
    write.close();
}

void write_in::write_end(string fileName){
    write.open(fileName.c_str(),ios::app);
    write<<"EOF"<<endl;
    write.close();
}



