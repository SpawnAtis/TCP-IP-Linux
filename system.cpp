#include "system.h"
#include "list.h"

void AddTicket(string buffer ,ServerSocket new_sock)
{
    Ticket *sp;
    
    new_sock>>buffer;
    sp->film_name=buffer;
    
    new_sock>>buffer;
    sp->film_price=atoi(buffer.c_str());
    
    new_sock>>buffer;
    sp->film_time=buffer;
    
    add(*sp);
    buffer[0] = '1';
}

/*void OutputTicket(string ,ServerSocket)
{
    show(sock);
    buffer[0] = '1';
    send(sock, buffer, 1, 0);
}
*/

void clrscr(void)
{
char a[80];
printf("\033[2J"); /* Clear the entire screen. */
printf("\033[0;0f"); /* Move cursor to the top left hand corner
*/
}


