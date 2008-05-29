/*
  OrangutanMotors.h - Library for using the motor drivers on the
      Orangutan LV-168 and Baby Orangutan B-48/B-168
  Written by Ben Schmidel, May 15, 2008.
  http://www.pololu.com
  http://forum.pololu.com
  Released into the public domain.
  
  Disclaimer: To the extent permitted by law, Pololu Corporation provides
  this work without any warranty.  It may be defective, in which case you
  agree to be responsible for all resulting costs and damages.
*/
#ifndef OrangutanMotors_h
#define OrangutanMotors_h


class OrangutanMotors
{
  public:

    // constructor (doesn't do anything)
	OrangutanMotors();

	// sets the motor speed.  The sign of 'speed' determines the direction
	// and the magnitude determines the speed.  limits: -255 <= speed < 255
	// |speed| = 255 produces the maximum speed while speed = 0 is full brake.
	static void setM1Speed(int speed);
	static void setM2Speed(int speed);
	static void setSpeeds(int m1Speed, int m2Speed);


  private:

	static inline void init()
	{
		static unsigned char initialized = 0;

		if (!initialized)
		{
			initialized = 1;	// this MUST be set before init2() is called
			init2();			// or else infinite recursion ensues
		}
	}
  	
	// initializes timers 0 and 2 for proper PWM generation
	static void init2();
};

#endif

// Local Variables: **
// mode: C++ **
// c-basic-offset: 4 **
// tab-width: 4 **
// indent-tabs-mode: t **
// end: **
