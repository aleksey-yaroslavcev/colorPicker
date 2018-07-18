#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QClipboard>
#include <QColorDialog>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewColorSelected(QColor color)
{
    int i = _colors.size();
    QPushButton* button = new QPushButton(this);
    _buttons.push_back(button);
    _colors.push_back(color);
    button->setStyleSheet(QString("QPushButton { \
                                    background-color: %1; \
                                   } \
                                   QPushButton:pressed { \
                                    background-color: white; \
                                   }").arg(color.name()));
    button->setText(color.name());
    ui->vertLayout->addWidget(_buttons.back());
    connect(button, &QPushButton::clicked, [ = ]() {
        QGuiApplication::clipboard()->setText(_colors.at(i).name());
    });
}

void MainWindow::on_actionAddColor_triggered()
{
    onNewColorSelected(QColorDialog::getColor(Qt::green, this, tr("Select Color")));
}

void MainWindow::on_actionRemoveLastColor_triggered()
{
    if (_buttons.isEmpty())
        return;

    delete _buttons.back();
    _buttons.pop_back();
    _colors.pop_back();
}
