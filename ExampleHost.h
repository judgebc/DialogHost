#pragma once

#include "DialogHost.h"

#include <QMainWindow>

class ExampleHost : public DialogHostMixin<QMainWindow>
{
  Q_OBJECT

public:
  ExampleHost() : DialogHostMixin<QMainWindow>()
  {
  }
};
