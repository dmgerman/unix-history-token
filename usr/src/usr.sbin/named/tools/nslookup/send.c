begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)send.c	5.17 (Berkeley) 6/29/90"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  *******************************************************************************  *  *  send.c --  *  *	Routine to send request packets to a name server.  *  *	Based on "@(#)res_send.c  6.25 (Berkeley) 6/1/90".  *  *******************************************************************************  */
end_comment

begin_comment
comment|/*  * Send query to name server and wait for reply.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<resolv.h>
end_include

begin_include
include|#
directive|include
file|"res.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|s
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket used for communications */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SET
end_ifndef

begin_define
define|#
directive|define
name|NFDBITS
value|32
end_define

begin_define
define|#
directive|define
name|FD_SETSIZE
value|32
end_define

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS] |= (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]&= ~(1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]& (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|bzero((char *)(p), sizeof(*(p)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SR
value|1
end_define

begin_comment
comment|/* SendRequest style */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|unsigned
name|short
name|nsport
init|=
name|NAMESERVER_PORT
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  *******************************************************************************  *  *   SendRequest --  *  *	Sends a request packet to a name server whose address  *	is specified by the first argument and returns with  *	the answer packet.  *  *  Results:  *	SUCCESS		- the request was sent and an answer  *			  was received.  *	TIME_OUT	- the virtual circuit connection timed-out  *			  or a reply to a datagram wasn't received.  *  *  *******************************************************************************  */
end_comment

begin_function
name|int
name|SendRequest
parameter_list|(
name|nsAddrPtr
parameter_list|,
name|buf
parameter_list|,
name|buflen
parameter_list|,
name|answer
parameter_list|,
name|anslen
parameter_list|,
name|trueLenPtr
parameter_list|)
name|struct
name|in_addr
modifier|*
name|nsAddrPtr
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|buflen
decl_stmt|;
name|char
modifier|*
name|answer
decl_stmt|;
name|u_int
name|anslen
decl_stmt|;
name|int
modifier|*
name|trueLenPtr
decl_stmt|;
block|{
specifier|register
name|int
name|n
decl_stmt|;
name|int
name|try
decl_stmt|,
name|v_circuit
decl_stmt|,
name|resplen
decl_stmt|,
name|ns
decl_stmt|;
name|int
name|gotsomewhere
init|=
literal|0
decl_stmt|,
name|connected
init|=
literal|0
decl_stmt|;
name|int
name|connreset
init|=
literal|0
decl_stmt|;
name|u_short
name|id
decl_stmt|,
name|len
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|fd_set
name|dsmask
decl_stmt|;
name|struct
name|timeval
name|timeout
decl_stmt|;
name|HEADER
modifier|*
name|hp
init|=
operator|(
name|HEADER
operator|*
operator|)
name|buf
decl_stmt|;
name|HEADER
modifier|*
name|anhp
init|=
operator|(
name|HEADER
operator|*
operator|)
name|answer
decl_stmt|;
name|struct
name|iovec
name|iov
index|[
literal|2
index|]
decl_stmt|;
name|int
name|terrno
init|=
name|ETIMEDOUT
decl_stmt|;
name|char
name|junk
index|[
literal|512
index|]
decl_stmt|;
if|#
directive|if
name|SR
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
if|if
condition|(
name|_res
operator|.
name|options
operator|&
name|RES_DEBUG2
condition|)
block|{
name|printf
argument_list|(
literal|"------------\nSendRequest(), len %d\n"
argument_list|,
name|buflen
argument_list|)
expr_stmt|;
name|Print_query
argument_list|(
name|buf
argument_list|,
name|buf
operator|+
name|buflen
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|sin
operator|.
name|sin_family
operator|=
name|AF_INET
expr_stmt|;
name|sin
operator|.
name|sin_port
operator|=
name|htons
argument_list|(
name|nsport
argument_list|)
expr_stmt|;
name|sin
operator|.
name|sin_addr
operator|=
operator|*
name|nsAddrPtr
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|_res
operator|.
name|options
operator|&
name|RES_DEBUG
condition|)
block|{
name|printf
argument_list|(
literal|"res_send()\n"
argument_list|)
expr_stmt|;
name|p_query
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|DEBUG
if|if
condition|(
operator|!
operator|(
name|_res
operator|.
name|options
operator|&
name|RES_INIT
operator|)
condition|)
if|if
condition|(
name|res_init
argument_list|()
operator|==
operator|-
literal|1
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* SR */
name|v_circuit
operator|=
operator|(
name|_res
operator|.
name|options
operator|&
name|RES_USEVC
operator|)
operator|||
name|buflen
operator|>
name|PACKETSZ
expr_stmt|;
name|id
operator|=
name|hp
operator|->
name|id
expr_stmt|;
comment|/* 	 * Send request, RETRY times, or until successful 	 */
for|for
control|(
name|try
operator|=
literal|0
init|;
name|try
operator|<
name|_res
operator|.
name|retry
condition|;
name|try
operator|++
control|)
block|{
if|#
directive|if
operator|!
name|SR
for|for
control|(
name|ns
operator|=
literal|0
init|;
name|ns
operator|<
name|_res
operator|.
name|nscount
condition|;
name|ns
operator|++
control|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|_res
operator|.
name|options
operator|&
name|RES_DEBUG
condition|)
name|printf
argument_list|(
literal|"Querying server (# %d) address = %s\n"
argument_list|,
name|ns
operator|+
literal|1
argument_list|,
name|inet_ntoa
argument_list|(
name|_res
operator|.
name|nsaddr_list
index|[
name|ns
index|]
operator|.
name|sin_addr
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
endif|#
directive|endif
comment|/* !SR */
name|usevc
label|:
if|if
condition|(
name|v_circuit
condition|)
block|{
name|int
name|truncated
init|=
literal|0
decl_stmt|;
comment|/* 			 * Use virtual circuit; 			 * at most one attempt per server. 			 */
name|try
operator|=
name|_res
operator|.
name|retry
expr_stmt|;
if|if
condition|(
name|s
operator|<
literal|0
condition|)
block|{
name|s
operator|=
name|socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_STREAM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|<
literal|0
condition|)
block|{
name|terrno
operator|=
name|errno
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|_res
operator|.
name|options
operator|&
name|RES_DEBUG
condition|)
name|perror
argument_list|(
literal|"socket (vc) failed"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
continue|continue;
block|}
if|#
directive|if
name|SR
if|if
condition|(
name|connect
argument_list|(
argument|s
argument_list|,
argument|&sin
argument_list|,
else|#
directive|else
argument|if (connect(s,&(_res.nsaddr_list[ns]),
endif|#
directive|endif
argument|sizeof(struct sockaddr))<
literal|0
argument|) { 					terrno = errno;
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 					    perror(
literal|"connect failed"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|(void) close(s); 					s = -
literal|1
argument|; 					continue; 				} 			}
comment|/* 			 * Send length& message 			 */
argument|len = htons((u_short)buflen); 			iov[
literal|0
argument|].iov_base = (caddr_t)&len; 			iov[
literal|0
argument|].iov_len = sizeof(len); 			iov[
literal|1
argument|].iov_base = buf; 			iov[
literal|1
argument|].iov_len = buflen; 			if (writev(s, iov,
literal|2
argument|) != sizeof(len) + buflen) { 				terrno = errno;
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 					perror(
literal|"write failed"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|(void) close(s); 				s = -
literal|1
argument|; 				continue; 			}
comment|/* 			 * Receive length& response 			 */
argument|cp = answer; 			len = sizeof(short); 			while (len !=
literal|0
argument|&& 			    (n = read(s, (char *)cp, (int)len))>
literal|0
argument|) { 				cp += n; 				len -= n; 			} 			if (n<=
literal|0
argument|) { 				terrno = errno;
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 					perror(
literal|"read failed"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|(void) close(s); 				s = -
literal|1
argument|;
comment|/* 				 * A long running process might get its TCP 				 * connection reset if the remote server was 				 * restarted.  Requery the server instead of 				 * trying a new one.  When there is only one 				 * server, this means that a query might work 				 * instead of failing.  We only allow one reset 				 * per query to prevent looping. 				 */
argument|if (terrno == ECONNRESET&& !connreset) { 					connreset =
literal|1
argument|; 					ns--; 				} 				continue; 			} 			cp = answer; 			if ((resplen = ntohs(*(u_short *)cp))> anslen) {
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 					fprintf(stderr,
literal|"response truncated\n"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|len = anslen; 				truncated =
literal|1
argument|; 			} else 				len = resplen; 			while (len !=
literal|0
argument|&& 			   (n = read(s, (char *)cp, (int)len))>
literal|0
argument|) { 				cp += n; 				len -= n; 			} 			if (n<=
literal|0
argument|) { 				terrno = errno;
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 					perror(
literal|"read failed"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|(void) close(s); 				s = -
literal|1
argument|; 				continue; 			} 			if (truncated) {
comment|/* 				 * Flush rest of answer 				 * so connection stays in synch. 				 */
argument|anhp->tc =
literal|1
argument|; 				len = resplen - anslen; 				while (len !=
literal|0
argument|) { 					n = (len> sizeof(junk) ? 					    sizeof(junk) : len); 					if ((n = read(s, junk, n))>
literal|0
argument|) 						len -= n; 					else 						break; 				} 			} 		} else {
comment|/* 			 * Use datagrams. 			 */
argument|if (s<
literal|0
argument|) { 				s = socket(AF_INET, SOCK_DGRAM,
literal|0
argument|); 				if (s<
literal|0
argument|) { 					terrno = errno;
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 					    perror(
literal|"socket (dg) failed"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|continue; 				} 			}
if|#
directive|if
name|SR
comment|/* 			 * Special case the send code below 			 * since we have just 1 server. 			 */
if|#
directive|if
name|BSD
operator|>=
literal|43
argument|if (connected ==
literal|0
argument|) { 					if (connect(s,&sin, 					    sizeof(struct sockaddr))<
literal|0
argument|) { 						if (_res.options& RES_DEBUG) 							perror(
literal|"connect"
argument|); 						continue; 					} 					connected =
literal|1
argument|; 				} 				if (send(s, buf, buflen,
literal|0
argument|) != buflen) { 					if (_res.options& RES_DEBUG) 						perror(
literal|"send"
argument|); 					continue; 				}
else|#
directive|else
comment|/* BSD */
argument|if (sendto(s, buf, buflen,
literal|0
argument|,&sin, 				    sizeof(struct sockaddr)) != buflen) { 					if (_res.options& RES_DEBUG) 						perror(
literal|"sendto"
argument|); 					continue; 				}
endif|#
directive|endif
else|#
directive|else
comment|/* SR */
if|#
directive|if
name|BSD
operator|>=
literal|43
comment|/* 			 * I'm tired of answering this question, so: 			 * On a 4.3BSD+ machine (client and server, 			 * actually), sending to a nameserver datagram 			 * port with no nameserver will cause an 			 * ICMP port unreachable message to be returned. 			 * If our datagram socket is "connected" to the 			 * server, we get an ECONNREFUSED error on the next 			 * socket operation, and select returns if the 			 * error message is received.  We can thus detect 			 * the absence of a nameserver without timing out. 			 * If we have sent queries to at least two servers, 			 * however, we don't want to remain connected, 			 * as we wish to receive answers from the first 			 * server to respond. 			 */
argument|if (_res.nscount ==
literal|1
argument||| (try ==
literal|0
argument|&& ns ==
literal|0
argument|)) {
comment|/* 				 * Don't use connect if we might 				 * still receive a response 				 * from another server. 				 */
argument|if (connected ==
literal|0
argument|) { 					if (connect(s,&_res.nsaddr_list[ns], 					    sizeof(struct sockaddr))<
literal|0
argument|) {
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 							perror(
literal|"connect"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|continue; 					} 					connected =
literal|1
argument|; 				} 				if (send(s, buf, buflen,
literal|0
argument|) != buflen) {
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 						perror(
literal|"send"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|continue; 				} 			} else {
comment|/* 				 * Disconnect if we want to listen 				 * for responses from more than one server. 				 */
argument|if (connected) { 					(void) connect(s,&no_addr, 					    sizeof(no_addr)); 					connected =
literal|0
argument|; 				}
endif|#
directive|endif
endif|BSD
argument|if (sendto(s, buf, buflen,
literal|0
argument|,&_res.nsaddr_list[ns], 				    sizeof(struct sockaddr)) != buflen) {
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 						perror(
literal|"sendto"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|continue; 				}
if|#
directive|if
name|BSD
operator|>=
literal|43
argument|}
endif|#
directive|endif
endif|#
directive|endif
comment|/* SR */
comment|/* 			 * Wait for reply 			 */
argument|timeout.tv_sec = (_res.retrans<< try);
if|#
directive|if
operator|!
name|SR
argument|if (try>
literal|0
argument|) 				timeout.tv_sec /= _res.nscount;
endif|#
directive|endif
comment|/* SR */
argument|if (timeout.tv_sec<=
literal|0
argument|) 				timeout.tv_sec =
literal|1
argument|; 			timeout.tv_usec =
literal|0
argument|; wait: 			FD_ZERO(&dsmask); 			FD_SET(s,&dsmask); 			n = select(s+
literal|1
argument|,&dsmask, (fd_set *)NULL, 				(fd_set *)NULL,&timeout); 			if (n<
literal|0
argument|) {
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 					perror(
literal|"select"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|continue; 			} 			if (n ==
literal|0
argument|) {
comment|/* 				 * timeout 				 */
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 					printf(
literal|"timeout (%d secs)\n"
argument|,  						timeout.tv_sec);
endif|#
directive|endif
endif|DEBUG
if|#
directive|if
name|BSD
operator|>=
literal|43
argument|gotsomewhere =
literal|1
argument|;
endif|#
directive|endif
argument|continue; 			} 			if ((resplen = recv(s, answer, anslen,
literal|0
argument|))<=
literal|0
argument|) {
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 					perror(
literal|"recvfrom"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|continue; 			} 			gotsomewhere =
literal|1
argument|; 			if (id != anhp->id) {
comment|/* 				 * response from old query, ignore it 				 */
if|#
directive|if
name|SR
argument|if (_res.options& RES_DEBUG2) { 					printf(
literal|"------------\nOld answer:\n"
argument|); 					Print_query(answer, answer+resplen,
literal|1
argument|); 				}
else|#
directive|else
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) { 					printf(
literal|"old answer:\n"
argument|); 					p_query(answer); 				}
endif|#
directive|endif
endif|DEBUG
endif|#
directive|endif
argument|goto wait; 			} 			if (!(_res.options& RES_IGNTC)&& anhp->tc) {
comment|/* 				 * get rest of answer; 				 * use TCP with same server. 				 */
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) 					printf(
literal|"truncated answer\n"
argument|);
endif|#
directive|endif
endif|DEBUG
argument|(void) close(s); 				s = -
literal|1
argument|; 				v_circuit =
literal|1
argument|; 				goto usevc; 			} 		}
if|#
directive|if
name|SR
argument|if (_res.options& RES_DEBUG) { 		    if (_res.options& RES_DEBUG2) 			printf(
literal|"------------\nGot answer (%d bytes):\n"
argument|, 			    resplen); 		    else 			printf(
literal|"------------\nGot answer:\n"
argument|); 		    Print_query(answer, answer+resplen,
literal|1
argument|); 		} 		(void) close(s); 		s = -
literal|1
argument|; 		*trueLenPtr = resplen; 		return (SUCCESS);
else|#
directive|else
ifdef|#
directive|ifdef
name|DEBUG
argument|if (_res.options& RES_DEBUG) { 			printf(
literal|"got answer:\n"
argument|); 			p_query(answer); 		}
endif|#
directive|endif
endif|DEBUG
comment|/* 		 * If using virtual circuits, we assume that the first server 		 * is preferred * over the rest (i.e. it is on the local 		 * machine) and only keep that one open. 		 * If we have temporarily opened a virtual circuit, 		 * or if we haven't been asked to keep a socket open, 		 * close the socket. 		 */
argument|if ((v_circuit&& 		    ((_res.options& RES_USEVC) ==
literal|0
argument||| ns !=
literal|0
argument|)) || 		    (_res.options& RES_STAYOPEN) ==
literal|0
argument|) { 			(void) close(s); 			s = -
literal|1
argument|; 		} 		return (resplen); 	   }
endif|#
directive|endif
comment|/* SR */
argument|} 	if (s>=
literal|0
argument|) { 		(void) close(s); 		s = -
literal|1
argument|; 	}
if|#
directive|if
name|SR
argument|if (v_circuit ==
literal|0
argument|) 		if (gotsomewhere ==
literal|0
argument|) 			return NO_RESPONSE;
comment|/* no nameservers found */
argument|else 			return TIME_OUT;
comment|/* no answer obtained */
argument|else 		if (errno == ECONNREFUSED) 			return NO_RESPONSE; 		else 			return ERROR;
else|#
directive|else
argument|if (v_circuit ==
literal|0
argument|) 		if (gotsomewhere ==
literal|0
argument|) 			errno = ECONNREFUSED;
comment|/* no nameservers found */
argument|else 			errno = ETIMEDOUT;
comment|/* no answer obtained */
argument|else 		errno = terrno; 	return (-
literal|1
argument|);
endif|#
directive|endif
argument|}
comment|/*  * This routine is for closing the socket if a virtual circuit is used and  * the program wants to close it.  *  * Called from the interrupt handler.  */
argument|SendRequest_close() { 	if (s != -
literal|1
argument|) { 		(void) close(s); 		s = -
literal|1
argument|; 	} }
end_function

end_unit

