// This is like server.c, but uses fdopen to allow communication
// via stdio functions rather than Unix system calls

#include <unistd.h>
#include <stdio.h> // for perror()
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>

#include <netinet/in.h> // for struct sockaddr_in
#include <arpa/inet.h> // for inet_pton

#include <string.h>

int main(int argc, char **argv)
{
	int server_sock_fd;
	int rc;
	int done = 0;
	int port;

	if (argc != 2) {
		fprintf(stderr, "Usage: ./arithmetic_server <port>\n");
		exit(1);
	}
	port = atoi(argv[1]);

	server_sock_fd = socket(PF_INET, SOCK_STREAM, 0);
	if (server_sock_fd < 0) {
		perror("Couldn't create socket");
		exit(1);
	}

	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

	rc = bind(
		server_sock_fd,
		(struct sockaddr *) &server_addr,
		sizeof(server_addr));
	if (rc < 0) {
		perror("Couldn't bind server socket");
		exit(1);
	}

	rc = listen(server_sock_fd, 5);
	if (rc < 0) {
		perror("Couldn't listen on server socket");
		exit(1);
	}

	while (!done) {
		// TODO: accept incoming connections, read requests, send back results

	}

	close(server_sock_fd);

	return 0;
}
