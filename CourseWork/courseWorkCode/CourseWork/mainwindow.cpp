#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math/point.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	_draw_label = new DrawLabel(_pixmap);
    _draw_label->resize(800, 800);
	ui->centralWidget->layout()->addWidget(_draw_label);
	_pixmap = QPixmap(_draw_label->width(), _draw_label->height());
	_pixmap.fill();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
	QPainter painter(&_pixmap);

	auto renderer = new Renderer(&painter);

	auto scene = new Scene();
    Point sPos(0, 0, 130);
    auto sph = new Sphere(sPos, 20);

	std::shared_ptr<Object> psph(sph);
    scene->addObject(psph);

    renderer->render(*scene);

    _draw_label->update();

}








