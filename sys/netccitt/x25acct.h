begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) University of British Columbia, 1984  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Laboratory for Computation Vision and the Computer Science Department  * of the University of British Columbia.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)x25acct.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETCCITT_X25ACCT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETCCITT_X25ACCT_H_
end_define

begin_comment
comment|/*  * Format of X.25 accounting record written  * to X25ACCTF whenever a circuit is closed.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|waterloo
end_ifdef

begin_define
define|#
directive|define
name|X25ACCTF
value|"/usr/adm/logs/x25acct"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|X25ACCTF
value|"/usr/adm/x25acct"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|x25acct
block|{
name|time_t
name|x25acct_stime
decl_stmt|;
comment|/* start time */
ifdef|#
directive|ifdef
name|waterloo
name|u_long
name|x25acct_etime
decl_stmt|;
comment|/* elapsed time (seconds) */
else|#
directive|else
name|u_short
name|x25acct_etime
decl_stmt|;
comment|/* elapsed time (seconds) */
endif|#
directive|endif
name|short
name|x25acct_uid
decl_stmt|;
comment|/* user id */
name|short
name|x25acct_net
decl_stmt|;
comment|/* network id */
name|u_short
name|x25acct_psize
range|:
literal|4
decl_stmt|,
comment|/* packet size */
name|x25acct_addrlen
range|:
literal|4
decl_stmt|,
comment|/* x25acct_addr length */
name|x25acct_revcharge
range|:
literal|1
decl_stmt|,
comment|/* reverse charging */
name|x25acct_callin
range|:
literal|1
decl_stmt|,
comment|/* incoming call */
name|x25acct_unused
range|:
literal|6
decl_stmt|;
name|char
name|x25acct_addr
index|[
literal|8
index|]
decl_stmt|;
comment|/* remote DTE address (in bcd) */
name|char
name|x25acct_udata
index|[
literal|4
index|]
decl_stmt|;
comment|/* protocol id */
name|long
name|x25acct_txcnt
decl_stmt|;
comment|/* packets transmitted */
name|long
name|x25acct_rxcnt
decl_stmt|;
comment|/* packets received */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

