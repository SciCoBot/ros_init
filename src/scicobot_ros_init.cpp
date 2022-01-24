/***********************************************************************************
 *  @file       scicobot_ros_init.cpp
 *  Project     scicobot_hardware
 *  @brief      *****
 *
 *  @author     Otávio Augusto Rocha da Cruz
 *  @bug 		 No known bugs.
 *  License     MIT
 *
 *  @section License
 *
 * Copyright (c) 2021 SciCoBot
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**********************************************************************************/
#include "scicobot_ros_init.h"
#include <led_debug.h>

void ScicobotRos::init()
{
	set_microros_transports();

	delay(2000);
	
	allocator = rcl_get_default_allocator();	

	DEBUG_ERROR_MICR0_ROS(rclc_support_init(&support, 0, NULL, &allocator));
	
	DEBUG_ERROR_MICR0_ROS(rclc_node_init_default(&scicobot_arduino, "scicobot_arduino", "", &support));

	#if SCICOBOT_ROS_INIT_DEBUG == 1 
		debugObj.DEBUGLN("initMicroRos() sucess...");  
	#endif
}

rclc_support_t* ScicobotRos::get_rclc_support()
{
	return &support;
}

rcl_allocator_t* ScicobotRos::get_rcl_allocator()
{
	return &allocator;
}

rcl_node_t* ScicobotRos::get_rcl_node()
{
	return &scicobot_arduino;
}
