#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QApplication *app, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QApplication *m_app;

    QWidget *m_currentWidget = Q_NULLPTR;

    QMap<QPushButton*, QWidget*> m_pagesMap;

private slots:
    void openPage();
    void returnToMainMenu();
};

#endif // MAINWINDOW_H
