begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)nfsrtt.h	7.2 (Berkeley) %G%  */
end_comment

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
name|int
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
name|int
name|proc
decl_stmt|;
comment|/* NFS procedure number */
name|u_long
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

end_unit

