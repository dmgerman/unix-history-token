begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== pthread.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@athena.mit.edu  *  * Description : Basic pthread header.  *  *  1.00 93/07/20 proven  *      -Started coding this file.  */
end_comment

begin_include
include|#
directive|include
file|<pthread/copyright.h>
end_include

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

begin_comment
comment|/* #include<pthread/stdio.h> Because I'm a moron -- proven */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* More includes, that need size_t or NULL */
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
name|PS_DEAD
block|}
enum|;
end_enum

begin_struct
struct|struct
name|pthread
block|{
name|struct
name|machdep_pthread
name|machdep_data
decl_stmt|;
name|struct
name|pthread_queue
modifier|*
name|queue
decl_stmt|;
name|enum
name|pthread_state
name|state
decl_stmt|;
name|pthread_attr_t
name|attr
decl_stmt|;
comment|/* 	 * Thread implementations are just multiple queue type implemenations, 	 * Below are the various link lists currently necessary 	 * It is possible for a thread to be on multiple, or even all the 	 * queues at once, much care must be taken during queue manipulation. 	 */
name|struct
name|pthread
modifier|*
name|pll
decl_stmt|;
comment|/* ALL threads, in any state */
comment|/* struct pthread		*rll;		/* Current run queue, before resced */
name|struct
name|pthread
modifier|*
name|next
decl_stmt|;
comment|/* Standard for mutexes, etc ... */
name|struct
name|pthread
modifier|*
name|s_next
decl_stmt|;
comment|/* For sleeping threads */
comment|/* struct pthread			*fd_next;	/* For kernel fd operations */
name|int
name|fd
decl_stmt|;
comment|/* Used when thread waiting on fd */
name|semaphore
name|lock
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

