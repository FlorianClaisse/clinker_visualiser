//
// Created by Florian Claisse on 28/06/2023.
//

#ifndef CLINKER_VISUALISER_MENUWIDGET_HPP
#define CLINKER_VISUALISER_MENUWIDGET_HPP

#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include <QScrollArea>

class MenuWidget: public QWidget {

private:
    QScrollArea *m_scrollArea;
    QWidget *m_scrollContent;

public:
    explicit MenuWidget(QWidget *parent = nullptr);

private:
    void addPlotArrangement(QVBoxLayout *layout);
    void addClusterSettings(QVBoxLayout *layout);
    void addGenearrows(QVBoxLayout *layout);
    void addGeneLabels(QVBoxLayout *layout);
    void addScaleBar(QVBoxLayout *layout);
    void addColorBar(QVBoxLayout *layout);
    void addLegend(QVBoxLayout *layout);
    void addLinks(QVBoxLayout *layout);

    void addSpinbox(const QString &label, QVBoxLayout *layout);
    void addCheckBox(const QString &label, QVBoxLayout *layout);
};


#endif //CLINKER_VISUALISER_MENUWIDGET_HPP
