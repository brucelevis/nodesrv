#include "msg.h"
#include <memory.h>

Message::Message()
{
    byte_sent = 0;
    sockfd = 0;
    sid = 0;
    ref_count = 0;
    memset(&option, 0, sizeof(option));
}
