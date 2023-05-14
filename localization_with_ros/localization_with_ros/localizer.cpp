#include "localization_with_ros/localizer.h"

Localizer::Localizer() {}

void Localizer::addIMU(const sensor_msgs::Imu& imu) {
  fImu = imu;
}

void Localizer::addOdometry(const nav_msgs::Odometry& odometry) {
  fOdometry = odometry;
}

void Localizer::addLaserScan(const sensor_msgs::LaserScan& laserScan) {
  fLaserScan = laserScan;
}
