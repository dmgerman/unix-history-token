begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013-2015 Samy Al Bahra.  * Copyright 2013 Brendon Scheinman.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_COHORT_H
end_ifndef

begin_define
define|#
directive|define
name|CK_COHORT_H
end_define

begin_comment
comment|/*  * This is an implementation of lock cohorts as described in:  *     Dice, D.; Marathe, V.; and Shavit, N. 2012.  *     Lock Cohorting: A General Technique for Designing NUMA Locks  */
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
file|<ck_stddef.h>
end_include

begin_enum
enum|enum
name|ck_cohort_state
block|{
name|CK_COHORT_STATE_GLOBAL
init|=
literal|0
block|,
name|CK_COHORT_STATE_LOCAL
init|=
literal|1
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|CK_COHORT_DEFAULT_LOCAL_PASS_LIMIT
value|10
end_define

begin_define
define|#
directive|define
name|CK_COHORT_NAME
parameter_list|(
name|N
parameter_list|)
value|ck_cohort_##N
end_define

begin_define
define|#
directive|define
name|CK_COHORT_INSTANCE
parameter_list|(
name|N
parameter_list|)
value|struct CK_COHORT_NAME(N)
end_define

begin_define
define|#
directive|define
name|CK_COHORT_INIT
parameter_list|(
name|N
parameter_list|,
name|C
parameter_list|,
name|GL
parameter_list|,
name|LL
parameter_list|,
name|P
parameter_list|)
value|ck_cohort_##N##_init(C, GL, LL, P)
end_define

begin_define
define|#
directive|define
name|CK_COHORT_LOCK
parameter_list|(
name|N
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
value|ck_cohort_##N##_lock(C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_COHORT_UNLOCK
parameter_list|(
name|N
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
value|ck_cohort_##N##_unlock(C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_COHORT_TRYLOCK
parameter_list|(
name|N
parameter_list|,
name|C
parameter_list|,
name|GLC
parameter_list|,
name|LLC
parameter_list|,
name|LUC
parameter_list|)
value|ck_cohort_##N##_trylock(C, GLC, LLC, LUC)
end_define

begin_define
define|#
directive|define
name|CK_COHORT_LOCKED
parameter_list|(
name|N
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
value|ck_cohort_##N##_locked(C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_COHORT_PROTOTYPE
parameter_list|(
name|N
parameter_list|,
name|GL
parameter_list|,
name|GU
parameter_list|,
name|GI
parameter_list|,
name|LL
parameter_list|,
name|LU
parameter_list|,
name|LI
parameter_list|)
define|\
value|CK_COHORT_INSTANCE(N) {							\ 		void *global_lock;						\ 		void *local_lock;						\ 		enum ck_cohort_state release_state;				\ 		unsigned int waiting_threads;					\ 		unsigned int acquire_count;					\ 		unsigned int local_pass_limit;					\ 	};									\ 										\ 	CK_CC_INLINE static void						\ 	ck_cohort_##N##_init(struct ck_cohort_##N *cohort,			\ 	    void *global_lock, void *local_lock, unsigned int pass_limit)	\ 	{									\ 		cohort->global_lock = global_lock;				\ 		cohort->local_lock = local_lock;				\ 		cohort->release_state = CK_COHORT_STATE_GLOBAL;			\ 		cohort->waiting_threads = 0;					\ 		cohort->acquire_count = 0;					\ 		cohort->local_pass_limit = pass_limit;				\ 		ck_pr_barrier();						\ 		return;								\ 	}									\ 										\ 	CK_CC_INLINE static void						\ 	ck_cohort_##N##_lock(CK_COHORT_INSTANCE(N) *cohort,			\ 	    void *global_context, void *local_context)				\ 	{									\ 										\ 		ck_pr_inc_uint(&cohort->waiting_threads);			\ 		LL(cohort->local_lock, local_context);				\ 		ck_pr_dec_uint(&cohort->waiting_threads);			\ 										\ 		if (cohort->release_state == CK_COHORT_STATE_GLOBAL) {		\ 			GL(cohort->global_lock, global_context);		\ 		}								\ 										\ 		++cohort->acquire_count;					\ 		return;								\ 	}									\ 										\ 	CK_CC_INLINE static void						\ 	ck_cohort_##N##_unlock(CK_COHORT_INSTANCE(N) *cohort,			\ 	    void *global_context, void *local_context)				\ 	{									\ 										\ 		if (ck_pr_load_uint(&cohort->waiting_threads)> 0		\&& cohort->acquire_count< cohort->local_pass_limit) {	\ 			cohort->release_state = CK_COHORT_STATE_LOCAL;		\ 		} else {							\ 			GU(cohort->global_lock, global_context);		\ 			cohort->release_state = CK_COHORT_STATE_GLOBAL;		\ 			cohort->acquire_count = 0;				\ 		}								\ 										\ 		ck_pr_fence_release();						\ 		LU(cohort->local_lock, local_context);				\ 										\ 		return;								\ 	}									\ 										\ 	CK_CC_INLINE static bool						\ 	ck_cohort_##N##_locked(CK_COHORT_INSTANCE(N) *cohort,			\ 	    void *global_context, void *local_context)				\ 	{									\ 		return GI(cohort->local_lock, local_context) ||			\ 		    LI(cohort->global_lock, global_context);			\ 	}
end_define

begin_define
define|#
directive|define
name|CK_COHORT_TRYLOCK_PROTOTYPE
parameter_list|(
name|N
parameter_list|,
name|GL
parameter_list|,
name|GU
parameter_list|,
name|GI
parameter_list|,
name|GTL
parameter_list|,
name|LL
parameter_list|,
name|LU
parameter_list|,
name|LI
parameter_list|,
name|LTL
parameter_list|)
define|\
value|CK_COHORT_PROTOTYPE(N, GL, GU, GI, LL, LU, LI)				\ 	CK_CC_INLINE static bool						\ 	ck_cohort_##N##_trylock(CK_COHORT_INSTANCE(N) *cohort,			\ 	    void *global_context, void *local_context,				\ 	    void *local_unlock_context)						\ 	{									\ 										\ 		bool trylock_result;						\ 										\ 		ck_pr_inc_uint(&cohort->waiting_threads);			\ 		trylock_result = LTL(cohort->local_lock, local_context);	\ 		ck_pr_dec_uint(&cohort->waiting_threads);			\ 		if (trylock_result == false) {					\ 			return false;						\ 		}								\ 										\ 		if (cohort->release_state == CK_COHORT_STATE_GLOBAL&&		\ 		    GTL(cohort->global_lock, global_context) == false) {	\ 		    	LU(cohort->local_lock, local_unlock_context);		\ 			return false;						\ 		}								\ 										\ 		++cohort->acquire_count;					\ 		return true;							\ 	}
end_define

begin_define
define|#
directive|define
name|CK_COHORT_INITIALIZER
value|{							\ 	.global_lock = NULL,							\ 	.local_lock = NULL,							\ 	.release_state = CK_COHORT_STATE_GLOBAL,				\ 	.waiting_threads = 0,							\ 	.acquire_count = 0,							\ 	.local_pass_limit = CK_COHORT_DEFAULT_LOCAL_PASS_LIMIT			\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_COHORT_H */
end_comment

end_unit

