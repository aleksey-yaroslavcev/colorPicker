#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QClipboard>
#include <QColorDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QTextStream>
#include <QString>
#include <QSettings>

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
    bool ok;
    QString butName = QInputDialog::getText(this, tr("New color"), tr("Color name:"), QLineEdit::Normal,
                                            color.name() + " | ", &ok);
    if (!ok)
        return;
    onNewColorSelected(color, butName);
}

void MainWindow::onNewColorSelected(QColor color, const QString& name)
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
    button->setText(name);
    ui->formLayout->addRow(QString::number(i), _buttons.back());
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

    ui->formLayout->removeRow(ui->formLayout->rowCount() - 1);
}

void MainWindow::on_actionSaveToFile_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty()) {
        QSettings file(fileName, QSettings::IniFormat);
        for (int i = 0; i < _colors.size(); i++) {
            file.setValue(QString("color%1").arg(i), _colors.at(i));
            file.setValue(QString("color%1-Name").arg(i), _buttons.at(i)->text());
        }
    }
}

void MainWindow::on_actionLoadFromFile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) {
        QSettings file(fileName, QSettings::IniFormat);
        int i = 0;
        while (file.value(QString("color%1").arg(i)).isValid()) {
            onNewColorSelected(QColor(file.value(QString("color%1").arg(i)).toString()),
                               file.value(QString("color%1-Name").arg(i)).toString());
            i++;
        }
    }
}
