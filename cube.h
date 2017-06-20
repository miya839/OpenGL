#ifndef CUBE_H_
#define CUBE_H_

        GLdouble vetex[][3] = {
            {0.0,0.0,0.0},
            {1.0,0.0,0.0},
            {1.0,1.0,0.0},
            {0.0,1.0,0.0},
            {0.0,0.0,1.0},
            {1.0,0.0,1.0},
            {1.0,1.0,1.0},
            {0.0,1.0,1.0}
        };
        
        int edge[][2] = {
            {0,1},{1,2},{2,3},
            {3,0},{4,5},{5,6},
            {6,7},{7,4},{0,4},
            {1,5},{2,6},{3,7}
        };

int face[][4] = {
    {0,1,2,3},
    {1,5,6,2},
    {5,4,7,6},
    {4,0,3,7},
    {4,5,1,0},
    {3,2,6,7}
};

#endif

