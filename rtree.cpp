#include <queue>
#include <fstream>

#include "rtree.h"

RTree::RTree(int m, int M, Split* split, const std::string& tree_directory)
        : m(m), M(M), split_method(split), tree_directory(tree_directory){
  current_tree_node = new RTreeNode(1, 0);
  root_id = 1;
  total_node_count = 1;
  current_tree_node->writeToDisk(tree_directory);
}

void RTree::find(const Rectangle other_rectangle) {
  std::queue<int> q;
  std::vector<Rectangle> results;
  std::ofstream result_file;
  result_file.open(tree_directory + "/last_find_result.txt");
  q.push(root_id);
  while (!q.empty()) {
    int next_node = q.front();
    q.pop();
    current_tree_node = RTreeNode::readFromDisk(tree_directory, next_node);
    for (const Rectangle& rectangle : current_tree_node->children) {
      if (other_rectangle.intersects(rectangle)) {
        if (current_tree_node->has_leaf_children) {
          results.push_back(rectangle);
          if(results.size() > M){
            for(Rectangle& rect : results){
              result_file << rect << "\n";
            }
            results.clear();
          }
        } else {
          q.push(rectangle.id);
        }
      }
    }
    delete current_tree_node;
  }
  for(Rectangle& rect : results){
    result_file << rect << "\n";
  }
  result_file.close();
}

void RTree::insert(Rectangle rectangle) {
  current_tree_node = RTreeNode::readFromDisk(tree_directory, root_id);
  rectangle.id = ++total_node_count;

  while (!current_tree_node->has_leaf_children) {
    long long min_area_diff = Rectangle::INF64;
    std::vector<Rectangle*> min_increasing_mbr_rectangles;
    for (Rectangle& child : current_tree_node->children) {
      double area_diff = Rectangle::mbr(child, rectangle).area() - child.area();
      if (area_diff < min_area_diff) {
        min_area_diff = area_diff;
        min_increasing_mbr_rectangles = std::vector<Rectangle*>();
        min_increasing_mbr_rectangles.push_back(&child);
      } else if (area_diff == min_area_diff) {
        min_increasing_mbr_rectangles.push_back(&child);
      }
    }
    Rectangle* min_area_rectangle = min_increasing_mbr_rectangles[0];
    for (Rectangle* rectangle : min_increasing_mbr_rectangles) {
      if (rectangle->area() < min_area_rectangle->area()) {
        min_area_rectangle = rectangle;
      }
    }
    Rectangle new_mbr = Rectangle::mbr(*min_area_rectangle, rectangle);
    min_area_rectangle = new Rectangle(min_area_rectangle->id, new_mbr.x1, new_mbr.y1, new_mbr.x2, new_mbr.y2);
    current_tree_node->writeToDisk(tree_directory);
    delete current_tree_node;
    current_tree_node = RTreeNode::readFromDisk(tree_directory, min_area_rectangle->id);
    delete min_area_rectangle;
  }

  current_tree_node->children.push_back(rectangle);
  bool has_leaf_children = true;
  while (current_tree_node->children.size() >= M) {
    std::vector<Rectangle> left_side;
    std::vector<Rectangle> right_side;
    split_method->split(current_tree_node->children, left_side, right_side);
    if (current_tree_node->id_parent == 0) { // root
      int id_left = current_tree_node->id;
      int id_right = ++total_node_count;
      int id_root = ++total_node_count;
      root_id = id_root;
      delete current_tree_node;
      current_tree_node = new RTreeNode(id_left, id_root, has_leaf_children, left_side);
      current_tree_node->writeToDisk(tree_directory);
      delete current_tree_node;
      current_tree_node = new RTreeNode(id_right, id_root, has_leaf_children, right_side);
      current_tree_node->fixChildren(tree_directory);
      current_tree_node->writeToDisk(tree_directory);
      delete current_tree_node;
      Rectangle left_mbr = Rectangle::mbr(left_side);
      left_mbr.id = id_left;
      Rectangle right_mbr = Rectangle::mbr(right_side);
      right_mbr.id = id_right;
      std::vector<Rectangle> root_children = {left_mbr, right_mbr};
      current_tree_node = new RTreeNode(id_root, 0, false, root_children);
      current_tree_node->writeToDisk(tree_directory);
    } else {
      int id_parent = current_tree_node->id_parent;
      int id_left = current_tree_node->id;
      int id_right = ++total_node_count;
      delete current_tree_node;
      current_tree_node = new RTreeNode(id_left, id_parent, has_leaf_children, left_side);
      current_tree_node->writeToDisk(tree_directory);
      delete current_tree_node;
      current_tree_node = new RTreeNode(id_right, id_parent, has_leaf_children, right_side);
      current_tree_node->fixChildren(tree_directory);
      current_tree_node->writeToDisk(tree_directory);
      delete current_tree_node;
      current_tree_node = RTreeNode::readFromDisk(tree_directory, id_parent);
      Rectangle right_mbr = Rectangle::mbr(right_side);
      right_mbr.id = id_right;
      current_tree_node->children.push_back(right_mbr);
      Rectangle left_mbr = Rectangle::mbr(left_side);
      left_mbr.id = id_left;
      current_tree_node->replaceChild(left_mbr);
      current_tree_node->writeToDisk(tree_directory);
    }
    has_leaf_children = false;
  }
  current_tree_node->writeToDisk(tree_directory);
  delete current_tree_node;
}


