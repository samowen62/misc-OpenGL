#include <application.h>
#include <qpushbutton.h>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QPushButton buttonD("die",0);
	buttonD.resize(100,30);

	app.setMainWidget(&buttonD);
	buttonD.show();
	return app.exec();

}