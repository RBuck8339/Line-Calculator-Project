//------------------------------------------------------------
// File : LineCalculatorFinalProject.cpp
// Class: COP 2006, Fall2022
// Devel: Ronan Buck
// Desc : Program to determine properties of a line given
//        two points
//------------------------------------------------------------
#include <iostream>
#include <cmath>
//------------------------------------------------------------


// structure definitions
struct Point{
    float x;
    float y;
};

struct Line{
    Point Set1;
    Point Set2;
};
//------------------------------------------------------------


//function declarations
void GetPoints(Point & Set1, Point & Set2, int counter);
float FindSlope(Point Set1, Point Set2);
float FindYIntercept( Point Set1, float lineSlope);
double FindLength(Point Set1, Point Set2);
double FindAngle(Point Set1, Point Set2);
void LineInfo(Point Set1, Point Set2, float lineSlope, float lineYInt,
              double lineLength, double lineAngle);
//------------------------------------------------------------


int main() {
    char calculate = 'Y'; // initializes variable to continue the do-while loop
    // used to get and modify data points
    Line CurrentLine;
    do{
        int counter = 0; // used to ensure first Point struct is modified
        GetPoints(CurrentLine.Set1, CurrentLine.Set2, counter);
        counter += 1; // used to ensure second Point struct is modified
        GetPoints(CurrentLine.Set1, CurrentLine.Set2, counter);

        // functions used to calculate data
        float lineSlope = FindSlope(CurrentLine.Set1, CurrentLine.Set2);
        float lineYInt = FindYIntercept(CurrentLine.Set1,  lineSlope);
        double lineLength = FindLength(CurrentLine.Set1, CurrentLine.Set2);
        double lineAngle = FindAngle(CurrentLine.Set1, CurrentLine.Set2);

        // prints all calculated data
        LineInfo(CurrentLine.Set1, CurrentLine.Set2, lineSlope, lineYInt,
                 lineLength, lineAngle);

        // asks user if they would like to keep running the program and start over
        std::cout << "Do you wish to calculate another line using new data points? (y/n)";
        std::cin >> calculate;

    } while (calculate == 'y' || calculate == 'Y'); // continues program as long as user
                                                    // indicated they would like to continue
    return 0;
}


/**
 * Function to get two data points
 * @param Set1 struct used to store an 'x' and 'y' data point for the first point
 * @param Set2 struct used to store an 'x' and 'y' data point for the second point
 * @param counter used to determine if the first or second set of points should be modified
 */
void GetPoints(struct Point & Set1, struct Point & Set2, int counter){
    // modifies the x and y value of the first data point
    if (counter == 0){
        std::cout << "Enter the 'x' value for the first data point";
        std::cin >> Set1.x;
        std::cout << "Enter the 'y' value for the first data point";
        std::cin >> Set1.y;
    }

    // modifies the x and y value of the second data point
    if (counter == 1){
        std::cout << "Enter the 'x' value for the second data point";
        std::cin >> Set2.x;
        std::cout << "Enter the 'y' value for the second data point";
        std::cin >> Set2.y;
    }
}


/**
 * /Function to calculate the slope of a line using the slope equation
 * @param Set1 struct containing the x and y coordinate values of the first point
 * @param Set2 struct containing the x and y coordinate values of the second point
 * @return a float value for the slope of the line using the equation (y2-y1)/(x2-x1)
 */
float FindSlope(struct Point Set1, struct Point Set2){
    float slope = (Set2.y-Set1.y)/(Set2.x-Set1.x);
    return slope;
}


/**
 * Function to calculate the y-intercept of a line using slope-intercept equation
 * @param Set1 Used for the 'x' and 'y' values in the equation to find Y-Intercept
 * @param lineSlope Used in the equation to find Y-Intercept
 * @return a float value for the y-intercept of a line using the equation b=y-mx
 */
float FindYIntercept(struct Point Set1, float lineSlope){
    float YInt = Set1.y-(Set1.x*lineSlope);
    return YInt;
}


/**
 * Function to calculate the length of a line using quadratic equation
 * @param Set1 Used for the calculation of the line length using the 'x' and 'y' values
 * @param Set2 Used for the calculation of the line length using the 'x' and 'y' values
 * @return a float value for the length of the line using the quadratic equation
 */
double FindLength(struct Point Set1, struct Point Set2){
    double length = sqrt(pow(Set2.x-Set1.x,2)+pow(Set2.y-Set1.y,2));
    return length;
}


/**
 * Function to calculate the angle of a line solving for theta using cmath library functions
 * @param Set1 Used for the calculation of the line angles using the 'x' and 'y' values
 * @param Set2 Used for the calculation of the line angle using the 'x' and 'y' values
 * @return a float value for the angle of the line
 */
double FindAngle(struct Point Set1, struct Point Set2){
    double angle = atan2(Set2.y-Set1.y, Set2.x - Set1.x)*(180/M_PI);
    return angle;
}


/**
 * Function to output all calculated data
 * @param Set1 Data points to print out for the first ordered pair
 * @param Set2 Data points to print out for the second ordered pair
 * @param lineSlope Line slope from the "FindSlope()" function to output
 * @param lineYInt Y-intercept of the line from the "FindYInt()" function to output
 * @param lineLength Length of the line from the "FindLength()" function to output
 * @param lineAngle Angle of the line from the "FindAngle()" function to output
 */
void LineInfo(struct Point Set1, struct Point Set2, float lineSlope, float lineYInt,
        double lineLength, double lineAngle){

    std::cout << "The data points for your line are: (" << Set1.x << "," << Set1.y << "),";
    std::cout << "(" << Set2.x << "," << Set2.y << ")." << std::endl;
    std::cout << "The slope of the line is " << lineSlope << "." << std::endl;
    std::cout << "The line's y-intercept is at (0," << lineYInt << ")." << std::endl;
    std::cout << "The length of the line is " << lineLength << " units." << std::endl;
    std::cout << "The angle of the line is " << lineAngle << " degrees." << std::endl;
}