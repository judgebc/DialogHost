#pragma once

#include "DialogHost.h"

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>

class ExampleDialog : public QDialog, public DialogHostObserver
{
  Q_OBJECT

public:
  ExampleDialog(QWidget *parent = nullptr)
    : QDialog(parent)
  {
    auto layout = new QHBoxLayout;
    auto label = new QLabel("Hello, world!");
    layout->addWidget(label);
    setLayout(layout);
  }

  void hostMoveEvent(QWidget *parent, QMoveEvent *event) override
  {
    resizeAndMove(parent);
  }

  void hostResizeEvent(QWidget *parent, QResizeEvent *event) override
  {
    resizeAndMove(parent);
  }

  void hostShowEvent(QWidget *parent, QShowEvent *event) override
  {
    resizeAndMove(parent);
  }

private:
  void resizeAndMove(QWidget *parent)
  {
    setFixedSize(parent->size() / 2);

    auto offset = (parent->size() - size()) / 2;
    move(parent->pos() + QPoint(offset.width(), offset.height()));
  }
};
