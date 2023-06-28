//
// Created by Florian Claisse on 28/06/2023.
//

#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>

#include "include/MenuWidget.hpp"

MenuWidget::MenuWidget(QWidget *parent): QWidget(parent) {
    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);

    m_scrollContent = new QWidget(m_scrollArea);
    auto scrollLayout = new QVBoxLayout(m_scrollContent);

    addPlotArrangement(scrollLayout);
    addClusterSettings(scrollLayout);

    m_scrollArea->setWidget(m_scrollContent);
}

void MenuWidget::addPlotArrangement(QVBoxLayout *layout) {
    auto *title = new QLabel("Plot arrangement", m_scrollContent);
    title->setStyleSheet("font-size: 14px; font-weight: bold;");

    layout->addWidget(title);

    addSpinbox("Scale factor", layout);
    addSpinbox("Vertical spacing", layout);
    addCheckBox("Show genes to scale", layout);
}

void MenuWidget::addClusterSettings(QVBoxLayout *layout) {
    auto *title = new QLabel("Cluster settings", m_scrollContent);
    title->setStyleSheet("font-size: 16px; font-weight: bold;");

    layout->addWidget(title);

    addCheckBox("Align labels", layout);
    addCheckBox("Hide locus coordinates", layout);
    addSpinbox("Inter-locus spacing", layout);
    addSpinbox("Cluster name font size", layout);
    addSpinbox("Locus name font size", layout);
}

void MenuWidget::addSpinbox(const QString &label, QVBoxLayout *layout) {
    auto *sectionContent = new QWidget(this);
    auto *sectionLayout = new QHBoxLayout(sectionContent);
    sectionLayout->setContentsMargins(10, 0, 5, 0);

    auto *qlabel = new QLabel(label, sectionContent);
    sectionLayout->addWidget(qlabel);

    auto *button = new QSpinBox(sectionContent);
    button->setMinimum(0);
    sectionLayout->addWidget(button, 0, Qt::AlignRight);

    layout->addWidget(sectionContent);
}

void MenuWidget::addCheckBox(const QString &label, QVBoxLayout *layout) {
    auto *sectionContent = new QWidget(this);
    auto *sectionLayout = new QHBoxLayout(sectionContent);
    sectionLayout->setContentsMargins(10, 0, 5, 0);

    auto *qlabel = new QLabel(label, sectionContent);
    sectionLayout->addWidget(qlabel);

    auto *button = new QCheckBox(sectionContent);
    sectionLayout->addWidget(button, 0, Qt::AlignRight);

    layout->addWidget(sectionContent);
}

/*void MenuWidget::addSection(const QString &title, QVBoxLayout *layout) {

    auto *titleLabel = new QLabel(title, m_scrollContent);
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    layout->addWidget(titleLabel);

    for (int i = 0; i < 3; i++) {
        auto *sectionContent = new QWidget(this);
        auto *sectionLayout = new QHBoxLayout(sectionContent);

        auto *label = new QLabel(QString("Label %1-%2").arg(title).arg(i + 1), sectionContent);
        sectionLayout->addWidget(label);

        sectionLayout->addStretch();

        auto *button = new QPushButton(QString("Button %1-%2").arg(title).arg(i + 1), sectionContent);
        sectionLayout->addWidget(button, 0, Qt::AlignRight);

        layout->addWidget(sectionContent);
    }
}*/
