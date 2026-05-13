#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QFileDialog>
#include <QCheckBox>

#include "OutputSettings.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	QWidget widget;

private slots:

	void selectFileToProcessFile();

	void setMargins(double a_value);
	void setCardWidth(double a_value);
	void setCardHeight(double a_value);
	void setDividerFlag(int a_state);
	void selectSavePath();
	void setOrientation(int a_state);

	void generate();

private:

	QLineEdit _pathToRead;
	QLineEdit _pathToSave;

private:

	OutputSettings _outputSettings;
};
#endif // MAINWINDOW_H
