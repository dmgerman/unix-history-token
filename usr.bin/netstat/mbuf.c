begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)mbuf.c	8.1 (Berkeley) 6/6/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"netstat.h"
end_include

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_decl_stmt
name|struct
name|mbstat
name|mbstat
decl_stmt|;
end_decl_stmt

begin_struct
specifier|static
struct|struct
name|mbtypes
block|{
name|int
name|mt_type
decl_stmt|;
name|char
modifier|*
name|mt_name
decl_stmt|;
block|}
name|mbtypes
index|[]
init|=
block|{
block|{
name|MT_DATA
block|,
literal|"data"
block|}
block|,
block|{
name|MT_OOBDATA
block|,
literal|"oob data"
block|}
block|,
block|{
name|MT_CONTROL
block|,
literal|"ancillary data"
block|}
block|,
block|{
name|MT_HEADER
block|,
literal|"packet headers"
block|}
block|,
block|{
name|MT_SOCKET
block|,
literal|"socket structures"
block|}
block|,
comment|/* XXX */
block|{
name|MT_PCB
block|,
literal|"protocol control blocks"
block|}
block|,
comment|/* XXX */
block|{
name|MT_RTABLE
block|,
literal|"routing table entries"
block|}
block|,
comment|/* XXX */
block|{
name|MT_HTABLE
block|,
literal|"IMP host table entries"
block|}
block|,
comment|/* XXX */
block|{
name|MT_ATABLE
block|,
literal|"address resolution tables"
block|}
block|,
block|{
name|MT_FTABLE
block|,
literal|"fragment reassembly queue headers"
block|}
block|,
comment|/* XXX */
block|{
name|MT_SONAME
block|,
literal|"socket names and addresses"
block|}
block|,
block|{
name|MT_SOOPTS
block|,
literal|"socket options"
block|}
block|,
block|{
name|MT_RIGHTS
block|,
literal|"access rights"
block|}
block|,
block|{
name|MT_IFADDR
block|,
literal|"interface addresses"
block|}
block|,
comment|/* XXX */
block|{
literal|0
block|,
literal|0
block|}
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|nmbtypes
init|=
sizeof|sizeof
argument_list|(
name|mbstat
operator|.
name|m_mtypes
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|short
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|seen
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "have we seen this type yet?" */
end_comment

begin_comment
comment|/*  * Print mbuf statistics.  */
end_comment

begin_function
name|void
name|mbpr
parameter_list|(
name|mbaddr
parameter_list|)
name|u_long
name|mbaddr
decl_stmt|;
block|{
specifier|register
name|int
name|totmem
decl_stmt|,
name|totfree
decl_stmt|,
name|totmbufs
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|struct
name|mbtypes
modifier|*
name|mp
decl_stmt|;
if|if
condition|(
name|nmbtypes
operator|!=
literal|256
condition|)
block|{
name|warnx
argument_list|(
literal|"unexpected change to mbstat; check source"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|mbaddr
operator|==
literal|0
condition|)
block|{
name|warnx
argument_list|(
literal|"mbstat: symbol not in namelist"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|kread
argument_list|(
name|mbaddr
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|mbstat
argument_list|,
sizeof|sizeof
argument_list|(
name|mbstat
argument_list|)
argument_list|)
condition|)
return|return;
name|totmbufs
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|mp
operator|=
name|mbtypes
init|;
name|mp
operator|->
name|mt_name
condition|;
name|mp
operator|++
control|)
name|totmbufs
operator|+=
name|mbstat
operator|.
name|m_mtypes
index|[
name|mp
operator|->
name|mt_type
index|]
expr_stmt|;
name|printf
argument_list|(
literal|"%u mbufs in use:\n"
argument_list|,
name|totmbufs
argument_list|)
expr_stmt|;
for|for
control|(
name|mp
operator|=
name|mbtypes
init|;
name|mp
operator|->
name|mt_name
condition|;
name|mp
operator|++
control|)
if|if
condition|(
name|mbstat
operator|.
name|m_mtypes
index|[
name|mp
operator|->
name|mt_type
index|]
condition|)
block|{
name|seen
index|[
name|mp
operator|->
name|mt_type
index|]
operator|=
name|YES
expr_stmt|;
name|printf
argument_list|(
literal|"\t%u mbufs allocated to %s\n"
argument_list|,
name|mbstat
operator|.
name|m_mtypes
index|[
name|mp
operator|->
name|mt_type
index|]
argument_list|,
name|mp
operator|->
name|mt_name
argument_list|)
expr_stmt|;
block|}
name|seen
index|[
name|MT_FREE
index|]
operator|=
name|YES
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nmbtypes
condition|;
name|i
operator|++
control|)
if|if
condition|(
operator|!
name|seen
index|[
name|i
index|]
operator|&&
name|mbstat
operator|.
name|m_mtypes
index|[
name|i
index|]
condition|)
block|{
name|printf
argument_list|(
literal|"\t%u mbufs allocated to<mbuf type %d>\n"
argument_list|,
name|mbstat
operator|.
name|m_mtypes
index|[
name|i
index|]
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"%lu/%lu mbuf clusters in use\n"
argument_list|,
name|mbstat
operator|.
name|m_clusters
operator|-
name|mbstat
operator|.
name|m_clfree
argument_list|,
name|mbstat
operator|.
name|m_clusters
argument_list|)
expr_stmt|;
name|totmem
operator|=
name|totmbufs
operator|*
name|MSIZE
operator|+
name|mbstat
operator|.
name|m_clusters
operator|*
name|MCLBYTES
expr_stmt|;
name|totfree
operator|=
name|mbstat
operator|.
name|m_clfree
operator|*
name|MCLBYTES
expr_stmt|;
name|printf
argument_list|(
literal|"%u Kbytes allocated to network (%d%% in use)\n"
argument_list|,
name|totmem
operator|/
literal|1024
argument_list|,
operator|(
name|totmem
operator|-
name|totfree
operator|)
operator|*
literal|100
operator|/
name|totmem
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%lu requests for memory denied\n"
argument_list|,
name|mbstat
operator|.
name|m_drops
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%lu requests for memory delayed\n"
argument_list|,
name|mbstat
operator|.
name|m_wait
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%lu calls to protocol drain routines\n"
argument_list|,
name|mbstat
operator|.
name|m_drain
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

