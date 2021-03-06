#ifndef JOINTROTATION_H
#define JOINTROTATION_H

#include "tools.h"
#include "meshinfo.h"
#include <QQuaternion>

/**
 Tool to rotate joints in a mesh
  */
class JointRotationTool : public Tool
{
private:
    QList<int> findRoots();
    void updateBaseMesh();
    void updateVertices();
    void calculateRelativeTransforms();
    void calculateAbsoluteTransforms();
    void calcTransform(int index, const QQuaternion &parentRotation, const Vector3 &parentTranslation);
    void updateBallCenter(int index);
    float getAngleOnPlane(int x, int y);

    // rotation quaternion and translation vector (relative to parent)
    QVector<QQuaternion> relativeRotations;
    QVector<Vector3> relativeTranslations;
    QVector<QQuaternion> absoluteRotations;
    QVector<Vector3> absoluteTranslations;

    // Remember info about the mesh so we can tell when it has changed
    MeshInfo meshInfo;

    // copy of the base mesh from when this tool was instatiated
    Mesh *baseMesh;

    float originalAngle;
    QQuaternion originalRotation;
    Vector3 projectedCenter;
    Vector3 planeNormal;

    int oldX, oldY;

public:
    JointRotationTool(View *view);
    ~JointRotationTool();

    bool mousePressed(QMouseEvent *event);
    void mouseDragged(QMouseEvent *event);
    void mouseReleased(QMouseEvent *event);
};

#endif // JOINTROTATION_H
