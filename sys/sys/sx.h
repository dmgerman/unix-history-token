begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2001 Jason Evans<jasone@freebsd.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer as  *    the first lines of this file unmodified other than the possible   *    addition of one or more copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SX_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SX_H_
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
file|<sys/condvar.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_struct
struct|struct
name|sx
block|{
name|struct
name|lock_object
name|lock_object
decl_stmt|;
comment|/* Common lock properties. */
name|struct
name|mtx
modifier|*
name|sx_lock
decl_stmt|;
comment|/* General protection lock. */
name|int
name|sx_cnt
decl_stmt|;
comment|/* -1: xlock,> 0: slock count. */
name|struct
name|cv
name|sx_shrd_cv
decl_stmt|;
comment|/* slock waiters. */
name|int
name|sx_shrd_wcnt
decl_stmt|;
comment|/* Number of slock waiters. */
name|struct
name|cv
name|sx_excl_cv
decl_stmt|;
comment|/* xlock waiters. */
name|int
name|sx_excl_wcnt
decl_stmt|;
comment|/* Number of xlock waiters. */
name|struct
name|thread
modifier|*
name|sx_xholder
decl_stmt|;
comment|/* Thread presently holding xlock. */
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
name|sx_sysinit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sx_init
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|sx_destroy
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_sx_slock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_xlock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_try_slock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_try_xlock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_sunlock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_xunlock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_try_upgrade
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_downgrade
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANT_SUPPORT
argument_list|)
end_if

begin_function_decl
name|void
name|_sx_assert
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
parameter_list|,
name|int
name|what
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_function_decl
name|int
name|sx_chain
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|thread
modifier|*
modifier|*
name|ownerp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|sx_args
block|{
name|struct
name|sx
modifier|*
name|sa_sx
decl_stmt|;
specifier|const
name|char
modifier|*
name|sa_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SX_SYSINIT
parameter_list|(
name|name
parameter_list|,
name|sxa
parameter_list|,
name|desc
parameter_list|)
define|\
value|static struct sx_args name##_args = {				\ 		(sxa),							\ 		(desc)							\ 	};								\ 	SYSINIT(name##_sx_sysinit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    sx_sysinit,&name##_args);					\ 	SYSUNINIT(name##_sx_sysuninit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    sx_destroy, (sxa))
end_define

begin_define
define|#
directive|define
name|sx_xlocked
parameter_list|(
name|sx
parameter_list|)
value|((sx)->sx_cnt< 0&& (sx)->sx_xholder == curthread)
end_define

begin_define
define|#
directive|define
name|sx_slock
parameter_list|(
name|sx
parameter_list|)
value|_sx_slock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_xlock
parameter_list|(
name|sx
parameter_list|)
value|_sx_xlock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_try_slock
parameter_list|(
name|sx
parameter_list|)
value|_sx_try_slock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_try_xlock
parameter_list|(
name|sx
parameter_list|)
value|_sx_try_xlock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_sunlock
parameter_list|(
name|sx
parameter_list|)
value|_sx_sunlock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_xunlock
parameter_list|(
name|sx
parameter_list|)
value|_sx_xunlock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_try_upgrade
parameter_list|(
name|sx
parameter_list|)
value|_sx_try_upgrade((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_downgrade
parameter_list|(
name|sx
parameter_list|)
value|_sx_downgrade((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_unlock
parameter_list|(
name|sx
parameter_list|)
value|do {						\ 	if (sx_xlocked(sx))						\ 		sx_xunlock(sx);						\ 	else								\ 		sx_sunlock(sx);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|sx_sleep
parameter_list|(
name|chan
parameter_list|,
name|sx
parameter_list|,
name|pri
parameter_list|,
name|wmesg
parameter_list|,
name|timo
parameter_list|)
define|\
value|_sleep((chan),&(sx)->lock_object, (pri), (wmesg), (timo))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANT_SUPPORT
argument_list|)
end_if

begin_define
define|#
directive|define
name|SX_LOCKED
value|LA_LOCKED
end_define

begin_define
define|#
directive|define
name|SX_SLOCKED
value|LA_SLOCKED
end_define

begin_define
define|#
directive|define
name|SX_XLOCKED
value|LA_XLOCKED
end_define

begin_define
define|#
directive|define
name|SX_UNLOCKED
value|LA_UNLOCKED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|sx_assert
parameter_list|(
name|sx
parameter_list|,
name|what
parameter_list|)
value|_sx_assert((sx), (what), LOCK_FILE, LOCK_LINE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sx_assert
parameter_list|(
name|sx
parameter_list|,
name|what
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* !_SYS_SX_H_ */
end_comment

end_unit

