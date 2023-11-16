#pragma once
#include "Vec2.h"
class Cam2D
{
    private : 
        Vec2<float> _offset;
        Vec2<float> _target;
        float _rotation;
        float _zoom;
    public :
        Cam2D();
        Cam2D(Vec2<float> offset, Vec2<float> target, float rotation, float zoom);
        void SetOffset(Vec2<float> offset);
        void SetTarget(Vec2<float> offset);

        Vec2<float> GetOffset();
        Vec2<float> GetTarget();
        float GetRotation();
        float GetZoom();
};
