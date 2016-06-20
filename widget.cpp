#include "widget.h"
#include "ui_widget.h"
#include <QtWidgets>
// program name : OSM_Parse
// goal : osm 파일의 노드 값을 출력하는 기능


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);


    initialize();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initialize()
{

    QStringList labels;
    labels << tr("Way") << tr("Lat.") <<tr("Long.");
    ui->treeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
    ui->treeWidget->setHeaderLabels(labels);

    folderIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirClosedIcon),
                         QIcon::Normal, QIcon::Off);
    folderIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon),
                         QIcon::Normal, QIcon::On);

    headIcon.addPixmap(style()->standardPixmap(QStyle::SP_FileIcon));

}

void Widget::on_pushBrowse_clicked()
{

   QString defaultpath = QDir::home().filePath("Documents");
   QString fileName =
           QFileDialog::getOpenFileName(this,tr("open osm file"),
                                        defaultpath,
                                         tr("osm files (*.osm)"));
   if(fileName.isEmpty())
      return;


   pWorker = new WorkerThread(fileName,this);

   connect(pWorker,SIGNAL(sigWayValue(QString)),this, SLOT(slotWayValue(QString)));
   connect(pWorker,SIGNAL(sigNodeValue(QString)),this,SLOT(slotNodeValue(QString)));
   connect(pWorker,SIGNAL(sigAttrValue(QString,QString)),this,
                                                SLOT(slotAttrValue(QString,QString)));

   // signal
   pWorker->start();

}




void Widget::slotWayValue(QString id)
{
    Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable;

    row1 = new QTreeWidgetItem;
    row1->setFlags(flags);

    ui->treeWidget->addTopLevelItem(row1);
    row1->setIcon(0,folderIcon);
    row1->setText(0,id);


}

void Widget::slotNodeValue(QString ref)
{

    sub1 = new QTreeWidgetItem;
    sub1->setIcon(0,headIcon);
    sub1->setText(0,ref);
    row1->addChild(sub1);
}


void Widget::slotAttrValue(QString m_lat, QString m_long)
{

//    sub2 = new QTreeWidgetItem;
//    sub2->setText(1,m_lat);
//    sub2->setText(2,m_long);
//    row1->addChild(sub2);

}



