#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#if defined(QT_PRINTSUPPORT_LIB)
  #include <QtPrintSupport/qtprintsupportglobal.h>
  #if QT_CONFIG(printer)
    #if QT_CONFIG(printdialog)
      #include <QPrintDialog>
    #endif
    #include <QPrinter>
  #endif
#endif
#include <QFont>
#include <QString>
#include <QtGlobal>
#include <QFontMetrics>

#include "notepad.h"
#include "ui_notepad.h"

#include "config.h"
#include "version.h"

Notepad::Notepad(QWidget *parent):
  QMainWindow(parent),
  ui(new Ui::Notepad) {
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    connect(ui->actionNew, &QAction::triggered, this, &Notepad::newDocument);
    connect(ui->actionOpen, &QAction::triggered, this, &Notepad::open);
    connect(ui->actionSave, &QAction::triggered, this, &Notepad::save);
    connect(ui->actionSave_as, &QAction::triggered, this, &Notepad::saveAs);
    connect(ui->actionPrint, &QAction::triggered, this, &Notepad::print);
    connect(ui->actionExit, &QAction::triggered, this, &Notepad::exit);
    connect(ui->actionCopy, &QAction::triggered, this, &Notepad::copy);
    connect(ui->actionCut, &QAction::triggered, this, &Notepad::cut);
    connect(ui->actionPaste, &QAction::triggered, this, &Notepad::paste);
    connect(ui->actionUndo, &QAction::triggered, this, &Notepad::undo);
    connect(ui->actionRedo, &QAction::triggered, this, &Notepad::redo);
    connect(ui->actionAbout, &QAction::triggered, this, &Notepad::about);
    connect(ui->actionZoomOut, &QAction::triggered, this, &Notepad::zoomOut);
    connect(ui->actionZoomIn, &QAction::triggered, this, &Notepad::zoomIn);

    QFont font;
    font.setFamily(font_family);
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    font.setPointSize(font_size);

    ui->textEdit->setFont(font);

    #if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
      ui->textEdit->setTabStopDistance(tab_size * 10);
    #else
      QFontMetrics metrics(font);

      ui->textEdit->setTabStopWidth(tab_size * metrics.width(" "));
    #endif

    #if !QT_CONFIG(printer)
      ui->actionPrint->setEnabled(false);
    #endif

    #if !QT_CONFIG(clipboard)
      ui->actionCut->setEnabled(false);
      ui->actionCopy->setEnabled(false);
      ui->actionPaste->setEnabled(false);
    #endif
  }

Notepad::~Notepad() {
  delete ui;
}

void Notepad::newDocument() {
  currentFile.clear();
  ui->textEdit->setText(QString());
}

void Notepad::open() {
  QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
  QFile file(fileName);
  currentFile = fileName;
  if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
    return;
  }
  setWindowTitle(fileName);
  //QTextStream in(&file);
  QString text = QString::fromUtf8(file.readAll());
  //QString text = in.readAll();
  ui->textEdit->setText(text);
  file.close();
}

void Notepad::save() {
  QString fileName;
  if (currentFile.isEmpty()) {
    fileName = QFileDialog::getSaveFileName(this, "Save");
    currentFile = fileName;
  }
  else {
    fileName = currentFile;
  }
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
    QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
    return;
  }
  setWindowTitle(fileName);
  QTextStream out(&file);
  //QString text = ui->textEdit->toPlainText();
  QString text = ui->textEdit->toPlainText().toUtf8();
  out << text;
  file.close();
}

void Notepad::saveAs() {
  QString fileName = QFileDialog::getSaveFileName(this, "Save as");
  QFile file(fileName);

  if (!file.open(QFile::WriteOnly | QFile::Text)) {
    QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
    return;
  }

  currentFile = fileName;
  setWindowTitle(fileName);
  QTextStream out(&file);
  //QString text = ui->textEdit->toPlainText();
  QString text = ui->textEdit->toPlainText().toUtf8();
  out << text;
  file.close();
}

void Notepad::print() {
  #if QT_CONFIG(printer)
    QPrinter printDev;
    #if QT_CONFIG(printdialog)
      QPrintDialog dialog(&printDev, this);
      if (dialog.exec() == QDialog::Rejected) {
        return;
      }
    #endif
    ui->textEdit->print(&printDev);
  #endif
}

void Notepad::exit() {
  QCoreApplication::quit();
}

void Notepad::copy() {
  #if QT_CONFIG(clipboard)
    ui->textEdit->copy();
  #endif
}

void Notepad::cut() {
  #if QT_CONFIG(clipboard)
    ui->textEdit->cut();
  #endif
}

void Notepad::paste() {
  #if QT_CONFIG(clipboard)
    ui->textEdit->paste();
  #endif
}

void Notepad::undo() {
  ui->textEdit->undo();
}

void Notepad::redo() {
  ui->textEdit->redo();
}

void Notepad::zoomOut() {
  ui->textEdit->zoomOut(zoom_range);
}

void Notepad::zoomIn() {
  ui->textEdit->zoomIn(zoom_range);
}

void Notepad::about() {
  QString about_message = QString("The <b>Notepad</b> example demonstrates how to code a basic text editor using QtWidgets<br><br>")
                        + QString("Notepad version: ")
                        + app_version
                        + QString("<br><br>Qt version: ")
                        + QT_VERSION_STR;

  QMessageBox::about(this, tr("About"), about_message);
}
