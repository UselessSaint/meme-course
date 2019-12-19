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

	_scene = new Scene();

	_cur_max_obj_id = 1;
	_cur_max_lt = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	QPainter painter(&_pixmap);

	auto _renderer = new Renderer(&painter);

	if (ui->rt->isChecked())
	{
		clock_t st = clock();
		_renderer->renderRaytrace(*_scene, int(ui->rtDepth->value()), (ui->persp->isChecked() ? false : true), ui->thrd->value());
		clock_t end = clock();

		std::cout << "(RT) Time to render: " << static_cast<double>(end - st) / CLOCKS_PER_SEC << std::endl;
		_draw_label->update();
	}
	else if (ui->gourand->isChecked())
	{
		clock_t st = clock();
		_renderer->renderZBuffer(_scene, true);
		clock_t end = clock();

		std::cout << "(ZG) Time to render: " << static_cast<double>(end - st) / CLOCKS_PER_SEC << std::endl;
		_draw_label->update();
	}
	else if (ui->phong->isChecked())
	{
		clock_t st = clock();
		_renderer->renderZBuffer(_scene, false);
		clock_t end = clock();

		std::cout << "(ZPH) Time to render: " << static_cast<double>(end - st) / CLOCKS_PER_SEC << std::endl;
		_draw_label->update();
	}
}

void MainWindow::on_pushButton_4_clicked()
{
	if (ui->tabWidget->currentIndex() == 0)
	{
		auto x = ui->icoX->text().toDouble();
		auto y = ui->icoY->text().toDouble();
		auto z = ui->icoZ->text().toDouble();

		auto r = ui->red->value();
		auto g = ui->green->value();
		auto b = ui->blue->value();

		auto disp = ui->dispertion->value();
		auto ref = ui->reflection->value();
		auto gloss = ui->gloss->text().toDouble();
		auto rad = ui->radius->text().toDouble();

		auto newObj = new Sphere(Point(x, y, z), rad);
		newObj->setColor(Point(r, g, b));
		newObj->setGlossCoef(gloss);
		newObj->setDispertionCoef(disp);
		newObj->setReflecitonCoef(ref);
		newObj->setName("icosahedron" + std::to_string(_cur_max_obj_id));

		std::shared_ptr<Object> p_newObj(newObj);
		_scene->addObject(p_newObj);

		ui->comboBox->addItem("icosahedron" + QString::number(_cur_max_obj_id));

		_cur_max_obj_id++;
	}
	else if (ui->tabWidget->currentIndex() == 1)
	{
		auto x = ui->cubeX->text().toDouble();
		auto y = ui->cubeY->text().toDouble();
		auto z = ui->cubeZ->text().toDouble();

		auto r = ui->cubeRed->value();
		auto g = ui->cubeGreen->value();
		auto b = ui->cubeBlue->value();

		auto disp = ui->cubeDisp->value();
		auto ref = ui->cubeRef->value();
		auto gloss = ui->cubeGloss->text().toDouble();

		auto width = ui->width->text().toDouble();
		auto height = ui->height->text().toDouble();
		auto depth = ui->depth->text().toDouble();

		auto newObj = new parallelepiped(Point(x, y, z), width, height, depth);
		newObj->setColor(Point(r, g, b));
		newObj->setGlossCoef(gloss);
		newObj->setDispertionCoef(disp);
		newObj->setReflecitonCoef(ref);
		newObj->setName("parallelepiped" + std::to_string(_cur_max_obj_id));

		std::shared_ptr<Object> p_newObj(newObj);
		_scene->addObject(p_newObj);

		ui->comboBox->addItem("parallelepiped" + QString::number(_cur_max_obj_id));

		_cur_max_obj_id++;
	}
	else if (ui->tabWidget->currentIndex() == 3)
	{
		auto x = ui->ltX->text().toDouble();
		auto y = ui->ltY->text().toDouble();
		auto z = ui->ltZ->text().toDouble();

		auto intens = ui->intens->text().toDouble();

		auto newLt = new Light(Point(x, y, z), intens);
		newLt->setName("light" + std::to_string(_cur_max_lt));


		std::shared_ptr<Light> p_newLt(newLt);
		_scene->addLight(p_newLt);

		ui->comboBox_2->addItem("light" + QString::number(_cur_max_lt));

		_cur_max_lt++;
	}
}

void MainWindow::on_pushButton_5_clicked()
{
	std::string name = ui->comboBox->currentText().toStdString();

	auto objs = _scene->getObjects();

	for (size_t i = 0; i < objs.size(); i++)
	{
		if (name == objs[i]->getName())
		{
			ui->comboBox->removeItem(ui->comboBox->currentIndex());
			_scene->removeObject(int(i));
		}
	}
}

void MainWindow::on_pushButton_6_clicked()
{
	std::string name = ui->comboBox_2->currentText().toStdString();

	auto lts = _scene->getLights();

	for (size_t i = 0; i < lts.size(); i++)
	{
		if (name == lts[i]->getName())
		{
			ui->comboBox_2->removeItem(ui->comboBox_2->currentIndex());
			_scene->removeLight(int(i));
		}
	}
}

void MainWindow::on_pushButton_2_clicked()
{
	auto rX = ui->rotX->text().toDouble();
	auto rY = ui->rotY->text().toDouble();
	auto rZ = ui->rotZ->text().toDouble();

	std::string name = ui->comboBox->currentText().toStdString();

	auto objs = _scene->getObjects();

	for (size_t i = 0; i < objs.size(); i++)
	{
		if (name == objs[i]->getName())
		{
			objs[i]->rotate(rX, rY, rZ);
		}
	}
}
