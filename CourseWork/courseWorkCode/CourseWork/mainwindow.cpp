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
	auto sph = new Sphere(Point(0, 0, 1000), 200);
	sph->setColor(Point(255,0,0));

	std::shared_ptr<Object> psph(sph);
	scene->addObject(psph);

	auto newObj = new Sphere(Point(0,0,800), 800);
	newObj->setColor(Point(0, 255, 255));
	std::shared_ptr<Object> psph2(newObj);
	//scene->addObject(psph2);

	auto newLt = new Light(Point(0, 0, -200), 400);
	std::shared_ptr<Light> pnewLt(newLt);
	scene->addLight(pnewLt);

	renderer->render(*scene);

    _draw_label->update();
}








