#include <vector>

const unsigned X_AXIS_SCOPE = 100;
const unsigned Y_AXIS_SCOPE = 100;
const unsigned Z_AXIS_SCOPE = 100;
const float TIME_STEP = 1 / 60;
const float DENSITY = 1;


struct Voxel {
	float velocityTop;
	float velocityBottom;
	float velocityLeft;
	float velocityRight;
	float velocityFront;
	float velocityBack;
	float temperature;
	float density;
};


struct Grid {
	Voxel grid[X_AXIS_SCOPE][Y_AXIS_SCOPE][Z_AXIS_SCOPE];
};