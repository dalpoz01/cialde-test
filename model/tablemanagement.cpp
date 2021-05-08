#include "tablemanagement.h"

//Costruttore
TableManagement::TableManagement(QObject *parent,const std::string& path, const std::string& file) :
    QAbstractTableModel(parent),
    model(new Model(path,file)) {
    model->loadXMl();   //Carico i dati da Xml
}

//Distruttore
TableManagement::~TableManagement() {
    if(model)
        delete model;
}

//Metodo che ritorna la dimensione del model, cioè il numero di righe della tabella
int TableManagement::rowCount(const QModelIndex&) const{return model->getSize();}

//Metodo che ritorna il numero di colonne (attributi del WaffleBox)
int TableManagement::columnCount(const QModelIndex&) const{return 6;}

//Metodo che ritorna uno degli attributi di un WaffleBox
QVariant TableManagement::data(const QModelIndex &modelIndex, int role) const{
    if(role != Qt::DisplayRole) return QVariant(); //Qt::DisplayRole è una costante == 0, indica che i dati vengono presi in QString
    switch(modelIndex.column()){
    case 0: return QString::fromStdString(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getID()); //getItem() ritorna l'obj ad un determinato indice
            break;
    case 1: return model->getItem(static_cast<unsigned int>(modelIndex.row()))->getCapacity();
            break;
    case 2: return model->getItem(static_cast<unsigned int>(modelIndex.row()))->getWeight();
            break;
    case 3: return model->getItem(static_cast<unsigned int>(modelIndex.row()))->getPrice();
            break;
    case 4: return model->getItem(static_cast<unsigned int>(modelIndex.row()))->getDiscount();
            break;
    case 5: return model->getItem(static_cast<unsigned int>(modelIndex.row()))->getStockAvailability();
            break;
    //Ho definito le colonne
    default: return QVariant();
    }
    return QVariant();
}

//Metodo 
QVariant TableManagement::headerData(int section, Qt::Orientation orientation, int role) const{
    if(role != Qt::DisplayRole) return QVariant();
    if(orientation == Qt::Horizontal){
        switch(section){
        case 0: return QVariant(QString("ID"));
                break;
        case 1: return QVariant(QString("Capacity"));
                break;
        case 2: return QVariant(QString("Weight"));
                break;
        case 3: return QVariant(QString("Price"));
                break;
        case 4: return QVariant(QString("Discount"));
                break;
        case 5: return QVariant(QString("StockAvailability"));
                break;
        }
    }
}

//Metodo per inserire n righe nella tabella dopo la riga afterRow
bool TableManagement::insertRows(int afterRow, int n, const QModelIndex &modelIndex){
    beginInsertRows(modelIndex,afterRow,(afterRow+n-1));
    model->addBox(wbToInsert);
    endInsertRows();
    return true;
}

//Metodo per rimuovere n righe dalla tabella dopo la riga afterRow
bool TableManagement::removeRows(int startRow, int n, const QModelIndex &modelIndex){
    beginRemoveRows(modelIndex,startRow,(startRow+n-1));
    model->removeBox(static_cast<unsigned int>(startRow));
    endRemoveRows();
    return true;
}
