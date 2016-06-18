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
    labels << tr("Tag") << tr("Attribute");
    ui->treeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
    ui->treeWidget->setHeaderLabels(labels);

//    folderIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirClosedIcon),
//                         QIcon::Normal, QIcon::Off);
//    folderIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon),
//                         QIcon::Normal, QIcon::On);

//    headIcon.addPixmap(style()->standardPixmap(QStyle::SP_FileIcon));
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


   WorkerThread *pWorker = new WorkerThread(fileName,this);
   pWorker->start();


}










