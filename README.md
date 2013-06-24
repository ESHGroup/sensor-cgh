sensor-cgh
==========

OpenNI Sensor-Driven Computer Generated Hologram (CGH) Engine

Last Modified: June 14, 2013
 
ESH Group:

	Gil Gallegos PhD
	Miguel Maestas B.S.
	Richard McIntosh
	Jared Leyba
	Jesus Angulo
	
Introduction:
******************************************************************************


Build Instructions:
******************************************************************************

Dependencies:
	
	* Cmake >= 2.6	
	* OpenNI - unstable <= 1.5.4 (NOTE: requires Avin2 driver and patches if 
	  working with the XBOX 360 Kinect sensor)
	* pthread
	* X11
	* CImg


NOTE: successfully compiled using g++ version 4.7.2

Steps:

	1.) clone repository: $ git clone https://github.com/ESHGroup/sensor-cgh.git

	2.) cd sensor-cgh

	3.) $ cmake src

	4.) $ ./sensor-cgh



