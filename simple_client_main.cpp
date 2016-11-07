#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include "ClientSocket.h"
#include "SocketException.h"
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <arpa/inet.h>
#include <locale.h>
#include <iostream>
#include <sstream>

using namespace std;

void clrscr(void);
int MainMenu();
void AddTicket(string ,ClientSocket);
void OutputTickets(string ,ClientSocket );

enum Menu
{
	t_AddTicket=1,
	t_OutputTickets,
	t_DeleteTicket,
	t_SortTickets,
	t_SearchTicket,
	t_Exit
};

struct Ticket
{
    string film_name;
    double film_price;
    string film_time;
};

int main ( int argc, char **argv )
{
  try
    {
      
      ClientSocket client_socket ( "localhost", 7500 );
      
      try //посылка запроса ,полученеи овтета и т.д.
	{
	  /*client_socket << "Test message.";
	  client_socket >> reply;*/
          while(true)
          {
              
          string buffer;
          switch (MainMenu())
	{

	case t_AddTicket: clrscr();cout<<"fdfdfdf";AddTicket(buffer,client_socket);clrscr();break;

	//case t_OutputTickets:clrscr();OutputTickets(buffer,client_socket);clrscr();break;

	case t_DeleteTicket:  break;

	case t_SortTickets:  break;

	case t_SearchTicket:  break;

	case t_Exit: exit(0);
        }
          
          }
          
      }
      catch ( SocketException& ) {}
      
      
      
    }
  
  
        catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;

}


void clrscr(void)
{
char a[80];
printf("\033[2J"); /* Clear the entire screen. */
printf("\033[0;0f"); /* Move cursor to the top left hand corner
*/
}

int MainMenu()
{
    clrscr();
    cout<<          "Добро пожаловать в программу!!!"<<endl;
    cout<<"<1> Добавить билет"<<endl;
    cout<<"<2> Просмотр существующих билетов"<<endl;
    cout<<"<3> Удалить билет"<<endl;
    cout<<"<4> Сортировка"<<endl;
    cout<<"<5> Поиск"<<endl;
    cout<<"<6> Выход"<<endl;
    int chose;
    while(!(cin>>chose)||chose<1||chose>6)
    {
            cin.clear();
            while(cin.get()!='\n')
            {
                cout<<"Ошибка!!!Повторите ввод!!!"<<endl;
                continue;
            }

    }
    cin.ignore();
    return chose;
}

void AddTicket(string buffer,ClientSocket client_socket)
{
    buffer= "1";
    client_socket<<buffer;
    clrscr();

    Ticket m;
    cout << "     ***Введите информацию о билете***" << endl;
    cout << "Название фильм: ";
    getline(cin, m.film_name);
    client_socket<<m.film_name;
    cout << "Стоимость билета($): ";
    while (!(cin >>m.film_price) || m.film_price< 0) {
        cin.clear();
        while (cin.get() != '\n'){
            continue;
            cout << "Ошибка!!!Повторите ввод" << endl;
            }
        }
    cin.ignore();
      
    stringstream k;
    k>>m.film_price;
    k<<buffer;
    client_socket<<buffer;   
    
    
    cout << "Время начала сеанса: ";
    getline(cin, m.film_time);
    client_socket<<m.film_time;
    
    cout<<"ghhshsg"<<endl;
    
}

/*void OutputTickets(string ,ClientSocket)
{
    buffer[0] ='2';
    send(sock, buffer, 1, 0);
    clrscr();

    Ticket *p;

    while (true)
    {
        recv(sock,buffer,sizeof(Ticket),0);
        if (buffer[0] == '1')
                break;

        p = (Ticket *)buffer;

        cout << "Название: " << p->film_name<< endl;
        cout << "Стоимость билета: " << p->film_price << endl;
        cout << "Время начала сеанса: " << p->film_time << endl;
        cout << endl << endl;

    }
    sleep(4000);
    //_getch();
}
 * */


