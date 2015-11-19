
#ifndef _AKEE_ACTOR_ACTOR_H_
#define _AKEE_ACTOR_ACTOR_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

#include <akee/config/Config.h>
#include <akee/config/ConfigurationFactory.h>

#include <akee/actor/IActorContext.h>

namespace akee {

class Actor {
private:
    std::string name_;
    Config config_;
    IActorContext * context_;

public:
    Actor() {
        initActor("default", ConfigurationFactory::load());
    }

    Actor(const std::string & name) {
        initActor(name, ConfigurationFactory::load());
    }

    Actor(const std::string & name, const Config & config) {
        initActor(name, config);
    }

    Actor(const Actor & src) {
        cloneActor(src);
    }

    ~Actor() {
    }

private:
    void initActor(const std::string & name, const Config & config) {
        name_ = name;
        config_ = config;
    }

protected:
    Actor * createActor(const std::string & name, const Config & config);
    Actor * createAndStartActor(const std::string & name, const Config & config);

    void cloneActor(const Actor & src) {
        this->name_ = src.name_;
        this->config_ = src.config_;
    }

public:
    std::string getName() const {
        return name_;
    }

    void setName(const std::string & name) {
        name_ = name;
    }

    int start() {
        return 0;
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTOR_H_ */
