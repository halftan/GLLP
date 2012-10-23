#include <QtGui>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPixmap>
#include <QWidget>
#include <QMouseEvent>

#include "gomokugame.h"

gomokugame::gomokugame(QWidget *parent)
    :QWidget(parent)
{
    board = new QLabel;
    p1Name = new QLabel;
    p2Name = new QLabel;
    blackPrev = new QLabel;
    whitePrev = new QLabel;
    notice = new QLabel;

    whosTurn = BLACK;
    boardEnabled = true;

    clearButton = new QPushButton(tr("&Clear"));
    quitButton = new QPushButton(tr("&Quit"));

    p1NameEdit = new QLineEdit;
    p2NameEdit = new QLineEdit;

    board_pic = new QPixmap(":/res/gomokub.png");
    black_pic = new QPixmap(":/res/blackp.png");
    white_pic = new QPixmap(":/res/whitep.png");

    board->setPixmap(*board_pic);
    blackPrev->setPixmap(*black_pic);
    whitePrev->setPixmap(*white_pic);

    connect(quitButton, SIGNAL(clicked()),
            this, SLOT(close()));
    connect(p1NameEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(on_p1Name_Changed(const QString &)));
    connect(p2NameEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(on_p2Name_Changed(const QString &)));
    connect(clearButton, SIGNAL(clicked()),
            this, SLOT(clearBoard()));

    QHBoxLayout *rightLayout = new QHBoxLayout;
    rightLayout->addWidget(board);

    QVBoxLayout *leftUpLayout = new QVBoxLayout;
    leftUpLayout->addWidget(p1Name);
    leftUpLayout->addWidget(p1NameEdit);
    leftUpLayout->addWidget(blackPrev);
    leftUpLayout->addSpacing(50);

    QVBoxLayout *leftMidLayout = new QVBoxLayout;
    leftMidLayout->addWidget(p2Name);
    leftMidLayout->addWidget(p2NameEdit);
    leftMidLayout->addWidget(whitePrev);
    leftMidLayout->addSpacing(100);

    QVBoxLayout *leftDownLayout = new QVBoxLayout;
    leftDownLayout->addWidget(notice);
    leftDownLayout->addWidget(clearButton);
    leftDownLayout->addWidget(quitButton);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(leftUpLayout);
    leftLayout->addLayout(leftMidLayout);
    leftLayout->addLayout(leftDownLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(rightLayout);
    mainLayout->addLayout(leftLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Gomoku"));
    setWindowIcon(*black_pic);
    setFixedHeight(sizeHint().height());
    setFixedWidth(sizeHint().width());

    p1Name->setText("Player1");
    p2Name->setText("Player2");

    for(int i = 0; i < LEN; ++i)
        for(int j = 0; j < LEN; ++j){
            loc[i][j] = new chessButton(i,j,board);
            loc[i][j]->setGeometry(23 + j*35,
                                   18 + i*35,
                                   35, 35);
            loc[i][j]->setPixmap(0);
            connect(loc[i][j], SIGNAL(clicked(int,int,Qt::MouseButton)),
                    this, SLOT(chessMove(int, int, Qt::MouseButton)));
            bdmap[i][j] = 0;
        }
}

gomokugame::~gomokugame(){
    this->~QWidget();
}

void gomokugame::on_p1Name_Changed(const QString &name){
    this->p1Name->setText(name);
}

void gomokugame::on_p2Name_Changed(const QString &name){
    this->p2Name->setText(name);
}

void gomokugame::clearBoard(){
    this->notice->clear();
    this->whosTurn = BLACK;
    for(int i = 0; i < LEN; ++i)
        for(int j = 0; j < LEN; ++j){
            loc[i][j]->setPixmap(0);
            bdmap[i][j] = 0;
        }
    boardEnabled = true;
}

bool gomokugame::hasFive(int loc_i, int loc_j, short patt){
    int i, j, count;
    i = loc_i;
    j = loc_j;
    while(i >= 0 && bdmap[i][j] == patt)
        --i;
    ++i; count = 0;
    //up down 5
    while(i < LEN && bdmap[i][j] == patt){
        ++count; ++i;
    }
    if(count >= 5)
        return true;
    // left right 5
    i = loc_i; j = loc_j;
    while(j >= 0 && bdmap[i][j] == patt)
        --j;
    ++j; count = 0;
    while(j < LEN && bdmap[i][j] == patt){
        ++count; ++j;
    }
    if(count >= 5)
        return true;
    //up left - down right 5
    i = loc_i; j = loc_j;
    while(i >= 0 && j >= 0 && bdmap[i][j] == patt){
        --i; --j;
    }
    ++i; ++j; count = 0;
    while(i < LEN && j < LEN && bdmap[i][j] == patt){
        ++count; ++i; ++j;
    }
    if(count >= 5)
        return true;
    //up right - down left 5
    i = loc_i; j = loc_j;
    while(i >= 0 && j < LEN && bdmap[i][j] == patt){
        --i; ++j;
    }
    ++i; --j; count = 0;
    while(i < LEN && j >= 0 && bdmap[i][j] == patt){
        ++count; ++i; --j;
    }
    if(count >= 5)
        return true;
    //no five
    return false;
}

void  gomokugame::gameOver(short winner){
    this->boardEnabled = false;
    switch(winner){
    case BLACK:
        this->notice->setText("Winner is " + this->p1Name->text());
        break;
    case WHITE:
        this->notice->setText("Winner is " + this->p2Name->text());
        break;
    default:
        this->notice->setText("Something wrong with winner-info.");
    }
}

void gomokugame::chessMove(int i, int j, Qt::MouseButton button){
    QString str;
    QPixmap *pie;
    if(!this->boardEnabled)
        return;
    if(button != Qt::LeftButton)
        return;
    if(!loc[i][j]->pixmap()->isNull())
        return;
    if(whosTurn == BLACK){
        pie = black_pic;
        str = "Black";
    }else{
        pie = white_pic;
        str = "White";
    }
    this->loc[i][j]->setPixmap(*pie);
    this->bdmap[i][j] = whosTurn;

    if(hasFive(i, j, whosTurn)){
        gameOver(whosTurn);
        return;
    }
    whosTurn = NEXT_TURN(whosTurn);
}
