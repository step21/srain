#ifndef __UI_H
#define __UI_H

#include <glib.h>
#include <irc.h>

#define PATH_LEN 256

typedef struct {
    char name[CHAN_LEN];
} chan_name_t;

typedef struct {
    char chan[CHAN_LEN];
    char nick[NICK_LEN];
} online_list_item_t;

typedef struct {
    char chan[CHAN_LEN];
    char topic[MSG_LEN];
} topic_t;

typedef struct {
    char id[NICK_LEN];
    char nick[NICK_LEN];
    char chan[CHAN_LEN];
    char msg[MSG_LEN];
    char avatar[PATH_LEN];   // path of cached avatar, can be null
    char img[PATH_LEN];      // path of cached img, can be null
} recv_msg_t;

typedef struct {
    char chan[CHAN_LEN];
    char msg[MSG_LEN];
} sys_msg_t;

#endif /* __UI_H */
