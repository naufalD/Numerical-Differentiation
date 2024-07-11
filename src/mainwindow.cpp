#include "include/mainwindow.h"
#include "include/differentiate.h"

#include <QwtLegend>
#include <QwtPlotGrid>
#include <QLayout>
#include <cmath>

double theFunction(double x){
    return (3*pow(x, 3)-pow(x, 2))*sin(100000*x);
}

Plot::Plot(QWidget *parent) : QwtPlot(parent)
{
    setTitle( "Differentiation" );
    setCanvasBackground( Qt::white );
    setMinimumSize(300,300);
    insertLegend(new QwtLegend);
    QwtPlotGrid* grid = new QwtPlotGrid();
    grid->attach( this );

    m_curve1 = new QwtPlotCurve();
    m_curve1->setPen(Qt::red, 1);
    m_curve1->setCurveAttribute(QwtPlotCurve::Fitted, true);
    m_curve1->attach(this);

    m_curve2 = new QwtPlotCurve();
    m_curve2->setPen(Qt::blue, 1);
    m_curve2->setCurveAttribute(QwtPlotCurve::Fitted, true);
    m_curve2->attach(this);

    m_curve3 = new QwtPlotCurve();
    m_curve3->setPen(Qt::green, 1);
    m_curve3->setCurveAttribute(QwtPlotCurve::Fitted, true);
    m_curve3->attach(this);
}

void Plot::updateCurve(double x, double y1, double y2, double y3){
    m_points1<<QPointF(x, y1);
    m_curve1->setSamples(m_points1);

    m_points2<<QPointF(x, y2);
    m_curve2->setSamples(m_points2);

    m_points3<<QPointF(x, y3);
    m_curve3->setSamples(m_points3);
    replot();
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    Plot *thePlot = new Plot();
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(thePlot);

    for (double i {0}; i<10;i+=0.1){
        thePlot->updateCurve(i, differentiateFD(i, &theFunction), differentiateCD(i, &theFunction), differentiateExtrap(i, &theFunction));
    }

}
