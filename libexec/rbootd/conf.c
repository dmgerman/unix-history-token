begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1992 The University of Utah and the Center  *	for Software Science (CSS).  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Center for Software Science of the University of Utah Computer  * Science Department.  CSS requests users of this software to return  * to css-dist@cs.utah.edu any improvements that they make and grant  * CSS redistribution rights.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)conf.c	8.1 (Berkeley) 6/4/93  *  * From: Utah Hdr: conf.c 3.1 92/07/06  * Author: Jeff Forys, University of Utah CSS  */
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
unit|static const char sccsid[] = "@(#)conf.c	8.1 (Berkeley) 6/4/93";
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
literal|"$FreeBSD$"
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
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_comment
comment|/* **  Define (and possibly initialize) global variables here. ** **  Caveat: **	The maximum number of bootable files (`char *BootFiles[]') is **	limited to C_MAXFILE (i.e. the maximum number of files that **	can be spec'd in the configuration file).  This was done to **	simplify the boot file search code. */
end_comment

begin_decl_stmt
name|char
name|MyHost
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name */
end_comment

begin_decl_stmt
name|pid_t
name|MyPid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process id */
end_comment

begin_decl_stmt
name|int
name|DebugFlg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set true if debugging */
end_comment

begin_decl_stmt
name|int
name|BootAny
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set true if we boot anyone */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ConfigFile
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DfltConfig
init|=
name|_PATH_RBOOTDCONF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default configuration file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PidFile
init|=
name|_PATH_RBOOTDPID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file w/pid of server */
end_comment

begin_decl_stmt
name|char
modifier|*
name|BootDir
init|=
name|_PATH_RBOOTDLIB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* directory w/boot files */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DbgFile
init|=
name|_PATH_RBOOTDDBG
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug output file */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|DbgFp
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug file pointer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|IntfName
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* intf we are attached to */
end_comment

begin_decl_stmt
name|u_int16_t
name|SessionID
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* generated session ID */
end_comment

begin_decl_stmt
name|char
modifier|*
name|BootFiles
index|[
name|C_MAXFILE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of boot files */
end_comment

begin_decl_stmt
name|CLIENT
modifier|*
name|Clients
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of addrs we'll accept */
end_comment

begin_decl_stmt
name|RMPCONN
modifier|*
name|RmpConns
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of active connections */
end_comment

begin_decl_stmt
name|u_int8_t
name|RmpMcastAddr
index|[
name|RMP_ADDRLEN
index|]
init|=
name|RMP_ADDR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RMP multicast address */
end_comment

end_unit

