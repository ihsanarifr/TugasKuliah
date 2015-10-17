#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

int main() {

    // alamat server
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(2000),
        .sin_addr.s_addr = INADDR_ANY
    };

    // alamat klien yg masuk
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);

    // 1. socket IPv4, TCP
    int server = socket(AF_INET, SOCK_STREAM, 0);

    // 2. bind socket ke alamat
    bind(server, (struct sockaddr*) &server_addr, sizeof(server_addr));

    // 3. listen koneksi yg masuk, antrian max 10
    listen(server, 10);
    printf("Server listening...");

    while (1) {

        // 4. accept koneksi masuk
        int conn = accept(server, (struct sockaddr*) &client_addr, &client_addr_size);
        printf("Client: %s:%d\n", inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
	
	// send 
	char mesg[] = "HTTP/1.0 200 OK\r\n Content-Type: text/html\r\n\r\n <html><body><h1>Hello World</h1></body></html>";
	send(conn,mesg,sizeof(mesg),0);
	
	//recv

        close(conn);
    }

    return 0;
}
