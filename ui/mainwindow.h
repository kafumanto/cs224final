#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class Document;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void modeChanged();
    void fileNew();
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();
    void fileExit();
    void editUndo();
    void editRedo();
    void editMenuAboutToShow();
    void editMenuAboutToHide();
    void generateMesh();
    void subdivideMesh();

private:
    Ui::MainWindow *ui;
    QString filePath;
    QString fileName;

    void updateMode();
    void updateTitle();
    bool checkCanOverwriteUnsavedChanges();

    void setDirectory(const QString &dir);
    QString getDirectory();
};

#endif // MAINWINDOW_H
