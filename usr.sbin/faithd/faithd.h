begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: faithd.h,v 1.6 2000/10/05 22:20:37 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1997 and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|logname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tcp_relay
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ftp_relay
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ftp_active
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ftp_passive
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rsh_relay
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rsh_dual_relay
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|exit_success
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|__format__
argument_list|(
name|__printf__
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|exit_failure
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|__format__
argument_list|(
name|__printf__
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEFAULT_PORT_NAME
value|"telnet"
end_define

begin_define
define|#
directive|define
name|DEFAULT_DIR
value|"/usr/libexec"
end_define

begin_define
define|#
directive|define
name|DEFAULT_NAME
value|"telnetd"
end_define

begin_define
define|#
directive|define
name|DEFAULT_PATH
value|(DEFAULT_DIR "/" DEFAULT_NAME)
end_define

begin_define
define|#
directive|define
name|FTP_PORT
value|21
end_define

begin_define
define|#
directive|define
name|RLOGIN_PORT
value|513
end_define

begin_define
define|#
directive|define
name|RSH_PORT
value|514
end_define

begin_define
define|#
directive|define
name|RETURN_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|RETURN_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_define
define|#
directive|define
name|MSS
value|2048
end_define

begin_define
define|#
directive|define
name|MAXARGV
value|20
end_define

begin_define
define|#
directive|define
name|NUMPRT
value|0
end_define

begin_define
define|#
directive|define
name|NUMPRG
value|1
end_define

begin_define
define|#
directive|define
name|NUMARG
value|2
end_define

begin_define
define|#
directive|define
name|UC
parameter_list|(
name|b
parameter_list|)
value|(((int)b)&0xff)
end_define

begin_define
define|#
directive|define
name|ERRSTR
value|strerror(errno)
end_define

begin_define
define|#
directive|define
name|FAITH_TIMEOUT
value|(30 * 60)
end_define

begin_comment
comment|/*second*/
end_comment

end_unit

