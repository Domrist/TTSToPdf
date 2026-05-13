#include "mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPdfWriter>
#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	QVBoxLayout *mainLayout = new QVBoxLayout();
	{
		QHBoxLayout * pathSelectorLayout = new QHBoxLayout();
		{
			pathSelectorLayout->addWidget(&_pathToRead);

			QPushButton * selectPathToOpenButton = new QPushButton("Выбарть файл");
			pathSelectorLayout->addWidget(selectPathToOpenButton);
			// make connect
			connect(selectPathToOpenButton, &QPushButton::clicked, this, &MainWindow::selectFileToProcessFile);
		}
		mainLayout->addLayout(pathSelectorLayout);

		QHBoxLayout * marginLayout = new QHBoxLayout();
		{
			QLabel * l = new QLabel("Отступы между элементами");
			marginLayout->addWidget(l);

			QDoubleSpinBox * e = new QDoubleSpinBox();
			marginLayout->addWidget(e);

			connect(e, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::setMargins);
		}
		mainLayout->addLayout(marginLayout);

		QHBoxLayout * cardDimension = new QHBoxLayout();
		{
			QLabel * w = new QLabel("Ширина карты"); cardDimension->addWidget(w);
			QDoubleSpinBox * dw = new QDoubleSpinBox(); cardDimension->addWidget(dw);
			QLabel * h = new QLabel("Высота карты"); cardDimension->addWidget(h);
			QDoubleSpinBox * dh = new QDoubleSpinBox(); cardDimension->addWidget(dh);

			connect(dw, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::setCardWidth);
			connect(dh, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::setCardHeight);
		}
		mainLayout->addLayout(cardDimension);

		QHBoxLayout * dividerFlagLayout = new QHBoxLayout();
		{
			QLabel * l = new QLabel("Разделитель");
			dividerFlagLayout->addWidget(l);
			QCheckBox * c = new QCheckBox();
			connect(c, &QCheckBox::stateChanged, this, &MainWindow::setDividerFlag);
			dividerFlagLayout->addWidget(c);
		}
		mainLayout->addLayout(dividerFlagLayout);

		QHBoxLayout * orientationLayout = new QHBoxLayout();
		{
			QLabel * l = new QLabel("Горизонтальная ориентация");
			orientationLayout->addWidget(l);
			QCheckBox * checkbox = new QCheckBox();
			orientationLayout->addWidget(checkbox);
			connect(checkbox, &QCheckBox::stateChanged, this, &MainWindow::setOrientation);
		}
		mainLayout->addLayout(orientationLayout);

		QHBoxLayout * selectPathLayout = new QHBoxLayout();
		{
			selectPathLayout->addWidget(&_pathToSave);

			QPushButton * b = new QPushButton("Выбрать путь сохранения");
			selectPathLayout->addWidget(b);
			connect(b, &QPushButton::clicked, this, &MainWindow::selectSavePath);
		}
		mainLayout->addLayout(selectPathLayout);
	}

	QPushButton * generateButton = new QPushButton("Сгенерировать");
	connect(generateButton, &QPushButton::clicked, this, &MainWindow::generate);
	mainLayout->addWidget(generateButton);

	widget.setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
}



void MainWindow::selectFileToProcessFile()
{
	_pathToRead.setText(QFileDialog::getOpenFileName());
}



void MainWindow::setMargins(double a_value)
{
	//
}



void MainWindow::setCardWidth(double a_value)
{
	//
}



void MainWindow::setCardHeight(double a_value)
{
	//
}



void MainWindow::setDividerFlag(int a_state)
{
	//
}



void MainWindow::selectSavePath()
{
	//
	_pathToSave.setText(QFileDialog::getSaveFileName());
}



void MainWindow::setOrientation(int a_state)
{
	//
}



void MainWindow::generate()
{
	if (_pathToSave.text().isEmpty())
	{
		return;
	}

	if (_pathToRead.text().isEmpty())
	{
		return;
	}

	if (!_outputSettings.isValid())
	{
		return;
	}

	QImage origin(_pathToRead.text());

	QPdfWriter pdfWriter(_pathToSave.text());

	pdfWriter.setResolution(300); // by default
	pdfWriter.setPageSize(QPdfWriter::A4);
	pdfWriter.setPageOrientation(QPageLayout::Orientation::Portrait);

	QPainter painter(&pdfWriter);

	QImage map = origin.copy(0,0,100,100);

	painter.drawImage(0,0, map);


	// do any other generations
}
