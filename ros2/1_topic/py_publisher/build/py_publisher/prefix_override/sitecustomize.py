import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/wudad10/Fold1/ros2/1_topic/py_publisher/install/py_publisher'
