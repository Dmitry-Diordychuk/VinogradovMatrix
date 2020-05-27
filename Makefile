################################################################################
#                                                                              #
#                         File: Makefile                                       #
#                   Created By: Dmitry Diordichuk                              #
#                        Email: cort@mail.ru                                   #
#                                                                              #
#                 File Created: 27th May 2020 9:12:48 pm                       #
#                Last Modified: 27th May 2020 9:12:52 pm                       #
#                                                                              #
################################################################################

all:
	gcc -g main.c standart.c vinograd.c matrix.c -o Matrix.exe
