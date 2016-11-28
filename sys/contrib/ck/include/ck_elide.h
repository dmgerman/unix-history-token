begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013-2015 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_ELIDE_H
end_ifndef

begin_define
define|#
directive|define
name|CK_ELIDE_H
end_define

begin_comment
comment|/*  * As RTM is currently only supported on TSO x86 architectures,  * fences have been omitted. They will be necessary for other  * non-TSO architectures with TM support.  */
end_comment

begin_include
include|#
directive|include
file|<ck_cc.h>
end_include

begin_include
include|#
directive|include
file|<ck_pr.h>
end_include

begin_include
include|#
directive|include
file|<ck_string.h>
end_include

begin_comment
comment|/*  * skip_-prefixed counters represent the number of consecutive  * elisions to forfeit. retry_-prefixed counters represent the  * number of elision retries to attempt before forfeit.  *  *     _busy: Lock was busy  *    _other: Unknown explicit abort  * _conflict: Data conflict in elision section  */
end_comment

begin_struct
struct|struct
name|ck_elide_config
block|{
name|unsigned
name|short
name|skip_busy
decl_stmt|;
name|short
name|retry_busy
decl_stmt|;
name|unsigned
name|short
name|skip_other
decl_stmt|;
name|short
name|retry_other
decl_stmt|;
name|unsigned
name|short
name|skip_conflict
decl_stmt|;
name|short
name|retry_conflict
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CK_ELIDE_CONFIG_DEFAULT_INITIALIZER
value|{	\ 	.skip_busy = 5,				\ 	.retry_busy = 256,			\ 	.skip_other = 3,			\ 	.retry_other = 3,			\ 	.skip_conflict = 2,			\ 	.retry_conflict = 5			\ }
end_define

begin_struct
struct|struct
name|ck_elide_stat
block|{
name|unsigned
name|int
name|n_fallback
decl_stmt|;
name|unsigned
name|int
name|n_elide
decl_stmt|;
name|unsigned
name|short
name|skip
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ck_elide_stat
name|ck_elide_stat_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CK_ELIDE_STAT_INITIALIZER
value|{ 0, 0, 0 }
end_define

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_elide_stat_init
parameter_list|(
name|ck_elide_stat_t
modifier|*
name|st
parameter_list|)
block|{
name|memset
argument_list|(
name|st
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|st
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|CK_F_PR_RTM
end_ifdef

begin_enum
enum|enum
name|_ck_elide_hint
block|{
name|CK_ELIDE_HINT_RETRY
init|=
literal|0
block|,
name|CK_ELIDE_HINT_SPIN
block|,
name|CK_ELIDE_HINT_STOP
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|CK_ELIDE_LOCK_BUSY
value|0xFF
end_define

begin_function
specifier|static
name|enum
name|_ck_elide_hint
name|_ck_elide_fallback
parameter_list|(
name|int
modifier|*
name|retry
parameter_list|,
name|struct
name|ck_elide_stat
modifier|*
name|st
parameter_list|,
name|struct
name|ck_elide_config
modifier|*
name|c
parameter_list|,
name|unsigned
name|int
name|status
parameter_list|)
block|{
name|st
operator|->
name|n_fallback
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|retry
operator|>
literal|0
condition|)
return|return
name|CK_ELIDE_HINT_RETRY
return|;
if|if
condition|(
name|st
operator|->
name|skip
operator|!=
literal|0
condition|)
return|return
name|CK_ELIDE_HINT_STOP
return|;
if|if
condition|(
name|status
operator|&
name|CK_PR_RTM_EXPLICIT
condition|)
block|{
if|if
condition|(
name|CK_PR_RTM_CODE
argument_list|(
name|status
argument_list|)
operator|==
name|CK_ELIDE_LOCK_BUSY
condition|)
block|{
name|st
operator|->
name|skip
operator|=
name|c
operator|->
name|skip_busy
expr_stmt|;
operator|*
name|retry
operator|=
name|c
operator|->
name|retry_busy
expr_stmt|;
return|return
name|CK_ELIDE_HINT_SPIN
return|;
block|}
name|st
operator|->
name|skip
operator|=
name|c
operator|->
name|skip_other
expr_stmt|;
return|return
name|CK_ELIDE_HINT_STOP
return|;
block|}
if|if
condition|(
operator|(
name|status
operator|&
name|CK_PR_RTM_RETRY
operator|)
operator|&&
operator|(
name|status
operator|&
name|CK_PR_RTM_CONFLICT
operator|)
condition|)
block|{
name|st
operator|->
name|skip
operator|=
name|c
operator|->
name|skip_conflict
expr_stmt|;
operator|*
name|retry
operator|=
name|c
operator|->
name|retry_conflict
expr_stmt|;
return|return
name|CK_ELIDE_HINT_RETRY
return|;
block|}
comment|/* 	 * Capacity, debug and nesting abortions are likely to be 	 * invariant conditions for the acquisition, execute regular 	 * path instead. If retry bit is not set, then take the hint. 	 */
name|st
operator|->
name|skip
operator|=
name|USHRT_MAX
expr_stmt|;
return|return
name|CK_ELIDE_HINT_STOP
return|;
block|}
end_function

begin_comment
comment|/*  * Defines an elision implementation according to the following variables:  *     N - Namespace of elision implementation.  *     T - Typename of mutex.  *   L_P - Lock predicate, returns false if resource is available.  *     L - Function to call if resource is unavailable of transaction aborts.  *   U_P - Unlock predicate, returns false if elision failed.  *     U - Function to call if transaction failed.  */
end_comment

begin_define
define|#
directive|define
name|CK_ELIDE_PROTOTYPE
parameter_list|(
name|N
parameter_list|,
name|T
parameter_list|,
name|L_P
parameter_list|,
name|L
parameter_list|,
name|U_P
parameter_list|,
name|U
parameter_list|)
define|\
value|CK_CC_INLINE static void							\ 	ck_elide_##N##_lock_adaptive(T *lock,						\ 	    struct ck_elide_stat *st,							\ 	    struct ck_elide_config *c)							\ 	{										\ 		enum _ck_elide_hint hint;						\ 		int retry;								\ 											\ 		if (CK_CC_UNLIKELY(st->skip != 0)) {					\ 			st->skip--;							\ 			goto acquire;							\ 		}									\ 											\ 		retry = c->retry_conflict;						\ 		do {									\ 			unsigned int status = ck_pr_rtm_begin();			\ 			if (status == CK_PR_RTM_STARTED) {				\ 				if (L_P(lock) == true)					\ 					ck_pr_rtm_abort(CK_ELIDE_LOCK_BUSY);		\ 											\ 				return;							\ 			}								\ 											\ 			hint = _ck_elide_fallback(&retry, st, c, status);		\ 			if (hint == CK_ELIDE_HINT_RETRY)				\ 				continue;						\ 											\ 			if (hint == CK_ELIDE_HINT_SPIN) {				\ 				while (--retry != 0) {					\ 					if (L_P(lock) == false)				\ 						break;					\ 											\ 					ck_pr_stall();					\ 				}							\ 											\ 				continue;						\ 			}								\ 											\ 			if (hint == CK_ELIDE_HINT_STOP)					\ 				break;							\ 		} while (CK_CC_LIKELY(--retry> 0));					\ 											\ 	acquire:									\ 		L(lock);								\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_elide_##N##_unlock_adaptive(struct ck_elide_stat *st, T *lock)		\ 	{										\ 											\ 		if (U_P(lock) == false) {						\ 			ck_pr_rtm_end();						\ 			st->skip = 0;							\ 			st->n_elide++;							\ 		} else {								\ 			U(lock);							\ 		}									\ 											\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_elide_##N##_lock(T *lock)							\ 	{										\ 											\ 		if (ck_pr_rtm_begin() != CK_PR_RTM_STARTED) {				\ 			L(lock);							\ 			return;								\ 		}									\ 											\ 		if (L_P(lock) == true)							\ 			ck_pr_rtm_abort(CK_ELIDE_LOCK_BUSY);				\ 											\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_elide_##N##_unlock(T *lock)							\ 	{										\ 											\ 		if (U_P(lock) == false) {						\ 			ck_pr_rtm_end();						\ 		} else {								\ 			U(lock);							\ 		}									\ 											\ 		return;									\ 	}
end_define

begin_define
define|#
directive|define
name|CK_ELIDE_TRYLOCK_PROTOTYPE
parameter_list|(
name|N
parameter_list|,
name|T
parameter_list|,
name|TL_P
parameter_list|,
name|TL
parameter_list|)
define|\
value|CK_CC_INLINE static bool					\ 	ck_elide_##N##_trylock(T *lock)					\ 	{								\ 									\ 		if (ck_pr_rtm_begin() != CK_PR_RTM_STARTED)		\ 			return false;					\ 									\ 		if (TL_P(lock) == true)					\ 			ck_pr_rtm_abort(CK_ELIDE_LOCK_BUSY);		\ 									\ 		return true;						\ 	}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * If RTM is not enabled on the target platform (CK_F_PR_RTM) then these  * elision wrappers directly calls into the user-specified lock operations.  * Unfortunately, the storage cost of both ck_elide_config and ck_elide_stat  * are paid (typically a storage cost that is a function of lock objects and  * thread count).  */
end_comment

begin_define
define|#
directive|define
name|CK_ELIDE_PROTOTYPE
parameter_list|(
name|N
parameter_list|,
name|T
parameter_list|,
name|L_P
parameter_list|,
name|L
parameter_list|,
name|U_P
parameter_list|,
name|U
parameter_list|)
define|\
value|CK_CC_INLINE static void					\ 	ck_elide_##N##_lock_adaptive(T *lock,				\ 	    struct ck_elide_stat *st,					\ 	    struct ck_elide_config *c)					\ 	{								\ 									\ 		(void)st;						\ 		(void)c;						\ 		L(lock);						\ 		return;							\ 	}								\ 	CK_CC_INLINE static void					\ 	ck_elide_##N##_unlock_adaptive(struct ck_elide_stat *st,	\ 	    T *lock)							\ 	{								\ 									\ 		(void)st;						\ 		U(lock);						\ 		return;							\ 	}								\ 	CK_CC_INLINE static void					\ 	ck_elide_##N##_lock(T *lock)					\ 	{								\ 									\ 		L(lock);						\ 		return;							\ 	}								\ 	CK_CC_INLINE static void					\ 	ck_elide_##N##_unlock(T *lock)					\ 	{								\ 									\ 		U(lock);						\ 		return;							\ 	}
end_define

begin_define
define|#
directive|define
name|CK_ELIDE_TRYLOCK_PROTOTYPE
parameter_list|(
name|N
parameter_list|,
name|T
parameter_list|,
name|TL_P
parameter_list|,
name|TL
parameter_list|)
define|\
value|CK_CC_INLINE static bool					\ 	ck_elide_##N##_trylock(T *lock)					\ 	{								\ 									\ 		return TL_P(lock);					\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CK_F_PR_RTM */
end_comment

begin_comment
comment|/*  * Best-effort elision lock operations. First argument is name (N)  * associated with implementation and the second is a pointer to  * the type specified above (T).  *  * Unlike the adaptive variant, this interface does not have any retry  * semantics. In environments where jitter is low, this may yield a tighter  * fast path.  */
end_comment

begin_define
define|#
directive|define
name|CK_ELIDE_LOCK
parameter_list|(
name|NAME
parameter_list|,
name|LOCK
parameter_list|)
value|ck_elide_##NAME##_lock(LOCK)
end_define

begin_define
define|#
directive|define
name|CK_ELIDE_UNLOCK
parameter_list|(
name|NAME
parameter_list|,
name|LOCK
parameter_list|)
value|ck_elide_##NAME##_unlock(LOCK)
end_define

begin_define
define|#
directive|define
name|CK_ELIDE_TRYLOCK
parameter_list|(
name|NAME
parameter_list|,
name|LOCK
parameter_list|)
value|ck_elide_##NAME##_trylock(LOCK)
end_define

begin_comment
comment|/*  * Adaptive elision lock operations. In addition to name and pointer  * to the lock, you must pass in a pointer to an initialized  * ck_elide_config structure along with a per-thread stat structure.  */
end_comment

begin_define
define|#
directive|define
name|CK_ELIDE_LOCK_ADAPTIVE
parameter_list|(
name|NAME
parameter_list|,
name|STAT
parameter_list|,
name|CONFIG
parameter_list|,
name|LOCK
parameter_list|)
define|\
value|ck_elide_##NAME##_lock_adaptive(LOCK, STAT, CONFIG)
end_define

begin_define
define|#
directive|define
name|CK_ELIDE_UNLOCK_ADAPTIVE
parameter_list|(
name|NAME
parameter_list|,
name|STAT
parameter_list|,
name|LOCK
parameter_list|)
define|\
value|ck_elide_##NAME##_unlock_adaptive(STAT, LOCK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ELIDE_H */
end_comment

end_unit

