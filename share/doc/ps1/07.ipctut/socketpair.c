begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986 The Regents of the University of California. .\" All rights reserved. .\" .\" Redistribution and use in source and binary forms, with or without .\" modification, are permitted provided that the following conditions .\" are met: .\" 1. Redistributions of source code must retain the above copyright .\"    notice, this list of conditions and the following disclaimer. .\" 2. Redistributions in binary form must reproduce the above copyright .\"    notice, this list of conditions and the following disclaimer in the .\"    documentation and/or other materials provided with the distribution. .\" 3. All advertising materials mentioning features or use of this software .\"    must display the following acknowledgement: .\"	This product includes software developed by the University of .\"	California, Berkeley and its contributors. .\" 4. Neither the name of the University nor the names of its contributors .\"    may be used to endorse or promote products derived from this software .\"    without specific prior written permission. .\" .\" THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND .\" ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE .\" IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE .\" ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE .\" FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL .\" DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS .\" OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) .\" HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT .\" LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY .\" OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF .\" SUCH DAMAGE. .\" .\"	from: @(#)socketpair.c	6.4 (Berkeley) 4/17/91 .\"	socketpair.c,v 1.2 1993/08/01 18:23:29 mycroft Exp .\" #include<sys/types.h> #include<sys/socket.h> #include<stdio.h>  #define DATA1 "
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

