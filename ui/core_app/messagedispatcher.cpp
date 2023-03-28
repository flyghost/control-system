#include "messagedispatcher.h"


MessageDispatcher& MessageDispatcher::instance()
{
    static MessageDispatcher instance;
    return instance;
}

void MessageDispatcher::registerReceiver(QObject* receiver)
{
    m_receivers[receiver] = true;
}

void MessageDispatcher::unregisterReceiver(QObject* receiver)
{
    m_receivers.remove(receiver);
}

void MessageDispatcher::dispatchMessage(const QByteArray& message)
{
    for (auto receiver : m_receivers.keys())
    {
        if (m_receivers[receiver])
        {
            QMetaObject::invokeMethod(receiver, "onMessageReceived", Qt::QueuedConnection, Q_ARG(QByteArray, message));
        }
    }
}

MessageDispatcher::MessageDispatcher(QObject* parent)
    : QObject(parent)
{
}
