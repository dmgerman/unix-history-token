begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_RWLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_RWLOCK_H_
end_define

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

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
enum|enum
block|{
name|RW_DRIVER
init|=
literal|2
block|,
comment|/* driver (DDI) rwlock */
name|RW_DEFAULT
init|=
literal|4
comment|/* kernel default rwlock */
block|}
name|krw_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|RW_WRITER
block|,
name|RW_READER
block|}
name|krw_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sx
name|krwlock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RW_READ_HELD
parameter_list|(
name|x
parameter_list|)
value|(rw_read_held((x)))
end_define

begin_define
define|#
directive|define
name|RW_WRITE_HELD
parameter_list|(
name|x
parameter_list|)
value|(rw_write_held((x)))
end_define

begin_define
define|#
directive|define
name|RW_LOCK_HELD
parameter_list|(
name|x
parameter_list|)
value|(rw_lock_held((x)))
end_define

begin_define
define|#
directive|define
name|RW_ISWRITER
parameter_list|(
name|x
parameter_list|)
value|(rw_iswriter(x))
end_define

begin_define
define|#
directive|define
name|rw_init
parameter_list|(
name|lock
parameter_list|,
name|desc
parameter_list|,
name|type
parameter_list|,
name|arg
parameter_list|)
define|\
value|sx_init_flags((lock), "zfs:" #lock, SX_DUPOK)
end_define

begin_define
define|#
directive|define
name|rw_destroy
parameter_list|(
name|lock
parameter_list|)
value|sx_destroy(lock)
end_define

begin_define
define|#
directive|define
name|rw_enter
parameter_list|(
name|lock
parameter_list|,
name|how
parameter_list|)
value|do {					\ 	if ((how) == RW_READER)						\ 		sx_slock(lock);						\ 	else
comment|/* if ((how) == RW_WRITER) */
value|\ 		sx_xlock(lock);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|rw_tryenter
parameter_list|(
name|lock
parameter_list|,
name|how
parameter_list|)
value|((how) == RW_READER ? sx_try_slock(lock) : sx_try_xlock(lock))
end_define

begin_define
define|#
directive|define
name|rw_exit
parameter_list|(
name|lock
parameter_list|)
value|sx_unlock(lock)
end_define

begin_define
define|#
directive|define
name|rw_downgrade
parameter_list|(
name|lock
parameter_list|)
value|sx_downgrade(lock)
end_define

begin_define
define|#
directive|define
name|rw_tryupgrade
parameter_list|(
name|lock
parameter_list|)
value|sx_try_upgrade(lock)
end_define

begin_define
define|#
directive|define
name|rw_read_held
parameter_list|(
name|lock
parameter_list|)
value|((lock)->sx_lock != SX_LOCK_UNLOCKED&& ((lock)->sx_lock& SX_LOCK_SHARED))
end_define

begin_define
define|#
directive|define
name|rw_write_held
parameter_list|(
name|lock
parameter_list|)
value|sx_xlocked(lock)
end_define

begin_define
define|#
directive|define
name|rw_lock_held
parameter_list|(
name|lock
parameter_list|)
value|(rw_read_held(lock) || rw_write_held(lock))
end_define

begin_define
define|#
directive|define
name|rw_iswriter
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
name|rw_owner
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
comment|/* defined(_KERNEL) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_RWLOCK_H_ */
end_comment

end_unit

