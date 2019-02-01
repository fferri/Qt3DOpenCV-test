#include <QGuiApplication>
#include <Qt3DQuickExtras/qt3dquickwindow.h>
#include "opencvcaptureimage.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType<OpenCVCaptureImage>("OpenCVCaptureImage", 1, 0, "OpenCVCaptureImage");

    QGuiApplication app(argc, argv);

    Qt3DExtras::Quick::Qt3DQuickWindow view;
    view.setSource(QUrl("qrc:/MyScene.qml"));
    view.show();

    return app.exec();
}
