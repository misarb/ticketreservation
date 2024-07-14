#ifndef EVENTMODEL_H
#define EVENTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <vector>
#include <tuple>
#include <string>

class EventModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit EventModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setEvents(const std::vector<std::tuple<int, std::string, std::string, std::string>>& events);

private:
    std::vector<std::tuple<int, std::string, std::string, std::string>> m_events;
};
#endif // EVENTMODEL_H
