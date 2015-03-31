#ifndef __TEST_WIN_H__
#define __TEST_WIN_H__

#include <QtCore>
#include <QtGui>
#include <QTextEdit>

#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_grid.h>
#include "qFlightInstruments.h"
#include <QBoxLayout>

class TestWin : public QWidget
{
public:
    TestWin(QWidget *parent = NULL);
    virtual ~TestWin();
    virtual int setupLayout(void);

    void timerEvent( QTimerEvent * );


protected:
    QADI                *m_ADI;
    QCompass            *m_Compass;
    QKeyValueListView   *m_infoList;

    QwtPlot             plot;
    QwtPlot             plot2;
    QwtPlotCurve        curve;
    QwtPlotCurve        curve2;
    QwtPlotGrid         grid;
    QwtPlotGrid         grid2;
 
    static const int plotDataSize = 100;
    double xData[plotDataSize];
    double xData2[plotDataSize];
    double yData[plotDataSize];
    double yData2[plotDataSize];

    void keyPressEvent(QKeyEvent *event);
       
 };

#endif // end of __TeST_WIN_H__
