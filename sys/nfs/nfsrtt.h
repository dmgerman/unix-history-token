begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsrtt.h	8.2 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSRTT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSRTT_H_
end_define

begin_comment
comment|/*  * Definitions for performance monitor.  * The client and server logging are turned on by setting the global  * constant "nfsrtton" to 1.  */
end_comment

begin_define
define|#
directive|define
name|NFSRTTLOGSIZ
value|128
end_define

begin_comment
comment|/*  * Circular log of client side rpc activity. Each log entry is for one  * rpc filled in upon completion. (ie. in order of completion)  * The "pos" is the table index for the "next" entry, therefore the  * list goes from nfsrtt.rttl[pos] --> nfsrtt.rttl[pos - 1] in  * chronological order of completion.  */
end_comment

begin_struct
struct|struct
name|nfsrtt
block|{
name|int
name|pos
decl_stmt|;
comment|/* Position in array for next entry */
struct|struct
name|rttl
block|{
name|u_int32_t
name|proc
decl_stmt|;
comment|/* NFS procedure number */
name|int
name|rtt
decl_stmt|;
comment|/* Measured round trip time */
name|int
name|rto
decl_stmt|;
comment|/* Round Trip Timeout */
name|int
name|sent
decl_stmt|;
comment|/* # rpcs in progress */
name|int
name|cwnd
decl_stmt|;
comment|/* Send window */
name|int
name|srtt
decl_stmt|;
comment|/* Ave Round Trip Time */
name|int
name|sdrtt
decl_stmt|;
comment|/* Ave mean deviation of RTT */
name|fsid_t
name|fsid
decl_stmt|;
comment|/* Fsid for mount point */
name|struct
name|timeval
name|tstamp
decl_stmt|;
comment|/* Timestamp of log entry */
block|}
name|rttl
index|[
name|NFSRTTLOGSIZ
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * And definitions for server side performance monitor.  * The log organization is the same as above except it is filled in at the  * time the server sends the rpc reply.  */
end_comment

begin_comment
comment|/*  * Bits for the flags field.  */
end_comment

begin_define
define|#
directive|define
name|DRT_NQNFS
value|0x01
end_define

begin_comment
comment|/* Rpc used Nqnfs protocol */
end_comment

begin_define
define|#
directive|define
name|DRT_TCP
value|0x02
end_define

begin_comment
comment|/* Client used TCP transport */
end_comment

begin_define
define|#
directive|define
name|DRT_CACHEREPLY
value|0x04
end_define

begin_comment
comment|/* Reply was from recent request cache */
end_comment

begin_define
define|#
directive|define
name|DRT_CACHEDROP
value|0x08
end_define

begin_comment
comment|/* Rpc request dropped, due to recent reply */
end_comment

begin_define
define|#
directive|define
name|DRT_NFSV3
value|0x10
end_define

begin_comment
comment|/* Rpc used NFS Version 3 */
end_comment

begin_comment
comment|/*  * Server log structure  * NB: ipadr == INADDR_ANY indicates a client using a non IP protocol.  *	(ISO perhaps?)  */
end_comment

begin_struct
struct|struct
name|nfsdrt
block|{
name|int
name|pos
decl_stmt|;
comment|/* Position of next log entry */
struct|struct
name|drt
block|{
name|int
name|flag
decl_stmt|;
comment|/* Bits as defined above */
name|u_int32_t
name|proc
decl_stmt|;
comment|/* NFS procedure number */
name|u_int32_t
name|ipadr
decl_stmt|;
comment|/* IP address of client */
name|int
name|resptime
decl_stmt|;
comment|/* Response time (usec) */
name|struct
name|timeval
name|tstamp
decl_stmt|;
comment|/* Timestamp of log entry */
block|}
name|drt
index|[
name|NFSRTTLOGSIZ
index|]
struct|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

