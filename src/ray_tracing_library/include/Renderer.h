//
// Created by Sahar on 10/06/2022.
//

#pragma once


#include <vector>
#include <Vec3.h>
#include "World.h"
#include "Camera.h"

class Renderer {

public:

    Renderer(const int imageWidth,
             const int imageHeight,
             const World &world,
             const Camera &camera,
             int rayBounces,
             int nSamplesPerPixel)
            : _imageWidth(imageWidth), _imageHeight(imageHeight), _world(world), _camera(camera), _nRayBounces(rayBounces),
              _nSamplesPerPixel(nSamplesPerPixel) {}

    [[nodiscard]] std::vector<Color> render() const;

private:
    int _imageWidth;
    int _imageHeight;
    const World &_world;
    const Camera &_camera;
    const int _nRayBounces;
    const int _nSamplesPerPixel;
};



