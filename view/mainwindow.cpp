#include "mainwindow.h"
#include "controller.h"

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent),
    menu(new MenuBar(this)),
    catalogo(new catalog(this)),
    aggiungiProdotto(new AddProduct(this)),
    modificaProdotto(new modifyProduct(this)),
    ricercaProdotto(new SearchInventory(this))/*,
    absModel(new TableModel(this)),
    tabella(new TableZone(this,absModel))*/{

    setWindowTitle("Cialde Pro");
    //Centro la finestra sullo schermo
    QSize size = sizeHint();
    QDesktopWidget* desktop = QApplication::desktop();
    int width = desktop->width();
    int height = desktop->height();
    int mw = size.width();
    int mh = size.height();
    int centerW = (width/2) - (mw/2);
    int centerH = (height/2) - (mh/2);
    move(centerW, centerH);

    QVBoxLayout* qv=new QVBoxLayout;

    qv->setMenuBar(menu);
    //menu->getCarrello()->setVisible(false);
    //aggiungiProdotto->hide();
    catalogo->hide();
    ricercaProdotto->hide();
    modificaProdotto->hide();
    qv->addWidget(ricercaProdotto);
    qv->addWidget(catalogo);
    qv->addWidget(aggiungiProdotto);
    qv->addWidget(modificaProdotto);
    //qv->addWidget(tabella);

    setLayout(qv);

}
QSize MainWindow::sizeHint() const {
    return QSize(1024, 468);
}

void MainWindow::setController(Controller *c){
    controller=c;
    connect(menu->getCatalog(),SIGNAL(triggered()),controller,SLOT(showCatalogo()));
    connect(menu->getAddProduct(),SIGNAL(triggered()),controller,SLOT(showAddProduct()));
    connect(menu->getModProduct(),SIGNAL(triggered()),controller,SLOT(showModProduct()));
    connect(aggiungiProdotto->getAdd(),SIGNAL(clicked()),aggiungiProdotto,SLOT(insert()));
    connect(aggiungiProdotto,SIGNAL(signalToInsert(WaffleBox*)),controller,SLOT(insertItemController(WaffleBox*)));
}

void MainWindow::showAddProduct() const{
    aggiungiProdotto->show();
    catalogo->hide();
    modificaProdotto->hide();
    ricercaProdotto->hide();
}

void MainWindow::insertItemInfo(){

    QMessageBox::information(this,"DONE IT!", "Inserimento avvenuto con successo");
    std::cout<<"Aggiunto"<<endl;

}

void MainWindow::showCatalog() const{
    catalogo->show();
    aggiungiProdotto->hide();
    modificaProdotto->hide();
    ricercaProdotto->hide();
}

void MainWindow::showModifyProduct() const{
    modificaProdotto->show();
    aggiungiProdotto->hide();
    catalogo->hide();    
    ricercaProdotto->hide();
}

MenuBar *MainWindow::getMenu() const{
    return menu;
}
