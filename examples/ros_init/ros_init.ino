#include <scicobot_hardware.h>

ScicobotRos microRos;

void setup() 
{
  Serial.begin(9600);
  microRos.init();
  
  microRos.get_rclc_support();
  microRos.get_rcl_allocator();
  microRos.get_rcl_node();
}

void loop() 
{

}
