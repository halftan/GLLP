#ifndef CHESSBUTTON_H
#define CHESSBUTTON_H

#include <QLabel>

class chessButton : public QLabel
{
    Q_OBJECT
public:
    chessButton(int i, int j, QWidget *parent = 0);
    
signals:
    void clicked(int i, int j, Qt::MouseButton);
    
private:
    void mousePressEvent(QMouseEvent *event);
    int loc_i, loc_j;
    
};

#endif // CHESSBUTTON_H
