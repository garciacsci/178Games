#include <GLCheckCollision.h>

GLCheckCollision::GLCheckCollision() {
    // constructor
}

GLCheckCollision::~GLCheckCollision() {
    // destructor
}

// 2D
    bool GLCheckCollision::isLinearCollision(float, float){} // check x,x1 or y,y1 components

    bool GLCheckCollision::isRadialCollision(vec3 p1, vec3 p2, float r1, float r2, float threshold){ // element 1, element2, 
        return( sqrt ( pow ( (p1.x - p2.x), 2 ) + pow ( (p1.y - p2.y), 2 ) ) < (r1 + r2) > threshold);
    }
    
    bool GLCheckCollision::isHitPlane(vec2, float){} // check ovject vs floor/wall

        // 3D
    bool GLCheckCollision::isCubicCollision(float, float){} // check x, y, z components of two models

    bool GLCheckCollision::isSphereCollision(vec3 p1, vec3 p2, float r1, float r2, float threshold)
    // element 1, element2, radius1, radius2
    {
        return( sqrt ( 
                  pow ( (p1.x - p2.x), 2 ) 
                + pow ( (p1.y - p2.y), 2 ) 
                + pow ( (p1.z - p2.z), 2 ) 
                ) < (r1 + r2) > threshold);
    }
    bool GLCheckCollision::isHitPlane3D(vec3, float){} // check ovject vs floor/wall