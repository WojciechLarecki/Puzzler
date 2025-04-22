#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include "Models/Entities/user.h"

#include <QPushButton>

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

    int boardSize; /**< Rozmiar planszy gry (np. 3x3, 4x4). */
    QVector<QVector<QPushButton*>> gameButtons; /**< Wektor przycisków odpowiadających za kafelki na planszy. */
    int emptyRow, emptyCol; /**< Indeksy pustego kafelka na planszy. */

    /**
     * @brief Inicjalizuje planszę gry.
     *
     * Ustala rozmiar planszy oraz ustawia odpowiednią liczbę przycisków w układzie.
     *
     * @param size Rozmiar planszy.
     */
    void initializeGameBoard(int size);

    /**
     * @brief Czyści aktualną planszę gry.
     *
     * Usuwa wszystkie elementy na planszy i resetuje jej stan.
     */
    void clearGameBoard();

    /**
     * @brief Obsługuje kliknięcie w kafelek.
     *
     * Po kliknięciu w kafelek, aktualizuje planszę i sprawdza stan gry.
     */
    void handleTileClick();

    /**
     * @brief Sprawdza, czy gra została rozwiązana.
     *
     * Zwraca wartość logiczną informującą, czy wszystkie kafelki są w odpowiednim porządku.
     *
     * @return bool True jeśli gra jest rozwiązana, false w przeciwnym razie.
     */
    bool isSolved() const;

private slots:
    //----------HOME PAGE---------
    void on_playAsGuestButton_clicked();
    void on_exitButton_clicked();
    void on_loginButton_clicked();

    //----------ACCOUNTS PAGE-------
    void on_loginAccountsButton_clicked();
    void on_createAccountAccountsButton_clicked();
    void on_returnAccountsButton_clicked();
    void onAccountRowSelected();

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
    void onManageAccountsRowSelected();

    //----------UPDATE ACCOUNT PAGE----------
    void on_createAccountUpdateAccountButton_clicked();
    void on_returnUpdateAccountButton_clicked();
    void on_updateUpdateAccountButton_clicked();

    //----------DIFFICULTY PAGE----------
    void on_easyDifficultyButton_clicked();
    void on_normalDifficultyButton_clicked();
    void on_hardDifficultyButton_clicked();
    void on_customDifficultyButton_clicked();
    void on_returnDifficultyButton_clicked();

    //----------GAME RESULTS PAGE--------
    void on_returnGameResultsButton_clicked();
    void on_deleteGameResultsButton_clicked();

private:
    Ui::MainWindow *ui; /**< Wskaźnik interfejsu użytkonika. */
    QStack<int> pageStack; /**< Stos do zarządzania historią przejść między stronami. */
    int loggedUserId = -999; /**< Identyfikator zalogowanego użytkownika. */

    // MANAGE ACCOUNTS PAGE
    void refreshManageAccountsTable(); /**< Odświeża tabelę zarządzania kontami. */

    // UPDATE ACCOUNT PAGE
    void fillUpdateAccountPage(User user); /**< Wypełnia formularz aktualizacji konta użytkownika danymi. */

    void jumpTo(int pageIndex); /**< Przechodzi do strony o danym indeksie. */
    void refreshAccountsTable(); /**< Odświeża tabelę kont użytkowników. */
    void resetAccountsPageState(); /**< Resetuje stan strony wyświetlającej konta użytkowników. */
    void validateCreateAccountForm(); /**< Waliduje formularz tworzenia nowego konta. */
    void goBack(); /**< Wróć do poprzedniej strony. */

    // GAME RESULTS PAGE
    void refreshGameResultsTableWidget(); /**< Odświeża tabelę wyników gry. */
    void onGameResultsTableRowSelected(); /**< Obsługuje wybór wiersza w tabeli wyników gry. */

    // GAME PAGE
    QTimer* gameTimer; /**< Wskaźnik na timer gry. */
    QTime elapsedTime; /**< Czas, który upłynął od rozpoczęcia gry. */
    QDateTime startDate; /**< Czas rozpoczęcia gry. */
    QDateTime endDate; /**< Czas zakończenia gry. */
};
#endif // MAINWINDOW_H
