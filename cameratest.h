#ifndef CAMERATEST_H
#define CAMERATEST_H

#include <QMainWindow>

#include <QCamera>
#include <QCameraInfo>
#include <QCameraImageCapture>
#include <QPixmap>
#include <QAbstractVideoSurface>
#include <QVideoFrame>
#include <QLabel>

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

    void saveImage(int,QImage);

    void on_saveButton_clicked();

private:
    Ui::CameraTest *ui;
    QCamera                 *m_pCamera;
    QCameraImageCapture     *m_pImageCapture;     //截图部件
    MyVideoSurface          *m_pVf;
    QLabel                  *m_label_camera_show;
};
#endif // CAMERATEST_H
