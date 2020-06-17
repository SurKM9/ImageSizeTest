#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

class ImageWidget;

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:

        MainWindow(QWidget* parent = nullptr);
        ~MainWindow();

    public slots:

        void on_btn_clicked();

    private:

        QString m_imageName;
        ImageWidget* m_imageWidget;
};
#endif // MAINWINDOW_H
