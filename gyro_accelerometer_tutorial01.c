/*
	This program  reads the angles from the acceleromter and gyrscope
	on a BerryIMU connected to a Raspberry Pi.
	http://ozzmaker.com/
    Copyright (C) 2014  Mark Williams
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    Library General Public License for more details.
    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
    MA 02111-1307, USA
*/


#include <gyro_accelerometer_tutorial01.h>
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>
#include "sensor.c"


#define DT 0.02         // [s/loop] loop period. 20ms
#define AA 0.97         // complementary filter constant

#define A_GAIN 0.0573      // [deg/LSB]
#define G_GAIN 0.070     // [deg/s/LSB]
#define RAD_TO_DEG 57.29578
#define M_PI 3.14159265358979323846




void  INThandler(int sig)
{
        signal(sig, SIG_IGN);
        exit(0);
}

int mymillis()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec) * 1000 + (tv.tv_usec)/1000;
}

int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
        long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
	result->tv_sec = diff / 1000000;
	result->tv_usec = diff % 1000000;
	return (diff<0);
}

void initf()
{
        signal(SIGINT, INThandler);
	enableIMU();
	gettimeofday(&tvBegin, NULL);
}


void readi2c(int* a, int* b, int* c)
{
       	startInt = mymillis();

	//read ACC GYR adn MAG data
	readACC(acc_raw);
	readGYR(gyr_raw);
	readMAG(mag_raw);

	//Convert Gyro raw to degrees per second
	rate_gyr_x = (float) gyr_raw[0] * G_GAIN;
	rate_gyr_y = (float) gyr_raw[1] * G_GAIN;
	rate_gyr_z = (float) gyr_raw[2] * G_GAIN;

	//Calculate the angles from the gyro
	gyroXangle+=rate_gyr_x*DT;
	gyroYangle+=rate_gyr_y*DT;
	gyroZangle+=rate_gyr_z*DT;

	//Convert Accelerometer values to degrees
	AccXangle = (float) (atan2(acc_raw[1],acc_raw[2])+M_PI)*RAD_TO_DEG;
	AccYangle = (float) (atan2(acc_raw[2],acc_raw[0])+M_PI)*RAD_TO_DEG;

        //If IMU is up the correct way, use these lines
        AccXangle -= (float)180.0;
	if (AccYangle > 90)
	        AccYangle -= (float)270;
	else
		AccYangle += (float)90;

	//Complementary filter used to combine the accelerometer and gyro values.
	CFangleX=AA*(CFangleX+rate_gyr_x*DT) +(1 - AA) * AccXangle;
	CFangleY=AA*(CFangleY+rate_gyr_y*DT) +(1 - AA) * AccYangle;

	//////////////////
	accXnorm = acc_raw[0]/sqrt(acc_raw[0]* acc_raw[0]+ acc_raw[1] * acc_raw[1] + acc_raw[2] * acc_raw[2]);
        accYnorm =acc_raw[1]/sqrt(acc_raw[0] *acc_raw[0] + acc_raw[1] * acc_raw[1] + acc_raw[2] * acc_raw[2]);

	pitch = asin(accXnorm);
	roll = -asin(accYnorm/cos(pitch));

	magXcomp = mag_raw[0]*cos(pitch)+mag_raw[02]*sin(pitch);
	magYcomp = mag_raw[0]*sin(roll)*sin(pitch)+mag_raw[1]*cos(roll)-mag_raw[2]*sin(roll)*cos(pitch);

	//Calculate heading
	float heading = 180*atan2(magYcomp,magXcomp)/M_PI;
        //Convert heading to 0 - 360
	if(heading < 0)
	      heading += 360;

	*a = CFangleX;    // Pitch
	*b = CFangleY;    // Roll
	*c = heading;     // Yaw
	/////////////
}

void change(int* a, int* b, int* c, int* aa, int* bb, int* cc)
{

  *aa=*a;
  *bb=*b;
  *cc=*c;
}
