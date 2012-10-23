#include <QApplication>
#include "gomokugame.h"

int main(int argc, char **argv){
    QApplication *app = new QApplication(argc,argv);
    gomokugame *main = new gomokugame();
    main->show();
    return app->exec();
}
