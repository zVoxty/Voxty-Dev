from Point import *
import os
class Polygon:

    points = []
    polygonName = ""
    polygonArea = 0
    polygonPerimeter = 0

    def __lt__(self, other):
         return self.polygonPerimeter < other.polygonPerimeter



    

