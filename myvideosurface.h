#ifndef MYVIDEOSURFACE_H
#define MYVIDEOSURFACE_H

#include <QAbstractVideoSurface>
#include <QList>
#include <QVideoFrame>

class MyVideoSurface : public QAbstractVideoSurface
{
    Q_OBJECT
public:
    explicit MyVideoSurface(QObject *parent = nullptr);

    //重载    用于设置程序支持原始视频格式
    virtual QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleTyle) const;

    bool present(const QVideoFrame &frame);

signals:
    void videoChanged(QVideoFrame);

public slots:
};

#endif // MYVIDEOSURFACE_H
