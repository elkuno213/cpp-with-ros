#include <localization_with_ros/Bar.h>
#include <localization_with_ros/Foo.h>

#include <iostream>

int main() {
  localization_with_ros::Foo foo;
  foo.foo = 42;
  std::cout << foo.foo << std::endl;

  localization_with_ros::Bar bar;
}
