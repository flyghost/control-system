#ifndef MESSAGEDISPATCHER_H
#define MESSAGEDISPATCHER_H


#include <QObject>
#include <QMap>

#define MSG_BTN_MUSIC_UPDATE        (1)
#define MSG_BTN_MUSIC_PLAY          (2)
#define MSG_BTN_MUSIC_STOP          (3)
#define MSG_BTN_MUSIC_LAST          (4)
#define MSG_BTN_MUSIC_NEXT          (5)

class MessageDispatcher : public QObject
{
    Q_OBJECT

public:
    static MessageDispatcher& instance();

    void registerReceiver(QObject* receiver);
    void unregisterReceiver(QObject* receiver);

public slots:
    void dispatchMessage(const QByteArray& message);

private:
    MessageDispatcher(QObject* parent = nullptr);

    QMap<QObject*, bool> m_receivers;
};

#endif // MESSAGEDISPATCHER_H
