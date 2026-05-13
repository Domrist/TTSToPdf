#include "mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QLineEdit>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	QVBoxLayout *mainLayout = new QVBoxLayout();
	{
		QHBoxLayout * pathSelectorLayout = new QHBoxLayout();
		{
			QLineEdit * pathLineEdit = new QLineEdit();
			{
				pathLineEdit->setMinimumWidth(200);
			}
			pathSelectorLayout->addWidget(pathLineEdit);
			QPushButton * selectPathToOpenButton = new QPushButton();
			{
				selectPathToOpenButton->setText("Выбарть файл");
			}
			pathSelectorLayout->addWidget(selectPathToOpenButton);
		}
		mainLayout->addLayout(pathSelectorLayout);
	}

	widget.setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
}

