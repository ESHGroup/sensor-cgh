sensor-cgh
==========

Sensor-Driven Computer Generated Hologram Generator

Last Modified: June 13, 2013

sense-cgh version 0.0.97 README:
 
ESH Group:

	Gil Gallegos
	Miguel Maesta
	Richard McIntosh
	Jared Leyba
	
Introduction:
******************************************************************************


Build Instructions:
******************************************************************************

Dependencies:
	
	* OpenNI - unstable <= 1.5.4 (NOTE: requires Avin2 driver and patches if 
	  working with the XBOX 360 Kinect sensor)
	
	TODO: What's min/max versions of these ???

	* pthread
	* X11
	* CImg


NOTE: successfully compiled using g++ version 4.7.2

Steps:

	1.) clone repository: $ git clone https://github.com/ESHGroup/sensor-cgh.git

	2.) cd ${SENSOR_CGH_HOME}/Debug

	3.) $ make all

	4.) $ ./sensor-cgh


