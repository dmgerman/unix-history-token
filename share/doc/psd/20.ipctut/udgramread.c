begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1986, 1993 .\"	The Regents of the University of California.  All rights reserved. .\" .\" Redistribution and use in source and binary forms, with or without .\" modification, are permitted provided that the following conditions .\" are met: .\" 1. Redistributions of source code must retain the above copyright .\"    notice, this list of conditions and the following disclaimer. .\" 2. Redistributions in binary form must reproduce the above copyright .\"    notice, this list of conditions and the following disclaimer in the .\"    documentation and/or other materials provided with the distribution. .\" 3. All advertising materials mentioning features or use of this software .\"    must display the following acknowledgement: .\"	This product includes software developed by the University of .\"	California, Berkeley and its contributors. .\" 4. Neither the name of the University nor the names of its contributors .\"    may be used to endorse or promote products derived from this software .\"    without specific prior written permission. .\" .\" THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND .\" ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE .\" IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE .\" ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE .\" FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL .\" DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS .\" OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) .\" HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT .\" LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY .\" OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF .\" SUCH DAMAGE. .\" .\"	@(#)udgramread.c	8.1 (Berkeley) 6/8/93 .\" #include<sys/types.h> #include<sys/socket.h> #include<sys/un.h>  /*  * In the included file<sys/un.h> a sockaddr_un is defined as follows  * struct sockaddr_un {  *	short	sun_family;  *	char	sun_path[108];  * };  */  #include<stdio.h>  #define NAME "
name|socket
literal|"  /*  * This program creates a UNIX domain datagram socket, binds a name to it,  * then reads from the socket.  */ main() { 	int sock, length; 	struct sockaddr_un name; 	char buf[1024];  	/* Create socket from which to read. */ 	sock = socket(AF_UNIX, SOCK_DGRAM, 0); 	if (sock< 0) { 		perror("
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

