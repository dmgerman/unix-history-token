begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Alfred Perlstein<alfred@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX4_KSEM_H_
end_ifndef

begin_define
define|#
directive|define
name|_POSIX4_KSEM_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-servicable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct
struct|struct
name|kuser
block|{
name|pid_t
name|ku_pid
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|kuser
argument_list|)
name|ku_next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ksem
block|{
name|LIST_ENTRY
argument_list|(
argument|ksem
argument_list|)
name|ks_entry
expr_stmt|;
comment|/* global list entry */
name|int
name|ks_onlist
decl_stmt|;
comment|/* boolean if on a list (ks_entry) */
name|char
modifier|*
name|ks_name
decl_stmt|;
comment|/* if named, this is the name */
name|int
name|ks_ref
decl_stmt|;
comment|/* number of references */
name|mode_t
name|ks_mode
decl_stmt|;
comment|/* protection bits */
name|uid_t
name|ks_uid
decl_stmt|;
comment|/* creator uid */
name|gid_t
name|ks_gid
decl_stmt|;
comment|/* creator gid */
name|unsigned
name|int
name|ks_value
decl_stmt|;
comment|/* current value */
name|struct
name|cv
name|ks_cv
decl_stmt|;
comment|/* waiters sleep here */
name|int
name|ks_waiters
decl_stmt|;
comment|/* number of waiters */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|kuser
argument_list|)
name|ks_users
expr_stmt|;
comment|/* pids using this sem */
name|struct
name|label
modifier|*
name|ks_label
decl_stmt|;
comment|/* MAC label */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX4_KSEM_H_ */
end_comment

end_unit

