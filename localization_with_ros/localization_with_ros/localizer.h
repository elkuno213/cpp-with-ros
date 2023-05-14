#ifndef LOCALIZER_H
#define LOCALIZER_H

#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/LaserScan.h>

class Localizer {
public:
  Localizer();
  void addIMU(const sensor_msgs::Imu& imu);
  void addOdometry(const nav_msgs::Odometry& odometry);
  void addLaserScan(const sensor_msgs::LaserScan& laserScan);

private:
  // Your implementation details
  sensor_msgs::Imu fImu;
  nav_msgs::Odometry fOdometry;
  sensor_msgs::LaserScan fLaserScan;
};

#endif  // LOCALIZER_H
