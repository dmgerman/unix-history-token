begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.2 (Berkeley) 4/4/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXTERN_H_
end_ifndef

begin_define
define|#
directive|define
name|_EXTERN_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETDB_H
end_ifdef

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PWD_H
end_ifdef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NBBY
end_ifndef

begin_define
define|#
directive|define
name|NBBY
value|CHAR_BIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|abor
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|do_delete
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
name|eprt
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|epsv
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|filename_check
parameter_list|(
name|char
modifier|*
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
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ftpd_getline
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
name|ftpd_logwtmp
parameter_list|(
name|char
modifier|*
parameter_list|,
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
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_empty_stmt
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
name|nreply
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|pasv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perror_reply
parameter_list|(
name|int
parameter_list|,
specifier|const
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
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|retrieve
parameter_list|(
specifier|const
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
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|do_store
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
name|void
name|list_file
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kauth
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
name|klist
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cond_kdestroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kdestroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|krbtkfile
parameter_list|(
specifier|const
name|char
modifier|*
name|tkfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|afslog
parameter_list|(
specifier|const
name|char
modifier|*
name|cell
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|afsunlog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|builtin_ls
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_login
parameter_list|(
name|int
name|code
parameter_list|,
name|char
modifier|*
name|passwd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|klogin
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ftp_rooted
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr
modifier|*
name|ctrl_addr
decl_stmt|,
modifier|*
name|his_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr
modifier|*
name|data_dest
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
name|struct
name|passwd
modifier|*
name|pw
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
name|int
name|logging
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
name|int
name|oobflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|off_t
name|file_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|off_t
name|byte_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|urgcatch
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
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ftpd_timeout
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
name|pdata
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[]
decl_stmt|,
name|remotehost
index|[]
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
name|usedefault
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|transflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tmpline
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EXTERN_H_ */
end_comment

end_unit

