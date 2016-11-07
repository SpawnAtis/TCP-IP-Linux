#ifndef SYSTEM_H
#define SYSTEM_H

#include "Socket.h"
#include "ServerSocket.h"
#include "SocketException.h"
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <netinet/in.h>
#include <locale.h>
#include <netdb.h> 
#include <iostream>

using namespace std;

enum Menu
{
	t_AddTicket=1,
	t_OutputTickets,
	t_DeleteTicket,
	t_SortTickets,
	t_SearchTicket,
	t_Exit
};

void AddTicket(string ,ServerSocket );
void OutputTicket(string ,ServerSocket );
void clrscr(void);


#endif /* SYSTEM_H */

