//
// Created by krasno on 2020-01-27.
//

#ifndef PONG_PONGRPC_H
#define PONG_PONGRPC_H


#include <discord_rpc.h>
#include "MP.h"

static long First;
static long LastUpload;

class PongRPC {
public:
    static void InitRPC();
    static void HandleDiscordReady(const DiscordUser* request);
    static void HandleDiscordError(int errorCode, const char* message);
    static void HandleDiscordDisconnected(int errorCode, const char* message);
    static void HandleDiscordJoinGame(const char* joinSecret);
    static void HandleDiscordSpectateGame(const char* spectateSecret);
    static void HandleDiscordJoinRequest(const DiscordUser* request);
    static void UpdatePresence(int scoreA, int scoreB, MultiplayerMode multiplayerMode);
};

//long PongRPC::First = 0;
//long PongRPC::LastUpload = 0;


#endif //PONG_PONGRPC_H
