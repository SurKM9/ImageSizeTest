#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPixmap>

// local
#include "mainwindow.h"
#include "imagewidget.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    QVBoxLayout* vBox = new QVBoxLayout;

    QPushButton* btn = new QPushButton("Load", this);
    connect(btn, &QPushButton::clicked, this, &MainWindow::on_btn_clicked);

    m_imageWidget = new ImageWidget(this);

    vBox->addWidget(btn);
    vBox->addWidget(m_imageWidget);

    QWidget* widget = new QWidget;
    widget->setLayout(vBox);

    setCentralWidget(widget);

    resize(800, 600);
}



void MainWindow::on_btn_clicked()
{
    m_imageName = QFileDialog::getOpenFileName(nullptr, "Choose a file", QString(),
                  QString("(*.png)"));

    if(!m_imageName.isNull())
    {
        m_imageWidget->setImage(QPixmap::fromImage(QImage(m_imageName)));
    }
}



void MainWindow::resizeEvent(QResizeEvent* event)
{
    m_imageWidget->updateImage();
}

