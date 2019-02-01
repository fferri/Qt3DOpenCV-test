import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import OpenCVCaptureImage 1.0
import QtQml 2.12

Entity {
    id: sceneRoot

    RenderSettings {
        id: renderSettings
        activeFrameGraph: ForwardRenderer {
            clearColor: Qt.rgba(0, 0.5, 1, 1)
            camera: Camera {
                id: objectsCamera
                projectionType: CameraLens.PerspectiveProjection
                fieldOfView: 45
                aspectRatio: 16/9
                nearPlane : 0.1
                farPlane : 1000.0
                position: Qt.vector3d( 0.0, 0.0, -40.0 )
                upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
                viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
            }
        }
    }

    InputSettings {
        id: inputSettings
    }

    components: [renderSettings, inputSettings]

    PlaneMesh {
        id: planeMesh
        width: 2
        height: 2
    }

    TextureMaterial {
        id: planeMaterial
        texture: Texture2D {
            id: planeTexture
            textureImages: [
                OpenCVCaptureImage {
                    id: capImage
                }
            ]
        }
    }

    /*
      timer in QML wil fail with error:
      TypeError: Property 'update' of object QPaintedTextureImage is not a function

    Timer {
        interval: 500
        running: true
        repeat: true
        onTriggered: capImage.update()
    }
    */

    Transform {
        id: planeTransform
        rotationX: 90
    }

    Entity {
        id: planeEntity
        components: [ planeMesh, planeMaterial, planeTransform ]
    }
}
