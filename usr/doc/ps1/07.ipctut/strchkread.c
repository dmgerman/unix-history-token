begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986 Regents of the University of California. .\" All rights reserved.  The Berkeley software License Agreement .\" specifies the terms and conditions for redistribution. .\" .\"	@(#)strchkread.c	6.2 (Berkeley) 5/8/86 .\" #include<sys/types.h> #include<sys/socket.h> #include<sys/time.h> #include<netinet/in.h> #include<netdb.h> #include<stdio.h> #define TRUE 1  /*  * This program uses select() to check that someone is trying to connect  * before calling accept().   */  main() { 	int sock, length; 	struct sockaddr_in server; 	int msgsock; 	char buf[1024]; 	int rval; 	fd_set ready; 	struct timeval to;  	/* Create socket */ 	sock = socket(AF_INET, SOCK_STREAM, 0); 	if (sock< 0) { 		perror("
name|opening
name|stream
name|socket
literal|"); 		exit(1); 	} 	/* Name socket using wildcards */ 	server.sin_family = AF_INET; 	server.sin_addr.s_addr = INADDR_ANY; 	server.sin_port = 0; 	if (bind(sock,&server, sizeof(server))) { 		perror("
name|binding
name|stream
name|socket
literal|"); 		exit(1); 	} 	/* Find out assigned port number and print it out */ 	length = sizeof(server); 	if (getsockname(sock,&server,&length)) { 		perror("
name|getting
name|socket
name|name
literal|"); 		exit(1); 	} 	printf("
name|Socket
name|has
name|port
operator|#
operator|%
name|d
operator|\
name|en
literal|", ntohs(server.sin_port));  	/* Start accepting connections */ 	listen(sock, 5); 	do { 		FD_ZERO(&ready); 		FD_SET(sock,&ready); 		to.tv_sec = 5; 		if (select(sock + 1,&ready, 0, 0,&to)< 0) { 			perror("
name|select
literal|"); 			continue; 		} 		if (FD_ISSET(sock,&ready)) { 			msgsock = accept(sock, (struct sockaddr *)0, (int *)0); 			if (msgsock == -1) 				perror("
name|accept
literal|"); 			else do { 				bzero(buf, sizeof(buf)); 				if ((rval = read(msgsock, buf, 1024))< 0) 					perror("
name|reading
name|stream
name|message
literal|"); 				else if (rval == 0) 					printf("
name|Ending
name|connection
operator|\
name|en
literal|"); 				else 					printf("
operator|--
operator|>
operator|%
name|s
operator|\
name|en
literal|", buf); 			} while (rval> 0); 			close(msgsock); 		} else 			printf("
name|Do
name|something
end_expr_stmt

begin_else
else|else
operator|\
name|en
literal|"
end_else

unit|); 	} while (TRUE); }
end_unit

