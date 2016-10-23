#include <queue>
#include <vector>

#include "rtree.h"

void RTree::setRootId(int id) {
  root_id = id;
}

std::vector<int> RTree::find(const Rectangle& other_rectangle) {
  std::queue<int> q;
  std::vector<int> results;
  q.push(root_id);
  while (!q.empty()) {
    int next_node = q.front();
    q.pop();
    current_tree_node = RTreeNode::readFromDisk(next_node);
    for (const Rectangle& rectangle : current_tree_node->children) {
      if (other_rectangle.intersects(rectangle)) {
        if (current_tree_node->has_leaf_children) {
          results.push_back(rectangle.id);
        } else {
          q.push(rectangle.id);
        }
      }
    }
    delete current_tree_node;
  }
  return results;
}

