#include "Plotter.h"
#include "simpio.h"
#include "filelib.h"
#include <string>
#include "vector.h"
#include "strlib.h"

using namespace std;

// Define a struct for recording coordinate
struct Point2d
{
    double _x;
    double _y;

    Point2d(double x, double y)
        :_x(x), _y(y){}
};

// PROCESS ALL TYPES OF COMMANDS
void ProcessPenDown(bool &isPenDown, Point2d pt, Vector<Point2d> &pointsPerLine);
void ProcessPenUp(bool &isPenDown, Vector<Point2d> &pointsPerLine, PenStyle penStyle);
void ProcessPenColor(PenStyle &style, string& command);
void ProcessPenWidth(PenStyle &style, string& command);
void ProcessMoveAbs(Point2d &pt, const string& command, const bool isPenDown, Vector<Point2d> &pointsPerLine);
void ProcessMoveRel(Point2d &pt, const string& command,  const bool isPenDown, Vector<Point2d> &pointsPerLine);

// MAIN SCRIPT
void runPlotterScript(istream& input) {

    // all the commands to process
    Vector<string> commands;
    readEntireFile(input, commands);

    // init pen style
    PenStyle style;
    style.width = 1;
    style.color = "black";

    // init coordinate
    Point2d pt(0 ,0);

    // init pen state
    bool isPenDown = false;

    // Line
    Vector<Point2d> pointsPerLine;

    // process command per line
    for(string command : commands)
    {
        command = toUpperCase(command);

        if(startsWith(command, "PENDOWN"))
        {
            ProcessPenDown(isPenDown, pt, pointsPerLine);
        }
        else if(startsWith(command, "PENUP"))
        {
            ProcessPenUp(isPenDown, pointsPerLine, style);
        }
        else if(startsWith(command, "MOVEABS"))
        {
            ProcessMoveAbs(pt, command, isPenDown, pointsPerLine);
        }
        else if(startsWith(command, "MOVEREL"))
        {
            ProcessMoveRel(pt, command, isPenDown, pointsPerLine);
        }
        else if(startsWith(command, "PENCOLOR"))
        {
            ProcessPenColor(style, command);
        }
        else if(startsWith(command, "PENWIDTH"))
        {
            ProcessPenWidth(style, command);
        }
        else
        {
            // do nothing
        }

    }

    // in the end, if the robot arm not up, raise it
    if(isPenDown)
    {
        ProcessPenUp(isPenDown, pointsPerLine, style);
    }

}

void ProcessPenDown(bool &isPenDown, Point2d pt, Vector<Point2d> &pointsPerLine)
{
    isPenDown = true;
    pointsPerLine.add(pt);
}

void ProcessPenUp(bool &isPenDown, Vector<Point2d> &pointsPerLine, PenStyle penStyle)
{

    if(pointsPerLine.size() < 2)
    {
        return;
    }

    for(int i = 0; i < pointsPerLine.size() - 1; i++)
    {
        drawLine(pointsPerLine[i]._x, pointsPerLine[i]._y,
                 pointsPerLine[i+1]._x, pointsPerLine[i+1]._y,
                 penStyle);
    }

    pointsPerLine.clear();
    isPenDown = false;
}

void ProcessPenColor(PenStyle &style, string& command)
{
    Vector<string> elements = stringSplit(command, " ");
    style.color = elements[1];
}

void ProcessPenWidth(PenStyle &style, string& command)
{
    Vector<string> elements = stringSplit(command, " ");
    style.width = stringToReal(elements[1]);
}

void ProcessMoveAbs(Point2d &pt, const string& command, const bool isPenDown, Vector<Point2d> &pointsPerLine)
{
    Vector<string> elements = stringSplit(command, " ");

    pt._x = stringToReal(elements[1]);
    pt._y = stringToReal(elements[2]);

    if(isPenDown)
    {
        pointsPerLine.add(pt);
    }
}

void ProcessMoveRel(Point2d &pt, const string& command,  const bool isPenDown, Vector<Point2d> &pointsPerLine)
{
    Vector<string> elements = stringSplit(command, " ");

    pt._x += stringToReal(elements[1]);
    pt._y += stringToReal(elements[2]);

    if(isPenDown)
    {
        pointsPerLine.add(pt);
    }
}
