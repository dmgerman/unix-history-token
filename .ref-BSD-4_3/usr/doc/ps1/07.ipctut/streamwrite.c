begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986 Regents of the University of California. .\" All rights reserved.  The Berkeley software License Agreement .\" specifies the terms and conditions for redistribution. .\" .\"	@(#)streamwrite.c	6.2 (Berkeley) 5/8/86 .\" #include<sys/types.h> #include<sys/socket.h> #include<netinet/in.h> #include<netdb.h> #include<stdio.h>  #define DATA "
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
literal|"  /*  * This program creates a socket and initiates a connection with the socket  * given in the command line.  One message is sent over the connection and  * then the socket is closed, ending the connection. The form of the command  * line is streamwrite hostname portnumber   */  main(argc, argv) 	int argc; 	char *argv[]; { 	int sock; 	struct sockaddr_in server; 	struct hostent *hp, *gethostbyname(); 	char buf[1024];  	/* Create socket */ 	sock = socket(AF_INET, SOCK_STREAM, 0); 	if (sock< 0) { 		perror("
name|opening
name|stream
name|socket
literal|"); 		exit(1); 	} 	/* Connect socket using name specified by command line. */ 	server.sin_family = AF_INET; 	hp = gethostbyname(argv[1]); 	if (hp == 0) { 		fprintf(stderr, "
operator|%
name|s
operator|:
name|unknown
name|host
operator|\
name|n
literal|", argv[1]); 		exit(2); 	} 	bcopy(hp->h_addr,&server.sin_addr, hp->h_length); 	server.sin_port = htons(atoi(argv[2]));  	if (connect(sock,&server, sizeof(server))< 0) { 		perror("
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

unit|); 	close(sock); }
end_unit

