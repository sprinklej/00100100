#ifndef PPIDRESULTSWINDOW_H
#define PPIDRESULTSWINDOW_H

#include <QDialog>
// included to display files
#include <QTextStream>

namespace Ui {
class PPIDResultsWindow;
}

class PPIDResultsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PPIDResultsWindow(QWidget *parent = 0);
    ~PPIDResultsWindow();
    void showSummaryText(QTextStream *stream, QString FN);
    void showDetailedText(QTextStream *stream, QString FN);

    void setResults(QString, QString);

private:
    Ui::PPIDResultsWindow *ui;
};

#endif // PPIDRESULTSWINDOW_H
