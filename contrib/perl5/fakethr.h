begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|int
name|perl_mutex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|perl_key
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|perl_thread
modifier|*
name|perl_os_thread
typedef|;
end_typedef

begin_comment
comment|/* With fake threads, thr is global(ish) so we don't need dTHR */
end_comment

begin_define
define|#
directive|define
name|dTHR
value|extern int errno
end_define

begin_struct
struct|struct
name|perl_wait_queue
block|{
name|struct
name|perl_thread
modifier|*
name|thread
decl_stmt|;
name|struct
name|perl_wait_queue
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|perl_wait_queue
modifier|*
name|perl_cond
typedef|;
end_typedef

begin_comment
comment|/* Ask thread.h to include our per-thread extras */
end_comment

begin_define
define|#
directive|define
name|HAVE_THREAD_INTERN
end_define

begin_struct
struct|struct
name|thread_intern
block|{
name|perl_os_thread
name|next_run
decl_stmt|,
name|prev_run
decl_stmt|;
comment|/* Linked list of runnable threads */
name|perl_cond
name|wait_queue
decl_stmt|;
comment|/* Wait queue that we are waiting on */
name|IV
name|private
decl_stmt|;
comment|/* Holds data across time slices */
name|I32
name|savemark
decl_stmt|;
comment|/* Holds MARK for thread join values */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|init_thread_intern
parameter_list|(
name|t
parameter_list|)
define|\
value|STMT_START {					\ 	t->self = (t);					\ 	(t)->i.next_run = (t)->i.prev_run = (t);	\ 	(t)->i.wait_queue = 0;				\ 	(t)->i.private = 0;				\     } STMT_END
end_define

begin_comment
comment|/*  * Note that SCHEDULE() is only callable from pp code (which  * must be expecting to be restarted). We'll have to do  * something a bit different for XS code.  */
end_comment

begin_define
define|#
directive|define
name|SCHEDULE
parameter_list|()
value|return schedule(), PL_op
end_define

begin_define
define|#
directive|define
name|MUTEX_LOCK
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MUTEX_UNLOCK
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|COND_INIT
parameter_list|(
name|c
parameter_list|)
value|perl_cond_init(c)
end_define

begin_define
define|#
directive|define
name|COND_SIGNAL
parameter_list|(
name|c
parameter_list|)
value|perl_cond_signal(c)
end_define

begin_define
define|#
directive|define
name|COND_BROADCAST
parameter_list|(
name|c
parameter_list|)
value|perl_cond_broadcast(c)
end_define

begin_define
define|#
directive|define
name|COND_WAIT
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
define|\
value|STMT_START {		\ 	perl_cond_wait(c);	\ 	SCHEDULE();		\     } STMT_END
end_define

begin_define
define|#
directive|define
name|COND_DESTROY
parameter_list|(
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|THREAD_CREATE
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|f((t))
end_define

begin_define
define|#
directive|define
name|THREAD_POST_CREATE
parameter_list|(
name|t
parameter_list|)
value|NOOP
end_define

begin_define
define|#
directive|define
name|YIELD
value|NOOP
end_define

end_unit

