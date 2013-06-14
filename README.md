sensor-cgh
==========

OpenNI Sensor-Driven Computer Generated Hologram (CGH) Engine

Last Modified: June 13, 2013

sense-cgh version 0.0.97 README
 
ESH Group:

	Gil Gallegos PhD
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
	* pthread
	* X11
	* CImg


NOTE: successfully compiled using g++ version 4.7.2

Steps:

	1.) clone repository: $ git clone https://github.com/ESHGroup/sensor-cgh.git

	2.) cd sensor-cgh/Debug

	3.) $ make all

	4.) $ ./sensor-cgh -c CONFIG -n MAX_FRAMES -o OBJ_FILE
		
		* CONFIG -> OpenNI config file listing Sensor's capbilities.
		* MAX_FRAMES -> Maximum amount of depth frames to capture from Sensor.
		* OBJ_FILE -> File to write contents of depth frames to.


Todo:

	Wow, just about everything this early in the project:
	
	* Refactor Classes so logic isn't in Constructor -> DepthCapture.cpp is just rediculous
	 
	* Provide a robust logging mechanism
	 
	* Get rid of all those ugly hard-coded values HoloFilm.cpp and provide dynamic Holofilm 
	  scaling
	* Much more! Please e-mail one of the members on the team if you would like to contribute
	  to our effor or need help building the binaries.

