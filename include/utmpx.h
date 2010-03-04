begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UTMPX_H_
end_ifndef

begin_define
define|#
directive|define
name|_UTMPX_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_timeval.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_PID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__pid_t
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_PID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|utmpx
block|{
name|short
name|ut_type
decl_stmt|;
comment|/* Type of entry. */
name|struct
name|timeval
name|ut_tv
decl_stmt|;
comment|/* Time entry was made. */
name|char
name|ut_id
index|[
literal|8
index|]
decl_stmt|;
comment|/* Record identifier. */
name|pid_t
name|ut_pid
decl_stmt|;
comment|/* Process ID. */
name|char
name|ut_user
index|[
literal|32
index|]
decl_stmt|;
comment|/* User login name. */
name|char
name|ut_line
index|[
literal|16
index|]
decl_stmt|;
comment|/* Device name. */
if|#
directive|if
name|__BSD_VISIBLE
name|char
name|ut_host
index|[
literal|128
index|]
decl_stmt|;
comment|/* Remote hostname. */
else|#
directive|else
name|char
name|__ut_host
index|[
literal|128
index|]
decl_stmt|;
endif|#
directive|endif
name|char
name|__ut_spare
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EMPTY
value|0
end_define

begin_comment
comment|/* No valid user accounting information. */
end_comment

begin_define
define|#
directive|define
name|BOOT_TIME
value|1
end_define

begin_comment
comment|/* Time of system boot. */
end_comment

begin_define
define|#
directive|define
name|OLD_TIME
value|2
end_define

begin_comment
comment|/* Time when system clock changed. */
end_comment

begin_define
define|#
directive|define
name|NEW_TIME
value|3
end_define

begin_comment
comment|/* Time after system clock changed. */
end_comment

begin_define
define|#
directive|define
name|USER_PROCESS
value|4
end_define

begin_comment
comment|/* A process. */
end_comment

begin_define
define|#
directive|define
name|INIT_PROCESS
value|5
end_define

begin_comment
comment|/* A process spawned by the init process. */
end_comment

begin_define
define|#
directive|define
name|LOGIN_PROCESS
value|6
end_define

begin_comment
comment|/* The session leader of a logged-in user. */
end_comment

begin_define
define|#
directive|define
name|DEAD_PROCESS
value|7
end_define

begin_comment
comment|/* A session leader who has exited. */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|SHUTDOWN_TIME
value|8
end_define

begin_comment
comment|/* Time of system shutdown. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|UTXDB_ACTIVE
value|0
end_define

begin_comment
comment|/* Active login sessions. */
end_comment

begin_define
define|#
directive|define
name|UTXDB_LASTLOGIN
value|1
end_define

begin_comment
comment|/* Last login sessions. */
end_comment

begin_define
define|#
directive|define
name|UTXDB_LOG
value|2
end_define

begin_comment
comment|/* Log indexed by time. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
name|void
name|endutxent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|utmpx
modifier|*
name|getutxent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|utmpx
modifier|*
name|getutxid
parameter_list|(
specifier|const
name|struct
name|utmpx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|utmpx
modifier|*
name|getutxline
parameter_list|(
specifier|const
name|struct
name|utmpx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|utmpx
modifier|*
name|pututxline
parameter_list|(
specifier|const
name|struct
name|utmpx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setutxent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|struct
name|utmpx
modifier|*
name|getutxuser
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setutxdb
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UTMPX_H_ */
end_comment

end_unit

