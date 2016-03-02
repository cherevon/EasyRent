#include <QApplication>
#include "FormUserQueries.h"

int main(int argc, char* argv[])
{
    QApplication *app = new QApplication(argc, argv);

    FormUserQueries* main = new FormUserQueries();
    app->setActiveWindow(main);
    main->show();

    return app->exec();
}
