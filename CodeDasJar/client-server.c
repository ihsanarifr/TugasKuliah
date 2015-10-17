#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int socketfd;
    char *server_host = "172.0.0.1";
    int   server_port = 20000;

    /* 1. Membuat soket */
    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr = {              /* alamat server tujuan */
        .sin_family = AF_INET,
        .sin_port = htons(server_port)
    };
    inet_aton(server_host, &server_addr.sin_addr);

    /* 2. Koneksi ke server --> soket aktif */
    connect(socketfd, (struct sockaddr*) &server_addr, sizeof server_addr);

    /* baca pesan dari server */
    char server_msg[80] = {0};
    read(socketfd, server_msg, sizeof server_msg);
    printf("%s", server_msg);

    /* kirim pesan ke server 
    printf("> ");
    char client_msg[80] = {0};
    fgets(client_msg, sizeof client_msg, stdin);
    write(socketfd, client_msg, sizeof client_msg);

    /* baca balasan dari server
    char server_reply[80] = {0};
    read(socketfd, server_reply, sizeof server_reply);
    printf("%s", server_reply);

    /* 3. Tutup koneksi ke server */
    close(socketfd);

    return 0;
}
