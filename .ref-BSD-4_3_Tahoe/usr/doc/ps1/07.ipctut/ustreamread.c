begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986 Regents of the University of California. .\" All rights reserved.  The Berkeley software License Agreement .\" specifies the terms and conditions for redistribution. .\" .\"	@(#)ustreamread.c	6.3 (Berkeley) 5/8/86 .\" #include<sys/types.h> #include<sys/socket.h> #include<sys/un.h> #include<stdio.h>  #define NAME "
name|socket
literal|"  /*  * This program creates a socket in the UNIX domain and binds a name to it.   * After printing the socket's name it begins a loop. Each time through the  * loop it accepts a connection and prints out messages from it.  When the  * connection breaks, or a termination message comes through, the program  * accepts a new connection.   */ main() { 	int sock, msgsock, rval; 	struct sockaddr_un server; 	char buf[1024];  	/* Create socket */ 	sock = socket(AF_UNIX, SOCK_STREAM, 0); 	if (sock< 0) { 		perror("
name|opening
name|stream
name|socket
literal|"); 		exit(1); 	} 	/* Name socket using file system name */ 	server.sun_family = AF_UNIX; 	strcpy(server.sun_path, NAME); 	if (bind(sock,&server, sizeof(struct sockaddr_un))) { 		perror("
name|binding
name|stream
name|socket
literal|"); 		exit(1); 	} 	printf("
name|Socket
name|has
name|name
operator|%
name|s
operator|\
name|en
literal|", server.sun_path); 	/* Start accepting connections */ 	listen(sock, 5); 	for (;;) { 		msgsock = accept(sock, 0, 0); 		if (msgsock == -1) 			perror("
name|accept
literal|"); 		else do { 			bzero(buf, sizeof(buf)); 			if ((rval = read(msgsock, buf, 1024))< 0) 				perror("
name|reading
name|stream
name|message
literal|"); 			else if (rval == 0) 				printf("
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
literal|"
end_expr_stmt

unit|, buf); 		} while (rval> 0); 		close(msgsock); 	} 	/* 	 * The following statements are not executed, because they follow an 	 * infinite loop.  However, most ordinary programs will not run 	 * forever.  In the UNIX domain it is necessary to tell the file 	 * system that one is through using NAME.  In most programs one uses 	 * the call unlink() as below. Since the user will have to kill this 	 * program, it will be necessary to remove the name by a command from 	 * the shell.  	 */ 	close(sock); 	unlink(NAME); }
end_unit

