#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QApplication>
#include "view/menubar.h"
#include "view/catalog.h"
#include "view/addproduct.h"
#include "view/modifyproduct.h"
#include "view/searchinventory.h"
#include "view/table.h"
#include "model/tablemodel.h"

class Controller;
class AddProduct;
using namespace std;


class MainWindow : public QWidget{
    Q_OBJECT
private:
    MenuBar *menu;
    catalog *catalogo;
    AddProduct* aggiungiProdotto;
    Controller* controller;

public:
    explicit MainWindow(QWidget * = nullptr);
    ~MainWindow() override = default;
    virtual QSize sizeHint() const override;
    void setController(Controller *c);
    AddProduct* getAddProduct() const;
    catalog* getCatalog() const;
    MenuBar *getMenu() const;

public slots:
    void insertItemInfo();  //slot che visualizza una finestra di successo
    void loadingXmlInfo();
    void savingXmlInfo();
    void seeInfo();
    void enableBtnTable(bool);  //slot che abilita/disabilita l'interazione con i bottoni della tabella Catalogo

};

#endif // MAINWINDOW_H
