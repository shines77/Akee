
#ifndef _AKEE_DISPATCH_MESSAGE_H_
#define _AKEE_DISPATCH_MESSAGE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

#include "akee/basic/stddef.h"

#include "akee/dispatch/MessageBase.h"

namespace akee {

class ActorPath;

class Message : public MessageBase {
private:
    //

public:
    Message() : MessageBase() {
        //
    }

    ~Message() { }
};

}  /* namespace akee */

#endif  /* _AKEE_DISPATCH_MESSAGE_H_ */
