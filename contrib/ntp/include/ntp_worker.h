begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_worker.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_WORKER_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_WORKER_H
end_define

begin_include
include|#
directive|include
file|"ntp_workimpl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WORKER
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WORK_THREAD
argument_list|)
operator|&&
name|defined
argument_list|(
name|WORK_PIPE
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SEMAPHORE_H
end_ifdef

begin_include
include|#
directive|include
file|<semaphore.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_comment
comment|/* #define TEST_BLOCKING_WORKER */
end_comment

begin_comment
comment|/* ntp_config.c ntp_intres.c */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|blocking_work_req_tag
block|{
name|BLOCKING_GETNAMEINFO
block|,
name|BLOCKING_GETADDRINFO
block|, }
name|blocking_work_req
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|blocking_work_callback
function_decl|)
parameter_list|(
name|blocking_work_req
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|blocking_magic_sig_e
block|{
name|BLOCKING_REQ_MAGIC
init|=
literal|0x510c7ecf
block|,
name|BLOCKING_RESP_MAGIC
init|=
literal|0x510c7e54
block|, }
name|blocking_magic_sig
typedef|;
end_typedef

begin_comment
comment|/*  * The same header is used for both requests to and responses from  * the child.  In the child, done_func and context are opaque.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|blocking_pipe_header_tag
block|{
name|size_t
name|octets
decl_stmt|;
name|blocking_magic_sig
name|magic_sig
decl_stmt|;
name|blocking_work_req
name|rtype
decl_stmt|;
name|u_int
name|child_idx
decl_stmt|;
name|blocking_work_callback
name|done_func
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
block|}
name|blocking_pipe_header
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|WORK_THREAD
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|WORK_PIPE
end_ifdef

begin_typedef
typedef|typedef
name|pthread_t
modifier|*
name|thr_ref
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|sem_t
modifier|*
name|sem_ref
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|HANDLE
name|thr_ref
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HANDLE
name|sem_ref
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORK_FORK
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|blocking_child_tag
block|{
name|int
name|reusable
decl_stmt|;
name|int
name|pid
decl_stmt|;
name|int
name|req_write_pipe
decl_stmt|;
comment|/* parent */
name|int
name|resp_read_pipe
decl_stmt|;
name|void
modifier|*
name|resp_read_ctx
decl_stmt|;
name|int
name|req_read_pipe
decl_stmt|;
comment|/* child */
name|int
name|resp_write_pipe
decl_stmt|;
name|int
name|ispipe
decl_stmt|;
block|}
name|blocking_child
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|WORK_THREAD
argument_list|)
end_elif

begin_typedef
typedef|typedef
struct|struct
name|blocking_child_tag
block|{
comment|/*  * blocking workitems and blocking_responses are dynamically-sized  * one-dimensional arrays of pointers to blocking worker requests and  * responses.  */
name|int
name|reusable
decl_stmt|;
name|thr_ref
name|thread_ref
decl_stmt|;
name|u_int
name|thread_id
decl_stmt|;
name|blocking_pipe_header
modifier|*
specifier|volatile
modifier|*
specifier|volatile
name|workitems
decl_stmt|;
specifier|volatile
name|size_t
name|workitems_alloc
decl_stmt|;
name|size_t
name|next_workitem
decl_stmt|;
comment|/* parent */
name|size_t
name|next_workeritem
decl_stmt|;
comment|/* child */
name|blocking_pipe_header
modifier|*
specifier|volatile
modifier|*
specifier|volatile
name|responses
decl_stmt|;
specifier|volatile
name|size_t
name|responses_alloc
decl_stmt|;
name|size_t
name|next_response
decl_stmt|;
comment|/* child */
name|size_t
name|next_workresp
decl_stmt|;
comment|/* parent */
comment|/* event handles / sem_t pointers */
comment|/* sem_ref		child_is_blocking; */
name|sem_ref
name|blocking_req_ready
decl_stmt|;
name|sem_ref
name|wake_scheduled_sleep
decl_stmt|;
ifdef|#
directive|ifdef
name|WORK_PIPE
name|int
name|resp_read_pipe
decl_stmt|;
comment|/* parent */
name|int
name|resp_write_pipe
decl_stmt|;
comment|/* child */
name|int
name|ispipe
decl_stmt|;
name|void
modifier|*
name|resp_read_ctx
decl_stmt|;
comment|/* child */
else|#
directive|else
name|sem_ref
name|blocking_response_ready
decl_stmt|;
endif|#
directive|endif
block|}
name|blocking_child
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WORK_THREAD */
end_comment

begin_decl_stmt
specifier|extern
name|blocking_child
modifier|*
modifier|*
name|blocking_children
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|blocking_children_alloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|worker_per_query
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boolean */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|intres_req_pending
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|u_int
name|available_blocking_child_slot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|queue_blocking_request
parameter_list|(
name|blocking_work_req
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|blocking_work_callback
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|queue_blocking_response
parameter_list|(
name|blocking_child
modifier|*
parameter_list|,
name|blocking_pipe_header
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|blocking_pipe_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|process_blocking_resp
parameter_list|(
name|blocking_child
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|send_blocking_req_internal
parameter_list|(
name|blocking_child
modifier|*
parameter_list|,
name|blocking_pipe_header
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|send_blocking_resp_internal
parameter_list|(
name|blocking_child
modifier|*
parameter_list|,
name|blocking_pipe_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|blocking_pipe_header
modifier|*
name|receive_blocking_req_internal
parameter_list|(
name|blocking_child
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|blocking_pipe_header
modifier|*
name|receive_blocking_resp_internal
parameter_list|(
name|blocking_child
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|blocking_child_common
parameter_list|(
name|blocking_child
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exit_worker
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|worker_sleep
parameter_list|(
name|blocking_child
modifier|*
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|worker_idle_timer_fired
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|interrupt_worker_sleep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|req_child_exit
parameter_list|(
name|blocking_child
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_IO_COMPLETION_PORT
end_ifndef

begin_function_decl
specifier|extern
name|int
name|pipe_socketpair
parameter_list|(
name|int
name|fds
index|[
literal|2
index|]
parameter_list|,
name|int
modifier|*
name|is_pipe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|close_all_beyond
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|close_all_except
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kill_asyncio
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WORK_PIPE
end_ifdef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|addremove_io_fd_func
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|addremove_io_fd_func
name|addremove_io_fd
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|handle_blocking_resp_sem
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|addremove_io_semaphore_func
function_decl|)
parameter_list|(
name|sem_ref
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|addremove_io_semaphore_func
name|addremove_io_semaphore
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WORK_FORK
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|worker_process
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WORKER */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DROPROOT
argument_list|)
operator|&&
name|defined
argument_list|(
name|WORK_FORK
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|fork_deferred_worker
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fork_deferred_worker
parameter_list|()
value|do {} while (0)
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
comment|/* !NTP_WORKER_H */
end_comment

end_unit

