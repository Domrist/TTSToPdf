#include "mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPdfWriter>
#include <QPainter>
#include <QDebug>

#define PDF_RESOLUTION 300
#define MM_PER_INC 24.5


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
			QLabel * w = new QLabel("Ширина карты (мм)"); cardDimension->addWidget(w);
			QDoubleSpinBox * dw = new QDoubleSpinBox(); cardDimension->addWidget(dw);
			QLabel * h = new QLabel("Высота карты (мм)"); cardDimension->addWidget(h);
			QDoubleSpinBox * dh = new QDoubleSpinBox(); cardDimension->addWidget(dh);

			connect(dw, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::setCardWidth);
			connect(dh, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::setCardHeight);
		}
		mainLayout->addLayout(cardDimension);

		QHBoxLayout * horizontalMaxCardCount = new QHBoxLayout();
		{
			QLabel *hcl = new QLabel("Количество карт по горизонтали (в фале оригинала)"); horizontalMaxCardCount->addWidget(hcl);
			QSpinBox * hc = new QSpinBox(); horizontalMaxCardCount->addWidget(hc);

			QLabel *vcl = new QLabel("Количество карт по вертикали (в фале оригинала)"); horizontalMaxCardCount->addWidget(vcl);
			QSpinBox * vc = new QSpinBox(); horizontalMaxCardCount->addWidget(vc);

			connect(hc, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),this, &MainWindow::setMaxHCardcount);
			connect(vc, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),this, &MainWindow::setMaxVCardCount);
		}
		mainLayout->addLayout(horizontalMaxCardCount);

		QHBoxLayout * pageSettingLayout = new QHBoxLayout();
		{
			QLabel *hcl = new QLabel("Количество карт по горизонтали "); pageSettingLayout->addWidget(hcl);
			QSpinBox * hc = new QSpinBox(); pageSettingLayout->addWidget(hc);

			QLabel *vcl = new QLabel("Количество карт по вертикали (в фале оригинала)"); pageSettingLayout->addWidget(vcl);
			QSpinBox * vc = new QSpinBox(); pageSettingLayout->addWidget(vc);

			connect(hc, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),this, &MainWindow::setMaxHCardcount);
			connect(vc, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),this, &MainWindow::setMaxVCardCount);
		}
		mainLayout->addLayout(pageSettingLayout);

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
	_outputSettings.margin = a_value;
}



void MainWindow::setCardWidth(double a_value)
{
	_outputSettings.cardW = a_value;
}



void MainWindow::setCardHeight(double a_value)
{
	_outputSettings.cardH = a_value;
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
	_outputSettings.isPortraitOrientation = a_state;
}



void MainWindow::setMaxHCardcount(int a_cardHMaxCount)
{
	// setting card count
	_outputSettings.cardCountMaxX = a_cardHMaxCount;
}



void MainWindow::setMaxVCardCount(int a_cardVMaxCount)
{
	_outputSettings.cardCountMaxY = a_cardVMaxCount;
}



void MainWindow::setRowCountPerPage(int a_count)
{
	_outputSettings.rowCountPerPage = a_count;
}



void MainWindow::setColumnCountPerPage(int a_count)
{
	_outputSettings.columnCountPerPage = a_count;
}



void MainWindow::generate()
{
	_pathToRead.setText("/home/user/da/pro/sandbox/TTSToPDF/template-sheet.png");
	_pathToSave.setText("/home/user/da/pro/sandbox/TTSToPDF/qweqwe");

	if (_pathToSave.text().isEmpty())
	{
		return;
	}

	if (_pathToRead.text().isEmpty())
	{
		return;
	}

	// if (!_outputSettings.isValid())
	// {
	// 	return;
	// }

	QImage origin(_pathToRead.text());

	QPdfWriter pdfWriter(_pathToSave.text());

	pdfWriter.setResolution(300); // by default
	pdfWriter.setPageSize(QPdfWriter::A4);
	pdfWriter.setPageOrientation(QPageLayout::Orientation::Portrait);

	QPainter painter(&pdfWriter);

	int cardOriginW = origin.width() / _outputSettings.cardCountMaxX;
	int cardOriginH = origin.height() / _outputSettings.cardCountMaxY;

	int currentRowCount = 0;
	int currentColCount = 0;

	for(int y = 0; y < _outputSettings.cardCountMaxY; y++)
	{
		for(int x = 0; x < _outputSettings.cardCountMaxX; x++)
		{
			int leftX = x * cardOriginW;
			int leftY = y * cardOriginH;
			int rightX = leftX + cardOriginW;
			int rightY = leftY + cardOriginH;
			QImage map = origin.copy(leftX, leftY , cardOriginW, cardOriginH);

			map = map.scaled(_outputSettings.cardW * (PDF_RESOLUTION / MM_PER_INC), _outputSettings.cardH * (PDF_RESOLUTION / MM_PER_INC));

			qDebug() << map.size() << " VS pdw writer width -> " <<  pdfWriter.width();

			int xDraw = currentColCount * _outputSettings.cardW * PDF_RESOLUTION / MM_PER_INC;
			int yDraw = currentRowCount * _outputSettings.cardH * PDF_RESOLUTION / MM_PER_INC;
			painter.drawImage(xDraw , yDraw, map);

			currentColCount++;

			if (currentColCount == _outputSettings.columnCountPerPage)
			{
				currentColCount = 0;
				currentRowCount++;
			}

			if (currentRowCount == _outputSettings.rowCountPerPage)
			{
				currentColCount = 0;
				currentRowCount = 0;
				pdfWriter.newPage();
			}
		}
	}

	// do any other generations
}
