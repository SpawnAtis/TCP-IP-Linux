# TCP-IP-Linux



Задание:

Сервер хранит информацию о наличии билетов к кассе кинотеатра. Клиент имеет возможность просмотра, добавления, удаления информации, сортировки по разным полям, а также поиска по заданному условию (например, по фильму, по стоимости билета, по времени начала сеанса). Программа клиента должна содержать меню, позволяющее осуществлять указанные действия на сервере. 


 Следующие файлы составляют наш проект:

Разное:
    Makefile - Makefile для этого проекта 
    Socket.h, Socket.cpp - класс Socket, который реализует вызовы функций API для сокетов. 
    SocketException.h - класс SocketException 
Сервер:
    simple_server_main.cpp - главный файл 
    ServerSocket.h, ServerSocket.cpp - класс ServerSocket 
Клиент:
    simple_client_main.cpp - главный файл 
    ClientSocket.h, ClientSocket.cpp - класс ClientSocket 
