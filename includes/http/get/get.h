#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#pragma once


/*
    *    includes/http/get/get.h
    *    Date: 12/6/21
    *    Author: 0x1CA3
*/


void directory_check_get(char *data, char *directory);
bool requests_get(int port, char *website, char *directory);