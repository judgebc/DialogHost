#include "ExampleDialog.h"
#include "ExampleHost.h"

#include <QApplication>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  ExampleHost host;
  host.setGeometry(100, 100, 1024, 768);
  host.show();

  ExampleDialog dialog(&host);
  host.installObserver(&dialog);
  dialog.setFixedSize(host.size() / 2);
  dialog.show();

  return app.exec();
}
