#include "myvideosurface.h"

MyVideoSurface::MyVideoSurface(QObject *parent) : QAbstractVideoSurface(parent)
{

}

QList<QVideoFrame::PixelFormat> MyVideoSurface::supportedPixelFormats(
        QAbstractVideoBuffer::HandleType handleTyle) const
{
    //返回图形的处理格式，window下转换的图片格式是Format_RGB32,苹果下的则是Format_ARGB32
    return QList<QVideoFrame::PixelFormat>()<<QVideoFrame::Format_RGB32;
}

//重载基类中的函数，用于获取当前帧的视频源数据
bool MyVideoSurface::present(const QVideoFrame &frame)
{
    emit videoChanged(frame);
    return true;
}
