#include <vector>

const float timeStep = 1.0f / 60.0f;
const float density = 1.0f;

class Grid {
public:
    const int cellCountX;
    const int cellCountY;
    const float cellSize;

    std::vector<std::vector<float>> velocitiesX;
    std::vector<std::vector<float>> velocitiesY;

    Grid(int cellCountX, int cellCountY, float cellSize)
        : cellCountX(cellCountX), 
          cellCountY(cellCountY), 
          cellSize(cellSize),
          velocitiesX(cellCountX + 1, std::vector<float>(cellCountY, 0.0f)),
          velocitiesY(cellCountX, std::vector<float>(cellCountY + 1, 0.0f))
    {

    }
    public float CalculateVelocityDivergence(int xCoord, yCoord) {
		float velocityTop = velocitiesX[xCoord, yCoord + 1];
		float velocityBottom = velocitiesY[xCoord, yCoord];
		float velocityLeft = velocitiesY[xCoord, yCoord];
		float velocityRight = velocitiesX[xCoord + 1, yCoord];

		float gradientX = (velocityRight - velocityLeft) / cellSize; // approx for du/dx
		float gradientY = (velocityTop - velocityBottom) / cellSize; // approx for du/dy

		float divergence = gradientX + gradientY;
		return divergence;
	}


	std::vector<std::vector<float>> pressureMap;
    std::vector<std::vector<float>> velocitiesX;
    std::vector<std::vector<float>> velocitiesY;
    
    float GetPressure(int xCoord, int yCoord) {
        bool outOfBounds = x < 0 || x >= cellCountX || y < 0 || y >= cellCountY;
        return outOfBounds ? 0.0f : pressureMap[x][y];
    }

    void PressureSolveCell(int x, int y) {
        float pressureTop    = GetPressure(x, y + 1);
        float pressureLeft   = GetPressure(x - 1, y);
        float pressureRight  = GetPressure(x + 1, y);
        float pressureBottom = GetPressure(x, y - 1);

        float velocityTop    = VelocitiesY[x][y + 1];
        float velocityLeft   = VelocitiesX[x - 1][y];
        float velocityRight  = VelocitiesX[x][y];
        float velocityBottom = VelocitiesY[x][y];

        float pressureSum = pressureRight + pressureLeft + pressureTop + pressureBottom;
        float deltaVelocitySum = velocityRight - velocityLeft + velocityTop - velocityBottom;
        PressureMap[x][y] = (pressureSum - density * cellSize * deltaVelocitySum / timeStep) / 4.0f;
    }

    void SolvePressure() {
    	for(int i = 0; i < cellCountX; i++) {
    		for(int j = 0; j < cellCountY; j++) {
    			PressureSolveCell(i, j);
    		}
    	}
    }





};







