#pragma once

#include <QList>

class QMoveEvent;
class QResizeEvent;
class QShowEvent;
class QWidget;

class DialogHostObserver
{
public:
  virtual void hostMoveEvent(QWidget * parent, QMoveEvent *event) = 0;
  virtual void hostResizeEvent(QWidget * parent, QResizeEvent *event) = 0;
  virtual void hostShowEvent(QWidget * parent, QShowEvent *event) = 0;
};

template<typename Base>
class DialogHostMixin : public Base
{
public:
  DialogHostMixin(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
    : Base(parent, f)
  {
  }

  void installObserver(DialogHostObserver *observer)
  {
    observers.append(observer);
  }

  void removeObserver(DialogHostObserver *observer)
  {
    observers.removeAll(observer);
  }

protected:
  void moveEvent(QMoveEvent *event) override
  {
    Base::moveEvent(event);

    for(auto observer : observers)
      observer->hostMoveEvent(this, event);
  }

  void resizeEvent(QResizeEvent *event) override
  {
    Base::resizeEvent(event);

    for(auto observer : observers)
      observer->hostResizeEvent(this, event);
  }

  void showEvent(QShowEvent *event) override
  {
    Base::showEvent(event);

    for(auto observer : observers)
      observer->hostShowEvent(this, event);
  }

private:
  QList<DialogHostObserver *> observers;
};

