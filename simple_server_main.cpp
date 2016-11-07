#include "system.h"

using namespace std;

int main ( int argc, char **argv )
{
  std::cout << "running....\n";

  try
    {
      // Create the socket
        ServerSocket server ( 7500 );
      
    while(true)
    {
        
        ServerSocket new_sock;
        server.accept ( new_sock );
    try   //разрешение соединения ,обработка запросов и т.д.
      {

        while ( true )
          {
            string buffer;
            new_sock>>buffer; //прочитать данные из new_sock, и поместить их в нашу строковую переменную 'buffer
           // cout<<"fsdfsdfsdf";

           switch (atoi(buffer.c_str()))
           {

              case t_AddTicket: cout<<"МЫ попали в добавление на сервере";AddTicket(buffer,new_sock);break;

             // case t_OutputTickets: cout<<"Сервер выводит"<<endl;OutputTicket(buffer,new_sock); break;

              case t_DeleteTicket:  break;

              case t_SortTickets:  break;

              case t_SearchTicket:  break;

              case t_Exit: exit(0);

           }
           

          }
      }
    catch ( SocketException& ) {}
        
         }
        
    }
        catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}

