begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== pthread.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * Description : Basic pthread header.  *  *  1.00 93/07/20 proven  *      -Started coding this file.  */
end_comment

begin_include
include|#
directive|include
file|<pthread/engine.h>
end_include

begin_include
include|#
directive|include
file|<pthread/kernel.h>
end_include

begin_include
include|#
directive|include
file|<pthread/queue.h>
end_include

begin_include
include|#
directive|include
file|<pthread/mutex.h>
end_include

begin_include
include|#
directive|include
file|<pthread/cond.h>
end_include

begin_include
include|#
directive|include
file|<pthread/fd.h>
end_include

begin_include
include|#
directive|include
file|<pthread/util.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* More includes */
end_comment

begin_include
include|#
directive|include
file|<pthread/pthread_once.h>
end_include

begin_comment
comment|/* More includes, that need size_t */
end_comment

begin_include
include|#
directive|include
file|<pthread/pthread_attr.h>
end_include

begin_enum
enum|enum
name|pthread_state
block|{
name|PS_RUNNING
block|,
name|PS_MUTEX_WAIT
block|,
name|PS_COND_WAIT
block|,
name|PS_FDLR_WAIT
block|,
name|PS_FDLW_WAIT
block|,
name|PS_FDR_WAIT
block|,
name|PS_FDW_WAIT
block|,
name|PS_SLEEP_WAIT
block|,
name|PS_JOIN
block|,
name|PS_DEAD
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PF_DETACHED
value|0x00000001
end_define

begin_struct
struct|struct
name|pthread
block|{
name|struct
name|machdep_pthread
name|machdep_data
decl_stmt|;
name|enum
name|pthread_state
name|state
decl_stmt|;
name|pthread_attr_t
name|attr
decl_stmt|;
comment|/* Other flags */
name|int
name|flags
decl_stmt|;
comment|/* Time until timeout */
name|int
name|time_sec
decl_stmt|;
name|int
name|time_usec
decl_stmt|;
comment|/* Join queue for waiting threads */
name|struct
name|pthread_queue
name|join_queue
decl_stmt|;
comment|/* Queue thread is waiting on, (mutexes, cond. etc.) */
name|struct
name|pthread_queue
modifier|*
name|queue
decl_stmt|;
comment|/* 	 * Thread implementations are just multiple queue type implemenations, 	 * Below are the various link lists currently necessary 	 * It is possible for a thread to be on multiple, or even all the 	 * queues at once, much care must be taken during queue manipulation. 	 *      * The pthread structure must be locked before you can even look at 	 * the link lists. 	 */
name|struct
name|pthread
modifier|*
name|pll
decl_stmt|;
comment|/* ALL threads, in any state */
comment|/* struct pthread		*rll;		 Current run queue, before resced */
name|struct
name|pthread
modifier|*
name|sll
decl_stmt|;
comment|/* For sleeping threads */
name|struct
name|pthread
modifier|*
name|next
decl_stmt|;
comment|/* Standard for mutexes, etc ... */
comment|/* struct pthread			*fd_next;	 For kernel fd operations */
name|int
name|fd
decl_stmt|;
comment|/* Used when thread waiting on fd */
name|semaphore
name|lock
decl_stmt|;
name|void
modifier|*
name|ret
decl_stmt|;
name|int
name|error
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pthread
modifier|*
name|pthread_t
typedef|;
end_typedef

begin_comment
comment|/*  * Globals  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pthread
modifier|*
name|pthread_run
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pthread
modifier|*
name|pthread_initial
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pthread
modifier|*
name|pthread_link_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_attr_t
name|pthread_default_attr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pthread_queue
name|pthread_current_queue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fd_table_entry
modifier|*
name|fd_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * New functions  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|pthread_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_create
name|__P
argument_list|(
operator|(
name|pthread_t
operator|*
operator|,
specifier|const
name|pthread_attr_t
operator|*
operator|,
name|void
operator|*
call|(
modifier|*
name|start_routine
call|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pthread_exit
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_t
name|pthread_self
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_equal
name|__P
argument_list|(
operator|(
name|pthread_t
operator|,
name|pthread_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_join
name|__P
argument_list|(
operator|(
name|pthread_t
operator|,
name|void
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_detach
name|__P
argument_list|(
operator|(
name|pthread_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PTHREAD_KERNEL
argument_list|)
end_if

begin_decl_stmt
name|void
name|pthread_yield
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Not valid, but I can't spell so this will be caught at compile time */
end_comment

begin_define
define|#
directive|define
name|pthread_yeild
parameter_list|(
name|notvalid
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

end_unit

