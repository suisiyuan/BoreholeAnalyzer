#pragma once

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QDebug>
#include <QActionGroup>
#include <QMessageBox>
#include <QUrl>
#include <QDesktopServices>
#include <QProgressDialog>
#include <QSettings>

#include "GraphicsSettings.h"
#include "GraphicsScene.h"
#include "DbHandler.h"
#include "PrjInfoDialog.h"
#include "AboutDialog.h"
//#include "RollWidget.h"
#include "Widget3D.h"
#include "app.h"
#include "ShiftDialog.h"
#include "ExportImageDialog.h"
#include "CopyAndPasteDialog.h"
#include "DeleteDialog.h"

#ifdef Q_OS_WIN
#include "QWord.h"
#include "QExcel.h"
#endif


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

public slots:
     void switchImage(qint32 index);
     void handleModeChanged(GraphicsScene::Mode curMode);
     void showStatus(QString message);

protected:
     void closeEvent(QCloseEvent * event);

private slots:
    void on_actionOpen_triggered();
    void on_actionClose_triggered();
    void on_actionSave_triggered();
    void on_actionProjectInfo_triggered();

    void on_actionExportImage_triggered();
    void on_actionExportWord_triggered();
    void on_actionExportExcel_triggered();

    void on_actionCopyAndPaste_triggered();
    void on_actionDelete_triggered();
    void on_actionShift_triggered();

    void on_actionSlitWidth_triggered();
    void on_actionRectangle_triggered();
    void on_actionAnyShape_triggered();
    void on_actionOccurrence_triggered();
    void on_actionTextbox_triggered();
    void on_actionCross_triggered();


    void on_actionAbout_triggered();
    void on_actionManual_triggered();
    void on_actionContact_triggered();



//    void keyPressEvent(QKeyEvent *event);


    void addRecentFiles(QString filename);
    void openRecentFile();
    void updateRecentFiles();
    void clearRecentFiles();
    void deleteRecentFile(QString filename);



    void on_actionExit_triggered();

    void on_actionImport_triggered();

private:

    enum AppStatus{
        IDLE = 0,
        OPENED = 1
    }appStatus;

    Ui::MainWindow *ui;
    DbHandler *handler;
    GraphicsScene *scene;
    PrjInfoDialog *infoDialog;


    QActionGroup *actionGroupFile;          // 文件操作
    QActionGroup *actionGroupExport;        // 导出操作
    QActionGroup *actionGroupGOperate;      // 全局操作
    QActionGroup *actionGroupMode;          // 2D, 3D模式切换
    QActionGroup *actionGroup2D;            // 2D模式下的操作
    QActionGroup *actionGroup3D;            // 3D模式下的操作
    QActionGroup *actionGroupSpin;          // 旋转操作
    QActionGroup *actionGroupZoom;          // 放大缩小操作

    QSettings settings;

    void initRegistry();
    void createActionGroups();
    void createSceneAndView();
    void createConnections();
    void resetActions();

    void openFile(QString filename);
    void importFile(QString filename);
    void saveFile(qint32 itemIndex);


    QImage getSceneImage(qint32 index);
    QImage getPixmapImage(qint32 index);
    QMap<QString, QGraphicsItem *> index2Item(DbHandler::IndexData indexData);


    QString getWordString(qint32 index);

signals:
    void clearScene();

    void updatePrjInfo(DbHandler::PrjInfo prjInfo);
    void clearPrjInfo();

    void sigFileOpened(QString filename);
    void sigFileClosed();

};

