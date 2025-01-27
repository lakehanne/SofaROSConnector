#ifndef ROSCONNECTOR_TOPIC_SUBSCRIBER_H
#define ROSCONNECTOR_TOPIC_SUBSCRIBER_H

#ifdef _WIN32
// Ensure that Winsock2.h is included before Windows.h, which can get
// pulled in by anybody (e.g., Boost).
#include <Winsock2.h>
#endif

#include "init_ZyROSConnector.h"

#include <string>
#include <ros/node_handle.h>

#include <boost/circular_buffer.hpp>
#include <boost/signals2/signal.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include "sofa/helper/logging/Messaging.h"

namespace Zyklio
{
    namespace ROSConnector
    {
        class SOFA_ZY_ROS_CONNECTOR_API ZyROSConnectorTopicSubscriberIface
        {
            public:
                void onMessageReceived();
                boost::signals2::signal<void()>& getSignal() { return m_sig; }

            protected:
                boost::signals2::signal<void()> m_sig;
        };

        class SOFA_ZY_ROS_CONNECTOR_API ZyROSListener : public ZyROSConnectorTopicSubscriberIface
        {
            public:
                ZyROSListener();
                virtual ~ZyROSListener() {}

                ZyROSListener(const ZyROSListener&);
                ZyROSListener& operator=(const ZyROSListener&);

                virtual void cleanup() { msg_info("ZyROSListener") << "cleanup() not implemented for a ZyROSListener."; }

                const boost::uuids::uuid& getUuid() { return m_uuid; }

                std::string getMessageType() { return messageType; }
                virtual std::string getTopic() { msg_warning("ZyRosListener") << "getTopic() not implemented for a ZyROSListener."; return ""; }

            protected:
                boost::uuids::uuid m_uuid;
                std::string m_rosTopic;

                boost::signals2::connection m_topicConnection;
                std::string messageType;
        };

        template <class MessageType>
        class SOFA_ZY_ROS_CONNECTOR_API ZyROSConnectorTopicSubscriber : public ZyROSListener
        {
            public:
                ZyROSConnectorTopicSubscriber();
                ZyROSConnectorTopicSubscriber(ros::NodeHandlePtr rosNode, const std::string& topic, unsigned int messageQueueLength = 10, bool useGenericMessageHandling = false);
                ~ZyROSConnectorTopicSubscriber();

                ZyROSConnectorTopicSubscriber(const ZyROSConnectorTopicSubscriber& other);
                ZyROSConnectorTopicSubscriber& operator=(const ZyROSConnectorTopicSubscriber& other);

                void processMessage(const boost::shared_ptr<MessageType const>& msg);
                void subscribeToTopic();
                void unsubscribeFromTopic();

                const MessageType& getLatestMessage();
                const MessageType& getMessage(size_t);
                unsigned int getMessageCount() const;

                void clearMessages();

                void cleanup();
                void handleGenericMessage();

                std::string getTopic() const { return m_rosTopic; }

            protected:
                ros::NodeHandlePtr m_rosNodeHandle;

                ros::Subscriber m_subscriber;

                boost::circular_buffer<MessageType> m_messageQueue;
                unsigned int m_lastValidMsgIndex;
                unsigned int m_messageQueueLength;

                boost::mutex m_mutex;
        };
    }
}

#endif // ROSCONNECTOR_TOPIC_SUBSCRIBER_H
