begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986 Regents of the University of California. .\" All rights reserved.  The Berkeley software License Agreement .\" specifies the terms and conditions for redistribution. .\" .\"	@(#)socketpair.c	6.2 (Berkeley) 5/8/86 .\" #include<sys/types.h> #include<sys/socket.h> #include<stdio.h>  #define DATA1 "
name|In
name|Xanadu
operator|,
name|did
name|Kublai
name|Khan
operator|.
expr|.
operator|.
literal|" #define DATA2 "
name|A
name|stately
name|pleasure
name|dome
name|decree
operator|.
expr|.
operator|.
literal|"  /*  * This program creates a pair of connected sockets then forks and  * communicates over them.  This is very similar to communication with pipes,  * however, socketpairs are two-way communications objects. Therefore I can  * send messages in both directions.   */  main() { 	int sockets[2], child; 	char buf[1024];  	if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets)< 0) { 		perror("
name|opening
name|stream
name|socket
name|pair
literal|"); 		exit(1); 	}  	if ((child = fork()) == -1) 		perror("
name|fork
literal|"); 	else if (child) {	/* This is the parent. */ 		close(sockets[0]); 		if (read(sockets[1], buf, 1024, 0)< 0) 			perror("
name|reading
name|stream
name|message
literal|"); 		printf("
operator|--
operator|>
operator|%
name|s
operator|\
name|en
literal|", buf); 		if (write(sockets[1], DATA2, sizeof(DATA2))< 0) 			perror("
name|writing
name|stream
name|message
literal|"); 		close(sockets[1]); 	} else {		/* This is the child. */ 		close(sockets[1]); 		if (write(sockets[0], DATA1, sizeof(DATA1))< 0) 			perror("
name|writing
name|stream
name|message
literal|"); 		if (read(sockets[0], buf, 1024, 0)< 0) 			perror("
name|reading
name|stream
name|message
literal|"); 		printf("
operator|--
operator|>
operator|%
name|s
operator|\
name|en
literal|"
end_expr_stmt

unit|, buf); 		close(sockets[0]); 	} }
end_unit

