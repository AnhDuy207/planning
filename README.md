# planning
`*` Control drone by code Position + Yaw <br>
`*` Avoid obstacles by code Ewok <br>

## Installation
```
git@github.com:AnhDuy207/planning.git
```

## Getting started
1. Connect my local computer with Jetson nano
```
ssh planning@192.168.*.*
```
2. Launch a quadrotor with px4 and mavros in gazebo 
```
roslaunch mavros px4.launch fcu_url:="/dev/ttyTHS1:921600" 
```
3. Open camera D435
```
roslaunch realsense2_camera rs_camera.launch depth_width:=640 depth_height:=480 depth_fps:=15
```
4. Transform frame "map" & frame "world"
```
roslaunch ewok_ring_buffer statictransform.launch
```
5. Convert encoding of topic camera from 16UC1 to 32FC1 
```
cd DuyNam_ws/src
python visualize_data.py
```
6. Run code Ewok create map
```
roslaunch ewok_optimization optimization_point.launch 
```
7. Run the offboard_position_yaw_control
```
roslaunch offboard planner.launch simulation:=true 
```
8. Record file bag
```
rosbag record -O subset_12052022 /camera/color/image_raw /camera/depth/image_rect_raw /depth_topic_2 /mavros/local_position/pose /mavros/imu/data /mavros/local_position/odom /ring_buffer/distance /ring_buffer/free /ring_buffer/free_array /ring_buffer/occupied
```
