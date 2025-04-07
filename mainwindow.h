#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //----------HOME PAGE---------
    void on_playAsGuestButton_clicked();
    void on_exitButton_clicked();
    void on_loginButton_clicked();

    //----------ACCOUNTS PAGE-------
    void on_loginAccountsButton_clicked();
    void on_createAccountAccountsButton_clicked();
    void on_returnAccountsButton_clicked();

    //----------CREATE ACCOUNT PAGE-------
    void on_createAccountCreateAccountButton_clicked();
    void on_returnUpsertAccountButton_clicked();

    //----------GAME PAGE----------
    void on_cancelGameButton_clicked();
    void on_resetGameButton_clicked();
    void on_solutionGameButton_clicked();
    void on_stepGameButton_clicked();
    void on_hintGameButton_clicked();
    void on_infoGameButton_clicked();
    void on_pushButton_clicked(); // zatrzymaj grę

    //----------PLAYER PAGE----------
    void on_playAsPlayerButton_clicked();
    void on_showScoresButton_clicked();
    void on_retrunButton_clicked();

    //----------ADMIN PAGE----------
    void on_playAdminButton_clicked();
    void on_showScoresAdminButton_clicked();
    void on_showAccountsAdminButton_clicked();
    void on_returnAdminButton_clicked();

    //----------MANAGE ACCOUNTS PAGE----------
    void on_editManageAccountsButton_clicked();
    void on_deleteManageAccountsButton_clicked();
    void on_returnManageAccountsButton_clicked();

    //----------UPDATE ACCOUNT PAGE----------
    void on_createAccountUpdateAccountButton_clicked();
    void on_returnUpdateAccountButton_clicked();

    //----------DIFFICULTY PAGE----------
    void on_easyDifficultyButton_clicked();
    void on_normalDifficultyButton_clicked();
    void on_hardDifficultyButton_clicked();
    void on_customDifficultyButton_clicked();
    void on_returnDifficultyButton_clicked();

private:
    Ui::MainWindow *ui;

    void refreshAccountsTable();
};
#endif // MAINWINDOW_H
