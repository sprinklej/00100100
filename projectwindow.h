#ifndef PROJECTWINDOW_H
#define PROJECTWINDOW_H

#include <QDialog>
#include "Project.h"
#include "User.h"
#include "adminwindow.h"

class ManageAdminControl;

namespace Ui {
class ProjectWindow;
}

class ProjectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectWindow(QWidget *parent = 0);
    ~ProjectWindow();

    void setOwner(Admin*);
    void setEdit(bool);
    void setProject(Project*);
    void setParent(ManageAdminControl*);

private slots:
    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::ProjectWindow *ui;
    Admin* owner;
    bool edit;
    Project* project;
    ManageAdminControl* parent;
};

#endif // PROJECTWINDOW_H
