#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math/point.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	_draw_label = new DrawLabel(_pixmap);
	_draw_label->resize(980, 800);
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

	auto sph = new Sphere(Point(450, 0, 400), 200);
	sph->setColor(Point(255,0,0));
	std::shared_ptr<Object> psph(sph);
	scene->addObject(psph);

	auto sph2 = new Sphere(Point(-100, 0, 400), 200);
	sph2->setColor(Point(255,255,0));
	std::shared_ptr<Object> psph2(sph2);
	scene->addObject(psph2);

	auto sph3 = new Sphere(Point(250, 0, 800), 200);
	sph3->setColor(Point(0,255,255));
	std::shared_ptr<Object> psph3(sph3);
	scene->addObject(psph3);

	auto newLt = new Light(Point(0, 0, 0), 200);
	std::shared_ptr<Light> pnewLt(newLt);
	scene->addLight(pnewLt);

	clock_t st = clock();
	renderer->render(*scene);
	clock_t end = clock();

	std::cout << "Time to render: " << static_cast<double>(end - st) / CLOCKS_PER_SEC;
    _draw_label->update();
}








