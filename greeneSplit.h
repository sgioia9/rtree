//
// Created by Geno on 30-Oct-16.
//

#ifndef RTREE_GREENESPLIT_H
#define RTREE_GREENESPLIT_H

#include "split.h"

class GreeneSplit : public Split {
public:
    GreeneSplit(RTree* rtree) : Split(rtree) { }

    virtual void split(const std::vector<Rectangle> &source,
                       std::vector<Rectangle> &firstSplit,
                       std::vector<Rectangle> &secondSplit) override;
};

#endif //RTREE_GREENESPLIT_H
