from setuptools import setup
import os
from glob import glob

package_name = 'py_tf'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # ✅ 安装 launch 文件
        ('share/' + package_name + '/launch',
            glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='you',
    maintainer_email='you@example.com',
    description='Python TF demo',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'py_tf_broadcaster = py_tf.py_tf_pub:main',
            'py_tf_listener = py_tf.py_tf_listener:main',
        ],
    },
)
