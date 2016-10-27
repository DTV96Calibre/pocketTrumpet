#include "wrappers.h"	/* Include the header */
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <semaphore.h>

pid_t Fork(void){
	pid_t pid = fork();
	if (-1 == pid) {
		perror("Fork error");
		exit(-1);
	} else {
		return pid;
	}
}

int Pipe(int pipefd[2]) {
	int ret = pipe(pipefd);
	if (-1 == ret) {
		perror("Pipe error");
		exit(-1);
	} else {
		return ret;
	}
}

pid_t Wait(int *status) {
	pid_t ret = wait(status);
	if (-1 == ret) {
		perror("Wait error");
		exit(-1);
	} else {
		return ret;
	}
}

int Open(const char *pathname, int flags){
	int ret = open(pathname, flags);
	if (-1 == ret) {
		perror("Open error");
		exit(-1);
	} else {
		return ret;
	}
}
/*
int Open(const char *pathname, int flags, mode_t mode){
	int ret = open(pathname, flags, mode);
	if (-1 == ret) {
		perror("Open error");
		exit(-1);
	} else {
		return ret;
	}
}*/

int Close(int fd){
	int ret = close(fd);
	if (-1 == ret) {
		perror("Close error");
		exit(-1);
	} else {
		return ret;
	}
}

pid_t Waitpid(pid_t pid, int *status, int options) {
	pid_t ret = Waitpid(pid, status, options);
	if (-1 == ret) {
		perror("Waitpid error");
		exit(-1);
	} else {
		return ret;
	}
}

ssize_t Write(int fd, const void *buf, size_t count) {
	ssize_t ret = write(fd, buf, count);
	if (-1 == ret) {
		perror("Write error");
		exit(-1);
	} else {
		return ret;
	}
}

ssize_t Read(int fd, void *buf, size_t count) {
	ssize_t ret = read(fd, buf, count);
	if (-1 == ret) {
		perror("Read error");
		exit(-1);
	}
	return ret;
}

int Socket(int domain, int type, int protocol) {
	int ret = socket(domain, type, protocol);
	if (-1 == ret) {
		perror("Socket error");
		exit(-1);
	}
	return ret;
}

int Connect(int sockfd, const struct sockaddr *addr,
							 socklen_t addrlen) {
	int ret = connect(sockfd, addr, addrlen);
	if (-1 == ret) {
		perror("Connect error");
		exit(-1);
	}
	return ret;
}

ssize_t Send(int sockfd, const void *buf, size_t len, int flags) {
	ssize_t ret = send(sockfd, buf, len, flags);
	if (-1 == ret) {
		perror("Send error");
		exit(-1);
	}
	return ret;
}

int Bind(int sockfd, const struct sockaddr *addr,
							 socklen_t addrlen) {
	int ret = bind(sockfd, addr, addrlen);
	if (-1 == ret) {
		perror("Bind error");
		exit(-1);
	}
	return ret;
}

int Listen(int sockfd, int backlog) {
	int ret = listen(sockfd, backlog);
	if (-1 == ret) {
		perror("Listen error");
		exit(-1);
	}
	return ret;
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
	int ret = accept(sockfd, addr, addrlen);
	if (-1 == ret) {
		perror("Accept error");
		exit(-1);
	}
	return ret;
}

int Pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg) {
  int ret = pthread_create(thread, attr, start_routine, arg);
  if (0 != ret) {
    perror("Thread creation error");
		exit(ret);
  }
  return ret;
}

int Sem_wait(sem_t *sem) {
	int ret = sem_wait(sem);
	if(0 != ret) {
		perror("Error waiting on semaphore");
		exit(-1);
	}
	return ret;
}
