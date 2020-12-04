#include "cameratest.h"
#include "ui_cameratest.h"

CameraTest::CameraTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CameraTest)
{
    ui->setupUi(this);

    //获取电脑的摄像头名称
    QCameraInfo info = QCameraInfo::defaultCamera();
    //将设备名加入摄像头类中
    m_pCamera = new QCamera(info);
    m_pImageCapture = new QCameraImageCapture(m_pCamera);
    m_pImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);

    m_pVf = new MyVideoSurface(this);
    m_pCamera->setCaptureMode(QCamera::CaptureStillImage);
    //捕获视频流
    m_pCamera->setViewfinder(m_pVf);

     m_label_camera_show = new QLabel;


//     QCameraViewfinderSettings VfSettings;
//     VfSettings.setResolution(640, 480);
//     m_pCamera->setViewfinderSettings(VfSettings);
     //m_pCamera->setCaptureMode(QCamera::CaptureStillImage);
     //m_pCamera->start();

    connect(m_pVf, SIGNAL(videoChanged(QVideoFrame)), this, SLOT(videoChangedslot(QVideoFrame)));
    connect(m_pImageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(saveImage(int, QImage)));
}

CameraTest::~CameraTest()
{
    delete ui;
}

//捕捉摄像头的图片
void CameraTest::videoChangedslot(QVideoFrame curFrame)
{
    QVideoFrame frame(curFrame);
    frame.map(QAbstractVideoBuffer::ReadOnly);
    //将QVideoFrame对象构建QImage对象
    QImage image(frame.bits(), frame.width(), frame.height(),
                 QVideoFrame::imageFormatFromPixelFormat(frame.pixelFormat()));
    //设置图片旋转180°，摄像头图片默认的是倒影
    QMatrix matrix;
    matrix.rotate(180);
    image = image.transformed(matrix);
    //将QImage格式转化成QPixmap格式显示图片
    QPixmap pixmap = QPixmap::fromImage(image);
    pixmap = pixmap.scaled(ui->label->size());
    ui->label->setPixmap(pixmap);
}

//截图
void CameraTest::saveImage(int,QImage image)
{
    image=image.convertToFormat(QImage::Format_RGB888);
    m_label_camera_show->setPixmap(QPixmap::fromImage(image));
    const QPixmap *pixmap = m_label_camera_show->pixmap();

    if(pixmap)
    {
        pixmap->save("E:\\1.jpg");
    }

}

void CameraTest::on_startButton_clicked()
{
    m_pCamera->setCaptureMode(QCamera::CaptureStillImage);
    m_pCamera->start();
}

void CameraTest::on_closeButton_clicked()
{
    m_pCamera->stop();
    ui->label->clear();
}

void CameraTest::on_saveButton_clicked()
{
    m_pImageCapture->capture();
}
