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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_WANT_FILE
argument_list|)
end_if

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

begin_struct
struct|struct
name|ksem
block|{
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
name|int
name|ks_flags
decl_stmt|;
comment|/* 	 * Values maintained solely to make this a better-behaved file 	 * descriptor for fstat() to run on. 	 * 	 * XXX: dubious 	 */
name|struct
name|timespec
name|ks_atime
decl_stmt|;
name|struct
name|timespec
name|ks_mtime
decl_stmt|;
name|struct
name|timespec
name|ks_ctime
decl_stmt|;
name|struct
name|timespec
name|ks_birthtime
decl_stmt|;
name|struct
name|label
modifier|*
name|ks_label
decl_stmt|;
comment|/* MAC label */
specifier|const
name|char
modifier|*
name|ks_path
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KS_ANONYMOUS
value|0x0001
end_define

begin_comment
comment|/* Anonymous (unnamed) semaphore. */
end_comment

begin_define
define|#
directive|define
name|KS_DEAD
value|0x0002
end_define

begin_comment
comment|/* No new waiters allowed. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX4_KSEM_H_ */
end_comment

end_unit

