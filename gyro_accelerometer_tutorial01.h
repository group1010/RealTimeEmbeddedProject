#ifndef GYRO_ACCELEROMETER_TUTORIAL01_H
#define GYRO_ACCELEROMETER_TUTORIAL01_H

#ifdef __cplusplus
extern "C" {
#endif


	float rate_gyr_y = 0.0;   // [deg/s]
	float rate_gyr_x = 0.0;    // [deg/s]
	float rate_gyr_z = 0.0;     // [deg/s]

	int  acc_raw[3];
	int  mag_raw[3];
	int  gyr_raw[3];

        float accXnorm,accYnorm,pitch,roll,magXcomp,magYcomp;

	float gyroXangle = 0.0;
	float gyroYangle = 0.0;
	float gyroZangle = 0.0;
	float AccYangle = 0.0;
	float AccXangle = 0.0;
	float CFangleX = 0.0;
	float CFangleY = 0.0;

        int startInt  = 10; // mymillis();
	struct  timeval tvBegin, tvEnd,tvDiff;

	signed int acc_y = 0;
	signed int acc_x = 0;
	signed int acc_z = 0;
	signed int gyr_x = 0;
	signed int gyr_y = 0;
	signed int gyr_z = 0;



/* Initialise the ADC
 *
 * Return: Pointer to led structure, or NULL
 */
  void initf();

/* Write a value to the leds */
  void readi2c();

#ifdef __cplusplus
}
#endif

#endif /* LEDOUT_H */
