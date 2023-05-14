#include <actionlib/server/simple_action_server.h>
#include <localization_with_ros/DoDishesAction.h>

#include <iostream>

using Server = actionlib::SimpleActionServer<localization_with_ros::DoDishesAction>;

void execute(const localization_with_ros::DoDishesGoalConstPtr& goal, Server* as) {
  // Do lots of awesome groundbreaking robot stuff here
  std::cout << goal.owner_hash_value() << std::endl;
  as->setSucceeded();
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "do_dishes_server");
  ros::NodeHandle n;
  Server server(n, "do_dishes", boost::bind(&execute, _1, &server), false);
  server.start();
  ros::spin();
  return 0;
}
