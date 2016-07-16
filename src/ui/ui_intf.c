/**
 * @file ui_intf.c
 * @brief irc server interface for UI module
 * @author Shengyu Zhang <lastavengers@outlook.com>
 * @version 1.0
 * @date 2016-04-21
 */

#define __LOG_ON

#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "srain_app.h"
#include "srain_window.h"
#include "srain_chan.h"
#include "log.h"

/* import from srain_app.c */
extern SrainApp *srain_app;
extern SrainWindow *srain_win;

/**
 * @brief Server Interface to execute a command
 *
 * @param source where this cmd comes from,
 *      if NULL, command echo may appear in the current SrainChan
 * @param cmd the command you want to execute
 *
 * @return 0 if successed, -1 if failed
 */
int ui_intf_server_cmd(SrainChan *chan, const char *cmd){
    int res;
    char *cmd2;
    const char *server_name;
    const char *chan_name;

    cmd2 = strdup(cmd);

    if (chan == NULL){
        chan = srain_window_get_cur_chan(srain_win);
    }

    if (chan){
        server_name = srain_chan_get_server_name(chan);
        chan_name = srain_chan_get_name(chan);
        res = srain_app->server_cmd(server_name, chan_name, cmd2);
    } else {
        res = srain_app->server_cmd(NULL, NULL, cmd2);
    }

    free(cmd2);
    return res;
}

/**
 * @brief join a channel of current server
 *
 * @param chan_name
 */
void ui_intf_server_join(const char *chan_name){
    const char *server_name;
    SrainChan *chan;

    chan = srain_window_get_cur_chan(srain_win);
    server_name = srain_chan_get_server_name(chan);

    srain_app->server_join(server_name, chan_name);
}

void ui_intf_server_part(SrainChan *chan){
    const char *server_name;
    const char *chan_name;

    server_name = srain_chan_get_server_name(chan);
    chan_name = srain_chan_get_name(chan);

    srain_app->server_part(server_name, chan_name);
}

void ui_intf_server_send(SrainChan *chan, const char *msg){
    const char *chan_name;
    const char *server_name;

    if (chan == NULL){
        ERR_FR("chan: NULL, msg: %s", msg);
        return;
    }

    server_name = srain_chan_get_server_name(chan);
    chan_name = srain_chan_get_name(chan);

    srain_app->server_send(server_name, chan_name, msg);
}
