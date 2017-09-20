#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"
#include <list>

const double epsilon = 0.00001;

TEST (Sort, sortByIncreasingPerimeter) {
    Sort *sorter = new Sort();
    Circle *c1 = new Circle(0, 0, 5, "Circle_1");
    Rectangle *r1 = new Rectangle(1, 1, 4, 2, "Rectangle_1");
    vertex v1,v2,v3;
    v1.x = 0;
    v1.y = 0;
    v2.x = 5;
    v2.y = 0;
    v3.x = 0;
    v3.y = 5;
    Triangle *t1 = new Triangle(v1, v2, v3, "Triangle_1");
    std::list<Shape*> shapeList;
    std::list<Shape*>::iterator it;
    shapeList.push_back(c1);
    shapeList.push_back(r1);
    shapeList.push_back(t1);
    sorter->sortByIncreasingPerimeter(&shapeList);
    Shape *tempS;
    int countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 1) break;
    }
    ASSERT_NEAR(12, tempS->perimeter(), epsilon);
    countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 2) break;
    }
    ASSERT_NEAR(17.071067, tempS->perimeter(), epsilon);
    countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 3) break;
    }
    ASSERT_NEAR(31.415926, tempS->perimeter(), epsilon);
}

TEST (Sort, sortByDecreasingPerimeter) {
    Sort *sorter = new Sort();
    Circle *c1 = new Circle(0, 0, 5, "Circle_1");
    Rectangle *r1 = new Rectangle(1, 1, 4, 2, "Rectangle_1");
    vertex v1,v2,v3;
    v1.x = 0;
    v1.y = 0;
    v2.x = 5;
    v2.y = 0;
    v3.x = 0;
    v3.y = 5;
    Triangle *t1 = new Triangle(v1, v2, v3, "Triangle_1");
    std::list<Shape*> shapeList;
    std::list<Shape*>::iterator it;
    shapeList.push_back(c1);
    shapeList.push_back(r1);
    shapeList.push_back(t1);
    sorter->sortByDecreasingPerimeter(&shapeList);
    Shape *tempS;
    int countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 1) break;
    }
    ASSERT_NEAR(31.415926, tempS->perimeter(), epsilon);
    countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 2) break;
    }
    ASSERT_NEAR(17.071067, tempS->perimeter(), epsilon);
    countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 3) break;
    }
    ASSERT_NEAR(12, tempS->perimeter(), epsilon);
}

TEST (Sort, sortByIncreasingArea) {
    Sort *sorter = new Sort();
    Circle *c1 = new Circle(0, 0, 5.0, "Circle_1");
    Rectangle *r1 = new Rectangle(1, 1, 4, 2, "Rectangle_1");
    vertex v1,v2,v3;
    v1.x = 0;
    v1.y = 0;
    v2.x = 5;
    v2.y = 0;
    v3.x = 0;
    v3.y = 5;
    Triangle *t1 = new Triangle(v1, v2, v3, "Triangle_1");
    std::list<Shape*> shapeList;
    std::list<Shape*>::iterator it;
    shapeList.push_back(c1);
    shapeList.push_back(r1);
    shapeList.push_back(t1);
    Shape *tempS;
    sorter->sortByIncreasingArea(&shapeList);
    int countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 1) break;
    }
    ASSERT_NEAR(8, tempS->area(), epsilon);
    countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 2) break;
    }
    ASSERT_NEAR(12.5, tempS->area(), epsilon);
    countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 3) break;
    }
    ASSERT_NEAR(78.53981, tempS->area(), epsilon);
}

TEST (Sort, sortByDecreasingArea) {
    Sort *sorter = new Sort();
    Circle *c1 = new Circle(0, 0, 5.0, "Circle_1");
    Rectangle *r1 = new Rectangle(1, 1, 4, 2, "Rectangle_1");
    vertex v1,v2,v3;
    v1.x = 0;
    v1.y = 0;
    v2.x = 5;
    v2.y = 0;
    v3.x = 0;
    v3.y = 5;
    Triangle *t1 = new Triangle(v1, v2, v3, "Triangle_1");
    std::list<Shape*> shapeList;
    std::list<Shape*>::iterator it;
    shapeList.push_back(c1);
    shapeList.push_back(r1);
    shapeList.push_back(t1);
    Shape *tempS;
    sorter->sortByDecreasingArea(&shapeList);
    int countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 1) break;
    }
    ASSERT_NEAR(78.53981, tempS->area(), epsilon);
    countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 2) break;
    }
    ASSERT_NEAR(12.5, tempS->area(), epsilon);
    countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 3) break;
    }
    ASSERT_NEAR(8, tempS->area(), epsilon);
}

TEST (Sort, sortByIncreasingCompactness) {
    Sort *sorter = new Sort();
    Circle *c1 = new Circle(0, 0, 5.0, "Circle_1");
    Rectangle *r1 = new Rectangle(1, 1, 4, 2, "Rectangle_1");
    vertex v1,v2,v3;
    v1.x = 0;
    v1.y = 0;
    v2.x = 5;
    v2.y = 0;
    v3.x = 0;
    v3.y = 5;
    Triangle *t1 = new Triangle(v1, v2, v3, "Triangle_1");
    std::list<Shape*> shapeList;
    std::list<Shape*>::iterator it;
    shapeList.push_back(c1);
    shapeList.push_back(r1);
    shapeList.push_back(t1);
    Shape *tempS;
    sorter->sortByIncreasingCompactness(&shapeList);
    int countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 1) break;
    }
    ASSERT_EQ("Rectangle_1", tempS->getShapeName());
    countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 2) break;
    }
    ASSERT_EQ("Triangle_1", tempS->getShapeName());
    countNumber = 0;
    for(it=shapeList.begin(); it!=shapeList.end(); it++){
        tempS = *it;
        countNumber++;
        if(countNumber == 3) break;
    }
    ASSERT_EQ("Circle_1", tempS->getShapeName());
}

#endif
