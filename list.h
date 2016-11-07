#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sstream>
#include <iostream>
#include <stdlib.h>

#define TRUE 1

using namespace std;

struct Ticket
{
    string film_name;
    double film_price;
    string film_time;
};

struct st
{
	Ticket s;
	st *next, *prev;
};

st *b = NULL, *e = NULL;

/*st *search(string _name)
{
	if (b == NULL)
		return NULL;
	else
	{
		st *p = b;
		while (TRUE)
		{
			if (p->s.Ticket_name== _name)
			{
				return p;
			}

			if (p->next == NULL)
				break;

			p = p->next;
		}
		return NULL;
	}
	return NULL;
}*/

void add(Ticket obj)
{
    cout<<"Мы попали в add()"<<endl;
    if (b == NULL)
    {
            b = new st;
            b->s = obj;
            b->next = b->prev = NULL;
            e = b;
    }
    else
    {
            e->next = new st;
            e->next->prev = e;
            e = e->next;
            e->s = obj;
            e->next = NULL;
    }
}

/*int del(string name)
{
	if (b != NULL)
	if (b->next == NULL)
	{
		if (b->s.Ticket_name==name)
		{
			delete b;
			e = b = NULL;
			return 0;
		}
		return 1;
	}
	else
	{
		st *p = search(name);
		if (p != NULL)
		{

			if (p->prev == NULL)
			{
				b = p->next;
				b->prev = NULL;
				delete p;
			}
			else
			{
				if (p->next == NULL)
				{
					e = p->prev;
					e->next = NULL;
					delete p;
				}
				else
				{
					p->next->prev = p->prev;
					p->prev->next = p->next;
					delete p;
				}
			}
			return 0;
		}
		return 1;
	}
	return 1;
}


int edit(st *p, Ticket * c)
{
	if (p != NULL)
	{
		p->s.Ticket_quantity = c->Ticket_quantity;
		p->s.Ticket_country = c->Ticket_country;
		p->s.Ticket_firm = c->Ticket_firm;
		p->s.Ticket_name = c->Ticket_name;
		return 0;
	}
	return 1;
}

//void sort(int field)
//{
//	int s1, s2, x = -1;
//	st *p = b->next;
//
//	while (x != 0)
//	{
//		x = 0;
//		p = b->next;
//
//		while (TRUE)
//		{
//			if (field == 1)
//			{
//				s1 = p->prev->s.name[0];
//				s2 = p->s.name[0];
//			}
//			if (field == 2)
//			{
//				s1 = p->prev->s.date[0];
//				s2 = p->s.date[0];
//			}
//			if (field == 3)
//			{
//				s1 = p->prev->s.post[0];
//				s2 = p->next->s.post[0];
//			}
//			if (field == 4)
//			{
//				s1 = p->prev->s.income;
//				s2 = p->s.income;
//			}
//
//			if (field != 4)
//			{
//				if (s1<97)
//					s1 += 32;
//				if (s2<97)
//					s2 += 32;
//			}
//			if (s1>s2)
//			{
//				Ticket t = p->prev->s;
//
//				p->prev->s = p->s;
//				p->s = t;
//
//				x++;
//
//			}
//			if (p->next == NULL)
//				break;
//			p = p->next;
//		}
//	}
//}
*/
void show(int s)
{
	if (b == NULL)
		return;

	st *p = b;

	while (TRUE)
	{
            send(s,(char*)&p->s,sizeof(Ticket),0);
            if (p->next == NULL)
                    return;

            p = p->next;
	}
}

/*void showQuantity(socket s,st *p)
{
	if (b == NULL)
		return;

	Sleep(10);
	stringstream k;
	k << p->s.Ticket_quantity;
	char quantity[256] = { "\0" };
	k >> quantity;
	send(s, quantity, sizeof(Ticket), NULL);

}*/
