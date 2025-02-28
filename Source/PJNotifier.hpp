//
//  PJNotifier.hpp
//  PJNotifier - App
//
//  Created by Gene Zilberstein on 7/17/18.
//

#ifndef PJNotifier_hpp
#define PJNotifier_hpp

#include <JuceHeader.h>
#include <map>

#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace juce;

#define STL_CONTAINS( container, key ) (container.find( key ) != container.end())

class PJNotifier : public juce::DeletedAtShutdown {
public:
    virtual ~PJNotifier() {
        clearSingletonInstance();
    }
    
    typedef std::function<void(ValueTree, Component::SafePointer<Component>)> HandlerT;
    typedef std::map<std::string, std::vector<HandlerT>> HandlerMapT;
    
    HandlerMapT mNotifRegistry;
    
    static void addHandler( const std::string &notifId, const HandlerT &handler ) {
        std::vector<HandlerT> &handlerVec = getInstance()->mNotifRegistry[notifId];
        //if (!STL_CONTAINS( handlerVec, handler )) // why doesn't this work?
        {
            handlerVec.push_back( handler );
        }
    }

    static void sendNotif( const String &notifStr, Component *comp ) {
        ValueTree vtArg( notifStr );
        String notifName;
        if (notifStr.contains("."))
        {
            notifName = notifStr.upToFirstOccurrenceOf(".", false, false);
            vtArg.setProperty( "tag", notifStr.fromLastOccurrenceOf(".", false, false), nullptr );
        }
        else
        {
            notifName = notifStr;
            vtArg.setProperty( "tag",  "", nullptr );
        }
        vtArg.setProperty( "notif", notifName, nullptr );
        sendNotif( notifName.toStdString(), vtArg, comp );
    }

    static void sendNotif( const std::string &notifName, ValueTree val, Component *comp = nullptr ) {
        PJNotifier *notifier = getInstance();
        Component::SafePointer<Component> compS = comp;
        MessageManager::callAsync( [notifier, notifName, val, compS]() {
            if (STL_CONTAINS(notifier->mNotifRegistry, notifName))
            {
                std::vector<HandlerT> &handlerVec = notifier->mNotifRegistry[notifName];
                for (int i = 0; i < handlerVec.size(); i++)
                {
                    handlerVec[i]( val, compS );
                }
            }
        });
    }
    
    static std::string getNotif( ValueTree vt )
    {
        return getStdString( "notif", vt );
    }
    static std::string getTag( ValueTree vt )
    {
        return getStdString( "tag", vt );
    }

    static std::string getStdString( const String &prop, ValueTree vt )
    {
        return vt.getProperty( prop ).toString().toStdString();
    }
    static String getString( const String &prop, ValueTree vt )
    {
        return vt.getProperty( prop ).toString();
    }

    JUCE_DECLARE_SINGLETON(PJNotifier, false);
};

#endif /* PJNotifier_hpp */
