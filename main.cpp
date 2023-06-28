#include "source/Views/include/MainWindow.hpp"

#include <QApplication>
#include <QWidget>
#include <QLocale>
#include <QTranslator>
#include <QVBoxLayout>
#include "source/Views/include/MenuWidget.hpp"

#include "source/Views/include/ArrowWidget.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "clinker_visualiser_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;

    MenuWidget *menuWidget = new MenuWidget(&w);
    w.setCentralWidget(menuWidget);

    /*QWidget *centralWidget = new QWidget(&w);
    w.setCentralWidget(centralWidget);

    // Création de la disposition verticale
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Création du widget de flèches
    auto arrowWidget_ = new ArrowWidget(centralWidget);
    layout->addWidget(arrowWidget_);

    std::vector<Arrow> arrows;
    arrows.push_back({20, 50, 150, 50});


    arrowWidget_->setArrows(arrows);*/



    w.show();
    return a.exec();
}
