# planning AirSim
`*` Control drone by code Position + Yaw <br>
`*` Avoid obstacles by code Ewok <br>

## Installation
```
git@github.com:AnhDuy207/planning.git
```

## Getting started
1. Open UE4 then my project, button "Play"
```
cd ~/IVSR/UnrealEngine/
./Engine/Binaries/Linux/UE4Editor
```
2. Initialize ports for PX4  
```
cd px4/Firmware/ 
make px4_sitl_default none_iris 
```
3. Connect AirSim with PX4 by Mavros
```
roslaunch mavros px4.launch fcu_url:=udp://:14550@localhost:14570
```
4. Run Ros Wrapper AirSim
```
roslaunch airsim_ros_pkgs airsim_node.launch
```
5. Run code Ewok create map
```
roslaunch ewok_optimization optimization_point.launch 
```
6. Run the offboard_position_yaw_control
```
roslaunch offboard planner.launch simulation:=true 
```
