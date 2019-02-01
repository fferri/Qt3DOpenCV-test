#ifndef OPENCVCAPTUREIMAGE_H
#define OPENCVCAPTUREIMAGE_H

#include <Qt3DRender/QPaintedTextureImage>
#include <opencv2/opencv.hpp>

class OpenCVCaptureImage : public Qt3DRender::QPaintedTextureImage
{
public:
    explicit OpenCVCaptureImage(Qt3DCore::QNode *parent = nullptr);
    void paint(QPainter *painter) override;

private:
    cv::VideoCapture cap_;
};


#endif // OPENCVCAPTUREIMAGE_H
