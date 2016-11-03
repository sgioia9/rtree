//
// Created by stefano on 11/3/2016.
//

#include <cassert>
#include <iostream>
#include "rectangle.h"
#include "greeneSplit.h"
#include "rtree.h"
#include "linearsplit.h"

using namespace std;


void test1() {
    RTree rtree(10, 40, new LinearSplit(10, 40), "case1");
    rtree.setRootId(1);

    std::vector<int> expected;
    expected.push_back(3);
    expected.push_back(4);

    std::vector<int> results = rtree.find("case1", Rectangle(1, -50, 5, 20, -5));

    assert (results == expected);
}

void test2() {
    RTree rtree(10, 40, new LinearSplit(10, 40), "case2");
    rtree.setRootId(1);

    std::vector<int> expected;
    expected.push_back(5);

    std::vector<int> results = rtree.find("case2", Rectangle(1, -50, 5, 20, -5));
    assert (results == expected);

    results = rtree.find("case2", Rectangle(0, 12, 45, 30, 20));
    expected = vector<int>();
    expected.push_back(5);
    assert (results == expected);

    results = rtree.find("case2", Rectangle(0, 0, 200, 200, 0));
    expected = vector<int>();
    for (int i = 4; i <= 7; i++) {
        expected.push_back(i);
    }
    assert (results == expected);
}

void testLinearSplit() {
    Split* split = new LinearSplit(2, 5);

    vector<Rectangle> first;
    vector<Rectangle> second;

    vector<Rectangle> source;
    source.push_back(Rectangle(0, 50, 10, 30));
    source.push_back(Rectangle(15, 40, 25, 5));
    source.push_back(Rectangle(20, 10, 50, 8));
    source.push_back(Rectangle(35, 40, 40, 20));

    split->split(source, first, second);

    for (const Rectangle& rect : first) {
        cout << rect << endl;
    }
    cout << "------" << endl;
    for (const Rectangle& rect : second) {
        cout << rect << endl;
    }
    delete split;
}

void testGreeneSplit(){
    Split* split = new GreeneSplit(2, 5);

    vector<Rectangle> first;
    vector<Rectangle> second;

    vector<Rectangle> source;
    source.push_back(Rectangle(0, 50, 10, 30));
    source.push_back(Rectangle(15, 40, 25, 5));
    source.push_back(Rectangle(20, 10, 50, 8));
    source.push_back(Rectangle(35, 40, 40, 20));

    split->split(source, first, second);

    for (const Rectangle& rect : first) {
        cout << rect << endl;
    }
    cout << "------" << endl;
    for (const Rectangle& rect : second) {
        cout << rect << endl;
    }
    delete split;
}
