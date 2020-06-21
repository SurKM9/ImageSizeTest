#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QResizeEvent>

class ImageWidget;

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:

        MainWindow(QWidget* parent = nullptr);

    public slots:

        void on_btn_clicked();

    protected:

        virtual void resizeEvent(QResizeEvent* event) override;

    private:

        QString m_imageName;
        ImageWidget* m_imageWidget;
};
#endif // MAINWINDOW_H
