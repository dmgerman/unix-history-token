begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1992 The University of Utah and the Center  *	for Software Science (CSS).  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Center for Software Science of the University of Utah Computer  * Science Department.  CSS requests users of this software to return  * to css-dist@cs.utah.edu any improvements that they make and grant  * CSS redistribution rights.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)defs.h	8.1 (Berkeley) 6/4/93  *  * Utah $Hdr: defs.h 3.1 92/07/06$  * Author: Jeff Forys, University of Utah CSS  */
end_comment

begin_include
include|#
directive|include
file|"rmp.h"
end_include

begin_include
include|#
directive|include
file|"rmp_var.h"
end_include

begin_comment
comment|/* **  Common #define's and external variables.  All other files should **  include this. */
end_comment

begin_comment
comment|/*  *  This may be defined in<sys/param.h>, if not, it's defined here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXHOSTNAMELEN
end_ifndef

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  SIGUSR1 and SIGUSR2 are defined in<signal.h> for 4.3BSD systems.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGUSR1
end_ifndef

begin_define
define|#
directive|define
name|SIGUSR1
value|SIGEMT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGUSR2
end_ifndef

begin_define
define|#
directive|define
name|SIGUSR2
value|SIGFPE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  These can be faster& more efficient than strcmp()/strncmp()...  */
end_comment

begin_define
define|#
directive|define
name|STREQN
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|((*s1 == *s2)&& (strcmp(s1,s2) == 0))
end_define

begin_define
define|#
directive|define
name|STRNEQN
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|((*s1 == *s2)&& (strncmp(s1,s2,n) == 0))
end_define

begin_comment
comment|/*  *  Configuration file limitations.  */
end_comment

begin_define
define|#
directive|define
name|C_MAXFILE
value|10
end_define

begin_comment
comment|/* max number of boot-able files */
end_comment

begin_define
define|#
directive|define
name|C_LINELEN
value|1024
end_define

begin_comment
comment|/* max length of line */
end_comment

begin_comment
comment|/*  *  Direction of packet (used as argument to DispPkt).  */
end_comment

begin_define
define|#
directive|define
name|DIR_RCVD
value|0
end_define

begin_define
define|#
directive|define
name|DIR_SENT
value|1
end_define

begin_define
define|#
directive|define
name|DIR_NONE
value|2
end_define

begin_comment
comment|/*  *  These need not be functions, so...  */
end_comment

begin_define
define|#
directive|define
name|FreeStr
parameter_list|(
name|str
parameter_list|)
value|free(str)
end_define

begin_define
define|#
directive|define
name|FreeClient
parameter_list|(
name|cli
parameter_list|)
value|free(cli)
end_define

begin_define
define|#
directive|define
name|GenSessID
parameter_list|()
value|(++SessionID ? SessionID: ++SessionID)
end_define

begin_comment
comment|/*  *  Converting an Ethernet address to a string is done in many routines.  *  Using `rmp.hp_hdr.saddr' works because this field is *never* changed;  *  it will *always* contain the source address of the packet.  */
end_comment

begin_define
define|#
directive|define
name|EnetStr
parameter_list|(
name|rptr
parameter_list|)
value|GetEtherAddr(&(rptr)->rmp.hp_hdr.saddr[0])
end_define

begin_comment
comment|/*  *  Every machine we can boot will have one of these allocated for it  *  (unless there are no restrictions on who we can boot).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|client_s
block|{
name|u_char
name|addr
index|[
name|RMP_ADDRLEN
index|]
decl_stmt|;
comment|/* addr of machine */
name|char
modifier|*
name|files
index|[
name|C_MAXFILE
index|]
decl_stmt|;
comment|/* boot-able files */
name|struct
name|client_s
modifier|*
name|next
decl_stmt|;
comment|/* ptr to next */
block|}
name|CLIENT
typedef|;
end_typedef

begin_comment
comment|/*  *  Every active connection has one of these allocated for it.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rmpconn_s
block|{
name|struct
name|rmp_packet
name|rmp
decl_stmt|;
comment|/* RMP packet */
name|int
name|rmplen
decl_stmt|;
comment|/* length of packet */
name|struct
name|timeval
name|tstamp
decl_stmt|;
comment|/* last time active */
name|int
name|bootfd
decl_stmt|;
comment|/* open boot file */
name|struct
name|rmpconn_s
modifier|*
name|next
decl_stmt|;
comment|/* ptr to next */
block|}
name|RMPCONN
typedef|;
end_typedef

begin_comment
comment|/*  *  All these variables are defined in "conf.c".  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|MyHost
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this hosts' name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|MyPid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this processes' ID */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|DebugFlg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set true if debugging */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|BootAny
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set true if we can boot anyone */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ConfigFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration file */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|DfltConfig
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default configuration file */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|DbgFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug output file */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PidFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file containing pid of server */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|BootDir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* directory w/boot files */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|DbgFp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug file pointer */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|IntfName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interface we are attached to */
end_comment

begin_decl_stmt
specifier|extern
name|u_short
name|SessionID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* generated session ID */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|BootFiles
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of boot files */
end_comment

begin_decl_stmt
specifier|extern
name|CLIENT
modifier|*
name|Clients
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of addrs we'll accept */
end_comment

begin_decl_stmt
specifier|extern
name|RMPCONN
modifier|*
name|RmpConns
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of active connections */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|RmpMcastAddr
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RMP multicast address */
end_comment

begin_decl_stmt
name|void
name|AddConn
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|BootDone
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|BpfClose
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|BpfGetIntfName
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|BpfOpen
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|BpfRead
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|BpfWrite
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DebugOff
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DebugOn
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DispPkt
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DoTimeout
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DspFlnm
name|__P
argument_list|(
operator|(
name|u_int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Exit
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CLIENT
modifier|*
name|FindClient
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RMPCONN
modifier|*
name|FindConn
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|FreeClients
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|FreeConn
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|FreeConns
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|GetBootFiles
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|GetEtherAddr
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CLIENT
modifier|*
name|NewClient
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RMPCONN
modifier|*
name|NewConn
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|NewStr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
modifier|*
name|ParseAddr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ParseConfig
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ProcessPacket
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|,
name|CLIENT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReConfig
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|RemoveConn
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SendBootRepl
name|__P
argument_list|(
operator|(
expr|struct
name|rmp_packet
operator|*
operator|,
name|RMPCONN
operator|*
operator|,
name|char
operator|*
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SendFileNo
name|__P
argument_list|(
operator|(
expr|struct
name|rmp_packet
operator|*
operator|,
name|RMPCONN
operator|*
operator|,
name|char
operator|*
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SendPacket
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SendReadRepl
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SendServerID
name|__P
argument_list|(
operator|(
name|RMPCONN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

