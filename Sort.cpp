#include "include/Sort.h"
#include "include/Shapes.h"

void Sort::sortByIncreasingPerimeter(std::list<Shape *> * shapeList){
    shapeList->sort([](Shape *x, Shape *y) -> bool {return x->perimeter() < y->perimeter(); });
}

void Sort::sortByDecreasingPerimeter(std::list<Shape *> *shapeList){
    shapeList->sort([](Shape *x, Shape *y) -> bool {return x->perimeter() > y->perimeter(); });
}

void Sort::sortByIncreasingArea(std::list<Shape *> * shapeList){
    shapeList->sort([](Shape *x, Shape *y) -> bool {return x->area() < y->area(); });
}

void Sort::sortByDecreasingArea(std::list<Shape *> * shapeList){
    shapeList->sort([](Shape *x, Shape *y) -> bool {return x->area() > y->area(); });
}

void Sort::sortByIncreasingCompactness(std::list<Shape *> * shapeList){
    shapeList->sort([](Shape *x, Shape *y) -> bool
    {
        return (x->area()/x->perimeter()) < (y->area()/y->perimeter());
    });
}
