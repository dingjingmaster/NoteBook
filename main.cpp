#include "notebook.h"
#include "setting.h"
#include "configinfo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    NoteBook notebook;

    notebook.show();
    return app.exec();
}
