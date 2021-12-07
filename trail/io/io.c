#include "../../includes/io/io.h"


/*
    *    trail/io/io.c
    *    Date: 12/6/21
    *    Author: 0x1CA3
*/


char *send_data_error(void) {
    return "Fatal error: Failed to send data to host!\n";
}

char *read_data_error(void) {
    return "Fatal error: Failed to read data from host!\n";
}

char *hostname_error(void) {
    return "Fatal error: Failed to get IP address of the host!\n";
}

char *connection_error(void) {
    return "Fatal error: Could not connect to host!\n";
}