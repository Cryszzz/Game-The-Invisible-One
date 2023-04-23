#include <winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "Packet.h"

#pragma comment (lib, "Ws2_32.lib")

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT _WIN32_WINNT_WINXP // mingw bug
#define DEFAULT_PORT "2400"

const int NUM_PLAYERS = 4;

class Server
{
public:
	Server();
	~Server();
	int update();
	void send_init_packet(int character_id);
	void recv_event();

	char buffer[NUM_PLAYERS][512];
	SOCKET ListenSocket;

	SOCKET sessions[NUM_PLAYERS];

	GameData* gd;
	Event e[NUM_PLAYERS];
	
	void updateByEvent(Event, Event, Event, Event);
	void updateBySingleEvent(Event, int);
};