// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h>
#include <sys/un.h>
#include <netdb.h>

#include <stdlib.h> 
#include <string.h> 
#define PORT 8080
#define UNIX_PREFIX "unix:"

static int sk_unix_server(const char *descr)
{
    int server_fd, new_socket, valread; 
    struct sockaddr_un address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *hello = "Hello from server"; 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_UNIX, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    }	
    printf("connect to %s\n", descr + strlen(UNIX_PREFIX));
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sun_family = AF_UNIX; 
    strncpy(address.sun_path, descr + strlen(UNIX_PREFIX),
		sizeof address.sun_path);

    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    valread = read( new_socket , buffer, 1024); 
    printf("%s\n",buffer ); 
    send(new_socket , hello , strlen(hello) , 0 ); 
    printf("Hello message sent\n");
    printf("Client socket %d\n",new_socket);

    close(new_socket);
    return(new_socket);
}
int main(int argc, char const *argv[]) 
{ 
   
    sk_unix_server(UNIX_PREFIX);
    return 0; 
} 

