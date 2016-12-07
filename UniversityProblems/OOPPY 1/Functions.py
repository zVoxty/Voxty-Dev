from turtle import *
from operator import itemgetter

from math import *

def GetRectangleOfPolygon(polygon):
    polygon.sort()
    xMin = polygon[0][0]
    xMax = polygon[len(polygon)-1][0]

    polygon.sort(key=lambda x: x[1])

    yMin = polygon[0][1]
    yMax = polygon[len(polygon)-1][1]

    rectangle = [[xMin,yMin],[xMax,yMin], [xMax,yMax],[xMin,yMax]]

    return rectangle

def GetArea(polygon):
    area = 0
    for i in range(len(polygon)-1):
        area += polygon[i][0] * polygon[i + 1][1] - polygon[i + 1][0] * polygon[i][1]
    return fabs(area/2)

def GetDistance(point1, point2):
    return sqrt((point2[0] - point1[0])**2 + (point2[1] - point1[1])**2)

def GetPolygonPerimeter(polygon):
    perimeter = 0
    for i in range(len(polygon)-1):
        perimeter += GetDistance(polygon[i],polygon[i+1])

    return perimeter

def GetInfo(polygon):
    numberOfPoints = int(input("Insert number of points : "))
    for i in range(numberOfPoints):
        print("Point ",i+1, ":")
        X = int(input("Insert X:"))
        Y = int(input("Insert Y:"))
        point = [X,Y]
        polygon.append(point)
        polygon.sort()

def DisplayPolygon(polygon):
    pu()
    for i in range(len(polygon)-1):
        goto(polygon[i][0] * 20,polygon[i][1]*20)
        pd()
        dot()

    goto(polygon[0][0]*20,polygon[0][1]*20)

def GetGravityCenter(polygon):
    x = 0
    y = 0
    for i in range(len(polygon)):
        x += polygon[i][0]
        y += polygon[i][1]

    x /= len(polygon)
    y /= len(polygon)

    return [x,y]

def PrintPolygon(polygon):
    for i in range(len(polygon)):
        print("Point ",i+1,":",polygon[i])

def ComparePolygons(polygon1, polygon2):
    p1Area = GetArea(polygon1)
    p2Area = GetArea(polygon2)

    if(p1Area > p2Area):
        return "Aria poligonului mai mare decat cea a dreptunghiului"
    else:
        return "Aria dreptunghiului mai mare decat cea a poligonului"

def printGraph():
    pu()
    goto(0,-200)
    lt(90)
    pd()
    fd(400)
    pu()
    goto(-200,0)
    pd()
    rt(90)
    fd(400)
    goto(0,0)


