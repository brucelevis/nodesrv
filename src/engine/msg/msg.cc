#include "msg.h"
#include <memory.h>

int Message::alloc_count = 0;

Message::Message()
{
    alloc_count++;
    byte_sent = 0;
    sockfd = 0;
    sid = 0;
    ref_count = 0;
    memset(&option, 0, sizeof(option));
}

Message::~Message()
{
    alloc_count--;
}
