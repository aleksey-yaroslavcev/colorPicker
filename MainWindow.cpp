#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QClipboard>

#include "NewColorDialog.h"

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
    QPalette pal = button->palette();
    pal.setColor(QPalette::Button, color);
    button->setAutoFillBackground(true);
    button->setPalette(pal);
    button->update();
    button->setText(color.name());
    ui->vertLayout->addWidget(_buttons.back());
    connect(button, &QPushButton::clicked, [ = ]() {
        QGuiApplication::clipboard()->setText(_colors.at(i).name());
    });
}

void MainWindow::on_actionAddColor_triggered()
{
    auto dlg = new NewColorDialog(this);
    connect(dlg, &NewColorDialog::newColorSelected, this, &MainWindow::onNewColorSelected);
    dlg->show();
}

void MainWindow::on_actionRemoveLastColor_triggered()
{
    if (_buttons.isEmpty())
        return;

    delete _buttons.back();
    _buttons.pop_back();
    _colors.pop_back();
}
