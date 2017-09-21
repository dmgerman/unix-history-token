begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Stephan Uphoff<ups@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_RMLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_RMLOCK_H_
end_define

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_rmlock.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Flags passed to rm_init_flags(9).  */
end_comment

begin_define
define|#
directive|define
name|RM_NOWITNESS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RM_RECURSE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RM_SLEEPABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RM_NEW
value|0x00000008
end_define

begin_function_decl
name|void
name|rm_init
parameter_list|(
name|struct
name|rmlock
modifier|*
name|rm
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rm_init_flags
parameter_list|(
name|struct
name|rmlock
modifier|*
name|rm
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rm_destroy
parameter_list|(
name|struct
name|rmlock
modifier|*
name|rm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rm_wowned
parameter_list|(
specifier|const
name|struct
name|rmlock
modifier|*
name|rm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rm_sysinit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rm_sysinit_flags
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_rm_wlock_debug
parameter_list|(
name|struct
name|rmlock
modifier|*
name|rm
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
name|_rm_wunlock_debug
parameter_list|(
name|struct
name|rmlock
modifier|*
name|rm
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
name|_rm_rlock_debug
parameter_list|(
name|struct
name|rmlock
modifier|*
name|rm
parameter_list|,
name|struct
name|rm_priotracker
modifier|*
name|tracker
parameter_list|,
name|int
name|trylock
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
name|_rm_runlock_debug
parameter_list|(
name|struct
name|rmlock
modifier|*
name|rm
parameter_list|,
name|struct
name|rm_priotracker
modifier|*
name|tracker
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
name|_rm_wlock
parameter_list|(
name|struct
name|rmlock
modifier|*
name|rm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_rm_wunlock
parameter_list|(
name|struct
name|rmlock
modifier|*
name|rm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_rm_rlock
parameter_list|(
name|struct
name|rmlock
modifier|*
name|rm
parameter_list|,
name|struct
name|rm_priotracker
modifier|*
name|tracker
parameter_list|,
name|int
name|trylock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_rm_runlock
parameter_list|(
name|struct
name|rmlock
modifier|*
name|rm
parameter_list|,
name|struct
name|rm_priotracker
modifier|*
name|tracker
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
name|_rm_assert
parameter_list|(
specifier|const
name|struct
name|rmlock
modifier|*
name|rm
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

begin_comment
comment|/*  * Public interface for lock operations.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_DEBUG
end_ifndef

begin_error
error|#
directive|error
error|LOCK_DEBUG not defined, include<sys/lock.h> before<sys/rmlock.h>
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LOCK_DEBUG
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|rm_wlock
parameter_list|(
name|rm
parameter_list|)
value|_rm_wlock_debug((rm), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|rm_wunlock
parameter_list|(
name|rm
parameter_list|)
value|_rm_wunlock_debug((rm), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|rm_rlock
parameter_list|(
name|rm
parameter_list|,
name|tracker
parameter_list|)
define|\
value|((void)_rm_rlock_debug((rm),(tracker), 0, LOCK_FILE, LOCK_LINE ))
end_define

begin_define
define|#
directive|define
name|rm_try_rlock
parameter_list|(
name|rm
parameter_list|,
name|tracker
parameter_list|)
define|\
value|_rm_rlock_debug((rm),(tracker), 1, LOCK_FILE, LOCK_LINE )
end_define

begin_define
define|#
directive|define
name|rm_runlock
parameter_list|(
name|rm
parameter_list|,
name|tracker
parameter_list|)
define|\
value|_rm_runlock_debug((rm), (tracker), LOCK_FILE, LOCK_LINE )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|rm_wlock
parameter_list|(
name|rm
parameter_list|)
value|_rm_wlock((rm))
end_define

begin_define
define|#
directive|define
name|rm_wunlock
parameter_list|(
name|rm
parameter_list|)
value|_rm_wunlock((rm))
end_define

begin_define
define|#
directive|define
name|rm_rlock
parameter_list|(
name|rm
parameter_list|,
name|tracker
parameter_list|)
value|((void)_rm_rlock((rm),(tracker), 0))
end_define

begin_define
define|#
directive|define
name|rm_try_rlock
parameter_list|(
name|rm
parameter_list|,
name|tracker
parameter_list|)
value|_rm_rlock((rm),(tracker), 1)
end_define

begin_define
define|#
directive|define
name|rm_runlock
parameter_list|(
name|rm
parameter_list|,
name|tracker
parameter_list|)
value|_rm_runlock((rm), (tracker))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|rm_sleep
parameter_list|(
name|chan
parameter_list|,
name|rm
parameter_list|,
name|pri
parameter_list|,
name|wmesg
parameter_list|,
name|timo
parameter_list|)
define|\
value|_sleep((chan),&(rm)->lock_object, (pri), (wmesg),		\ 	    tick_sbt * (timo), 0, C_HARDCLOCK)
end_define

begin_struct
struct|struct
name|rm_args
block|{
name|struct
name|rmlock
modifier|*
name|ra_rm
decl_stmt|;
specifier|const
name|char
modifier|*
name|ra_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rm_args_flags
block|{
name|struct
name|rmlock
modifier|*
name|ra_rm
decl_stmt|;
specifier|const
name|char
modifier|*
name|ra_desc
decl_stmt|;
name|int
name|ra_opts
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RM_SYSINIT
parameter_list|(
name|name
parameter_list|,
name|rm
parameter_list|,
name|desc
parameter_list|)
define|\
value|static struct rm_args name##_args = {				\ 		(rm),							\ 		(desc),							\ 	};								\ 	SYSINIT(name##_rm_sysinit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    rm_sysinit,&name##_args);					\ 	SYSUNINIT(name##_rm_sysuninit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    rm_destroy, (rm))
end_define

begin_define
define|#
directive|define
name|RM_SYSINIT_FLAGS
parameter_list|(
name|name
parameter_list|,
name|rm
parameter_list|,
name|desc
parameter_list|,
name|opts
parameter_list|)
define|\
value|static struct rm_args name##_args = {				\ 		(rm),							\ 		(desc),							\                 (opts),							\ 	};								\ 	SYSINIT(name##_rm_sysinit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    rm_sysinit_flags,&name##_args);				\ 	SYSUNINIT(name##_rm_sysuninit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    rm_destroy, (rm))
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
name|RA_LOCKED
value|LA_LOCKED
end_define

begin_define
define|#
directive|define
name|RA_RLOCKED
value|LA_SLOCKED
end_define

begin_define
define|#
directive|define
name|RA_WLOCKED
value|LA_XLOCKED
end_define

begin_define
define|#
directive|define
name|RA_UNLOCKED
value|LA_UNLOCKED
end_define

begin_define
define|#
directive|define
name|RA_RECURSED
value|LA_RECURSED
end_define

begin_define
define|#
directive|define
name|RA_NOTRECURSED
value|LA_NOTRECURSED
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
name|rm_assert
parameter_list|(
name|rm
parameter_list|,
name|what
parameter_list|)
value|_rm_assert((rm), (what), LOCK_FILE, LOCK_LINE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|rm_assert
parameter_list|(
name|rm
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
comment|/* !_SYS_RMLOCK_H_ */
end_comment

end_unit

