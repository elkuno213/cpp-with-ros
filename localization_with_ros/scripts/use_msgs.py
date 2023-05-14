#!/usr/bin/env python

from sensor_msgs.msg import LaserScan
from localization_with_ros.msg import Foo

f = Foo(42)
print(f.foo)

s = LaserScan()
