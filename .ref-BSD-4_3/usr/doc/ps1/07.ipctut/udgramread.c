begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986 Regents of the University of California. .\" All rights reserved.  The Berkeley software License Agreement .\" specifies the terms and conditions for redistribution. .\" .\"	@(#)udgramread.c	6.3 (Berkeley) 5/8/86 .\" #include<sys/types.h> #include<sys/socket.h> #include<sys/un.h>  /*  * In the included file<sys/un.h> a sockaddr_un is defined as follows  * struct sockaddr_un {  *	short	sun_family;  *	char	sun_path[108];  * };   */  #include<stdio.h>  #define NAME "
name|socket
literal|"  /*  * This program creates a UNIX domain datagram socket, binds a name to it,  * then reads from the socket.   */ main() { 	int sock, length; 	struct sockaddr_un name; 	char buf[1024];  	/* Create socket from which to read. */ 	sock = socket(AF_UNIX, SOCK_DGRAM, 0); 	if (sock< 0) { 		perror("
name|opening
name|datagram
name|socket
literal|"); 		exit(1); 	} 	/* Create name. */ 	name.sun_family = AF_UNIX; 	strcpy(name.sun_path, NAME); 	if (bind(sock,&name, sizeof(struct sockaddr_un))) { 		perror("
name|binding
name|name
name|to
name|datagram
name|socket
literal|"); 		exit(1); 	} 	printf("
name|socket
operator|--
operator|>
operator|%
name|s
operator|\
name|en
literal|", NAME); 	/* Read from the socket */ 	if (read(sock, buf, 1024)< 0) 		perror("
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

unit|, buf); 	close(sock); 	unlink(NAME); }
end_unit

