begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.2 (Berkeley) 4/4/94  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_function_decl
name|void
name|blkfree
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|copyblk
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cwd
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dologout
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatalerror
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ftpd_logwtmp
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ftpd_pclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|ftpd_popen
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getline
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lreply
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|makedir
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nack
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|passive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|long_passive
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perror_reply
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pwd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|removedir
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|renamecmd
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|renamefrom
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reply
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|retrieve
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_file_list
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_SETPROCTITLE
end_ifdef

begin_function_decl
name|void
name|setproctitle
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|statcmd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|statfilecmd
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|store
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|upper
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|user
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|yyerror
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ls_main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|assumeutf8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|cbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|sockunion
name|data_dest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|epsvall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|form
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ftpdebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|guest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|sockunion
name|his_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|homedir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hostinfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hostname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxtimeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|logged_in
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|logging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|noepsv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|noguestretr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|noretr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|paranoid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pdata
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|proctitle
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|readonly
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|off_t
name|restart_point
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tmpline
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|typenames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in<arpa/ftp.h> included from ftpd.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|usedefault
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|sockaddr_in
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_in6
struct_decl|;
end_struct_decl

begin_union
union|union
name|sockunion
block|{
struct|struct
name|sockinet
block|{
name|u_char
name|si_len
decl_stmt|;
name|u_char
name|si_family
decl_stmt|;
name|u_short
name|si_port
decl_stmt|;
block|}
name|su_si
struct|;
name|struct
name|sockaddr_in
name|su_sin
decl_stmt|;
name|struct
name|sockaddr_in6
name|su_sin6
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|su_len
value|su_si.si_len
end_define

begin_define
define|#
directive|define
name|su_family
value|su_si.si_family
end_define

begin_define
define|#
directive|define
name|su_port
value|su_si.si_port
end_define

end_unit

