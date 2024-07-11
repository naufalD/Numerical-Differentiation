#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QwtPlot>
#include <QwtPlotCurve>


class Plot : public QwtPlot
{
public:
    Plot(QWidget *parent = nullptr);
    void updateCurve(double x, double y1, double y2, double y3);
private:
    QPolygonF m_points1;
    QwtPlotCurve *m_curve1;
    QPolygonF m_points2;
    QwtPlotCurve *m_curve2;
    QPolygonF m_points3;
    QwtPlotCurve *m_curve3;
};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
};
#endif // WIDGET_H
