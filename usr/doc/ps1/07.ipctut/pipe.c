begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986 Regents of the University of California. .\" All rights reserved.  The Berkeley software License Agreement .\" specifies the terms and conditions for redistribution. .\" .\"	@(#)pipe.c	6.2 (Berkeley) 5/8/86 .\" #include<stdio.h>  #define DATA "
name|Bright
name|star
operator|,
name|would
name|I
name|were
name|steadfast
name|as
name|thou
name|art
operator|.
expr|.
operator|.
literal|"  /*  * This program creates a pipe, then forks.  The child communicates to the  * parent over the pipe. Notice that a pipe is a one-way communications  * device.  I can write to the output socket (sockets[1], the second socket  * of the array returned by pipe()) and read from the input socket  * (sockets[0]), but not vice versa.   */  main() { 	int sockets[2], child;  	/* Create a pipe */ 	if (pipe(sockets)< 0) { 		perror("
name|opening
name|stream
name|socket
name|pair
literal|"); 		exit(10); 	}  	if ((child = fork()) == -1) 		perror("
name|fork
literal|"); 	else if (child) { 		char buf[1024];  		/* This is still the parent.  It reads the child's message. */ 		close(sockets[1]); 		if (read(sockets[0], buf, 1024)< 0) 			perror("
name|reading
name|message
literal|"); 		printf("
operator|--
operator|>
operator|%
name|s
operator|\
name|en
literal|", buf); 		close(sockets[0]); 	} else { 		/* This is the child.  It writes a message to its parent. */ 		close(sockets[0]); 		if (write(sockets[1], DATA, sizeof(DATA))< 0) 			perror("
name|writing
name|message
literal|"
end_expr_stmt

unit|); 		close(sockets[1]); 	} }
end_unit

