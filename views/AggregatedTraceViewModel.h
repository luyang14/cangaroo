#ifndef AGGREGATEDTRACEVIEWMODEL_H
#define AGGREGATEDTRACEVIEWMODEL_H

#include <QAbstractItemModel>
#include <QMap>
#include <QList>

#include <sys/time.h>

#include <views/BaseTraceViewModel.h>
#include <model/CanMessage.h>
#include <drivers/CanInterface.h>
#include <setup/MeasurementNetwork.h>

#include "AggregatedTraceViewItem.h"


class AggregatedTraceViewModel : public BaseTraceViewModel
{
    Q_OBJECT

public:
    typedef uint64_t unique_key_t;
    typedef QMap<unique_key_t, AggregatedTraceViewItem*> CanIdMap;

public:
    AggregatedTraceViewModel(MeasurementSetup *setup);

    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const;
    virtual QModelIndex parent(const QModelIndex &child) const;
    virtual int rowCount(const QModelIndex &parent) const;

public slots:
    void messageReceived(const CanMessage &msg);

private:
    CanIdMap _map;
    AggregatedTraceViewItem *_rootItem;
    unique_key_t makeUniqueKey(const CanMessage &msg);

protected:
    virtual QVariant data_DisplayRole(const QModelIndex &index, int role) const;

};

#endif // AGGREGATEDTRACEVIEWMODEL_H
