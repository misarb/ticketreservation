#include "EventModel.h"

EventModel::EventModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int EventModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_events.size();
}

QVariant EventModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_events.size())
        return QVariant();

    if (role == Qt::DisplayRole) {
        const auto &event = m_events[index.row()];
        return QString("%1 - %2 - %3").arg(QString::fromStdString(std::get<1>(event)),
                                           QString::fromStdString(std::get<2>(event)),
                                           QString::fromStdString(std::get<3>(event)));
    }
    return QVariant();
}

void EventModel::setEvents(const std::vector<std::tuple<int, std::string, std::string, std::string>>& events)
{
    beginResetModel();
    m_events = events;
    endResetModel();
    qDebug() << "Model updated with" << m_events.size() << "events";
}
