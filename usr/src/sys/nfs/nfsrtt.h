begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)nfsrtt.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Definitions for client side performance monitor.  */
end_comment

begin_define
define|#
directive|define
name|NFSRTTLOGSIZ
value|128
end_define

begin_struct
struct|struct
name|nfsrtt
block|{
name|int
name|pos
decl_stmt|;
struct|struct
name|rttl
block|{
name|int
name|proc
decl_stmt|;
name|int
name|rtt
decl_stmt|;
name|int
name|rto
decl_stmt|;
name|int
name|sent
decl_stmt|;
name|int
name|cwnd
decl_stmt|;
name|int
name|srtt
decl_stmt|;
name|int
name|sdrtt
decl_stmt|;
name|fsid_t
name|fsid
decl_stmt|;
name|struct
name|timeval
name|tstamp
decl_stmt|;
block|}
name|rttl
index|[
name|NFSRTTLOGSIZ
index|]
struct|;
block|}
struct|;
end_struct

end_unit

