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

	QPainter painter(&_pixmap);

	_renderer = new Renderer(&painter);

	auto scene = new Scene();

	auto sph = new Sphere(Point(-100, 0, 300), 200);
	sph->setColor(Point(0,255,255));
	sph->setReflecitonCoef(0);
	std::shared_ptr<Object> psph(sph);
	scene->addObject(psph);

	auto sph2 = new Sphere(Point(50, 0, 400), 200);
	sph2->setColor(Point(255,0,0));
	sph2->setReflecitonCoef(0);
	std::shared_ptr<Object> psph2(sph2);
	//scene->addObject(psph2);

	auto par1 = new parallelepiped(Point(0,15,700), 500, 500, 20);
	par1->setColor(Point(255, 255, 0));
	par1->setReflecitonCoef(1);
	std::shared_ptr<Object> ppar1(par1);
	scene->addObject(ppar1);

	auto sph3 = new Sphere(Point(-150, 0, 300), 200);
	sph3->setColor(Point(255,255,255));
	std::shared_ptr<Object> psph3(sph3);
	//scene->addObject(psph3);

	auto sph4 = new Sphere(Point(50, 200, 300), 200);
	sph4->setColor(Point(255,255,255));
	std::shared_ptr<Object> psph4(sph4);
	//scene->addObject(psph4);

	auto sph5 = new Sphere(Point(50, -200, 300), 200);
	sph5->setColor(Point(255,255,255));
	std::shared_ptr<Object> psph5(sph5);
	//scene->addObject(psph5);

	auto newLt = new Light(Point(500, 0, -150), 300);
	std::shared_ptr<Light> pnewLt(newLt);
	scene->addLight(pnewLt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
	clock_t st = clock();
	_renderer->renderZBuffer(*_scene, true);
	clock_t end = clock();

	std::cout << "Time to render: " << static_cast<double>(end - st) / CLOCKS_PER_SEC;
	_draw_label->update();
}

void MainWindow::on_pushButton_clicked()
{
	clock_t st = clock();
	_renderer->renderRaytrace(*_scene, 1);
	clock_t end = clock();

	std::cout << "Time to render: " << static_cast<double>(end - st) / CLOCKS_PER_SEC;
	_draw_label->update();
}
