begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986 Regents of the University of California. .\" All rights reserved.  The Berkeley software License Agreement .\" specifies the terms and conditions for redistribution. .\" .\"	@(#)streamread.c	6.2 (Berkeley) 5/8/86 .\" #include<sys/types.h> #include<sys/socket.h> #include<netinet/in.h> #include<netdb.h> #include<stdio.h> #define TRUE 1  /*  * This program creates a socket and then begins an infinite loop. Each time  * through the loop it accepts a connection and prints out messages from it.   * When the connection breaks, or a termination message comes through, the  * program accepts a new connection.   */  main() { 	int sock, length; 	struct sockaddr_in server; 	int msgsock; 	char buf[1024]; 	int rval; 	int i;  	/* Create socket */ 	sock = socket(AF_INET, SOCK_STREAM, 0); 	if (sock< 0) { 		perror("
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
literal|", ntohs(server.sin_port));  	/* Start accepting connections */ 	listen(sock, 5); 	do { 		msgsock = accept(sock, 0, 0); 		if (msgsock == -1) 			perror("
name|accept
literal|"); 		else do { 			bzero(buf, sizeof(buf)); 			if ((rval = read(msgsock, buf, 1024))< 0) 				perror("
name|reading
name|stream
name|message
literal|"); 			i = 0; 			if (rval == 0) 				printf("
name|Ending
name|connection
operator|\
name|en
literal|"); 			else 				printf("
operator|--
operator|>
operator|%
name|s
operator|\
name|en
literal|", buf); 		} while (rval != 0); 		close(msgsock); 	} while (TRUE); 	/* 	 * Since this program has an infinite loop, the socket "
name|sock
literal|"
end_expr_stmt

unit|is 	 * never explicitly closed.  However, all sockets will be closed 	 * automatically when a process is killed or terminates normally.  	 */ }
end_unit

