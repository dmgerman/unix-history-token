begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986 Regents of the University of California. .\" All rights reserved.  The Berkeley software License Agreement .\" specifies the terms and conditions for redistribution. .\" .\"	@(#)dgramread.c	6.2 (Berkeley) %G% .\" #include<sys/types.h> #include<sys/socket.h> #include<netinet/in.h> #include<stdio.h>  /*  * In the included file<netinet/in.h> a sockaddr_in is defined as follows:  * struct sockaddr_in {  *	short	sin_family;  *	u_short	sin_port;  *	struct in_addr sin_addr;  *	char	sin_zero[8];  * };   *  * This program creates a datagram socket, binds a name to it, then reads  * from the socket.    */ main() { 	int             sock, length; 	struct sockaddr_in name; 	char            buf[1024];  	/* Create socket from which to read. */ 	sock = socket(AF_INET, SOCK_DGRAM, 0); 	if (sock< 0) { 		perror("
name|opening
name|datagram
name|socket
literal|"); 		exit(-1); 	} 	/* Create name with wildcards. */ 	name.sin_family = AF_INET; 	name.sin_addr.s_addr = INADDR_ANY; 	name.sin_port = 0; 	if (bind(sock,&name, sizeof(name))) { 		close(sock); 		perror("
name|binding
name|datagram
name|socket
literal|"); 	} 	/* Find assigned port value and print it out. */ 	length = sizeof(name); 	if (getsockname(sock,&name,&length)) { 		close(sock); 		perror("
name|getting
name|socket
name|name
literal|"); 	} 	printf("
name|Socket
name|has
name|port
operator|#
operator|%
name|d
operator|\
name|en
literal|", ntohs(name.sin_port)); 	/* Read from the socket */ 	if (read(sock, buf, 1024, 0)< 0) 		perror("
name|receiving
name|datagram
name|packet
literal|"); 	printf("
operator|--
operator|>
operator|%
name|s
operator|\
name|en
literal|"
end_expr_stmt

unit|, buf); 	close(sock); }
end_unit

