#include "mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QFileDialog>
#include <QCheckBox>


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

			QPushButton * selectPathToOpenButton = new QPushButton("Выбарть файл");
			pathSelectorLayout->addWidget(selectPathToOpenButton);
		}
		mainLayout->addLayout(pathSelectorLayout);

		QHBoxLayout * marginLayout = new QHBoxLayout();
		{
			QLabel * l = new QLabel("Отступы между элементами");
			marginLayout->addWidget(l);

			QLineEdit * e = new QLineEdit();
			marginLayout->addWidget(e);
		}
		mainLayout->addLayout(marginLayout);

		QHBoxLayout * cardDimension = new QHBoxLayout();
		{
			QLabel * w = new QLabel("Ширина карты"); cardDimension->addWidget(w);
			QDoubleSpinBox * dw = new QDoubleSpinBox(); cardDimension->addWidget(dw);
			QLabel * h = new QLabel("Высота карты"); cardDimension->addWidget(h);
			QDoubleSpinBox * dh = new QDoubleSpinBox(); cardDimension->addWidget(dh);

			// connect signals to setting main settings
		}
		mainLayout->addLayout(cardDimension);

		QHBoxLayout * dividerFlagLayout = new QHBoxLayout();
		{
			QLabel * l = new QLabel("Разделитель");
			dividerFlagLayout->addWidget(l);
			QCheckBox * c = new QCheckBox();
			// do connect
			dividerFlagLayout->addWidget(c);
		}
		mainLayout->addLayout(dividerFlagLayout);

		QHBoxLayout * orientationLayout = new QHBoxLayout();
		{
			QLabel * l = new QLabel("Горизонтальная ориентация");
			orientationLayout->addWidget(l);
			QCheckBox * checkbox = new QCheckBox();
			orientationLayout->addWidget(checkbox);
			// make connect
		}
		mainLayout->addLayout(orientationLayout);

		QHBoxLayout * selectPathLayout = new QHBoxLayout();
		{
			QLineEdit * selectPathLineEdit = new QLineEdit();
			selectPathLayout->addWidget(selectPathLineEdit);

			QPushButton * b = new QPushButton("Выбрать путь сохранения");
			selectPathLayout->addWidget(b);
			// make connect
		}
		mainLayout->addLayout(selectPathLayout);
	}

	QPushButton * generateButton = new QPushButton("Сгенерировать");
	// connect to signal
	mainLayout->addWidget(generateButton);

	widget.setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
}

