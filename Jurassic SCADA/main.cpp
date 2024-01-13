#include "JurassicSCADA.h"
#include "Camera.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JurassicSCADA w;
    w.show();
    return a.exec();
}
