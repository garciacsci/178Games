#ifndef GLCHECKCOLLISION_H
#define GLCHECKCOLLISION_H

// include necessary libraries
#include "common.h" // for vec2

// declare your class or functions here
class GLCheckCollision {
    public:
        GLCheckCollision(); // constructor
        virtual ~GLCheckCollision(); // destructor

        // declare collision detection functions
            // 2D
        bool isLinearCollision(float, float); // check x,x1 or y,y1 components

        bool isRadialCollision(vec3, vec3, float, float, float); 
        // element 1, element2, radius1, radius2, threshold

        bool isHitPlane(vec2, float); // check ovject vs floor/wall

            // 3D
        bool isCubicCollision(float, float); // check x, y, z components of two models
        
        bool isSphereCollision(vec3, vec3, float, float, float); 
        // element 1, element2, radius1, radius2, threshold
        bool isHitPlane3D(vec3, float); // check ovject vs floor/wall

        


    protected:

    private:

};

#endif // GLCHECKCOLLISION_H