// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h>
#include <sys/un.h>
//#include <netdb.h>
//#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 
   
#define UNIX_PREFIX "unix:"
static int sk_unix_client(const char *descr)
{
    int sock = 0, valread; 
    struct sockaddr_un serv_addr; 
    char *hello = "Hello from client"; 
    char buffer[1024] = {0}; 
    if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    printf("connect to %s\n", descr + strlen(UNIX_PREFIX));

    memset(&serv_addr, 0, sizeof serv_addr);
    serv_addr.sun_family = AF_UNIX;
    strncpy(serv_addr.sun_path, descr + strlen(UNIX_PREFIX),
		sizeof serv_addr.sun_path);
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    send(sock , hello , strlen(hello) , 0 ); 
    printf("Hello message sent\n"); 
    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer );
    printf("Server socket: %d\n", sock);
    return(sock);
}
int main(int argc, char const *argv[]) 
{ 
 
    sk_unix_client(UNIX_PREFIX);
    return 0; 
} 

