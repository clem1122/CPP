#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include "base.h"

struct data {
	int * fd;
	char * msg;
}

void * hconnect (void * data)
{
	
	int f = *((int *)data.fd);
	snprintf(tmp, sizeof(tmp), data.msg);
	
	size_t len = strlen(tmp);
	ssize_t size;
	size = write(f, &len, sizeof(len));
	if (size != sizeof(len));
	size = write(f, tmp, 1 + strlen(tmp));
	close(f);

	free(fd);
	pthread_detach(pthread_self());
	return NULL;	
}

int main (int argc, char ** argv)

{
        const char * server = "0.0.0.0";
        struct sockaddr_in sin;
        int s, f, ret;
	pthread_t tid;
	int optval = 1;

        sin.sin_family = AF_INET;
        sin.sin_port = htons(DEFAULT_PORT);
        ret = inet_aton(server, &sin.sin_addr);
        if (ret == 0) {
		fprintf(stderr, "address %s invalid\n", server);
		return 0;
	}

        s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (s < 0) {
		fprintf(stderr, "cannot create socket\n");
		return 0;
	}

        ret = setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
        if (ret != 0) {
                fprintf(stderr, "setsockopt() failed\n");
                return 0;
        }

        ret = bind(s, (struct sockaddr *)&sin, sizeof(sin));
        if (ret != 0) {
		fprintf(stderr, "bind() failed\n");
		return 0;
	}

        ret = listen(s, 10);
        if (ret != 0) {
		fprintf(stderr, "listen() failed\n");
		return 0;
	}

        while (1) {
                f = accept(s, NULL, 0);
                if (f == -1) {
			fprintf(stderr, "accept() failed\n");
			return 0;
		}

		int * fd = new int;
		*fd = f;
		pthread_create(&tid, NULL, hconnect, (void *)fd);
        }

        return 0;
}
     
