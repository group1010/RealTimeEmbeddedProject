#include <stdio.h>
#include <stdlib.h>
#include "gyro_accelerometer_tutorial01.c"
#include "gpio-sysfs.cpp"

#include <QtCore>
#include <QtGui>
#include <QBoxLayout>
#include <QVBoxLayout>

#include "TestWin.h"

int a, b, c, aa, bb, cc;
int  warnroll = 24;
int  saferoll = 11;
int  warnpitch = 23;
int  safepitch = 17;



TestWin::TestWin(QWidget *parent) : QWidget(parent)
{

     // setup layout
     setupLayout();

     // initialise I2C
     initf();

     // initialise GPIO
     gpio_export(warnroll);
     gpio_export(saferoll);
     gpio_export(warnpitch);
     gpio_export(safepitch);
	    
     // sets GPIO direction to 'out'
     gpio_set_dir(warnroll, 1);
     gpio_set_dir(saferoll, 1);
     gpio_set_dir(warnpitch, 1);
     gpio_set_dir(safepitch, 1);
}


TestWin::~TestWin()
{

}

int TestWin::setupLayout(void)
{
     // Make initial data for plots
     for( int index=0; index<plotDataSize; ++index )
     {
         xData[index] = index;
         xData2[index] = index;
         yData[index] = 0;
	 yData2[index] = 0;
     } 
  
     // Make curves for pitch and roll
     curve.setSamples(xData, yData, plotDataSize);
     curve2.setSamples(xData2, yData2, plotDataSize);
     //curve.setPen();
     // Add curves to the plot
     curve.setPen(* new QPen(Qt::blue,2,Qt::SolidLine));
     curve2.setPen(* new QPen(Qt::blue,2,Qt::SolidLine));
     curve.attach(&plot);
     curve2.attach(&plot2);

     //Add grid to plots
     grid.attach(&plot);
     grid2.attach(&plot2);

     // Set y axis from -90 to 90
     plot.setAxisScale(0, -90, 90, 0);
     plot2.setAxisScale(0, -90, 90, 0);

     plot.setTitle("ROLL");
     plot2.setTitle("PITCH");

     // Make plots
     plot.replot();
     plot2.replot();
     plot.show();
     plot2.show();
	
     // Make ADI and Compass
     m_ADI      = new QADI(this);
     m_Compass  = new QCompass(this);

     // Make left panel
     QWidget *wLeftPanel = new QWidget(this);
     QVBoxLayout *vl = new QVBoxLayout(wLeftPanel);
     wLeftPanel->setLayout(vl);
     wLeftPanel->setFocusPolicy(Qt::NoFocus);

     vl->addWidget(m_ADI,      0, Qt::AlignTop|Qt::AlignHCenter);
     vl->addWidget(m_Compass,  0, Qt::AlignTop|Qt::AlignHCenter);
        
     vl->setMargin(0);
     vl->setSpacing(4);

     // Make right panel
     QWidget *wRightPanel = new QWidget(this);
     QVBoxLayout *vl2 = new QVBoxLayout(wRightPanel);
     wRightPanel->setLayout(vl2);

     vl2->addWidget(&plot, 0);
     vl2->addWidget(&plot2, 0);

     // Overall layout
     QHBoxLayout *hl = new QHBoxLayout(this);
     this->setLayout(hl);
     hl->addWidget(wLeftPanel, 0);
     hl->addWidget(wRightPanel, 0);

     return 0;
}


void TestWin::timerEvent( QTimerEvent * )
{
     // Read sensor reading
     readi2c(&a, &b, &c);    // a = roll; b = pitch; c = yaw

     double inVal = a-aa;
     double inVal2 = b-bb;
     double inVal3 = c-cc;
  
     // Update plots
     memmove( yData, yData+1, (plotDataSize-1) * sizeof(double) );
     yData[plotDataSize-1] = inVal;
     curve.setSamples(xData, yData, plotDataSize);
     plot.replot();

     memmove( yData2, yData2+1, (plotDataSize-1) * sizeof(double) );
     yData2[plotDataSize-1] = inVal2;
     curve2.setSamples(xData2, yData2, plotDataSize);
     plot2.replot();

     // Update ADI and Compass
     m_ADI->setData(inVal, inVal2);
     m_Compass->setYaw(inVal3);


     //GPIO
     // switches on the sysfs entry for pin numbers 11, 17, 23, 24

     //Roll
     if(inVal>20 || inVal<-20)
	{
	  gpio_set_value(warnroll,1);
	  gpio_set_value(saferoll,0);
	}
     else
	{
	  //LED Off
	  gpio_set_value(warnroll,0);
	  gpio_set_value(saferoll,1);
	}

     //Pitch
     if(inVal2>20 || inVal2<-20)
	{
	  gpio_set_value(warnpitch,1);
	  gpio_set_value(safepitch,0);
	}
     else
	{
	  //LED Off
	  gpio_set_value(warnpitch,0);
	  gpio_set_value(safepitch,1);
	}
}


void TestWin::keyPressEvent(QKeyEvent *event)
{
  int key;
  key = event->key();  
  if( key == Qt::Key_Up ) {
    change(&a, &b, &c, &aa, &bb, &cc);
  } else if( key == Qt::Key_Q ) {
    exit(1);
  } 

}
