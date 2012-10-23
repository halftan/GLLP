#ifndef GOMOKUGAME_H
#define GOMOKUGAME_H

#include <QWidget>
#include "chessbutton.h"

#define WHITE 2
#define BLACK 1
#define NEXT_TURN(x) 3 - x
#define LEN 15

class QLabel;
class QLineEdit;
class QPushButton;
class QPixmap;

class gomokugame : public QWidget
{
    Q_OBJECT

public:
    gomokugame(QWidget *parent = 0);
    ~gomokugame();

private:
    QLabel *board;
    QLabel *p1Name;
    QLabel *p2Name;
    QLabel *blackPrev;
    QLabel *whitePrev;
    QLabel *notice;
    QPushButton *clearButton;
    QPushButton *quitButton;
    QLineEdit *p1NameEdit;
    QLineEdit *p2NameEdit;
    QPixmap *board_pic;
    QPixmap *black_pic;
    QPixmap *white_pic;

    short int whosTurn;
    bool boardEnabled;

    chessButton *loc[LEN][LEN];
    short int bdmap[LEN][LEN];

    bool hasFive(int loc_i, int loc_j, short int patt);
    void gameOver(short int winner);

private slots:
    void on_p1Name_Changed(const QString &name);
    void on_p2Name_Changed(const QString &name);
    void clearBoard(void);
    void chessMove(int i, int j, Qt::MouseButton button);
//    void on_Mouse_Clicked(void);

};

#endif // GOMOKUGAME_H
