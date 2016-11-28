#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>

class MyObject : public QObject
{
public:
    MyObject(QGraphicsItem *i, QObject *parent = 0) : QObject(parent), itemToToggle(i)
    {
        startTimer(500);
    }
protected:
    void timerEvent(QTimerEvent *)
    {
        itemToToggle->setVisible(!itemToToggle->isVisible());
    }
private:
    QGraphicsItem *itemToToggle;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView gv;
    int width = 300;
    int height = 300;
    gv.setFixedSize(width, height);
    gv.setSceneRect(0, 0, width, height);
    gv.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gv.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    QGraphicsRectItem *item = new QGraphicsRectItem;
    item->setRect(0,0, 200,200);
    
    QGraphicsScene *scene = new QGraphicsScene(&gv);
    gv.setScene(scene);
    
    //QGraphicsItem *rect = scene->addRect(0, 0, 200, 200, QPen(Qt::NoPen), QBrush(Qt::yellow));
    //rect->setFlag(QGraphicsItem::ItemHasNoContents);
    //rect->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    
    //QGraphicsItem *childRect = scene->addRect(0, 0, 100, 100, QPen(Qt::), QBrush(Qt::red));
    item->setBrush(QBrush(Qt::red, Qt::SolidPattern));
    item->setPen(QPen(Qt::lightGray));	//rect->setPen(QPen(Qt::DotLine));
    item->setFlags(QGraphicsItem::ItemIsSelectable);
    //childRect->setParentItem(rect);
    scene->addItem(item);
    gv.show();
    /*
    MyObject o(rect);
    QMessageBox::information(0, "What you should see",
                             "The red rectangle should toggle visibility, so you should see it flash on and off");
     */
    return a.exec();
}
