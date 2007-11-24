begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2001 Jason Evans<jasone@freebsd.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer as  *    the first lines of this file unmodified other than the possible  *    addition of one or more copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SEMA_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SEMA_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_struct
struct|struct
name|sema
block|{
name|struct
name|mtx
name|sema_mtx
decl_stmt|;
comment|/* General protection lock. */
name|struct
name|cv
name|sema_cv
decl_stmt|;
comment|/* Waiters. */
name|int
name|sema_waiters
decl_stmt|;
comment|/* Number of waiters. */
name|int
name|sema_value
decl_stmt|;
comment|/* Semaphore value. */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|sema_init
parameter_list|(
name|struct
name|sema
modifier|*
name|sema
parameter_list|,
name|int
name|value
parameter_list|,
specifier|const
name|char
modifier|*
name|description
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sema_destroy
parameter_list|(
name|struct
name|sema
modifier|*
name|sema
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_sema_post
parameter_list|(
name|struct
name|sema
modifier|*
name|sema
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_sema_wait
parameter_list|(
name|struct
name|sema
modifier|*
name|sema
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_sema_timedwait
parameter_list|(
name|struct
name|sema
modifier|*
name|sema
parameter_list|,
name|int
name|timo
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_sema_trywait
parameter_list|(
name|struct
name|sema
modifier|*
name|sema
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sema_value
parameter_list|(
name|struct
name|sema
modifier|*
name|sema
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|sema_post
parameter_list|(
name|sema
parameter_list|)
value|_sema_post((sema), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sema_wait
parameter_list|(
name|sema
parameter_list|)
value|_sema_wait((sema), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sema_timedwait
parameter_list|(
name|sema
parameter_list|,
name|timo
parameter_list|)
define|\
value|_sema_timedwait((sema), (timo), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sema_trywait
parameter_list|(
name|sema
parameter_list|)
value|_sema_trywait((sema), LOCK_FILE, LOCK_LINE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SEMA_H_ */
end_comment

end_unit

