#ifndef __LABEL_VIEW_HPP__
#define __LABEL_VIEW_HPP__

#include <QTreeView>

#include <medusa/medusa.hpp>
#include <medusa/document.hpp>
#include <medusa/view.hpp>
#include <medusa/label.hpp>

Q_DECLARE_METATYPE(QVector<int>)

class LabelView : public QTreeView, public medusa::View
{
  Q_OBJECT

public:
  LabelView(QWidget * parent, medusa::Medusa& core);
  virtual ~LabelView(void) {}

  virtual void OnLabelUpdated(medusa::Label const& label, bool removed);

signals:
  void goTo(medusa::Address const& addr);

private slots:
  void onLabelDoubleClicked(QModelIndex const& idx);

private:
  medusa::Medusa& _core;
};

#endif // !__LABEL_VIEW_HPP__