begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  *  * POSIX 1003.1c scheduling definitions.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCHED_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCHED_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/*  * Scheduling policies (unimplemented)  */
end_comment

begin_define
define|#
directive|define
name|SCHED_FIFO
value|0
end_define

begin_comment
comment|/* First in-first out scheduling policy.  */
end_comment

begin_define
define|#
directive|define
name|SCHED_RR
value|1
end_define

begin_comment
comment|/* Round robin scheduling policy.         */
end_comment

begin_define
define|#
directive|define
name|SCHED_OTHER
value|2
end_define

begin_comment
comment|/* Another scheduling policy.             */
end_comment

begin_comment
comment|/*  * POSIX 1003.1 scheduling parameter structure.  */
end_comment

begin_struct
struct|struct
name|sched_param
block|{
name|int
name|sched_priority
decl_stmt|;
comment|/* Process execution scheduling priority. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scheduling function prototype definitions.  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|sched_getparam
name|__P
argument_list|(
operator|(
name|pid_t
operator|,
specifier|const
expr|struct
name|sched_param
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sched_getscheduler
name|__P
argument_list|(
operator|(
name|pid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sched_get_priority_max
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sched_get_priority_min
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sched_rr_get_interval
name|__P
argument_list|(
operator|(
name|pid_t
operator|,
expr|struct
name|timespec
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sched_setparam
name|__P
argument_list|(
operator|(
name|pid_t
operator|,
specifier|const
expr|struct
name|sched_param
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sched_setscheduler
name|__P
argument_list|(
operator|(
name|pid_t
operator|,
name|int
operator|,
specifier|const
expr|struct
name|sched_param
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sched_yield
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCHED_H_ */
end_comment

end_unit

