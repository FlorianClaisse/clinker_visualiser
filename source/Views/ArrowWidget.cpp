//
// Created by Florian Claisse on 27/06/2023.
//

#include <QPainter>

#include "include/ArrowWidget.hpp"

ArrowWidget::ArrowWidget(QWidget *parent): QWidget(parent) { }

void ArrowWidget::setArrows(const std::vector<Arrow> &arrows) {
    m_arrows = arrows;
    update();
}

void ArrowWidget::updateArrow(int index, const Arrow &newArrow) {
    if (index >= 0 && index < m_arrows.size()) {
        m_arrows[index] = newArrow;
        update();
    }
}

void ArrowWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (const auto &arrow: m_arrows)
        draw(painter, arrow);
}

void ArrowWidget::draw(QPainter &painter, const Arrow &arrow) {
    const double arrowSize = 10.0;
    const double bodyWidth = 10.0;

    QPolygonF bodyPolygon;
    bodyPolygon << QPointF(arrow.startX, arrow.startY - (bodyWidth / 2));
    bodyPolygon << QPointF(arrow.endX - arrowSize, arrow.startY - (bodyWidth / 2));
    bodyPolygon << QPointF(arrow.endX - arrowSize, arrow.startY - (bodyWidth / 2) - (arrowSize / 2));
    bodyPolygon << QPointF(arrow.endX, arrow.endY);
    bodyPolygon << QPointF(arrow.endX - arrowSize, arrow.startY + (bodyWidth / 2) + (arrowSize / 2));
    bodyPolygon << QPointF(arrow.endX - arrowSize, arrow.startY + (bodyWidth / 2));
    bodyPolygon << QPointF(arrow.startX, arrow.startY + (bodyWidth / 2));

    painter.setBrush(Qt::blue);
    painter.drawPolygon(bodyPolygon);
}
