begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986 Regents of the University of California. .\" All rights reserved.  The Berkeley software License Agreement .\" specifies the terms and conditions for redistribution. .\" .\"	@(#)ustreamwrite.c	6.3 (Berkeley) 5/8/86 .\" #include<sys/types.h> #include<sys/socket.h> #include<sys/un.h> #include<stdio.h>  #define DATA "
name|Half
name|a
name|league
operator|,
name|half
name|a
name|league
operator|.
expr|.
operator|.
literal|"  /*  * This program connects to the socket named in the command line and sends a  * one line message to that socket. The form of the command line is  * ustreamwrite pathname   */ main(argc, argv) 	int argc; 	char *argv[]; { 	int sock; 	struct sockaddr_un server; 	char buf[1024];  	/* Create socket */ 	sock = socket(AF_UNIX, SOCK_STREAM, 0); 	if (sock< 0) { 		perror("
name|opening
name|stream
name|socket
literal|"); 		exit(1); 	} 	/* Connect socket using name specified by command line. */ 	server.sun_family = AF_UNIX; 	strcpy(server.sun_path, argv[1]);  	if (connect(sock,&server, sizeof(struct sockaddr_un))< 0) { 		close(sock); 		perror("
name|connecting
name|stream
name|socket
literal|"); 		exit(1); 	} 	if (write(sock, DATA, sizeof(DATA))< 0) 		perror("
name|writing
name|on
name|stream
name|socket
literal|"
end_expr_stmt

unit|); }
end_unit

