#include "opencvcaptureimage.h"
#include <QPainter>
#include <QImage>
#include <QPaintDevice>
#include <QTimer>

OpenCVCaptureImage::OpenCVCaptureImage(Qt3DCore::QNode *parent)
    : Qt3DRender::QPaintedTextureImage(parent),
      cap_(0)
{
    QTimer::singleShot(2500, [=] {
        auto t = new QTimer(this);
        connect(t, &QTimer::timeout, [=] {
            this->update();
        });
        t->setInterval(200);
        t->start();
    });
}

void OpenCVCaptureImage::paint(QPainter *painter)
{
    cv::Mat frame;
    cap_ >> frame;
    QImage im(static_cast<uchar *>(frame.data), frame.cols, frame.rows, int(frame.step), QImage::Format_RGB888);
    if(im.isNull()) return;
    setSize(im.size());
    //int w = painter->device()->width();
    //int h = painter->device()->height();
    painter->drawImage(0, 0, im);
}
