#include "mw1.h"
#include "write_in.h"
#include <QApplication>
#include <fstream>
fstream error;
fstream write;
write_in draw;
bool man=true;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    write.open("C:\\Users\\123213\\Desktop\\map.txt",ios::in);
//    if(write.peek()==EOF){
    //}

    draw.write_all("/Users/air/desktop/castle.txt");
    MW1 mw;
    mw.show();

    return a.exec();
}
