#include "table.h"

Table::Table(QWidget *parent) : QTableView(parent), mymodel(new TableModel()) {
    setModel(mymodel);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    verticalHeader()->setMaximumHeight(300);
}

TableModel* Table::getMyModel() const{ return mymodel; }
