#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMouseEvent>
#include <QWidget>
#include "drawlabel.h"
#include <iostream>
#include "render/renderer.h"
#include "objects/sphere.h"
#include <time.h>
#include "objects/parallelepiped.h"
#include "z_buffer/zbuffer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
	DrawLabel *_draw_label;
	QPixmap _pixmap;
	Renderer *_renderer;
	Scene *_scene;
};

#endif // MAINWINDOW_H
