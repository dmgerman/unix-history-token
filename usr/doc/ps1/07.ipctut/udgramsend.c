begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986 Regents of the University of California. .\" All rights reserved.  The Berkeley software License Agreement .\" specifies the terms and conditions for redistribution. .\" .\"	@(#)udgramsend.c	6.2 (Berkeley) 5/8/86 .\" #include<sys/types.h> #include<sys/socket.h> #include<sys/un.h> #include<stdio.h>  #define DATA "
name|The
name|sea
name|is
name|calm
name|tonight
operator|,
name|the
name|tide
name|is
name|full
operator|.
expr|.
operator|.
literal|"  /*  * Here I send a datagram to a receiver whose name I get from the command  * line arguments.  The form of the command line is udgramsend pathname   */  main(argc, argv) 	int argc; 	char *argv[]; { 	int sock; 	struct sockaddr_un name;  	/* Create socket on which to send. */ 	sock = socket(AF_UNIX, SOCK_DGRAM, 0); 	if (sock< 0) { 		perror("
name|opening
name|datagram
name|socket
literal|"); 		exit(1); 	} 	/* Construct name of socket to send to. */ 	name.sun_family = AF_UNIX; 	strcpy(name.sun_path, argv[1]); 	/* Send message. */ 	if (sendto(sock, DATA, sizeof(DATA), 0,&name, sizeof(struct sockaddr_un))< 0) { 		perror("
name|sending
name|datagram
name|message
literal|"
end_expr_stmt

unit|); 	} 	close(sock); }
end_unit

