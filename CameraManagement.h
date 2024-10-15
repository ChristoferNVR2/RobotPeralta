//
// Created by chrisvega on 10/14/24.
//

#pragma once

#include <GL/glu.h>

struct Camera {
    float ex, ey, ez;
    float cx, cy, cz;
    float ux, uy, uz;

    void lookAt() const {
        gluLookAt(ex, ey, ez, cx, cy, cz, ux, uy, uz);
    }
};

inline Camera cam1 = {
    20, 20, 40,
    0, 2, 0,
    0, 1, 0
};

inline Camera cam2 = {
    20, 0, 40,
    0, 2, 0,
    0, 1, 0
};

inline Camera cam3 = {
    0, 0, 40,
    0, 2, 0,
    0, 1, 0
};

inline Camera cam4 = {
    40, 0, 0,
    0, 0, 0,
    0, 1, 0
};

inline Camera currentCam = cam1;
