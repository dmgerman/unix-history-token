begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Daniel Eischen<eischen@vigrid.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Daniel Eischen.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY DANIEL EISCHEN AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_pthread_setschedparam
argument_list|,
name|pthread_setschedparam
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_pthread_setschedparam
parameter_list|(
name|pthread_t
name|pthread
parameter_list|,
name|int
name|policy
parameter_list|,
specifier|const
name|struct
name|sched_param
modifier|*
name|param
parameter_list|)
block|{
if|#
directive|if
literal|0
block|int old_prio = 0; 	int in_readyq = 0;
endif|#
directive|endif
name|int
name|ret
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|param
operator|==
name|NULL
operator|)
operator|||
operator|(
name|policy
operator|<
name|SCHED_FIFO
operator|)
operator|||
operator|(
name|policy
operator|>
name|SCHED_RR
operator|)
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
if|if
condition|(
operator|(
name|param
operator|->
name|sched_priority
operator|<
name|PTHREAD_MIN_PRIORITY
operator|)
operator|||
operator|(
name|param
operator|->
name|sched_priority
operator|>
name|PTHREAD_MAX_PRIORITY
operator|)
condition|)
return|return
operator|(
name|ENOTSUP
operator|)
return|;
if|#
directive|if
literal|0
comment|/* XXX pthread priorities don't work anyways */
comment|/* Find the thread in the list of active threads: */
block|if ((ret = _find_thread(pthread)) == 0) { 		GIANT_LOCK(curthread);  		if (param->sched_priority != 		    PTHREAD_BASE_PRIORITY(pthread->base_priority)) {
comment|/* 			 * Remove the thread from its current priority 			 * queue before any adjustments are made to its 			 * active priority: 			 */
block|old_prio = pthread->active_priority;
if|#
directive|if
literal|0
comment|/* XXXTHR */
block|if ((pthread->flags& PTHREAD_FLAGS_IN_PRIOQ) != 0) { 				in_readyq = 1; 				PTHREAD_PRIOQ_REMOVE(pthread); 			}
endif|#
directive|endif
comment|/* Set the thread base priority: */
block|pthread->base_priority&= 			    (PTHREAD_SIGNAL_PRIORITY | PTHREAD_RT_PRIORITY); 			pthread->base_priority = param->sched_priority;
comment|/* Recalculate the active priority: */
block|pthread->active_priority = MAX(pthread->base_priority, 			    pthread->inherited_priority);
if|#
directive|if
literal|0
block|if (in_readyq) { 				if ((pthread->priority_mutex_count> 0)&& 				    (old_prio> pthread->active_priority)) {
comment|/* 					 * POSIX states that if the priority is 					 * being lowered, the thread must be 					 * inserted at the head of the queue for 					 * its priority if it owns any priority 					 * protection or inheritence mutexes. 					 */
block|PTHREAD_PRIOQ_INSERT_HEAD(pthread); 				} 				else 					PTHREAD_PRIOQ_INSERT_TAIL(pthread); 			}
endif|#
directive|endif
comment|/* 			 * Check for any mutex priority adjustments.  This 			 * includes checking for a priority mutex on which 			 * this thread is waiting. 			 */
block|_mutex_notify_priochange(pthread); 		}
comment|/* Set the scheduling policy: */
block|pthread->attr.sched_policy = policy;  		GIANT_UNLOCK(curthread); 	}
endif|#
directive|endif
comment|/* XXX pthread priorities don't work anyways */
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

end_unit

