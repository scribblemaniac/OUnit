#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "TemporalFrequencyWidget.h"
#include "TemperatureWidget.h"
#include "InductanceWidget.h"

MainWindow::MainWindow(QApplication *app, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_app(app)
{
    ui->setupUi(this);

    ui->mainMenuButton->hide();

    QWidget *page;
    page = new TemporalFrequencyWidget(m_app, this);
    page->hide();
    m_pagesMap.insert(ui->temporalFrequencyButton, page);
    connect(ui->temporalFrequencyButton, &QPushButton::clicked, this, &MainWindow::openPage);
    page = new TemperatureWidget(m_app, this);
    page->hide();
    m_pagesMap.insert(ui->temperatureButton, page);
    connect(ui->temperatureButton, &QPushButton::clicked, this, &MainWindow::openPage);
    page = new InductanceWidget(m_app, this);
    page->hide();
    m_pagesMap.insert(ui->inductanceButton, page);
    connect(ui->inductanceButton, &QPushButton::clicked, this, &MainWindow::openPage);

    connect(ui->mainMenuButton, &QPushButton::clicked, this, &MainWindow::returnToMainMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openPage()
{
    if(m_currentWidget != Q_NULLPTR) {
        returnToMainMenu();
    }

    m_currentWidget = m_pagesMap.value(qobject_cast<QPushButton*>(sender()), Q_NULLPTR);

    if(m_currentWidget == Q_NULLPTR) return;

    ui->title->hide();
    ui->scrollArea->hide();
    ui->mainMenuButton->show();
    ui->centralWidget->layout()->addWidget(m_currentWidget);
    m_currentWidget->show();
}

void MainWindow::returnToMainMenu()
{
    if(m_currentWidget != Q_NULLPTR) {
        m_currentWidget->hide();
        ui->centralWidget->layout()->removeWidget(m_currentWidget);
        ui->mainMenuButton->hide();
        ui->title->show();
        ui->scrollArea->show();
        m_currentWidget = Q_NULLPTR;
    }
}
