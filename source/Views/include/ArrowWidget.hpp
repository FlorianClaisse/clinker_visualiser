//
// Created by Florian Claisse on 27/06/2023.
//

#ifndef CLINKER_VISUALISER_ARROWWIDGET_HPP
#define CLINKER_VISUALISER_ARROWWIDGET_HPP

#include <QWidget>

#include "../../Models/include/Arrow.hpp"

class ArrowWidget: public QWidget {

private:
    std::vector<Arrow> m_arrows;

public:
    explicit ArrowWidget(QWidget *parent = nullptr);

public:
    void setArrows(const std::vector<Arrow> &arrows);
    void updateArrow(int index, const Arrow &newArrow);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    static void draw(QPainter &painter, const Arrow &arrow);
};


#endif //CLINKER_VISUALISER_ARROWWIDGET_HPP
