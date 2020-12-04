#ifndef CAMERATEST_H
#define CAMERATEST_H

#include <QMainWindow>

#include <QCamera>
#include <QCameraInfo>
#include <QPixmap>
#include <QAbstractVideoSurface>
#include <QVideoFrame>

#include "myvideosurface.h"



QT_BEGIN_NAMESPACE
namespace Ui { class CameraTest; }
QT_END_NAMESPACE

class CameraTest : public QMainWindow
{
    Q_OBJECT

public:
    CameraTest(QWidget *parent = nullptr);
    ~CameraTest();

private slots:
    void on_startButton_clicked();

    void on_closeButton_clicked();

    void videoChangedslot(QVideoFrame curFrame);


private:
    Ui::CameraTest *ui;
    QCamera             *m_pCamera;
    MyVideoSurface      *m_pVf;
};
#endif // CAMERATEST_H
