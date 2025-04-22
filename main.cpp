#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(R"(
/* === Główne tło === */
QWidget {
    font-family: "Segoe UI", sans-serif;
    font-size: 14px;
    background-color: #fdf7f0;
    color: #2c3e50;
}

/* === Przycisk ogólny === */
QPushButton {
    background-color: #f39c12;
    color: white;
    border: none;
    border-radius: 8px;
    padding: 10px 15px;
    font-weight: bold;
}
QPushButton:hover {
    background-color: #e67e22;
}
QPushButton:pressed {
    background-color: #d35400;
}

/* === Kafelki gry === */
QPushButton[tile="true"] {
    background-color: #fdebd0;
    color: #2c3e50;
    font-size: 18px;
    font-weight: bold;
    border: 2px solid #f5cba7;
    border-radius: 6px;
}
QPushButton[tile="true"]:hover {
    background-color: #f8c471;
}

/* === Puste pole === */
QPushButton[empty="true"] {
    background-color: #f0b27a;
    border: 2px dashed #d68910;
    color: transparent;
}

/* === Pola tekstowe === */
QLineEdit {
    border: 1px solid #d5d8dc;
    border-radius: 6px;
    padding: 6px;
    background-color: white;
}
QLineEdit:focus {
    border: 1px solid #f39c12;
}

/* === Nagłówki tabeli === */
QHeaderView::section {
    background-color: #2c3e50;
    color: white;
    padding: 6px;
    border: none;
    font-weight: bold;
}

/* === Tabela wyników === */
QTableView {
    gridline-color: #ecf0f1;
    selection-background-color: #f8c471;
    background-color: white;
    alternate-background-color: #fcf3cf;
}
QTableView::item:selected {
    color: #2c3e50;
}

/* === Etykiety (Label) === */
QLabel {
    font-size: 14px;
    font-weight: normal;
}
QLabel[heading="true"] {
    font-size: 18px;
    font-weight: bold;
    color: #d35400;
}

/* === GroupBox === */
QGroupBox {
    border: 1px solid #f5cba7;
    border-radius: 6px;
    margin-top: 10px;
}
QGroupBox::title {
    subcontrol-origin: margin;
    subcontrol-position: top center;
    padding: 0 6px;
    background-color: #fdebd0;
    color: #2c3e50;
    font-weight: bold;
}

/* === Scrollbary === */
QScrollBar:vertical, QScrollBar:horizontal {
    background: #fdebd0;
    border: none;
    width: 12px;
    margin: 0px;
}
QScrollBar::handle {
    background: #f39c12;
    border-radius: 6px;
}
QScrollBar::handle:hover {
    background: #e67e22;
}
)");
    MainWindow w;
    w.show();
    return a.exec();
}
