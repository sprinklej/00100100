#include "ppidresultswindow.h"
#include "ui_ppidresultswindow.h"

PPIDResultsWindow::PPIDResultsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PPIDResultsWindow)
{
    ui->setupUi(this);
}

PPIDResultsWindow::~PPIDResultsWindow()
{
    delete ui;
}

// show text on the summary tab
void PPIDResultsWindow::showSummaryText(QTextStream *stream, QString FN)
{
    /*
    // display the teams
    ui->textBrowser_Summary->setText(stream->readAll());

    // display the files location
    FN = "File location: " + FN;
    ui->label_Summary_Loc->setText(FN);
    */
}

// show text on the detailed tab
void PPIDResultsWindow::showDetailedText(QTextStream *stream, QString FN)
{
    /*
    // display the teams
    ui->textBrowser_Detailed->setText(stream->readAll());

    // display the files location
    FN = "File location: " + FN;
    ui->label_Detailed_Loc->setText(FN);
    */
}
