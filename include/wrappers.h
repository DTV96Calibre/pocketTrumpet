#ifndef WRAPPERS_H_	/* Include guard */
#define WRAPPERS_H_

#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <semaphore.h>


pid_t Fork(void);
int Pipe(int pipefd[2]);
pid_t Wait(int *status);
pid_t Waitpid(pid_t pid, int *status, int options);
int Open(const char *pathname, int flags);
//int Open(const char *pathname, int flags, mode_t mode);
int Close(int fd);
ssize_t Write(int fd, const void *buf, size_t count);
ssize_t Read(int fd, void *buf, size_t count);
int Socket(int domain, int type, int protocol);
int Connect(int sockfd, const struct sockaddr *addr,
                 socklen_t addrlen);
ssize_t Send(int sockfd, const void *buf, size_t len, int flags);
int Bind(int sockfd, const struct sockaddr *addr,
                 socklen_t addrlen);
int Listen(int sockfd, int backlog);

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int Pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                 void *(*start_routine) (void *), void *arg);
int Sem_wait(sem_t *sem);

#endif // WRAPPERS_H_
