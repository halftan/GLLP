#include <QtGui>
#include "chessbutton.h"

chessButton::chessButton(int i, int j, QWidget *parent)
    : QLabel(parent), loc_i(i), loc_j(j){}

void chessButton::mousePressEvent(QMouseEvent *event){
    clicked(loc_i, loc_j, event->button());
}
