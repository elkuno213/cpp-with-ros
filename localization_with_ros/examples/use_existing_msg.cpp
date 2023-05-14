#include <sensor_msgs/LaserScan.h>

#include <iostream>

int main() {
  sensor_msgs::LaserScan scan;
  for (int i = 0; i < 100; i++) {
    scan.ranges.push_back(42.0 * i);
  }

  for (const auto& range : scan.ranges) {
    std::cout << range << std::endl;
  }
}
