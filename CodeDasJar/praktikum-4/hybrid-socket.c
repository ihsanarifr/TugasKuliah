#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <pthread.h>

#define NPROCESS 3
#define NTHREAD  3

int i, j, server_id, client_id = 0;

void *accept_connection(void *arg);

int main(int argc, char *argv[])
{
    int port = atoi(argv[1]);                       /* port server */
    pthread_t thread[NTHREAD];

    /* 1. Membuat soket */
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        fprintf(stderr, "Error creating socket.\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {              /* alamat server */
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };

    /* 2. Memberikan alamat ke soket */
    if (bind(listen_socket, (struct sockaddr*) &server_addr, sizeof (struct sockaddr_in)) == -1) {
        fprintf(stderr, "Error binding.\n");
        exit(EXIT_FAILURE);
    }

    /* 3. Listen --> soket pasif */
    if (listen(listen_socket, 5) == -1) {
        fprintf(stderr, "Error listening.\n");
        exit(EXIT_FAILURE);
    }
    printf("[SERVER] listening...\n");

    /* 4a. Preforking sebanyak jumlah proses yang diinginkan */
    for (i = 0; i < NPROCESS; i++) {
        printf("[SERVER] creating child-%d\n", i);
        if (fork() == 0) {                          /* jika proses anak, akan melakukan prethreading */

            /* 4b. Prethreading, tiap thread menerima koneksi dari klien */
            for (j = 0; j < NTHREAD; j++) {
                printf("[SERVER] child-%d creating thread-%d%d\n", i, i, j);
                pthread_create(&thread[j], NULL, accept_connection, (void *)&listen_socket);
                sleep(1);
            }
            for (j = 0; j < NTHREAD; j++) {                 /* parent menunggu sampai tiap thread selesai */
                pthread_join(thread[j], NULL);
            }
        }
    }
    wait(NULL);


    /* tutup soket */
    close(listen_socket);
    exit(EXIT_SUCCESS);
}

void *accept_connection(void *arg)
{
    int listen_socket = *(int *)arg;
    int tid = i;

    while (1) {
        struct sockaddr_in client_addr;             /* alamat klien */
        socklen_t client_addr_size = sizeof (struct sockaddr_in);

        /* 5. Membuat soket untuk menerima koneksi dari klien */
        int accept_socket = accept(listen_socket, (struct sockaddr*) &client_addr, &client_addr_size);
        if (accept_socket == -1) {
            fprintf(stderr, "Error accepting accept_socket.\n");
            exit(EXIT_FAILURE);
        }
        int cid = client_id++;

        /* cetak alamat klien */
        printf("[SERVER] thread-%d accepting client-%d from %s:%d\n", tid, cid, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        /* kirim pesan ke klien */
        char server_msg[] = "+OK Welcome, type your message.\n";
        write(accept_socket, server_msg, sizeof server_msg);

        /* baca pesan dari klien */
        char client_msg[100] = {0};
        read(accept_socket, client_msg, sizeof client_msg);
        printf("[CLIENT] client-%d said: %s", cid, client_msg);

        /* balas pesan ke klien */
        char server_reply[] = "+OK Message accepted. Bye!\n";
        write(accept_socket, server_reply, sizeof server_reply);

        /* 6. Tutup koneksi klien */
        close(accept_socket);
    }
}
