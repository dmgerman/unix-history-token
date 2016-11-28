begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013-2015 Samy Al Bahra.  * Copyright 2013 Brendon Scheinman.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_RWCOHORT_H
end_ifndef

begin_define
define|#
directive|define
name|CK_RWCOHORT_H
end_define

begin_comment
comment|/*  * This is an implementation of NUMA-aware reader-writer locks as described in:  *     Calciu, I.; Dice, D.; Lev, Y.; Luchangco, V.; Marathe, V.; and Shavit, N. 2014.  *     NUMA-Aware Reader-Writer Locks  */
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

begin_include
include|#
directive|include
file|<ck_cohort.h>
end_include

begin_define
define|#
directive|define
name|CK_RWCOHORT_WP_NAME
parameter_list|(
name|N
parameter_list|)
value|ck_rwcohort_wp_##N
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_WP_INSTANCE
parameter_list|(
name|N
parameter_list|)
value|struct CK_RWCOHORT_WP_NAME(N)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_WP_INIT
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|WL
parameter_list|)
value|ck_rwcohort_wp_##N##_init(RW, WL)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_WP_READ_LOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_wp_##N##_read_lock(RW, C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_WP_READ_UNLOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_wp_##N##_read_unlock(RW)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_WP_WRITE_LOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_wp_##N##_write_lock(RW, C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_WP_WRITE_UNLOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_wp_##N##_write_unlock(RW, C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_WP_DEFAULT_WAIT_LIMIT
value|1000
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_WP_PROTOTYPE
parameter_list|(
name|N
parameter_list|)
define|\
value|CK_RWCOHORT_WP_INSTANCE(N) {							\ 		unsigned int read_counter;						\ 		unsigned int write_barrier;						\ 		unsigned int wait_limit;						\ 	};										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_wp_##N##_init(CK_RWCOHORT_WP_INSTANCE(N) *rw_cohort,		\ 	    unsigned int wait_limit)							\ 	{										\ 											\ 		rw_cohort->read_counter = 0;						\ 		rw_cohort->write_barrier = 0;						\ 		rw_cohort->wait_limit = wait_limit;					\ 		ck_pr_barrier();							\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_wp_##N##_write_lock(CK_RWCOHORT_WP_INSTANCE(N) *rw_cohort,		\ 	    CK_COHORT_INSTANCE(N) *cohort, void *global_context,			\ 	    void *local_context)							\ 	{										\ 											\ 		while (ck_pr_load_uint(&rw_cohort->write_barrier)> 0)			\ 			ck_pr_stall();							\ 											\ 		CK_COHORT_LOCK(N, cohort, global_context, local_context);		\ 											\ 		while (ck_pr_load_uint(&rw_cohort->read_counter)> 0) 			\ 			ck_pr_stall();							\ 											\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_wp_##N##_write_unlock(CK_RWCOHORT_WP_INSTANCE(N) *rw_cohort,	\ 	    CK_COHORT_INSTANCE(N) *cohort, void *global_context,			\ 	    void *local_context)							\ 	{										\ 											\ 		(void)rw_cohort;							\ 		CK_COHORT_UNLOCK(N, cohort, global_context, local_context);		\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_wp_##N##_read_lock(CK_RWCOHORT_WP_INSTANCE(N) *rw_cohort,		\ 	    CK_COHORT_INSTANCE(N) *cohort, void *global_context,			\ 	    void *local_context)							\ 	{										\ 		unsigned int wait_count = 0;						\ 		bool raised = false;							\ 											\ 		for (;;) {								\ 			ck_pr_inc_uint(&rw_cohort->read_counter);			\ 			ck_pr_fence_atomic_load();					\ 			if (CK_COHORT_LOCKED(N, cohort, global_context,			\ 			    local_context) == false)					\ 				break;							\ 											\ 			ck_pr_dec_uint(&rw_cohort->read_counter);			\ 			while (CK_COHORT_LOCKED(N, cohort, global_context,		\ 			    local_context) == true) {					\ 				ck_pr_stall();						\ 				if (++wait_count> rw_cohort->wait_limit&&		\ 				    raised == false) {					\ 					ck_pr_inc_uint(&rw_cohort->write_barrier);	\ 					raised = true;					\ 				}							\ 			}								\ 		}									\ 											\ 		if (raised == true)							\ 			ck_pr_dec_uint(&rw_cohort->write_barrier);			\ 											\ 		ck_pr_fence_load();							\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_wp_##N##_read_unlock(CK_RWCOHORT_WP_INSTANCE(N) *cohort)		\ 	{										\ 											\ 		ck_pr_fence_load_atomic();						\ 		ck_pr_dec_uint(&cohort->read_counter);					\ 		return;									\ 	}
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_WP_INITIALIZER
value|{							\ 	.read_counter = 0,								\ 	.write_barrier = 0,								\ 	.wait_limit = 0									\ }
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_RP_NAME
parameter_list|(
name|N
parameter_list|)
value|ck_rwcohort_rp_##N
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_RP_INSTANCE
parameter_list|(
name|N
parameter_list|)
value|struct CK_RWCOHORT_RP_NAME(N)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_RP_INIT
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|WL
parameter_list|)
value|ck_rwcohort_rp_##N##_init(RW, WL)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_RP_READ_LOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_rp_##N##_read_lock(RW, C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_RP_READ_UNLOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_rp_##N##_read_unlock(RW)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_RP_WRITE_LOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_rp_##N##_write_lock(RW, C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_RP_WRITE_UNLOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_rp_##N##_write_unlock(RW, C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_RP_DEFAULT_WAIT_LIMIT
value|1000
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_RP_PROTOTYPE
parameter_list|(
name|N
parameter_list|)
define|\
value|CK_RWCOHORT_RP_INSTANCE(N) {							\ 		unsigned int read_counter;						\ 		unsigned int read_barrier;						\ 		unsigned int wait_limit;						\ 	};										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_rp_##N##_init(CK_RWCOHORT_RP_INSTANCE(N) *rw_cohort,		\ 	    unsigned int wait_limit)							\ 	{										\ 											\ 		rw_cohort->read_counter = 0;						\ 		rw_cohort->read_barrier = 0;						\ 		rw_cohort->wait_limit = wait_limit;					\ 		ck_pr_barrier();							\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_rp_##N##_write_lock(CK_RWCOHORT_RP_INSTANCE(N) *rw_cohort,		\ 	    CK_COHORT_INSTANCE(N) *cohort, void *global_context,			\ 	    void *local_context)							\ 	{										\ 		unsigned int wait_count = 0;						\ 		bool raised = false;							\ 											\ 		for (;;) {								\ 			CK_COHORT_LOCK(N, cohort, global_context, local_context);	\ 			if (ck_pr_load_uint(&rw_cohort->read_counter) == 0)		\ 				break;							\ 											\ 			CK_COHORT_UNLOCK(N, cohort, global_context, local_context);	\ 			while (ck_pr_load_uint(&rw_cohort->read_counter)> 0) {		\ 				ck_pr_stall();						\ 				if (++wait_count> rw_cohort->wait_limit&&		\ 				    raised == false) {					\ 					ck_pr_inc_uint(&rw_cohort->read_barrier);	\ 					raised = true;					\ 				}							\ 			}								\ 		}									\ 											\ 		if (raised == true)							\ 			ck_pr_dec_uint(&rw_cohort->read_barrier);			\ 											\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_rp_##N##_write_unlock(CK_RWCOHORT_RP_INSTANCE(N) *rw_cohort,	\ 	    CK_COHORT_INSTANCE(N) *cohort, void *global_context, void *local_context)	\ 	{										\ 											\ 		(void)rw_cohort;							\ 		CK_COHORT_UNLOCK(N, cohort, global_context, local_context);		\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_rp_##N##_read_lock(CK_RWCOHORT_RP_INSTANCE(N) *rw_cohort,		\ 	    CK_COHORT_INSTANCE(N) *cohort, void *global_context,			\ 	    void *local_context)							\ 	{										\ 											\ 		while (ck_pr_load_uint(&rw_cohort->read_barrier)> 0)			\ 			ck_pr_stall();							\ 											\ 		ck_pr_inc_uint(&rw_cohort->read_counter);				\ 		ck_pr_fence_atomic_load();						\ 											\ 		while (CK_COHORT_LOCKED(N, cohort, global_context,			\ 		    local_context) == true)						\ 			ck_pr_stall();							\ 											\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_rp_##N##_read_unlock(CK_RWCOHORT_RP_INSTANCE(N) *cohort)		\ 	{										\ 											\ 		ck_pr_fence_load_atomic();						\ 		ck_pr_dec_uint(&cohort->read_counter);					\ 		return;									\ 	}
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_RP_INITIALIZER
value|{							\ 	.read_counter = 0,								\ 	.read_barrier = 0,								\ 	.wait_limit = 0									\ }
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_NEUTRAL_NAME
parameter_list|(
name|N
parameter_list|)
value|ck_rwcohort_neutral_##N
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_NEUTRAL_INSTANCE
parameter_list|(
name|N
parameter_list|)
value|struct CK_RWCOHORT_NEUTRAL_NAME(N)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_NEUTRAL_INIT
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|)
value|ck_rwcohort_neutral_##N##_init(RW)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_NEUTRAL_READ_LOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_neutral_##N##_read_lock(RW, C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_NEUTRAL_READ_UNLOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_neutral_##N##_read_unlock(RW)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_NEUTRAL_WRITE_LOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_neutral_##N##_write_lock(RW, C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_NEUTRAL_WRITE_UNLOCK
parameter_list|(
name|N
parameter_list|,
name|RW
parameter_list|,
name|C
parameter_list|,
name|GC
parameter_list|,
name|LC
parameter_list|)
define|\
value|ck_rwcohort_neutral_##N##_write_unlock(RW, C, GC, LC)
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_NEUTRAL_DEFAULT_WAIT_LIMIT
value|1000
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_NEUTRAL_PROTOTYPE
parameter_list|(
name|N
parameter_list|)
define|\
value|CK_RWCOHORT_NEUTRAL_INSTANCE(N) {						\ 		unsigned int read_counter;						\ 	};										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_neutral_##N##_init(CK_RWCOHORT_NEUTRAL_INSTANCE(N) *rw_cohort)	\ 	{										\ 											\ 		rw_cohort->read_counter = 0;						\ 		ck_pr_barrier();							\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_neutral_##N##_write_lock(CK_RWCOHORT_NEUTRAL_INSTANCE(N) *rw_cohort,\ 	    CK_COHORT_INSTANCE(N) *cohort, void *global_context,			\ 	    void *local_context)							\ 	{										\ 											\ 		CK_COHORT_LOCK(N, cohort, global_context, local_context);		\ 		while (ck_pr_load_uint(&rw_cohort->read_counter)> 0) {			\ 			ck_pr_stall();							\ 		}									\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_neutral_##N##_write_unlock(CK_RWCOHORT_NEUTRAL_INSTANCE(N) *rw_cohort,\ 	    CK_COHORT_INSTANCE(N) *cohort, void *global_context, void *local_context)	\ 	{										\ 											\ 		(void)rw_cohort;							\ 		CK_COHORT_UNLOCK(N, cohort, global_context, local_context);		\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_neutral_##N##_read_lock(CK_RWCOHORT_NEUTRAL_INSTANCE(N) *rw_cohort,	\ 	    CK_COHORT_INSTANCE(N) *cohort, void *global_context,			\ 	    void *local_context)							\ 	{										\ 											\ 		CK_COHORT_LOCK(N, cohort, global_context, local_context);		\ 		ck_pr_inc_uint(&rw_cohort->read_counter);				\ 		CK_COHORT_UNLOCK(N, cohort, global_context, local_context);		\ 		return;									\ 	}										\ 	CK_CC_INLINE static void							\ 	ck_rwcohort_neutral_##N##_read_unlock(CK_RWCOHORT_NEUTRAL_INSTANCE(N) *cohort)	\ 	{										\ 											\ 		ck_pr_fence_load_atomic();						\ 		ck_pr_dec_uint(&cohort->read_counter);					\ 		return;									\ 	}
end_define

begin_define
define|#
directive|define
name|CK_RWCOHORT_NEUTRAL_INITIALIZER
value|{						\ 	.read_counter = 0,								\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_RWCOHORT_H */
end_comment

end_unit

