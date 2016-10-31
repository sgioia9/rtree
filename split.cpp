//
// Created by Geno on 30-Oct-16.
//

#include "split.h"

std::vector<Rectangle> Split::get_extreme_rects(const std::vector<Rectangle> &source) {
    Rectangle topY = source[0];
    Rectangle bottomY = source[0];
    Rectangle leftX = source[0];
    Rectangle rightX = source[0];
    for (const Rectangle& rectangle : source) {
        if (rectangle.x2 < leftX.x2) leftX = rectangle;
        if (rectangle.x1 > rightX.x1) rightX = rectangle;
        if (rectangle.y2 > topY.y2) topY = rectangle;
        if (rectangle.y1 < bottomY.y1) bottomY = rectangle;
    }
    std::vector<Rectangle> res;
    res.push_back(leftX);
    res.push_back(rightX);
    res.push_back(topY);
    res.push_back(bottomY);
    return res;
}
