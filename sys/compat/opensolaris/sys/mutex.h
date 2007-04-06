begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_MUTEX_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_MUTEX_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_empty
empty|#include_next<sys/mutex.h>
end_empty

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|MUTEX_DEFAULT
init|=
literal|6
comment|/* kernel default mutex */
block|}
name|kmutex_type_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MUTEX_HELD
parameter_list|(
name|x
parameter_list|)
value|(mutex_owned(x))
end_define

begin_define
define|#
directive|define
name|MUTEX_NOT_HELD
parameter_list|(
name|x
parameter_list|)
value|(!mutex_owned(x) || panicstr)
end_define

begin_typedef
typedef|typedef
name|struct
name|sx
name|kmutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|mutex_init
parameter_list|(
name|lock
parameter_list|,
name|desc
parameter_list|,
name|type
parameter_list|,
name|arg
parameter_list|)
value|do {			\ 	ASSERT((type) == MUTEX_DEFAULT);				\ 	sx_init_flags((lock), "zfs:" #lock, SX_DUPOK);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|mutex_destroy
parameter_list|(
name|lock
parameter_list|)
value|sx_destroy(lock)
end_define

begin_define
define|#
directive|define
name|mutex_enter
parameter_list|(
name|lock
parameter_list|)
value|sx_xlock(lock)
end_define

begin_define
define|#
directive|define
name|mutex_tryenter
parameter_list|(
name|lock
parameter_list|)
value|sx_try_xlock(lock)
end_define

begin_define
define|#
directive|define
name|mutex_exit
parameter_list|(
name|lock
parameter_list|)
value|sx_xunlock(lock)
end_define

begin_define
define|#
directive|define
name|mutex_owned
parameter_list|(
name|lock
parameter_list|)
value|sx_xlocked(lock)
end_define

begin_comment
comment|/* TODO: Change to sx_xholder() once it is moved from kern_sx.c to sx.h. */
end_comment

begin_define
define|#
directive|define
name|mutex_owner
parameter_list|(
name|lock
parameter_list|)
value|((lock)->sx_lock& SX_LOCK_SHARED ? NULL : (struct thread *)SX_OWNER((lock)->sx_lock))
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
comment|/* _OPENSOLARIS_SYS_MUTEX_H_ */
end_comment

end_unit

