begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Attilio Rao<attilio@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer as  *    the first lines of this file unmodified other than the possible   *    addition of one or more copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LOCKMGR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LOCKMGR_H_
end_define

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lockmgr.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/_rwlock.h>
end_include

begin_define
define|#
directive|define
name|LK_SHARE
value|0x01
end_define

begin_define
define|#
directive|define
name|LK_SHARED_WAITERS
value|0x02
end_define

begin_define
define|#
directive|define
name|LK_EXCLUSIVE_WAITERS
value|0x04
end_define

begin_define
define|#
directive|define
name|LK_EXCLUSIVE_SPINNERS
value|0x08
end_define

begin_define
define|#
directive|define
name|LK_ALL_WAITERS
define|\
value|(LK_SHARED_WAITERS | LK_EXCLUSIVE_WAITERS)
end_define

begin_define
define|#
directive|define
name|LK_FLAGMASK
define|\
value|(LK_SHARE | LK_ALL_WAITERS | LK_EXCLUSIVE_SPINNERS)
end_define

begin_define
define|#
directive|define
name|LK_HOLDER
parameter_list|(
name|x
parameter_list|)
value|((x)& ~LK_FLAGMASK)
end_define

begin_define
define|#
directive|define
name|LK_SHARERS_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|LK_SHARERS
parameter_list|(
name|x
parameter_list|)
value|(LK_HOLDER(x)>> LK_SHARERS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LK_SHARERS_LOCK
parameter_list|(
name|x
parameter_list|)
value|((x)<< LK_SHARERS_SHIFT | LK_SHARE)
end_define

begin_define
define|#
directive|define
name|LK_ONE_SHARER
value|(1<< LK_SHARERS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LK_UNLOCKED
value|LK_SHARERS_LOCK(0)
end_define

begin_define
define|#
directive|define
name|LK_KERNPROC
value|((uintptr_t)(-1)& ~LK_FLAGMASK)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCK_FILE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|LOCK_LINE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"LOCK_FILE and LOCK_LINE not defined, include<sys/lock.h> before"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|lk_recurse
value|lock_object.lo_data
end_define

begin_comment
comment|/*  * Function prototipes.  Routines that start with an underscore are not part  * of the public interface and might be wrappered with a macro.  */
end_comment

begin_function_decl
name|int
name|__lockmgr_args
parameter_list|(
name|struct
name|lock
modifier|*
name|lk
parameter_list|,
name|u_int
name|flags
parameter_list|,
name|struct
name|lock_object
modifier|*
name|ilk
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|prio
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
name|_lockmgr_assert
parameter_list|(
name|struct
name|lock
modifier|*
name|lk
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

begin_function_decl
name|void
name|_lockmgr_disown
parameter_list|(
name|struct
name|lock
modifier|*
name|lk
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
name|lockdestroy
parameter_list|(
name|struct
name|lock
modifier|*
name|lk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lockinit
parameter_list|(
name|struct
name|lock
modifier|*
name|lk
parameter_list|,
name|int
name|prio
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|timo
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_function_decl
name|int
name|lockmgr_chain
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

begin_function_decl
name|void
name|lockmgr_printinfo
parameter_list|(
name|struct
name|lock
modifier|*
name|lk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lockstatus
parameter_list|(
name|struct
name|lock
modifier|*
name|lk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * As far as the ilk can be a static NULL pointer these functions need a  * strict prototype in order to safely use the lock_object member.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|_lockmgr_args
parameter_list|(
name|struct
name|lock
modifier|*
name|lk
parameter_list|,
name|u_int
name|flags
parameter_list|,
name|struct
name|mtx
modifier|*
name|ilk
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|prio
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
block|{
return|return
operator|(
name|__lockmgr_args
argument_list|(
name|lk
argument_list|,
name|flags
argument_list|,
operator|(
name|ilk
operator|!=
name|NULL
operator|)
condition|?
operator|&
name|ilk
operator|->
name|lock_object
else|:
name|NULL
argument_list|,
name|wmesg
argument_list|,
name|prio
argument_list|,
name|timo
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|_lockmgr_args_rw
parameter_list|(
name|struct
name|lock
modifier|*
name|lk
parameter_list|,
name|u_int
name|flags
parameter_list|,
name|struct
name|rwlock
modifier|*
name|ilk
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|prio
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
block|{
return|return
operator|(
name|__lockmgr_args
argument_list|(
name|lk
argument_list|,
name|flags
argument_list|,
operator|(
name|ilk
operator|!=
name|NULL
operator|)
condition|?
operator|&
name|ilk
operator|->
name|lock_object
else|:
name|NULL
argument_list|,
name|wmesg
argument_list|,
name|prio
argument_list|,
name|timo
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Define aliases in order to complete lockmgr KPI.  */
end_comment

begin_define
define|#
directive|define
name|lockmgr
parameter_list|(
name|lk
parameter_list|,
name|flags
parameter_list|,
name|ilk
parameter_list|)
define|\
value|_lockmgr_args((lk), (flags), (ilk), LK_WMESG_DEFAULT,		\ 	    LK_PRIO_DEFAULT, LK_TIMO_DEFAULT, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|lockmgr_args
parameter_list|(
name|lk
parameter_list|,
name|flags
parameter_list|,
name|ilk
parameter_list|,
name|wmesg
parameter_list|,
name|prio
parameter_list|,
name|timo
parameter_list|)
define|\
value|_lockmgr_args((lk), (flags), (ilk), (wmesg), (prio), (timo),	\ 	    LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|lockmgr_args_rw
parameter_list|(
name|lk
parameter_list|,
name|flags
parameter_list|,
name|ilk
parameter_list|,
name|wmesg
parameter_list|,
name|prio
parameter_list|,
name|timo
parameter_list|)
define|\
value|_lockmgr_args_rw((lk), (flags), (ilk), (wmesg), (prio), (timo),	\ 	    LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|lockmgr_disown
parameter_list|(
name|lk
parameter_list|)
define|\
value|_lockmgr_disown((lk), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|lockmgr_recursed
parameter_list|(
name|lk
parameter_list|)
define|\
value|((lk)->lk_recurse != 0)
end_define

begin_define
define|#
directive|define
name|lockmgr_rw
parameter_list|(
name|lk
parameter_list|,
name|flags
parameter_list|,
name|ilk
parameter_list|)
define|\
value|_lockmgr_args_rw((lk), (flags), (ilk), LK_WMESG_DEFAULT,	\ 	    LK_PRIO_DEFAULT, LK_TIMO_DEFAULT, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|lockmgr_waiters
parameter_list|(
name|lk
parameter_list|)
define|\
value|((lk)->lk_lock& LK_ALL_WAITERS)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|lockmgr_assert
parameter_list|(
name|lk
parameter_list|,
name|what
parameter_list|)
define|\
value|_lockmgr_assert((lk), (what), LOCK_FILE, LOCK_LINE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|lockmgr_assert
parameter_list|(
name|lk
parameter_list|,
name|what
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Flags for lockinit().  */
end_comment

begin_define
define|#
directive|define
name|LK_INIT_MASK
value|0x0000FF
end_define

begin_define
define|#
directive|define
name|LK_CANRECURSE
value|0x000001
end_define

begin_define
define|#
directive|define
name|LK_NODUP
value|0x000002
end_define

begin_define
define|#
directive|define
name|LK_NOPROFILE
value|0x000004
end_define

begin_define
define|#
directive|define
name|LK_NOSHARE
value|0x000008
end_define

begin_define
define|#
directive|define
name|LK_NOWITNESS
value|0x000010
end_define

begin_define
define|#
directive|define
name|LK_QUIET
value|0x000020
end_define

begin_define
define|#
directive|define
name|LK_ADAPTIVE
value|0x000040
end_define

begin_comment
comment|/* LK_EXSLPFAIL to follow, even if not used in lockinit() */
end_comment

begin_define
define|#
directive|define
name|LK_EXSLPFAIL
value|0x000080
end_define

begin_comment
comment|/*  * Additional attributes to be used in lockmgr().  */
end_comment

begin_define
define|#
directive|define
name|LK_EATTR_MASK
value|0x00FF00
end_define

begin_define
define|#
directive|define
name|LK_INTERLOCK
value|0x000100
end_define

begin_define
define|#
directive|define
name|LK_NOWAIT
value|0x000200
end_define

begin_define
define|#
directive|define
name|LK_RETRY
value|0x000400
end_define

begin_define
define|#
directive|define
name|LK_SLEEPFAIL
value|0x000800
end_define

begin_define
define|#
directive|define
name|LK_TIMELOCK
value|0x001000
end_define

begin_comment
comment|/*  * Operations for lockmgr().  */
end_comment

begin_define
define|#
directive|define
name|LK_TYPE_MASK
value|0xFF0000
end_define

begin_define
define|#
directive|define
name|LK_DOWNGRADE
value|0x010000
end_define

begin_define
define|#
directive|define
name|LK_DRAIN
value|0x020000
end_define

begin_define
define|#
directive|define
name|LK_EXCLOTHER
value|0x040000
end_define

begin_define
define|#
directive|define
name|LK_EXCLUSIVE
value|0x080000
end_define

begin_define
define|#
directive|define
name|LK_RELEASE
value|0x100000
end_define

begin_define
define|#
directive|define
name|LK_SHARED
value|0x200000
end_define

begin_define
define|#
directive|define
name|LK_UPGRADE
value|0x400000
end_define

begin_define
define|#
directive|define
name|LK_TOTAL_MASK
value|(LK_INIT_MASK | LK_EATTR_MASK | LK_TYPE_MASK)
end_define

begin_comment
comment|/*  * Default values for lockmgr_args().  */
end_comment

begin_define
define|#
directive|define
name|LK_WMESG_DEFAULT
value|(NULL)
end_define

begin_define
define|#
directive|define
name|LK_PRIO_DEFAULT
value|(0)
end_define

begin_define
define|#
directive|define
name|LK_TIMO_DEFAULT
value|(0)
end_define

begin_comment
comment|/*  * Assertion flags.  */
end_comment

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
name|KA_LOCKED
value|LA_LOCKED
end_define

begin_define
define|#
directive|define
name|KA_SLOCKED
value|LA_SLOCKED
end_define

begin_define
define|#
directive|define
name|KA_XLOCKED
value|LA_XLOCKED
end_define

begin_define
define|#
directive|define
name|KA_UNLOCKED
value|LA_UNLOCKED
end_define

begin_define
define|#
directive|define
name|KA_RECURSED
value|LA_RECURSED
end_define

begin_define
define|#
directive|define
name|KA_NOTRECURSED
value|LA_NOTRECURSED
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
comment|/* !_SYS_LOCKMGR_H_ */
end_comment

end_unit

