begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2001 Jason Evans<jasone@freebsd.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer as  *    the first lines of this file unmodified other than the possible   *    addition of one or more copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * $FreeBSD$  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_struct
struct|struct
name|sx
block|{
name|struct
name|mtx
name|sx_lock
decl_stmt|;
comment|/* General protection lock. */
specifier|const
name|char
modifier|*
name|sx_descr
decl_stmt|;
comment|/* sx lock description. */
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
name|proc
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
name|sx_slock
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
name|sx_xlock
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
name|sx_sunlock
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
name|sx_xunlock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_comment
comment|/*  * SX_ASSERT_SLOCKED() can only detect that at least *some* thread owns an  * slock, but it cannot guarantee that *this* thread owns an slock.  */
end_comment

begin_define
define|#
directive|define
name|SX_ASSERT_SLOCKED
parameter_list|(
name|sx
parameter_list|)
value|do {					\ 	mtx_lock(&(sx)->sx_lock);					\ 	_SX_ASSERT_SLOCKED((sx));					\ 	mtx_unlock(&(sx)->sx_lock);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_SX_ASSERT_SLOCKED
parameter_list|(
name|sx
parameter_list|)
value|do {					\ 	KASSERT(((sx)->sx_cnt> 0), ("%s: lacking slock %s\n",		\ 	    __FUNCTION__, (sx)->sx_descr));				\ } while (0)
end_define

begin_comment
comment|/*  * SX_ASSERT_XLOCKED() detects and guarantees that *we* own the xlock.  */
end_comment

begin_define
define|#
directive|define
name|SX_ASSERT_XLOCKED
parameter_list|(
name|sx
parameter_list|)
value|do {					\ 	mtx_lock(&(sx)->sx_lock);					\ 	_SX_ASSERT_XLOCKED((sx));					\ 	mtx_unlock(&(sx)->sx_lock);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_SX_ASSERT_XLOCKED
parameter_list|(
name|sx
parameter_list|)
value|do {					\ 	KASSERT(((sx)->sx_xholder == curproc),				\ 	    ("%s: thread %p lacking xlock %s\n", __FUNCTION__,		\ 	    curproc, (sx)->sx_descr));					\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* INVARIANTS */
end_comment

begin_define
define|#
directive|define
name|SX_ASSERT_SLOCKED
parameter_list|(
name|sx
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SX_ASSERT_XLOCKED
parameter_list|(
name|sx
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_SX_ASSERT_SLOCKED
parameter_list|(
name|sx
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_SX_ASSERT_XLOCKED
parameter_list|(
name|sx
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INVARIANTS */
end_comment

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
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SX_H_ */
end_comment

end_unit

