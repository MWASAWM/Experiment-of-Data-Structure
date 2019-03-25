#include "normalui_historicaodata.h"
#include "ui_normalui_historicaodata.h"

NormalUI_HistoricaoData::NormalUI_HistoricaoData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalUI_HistoricaoData)
{
    ui->setupUi(this);
}

NormalUI_HistoricaoData::~NormalUI_HistoricaoData()
{
    delete ui;
}
