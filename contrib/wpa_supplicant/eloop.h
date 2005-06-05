begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|ELOOP_H
end_ifndef

begin_define
define|#
directive|define
name|ELOOP_H
end_define

begin_comment
comment|/* Magic number for eloop_cancel_timeout() */
end_comment

begin_define
define|#
directive|define
name|ELOOP_ALL_CTX
value|(void *) -1
end_define

begin_comment
comment|/* Initialize global event loop data - must be called before any other eloop_*  * function. user_data is a pointer to global data structure and will be passed  * as eloop_ctx to signal handlers. */
end_comment

begin_function_decl
name|void
name|eloop_init
parameter_list|(
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register handler for read event */
end_comment

begin_function_decl
name|int
name|eloop_register_read_sock
parameter_list|(
name|int
name|sock
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|int
name|sock
parameter_list|,
name|void
modifier|*
name|eloop_ctx
parameter_list|,
name|void
modifier|*
name|sock_ctx
parameter_list|)
parameter_list|,
name|void
modifier|*
name|eloop_data
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eloop_unregister_read_sock
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register timeout */
end_comment

begin_function_decl
name|int
name|eloop_register_timeout
parameter_list|(
name|unsigned
name|int
name|secs
parameter_list|,
name|unsigned
name|int
name|usecs
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|void
modifier|*
name|eloop_ctx
parameter_list|,
name|void
modifier|*
name|timeout_ctx
parameter_list|)
parameter_list|,
name|void
modifier|*
name|eloop_data
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Cancel timeouts matching<handler,eloop_data,user_data>.  * ELOOP_ALL_CTX can be used as a wildcard for cancelling all timeouts  * regardless of eloop_data/user_data. */
end_comment

begin_function_decl
name|int
name|eloop_cancel_timeout
parameter_list|(
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|void
modifier|*
name|eloop_ctx
parameter_list|,
name|void
modifier|*
name|sock_ctx
parameter_list|)
parameter_list|,
name|void
modifier|*
name|eloop_data
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register handler for signal.  * Note: signals are 'global' events and there is no local eloop_data pointer  * like with other handlers. The (global) pointer given to eloop_init() will be  * used as eloop_ctx for signal handlers. */
end_comment

begin_function_decl
name|int
name|eloop_register_signal
parameter_list|(
name|int
name|sock
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|int
name|sig
parameter_list|,
name|void
modifier|*
name|eloop_ctx
parameter_list|,
name|void
modifier|*
name|signal_ctx
parameter_list|)
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Start event loop and continue running as long as there are any registered  * event handlers. */
end_comment

begin_function_decl
name|void
name|eloop_run
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Terminate event loop even if there are registered events. */
end_comment

begin_function_decl
name|void
name|eloop_terminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free any reserved resources. After calling eloop_destoy(), other eloop_*  * functions must not be called before re-running eloop_init(). */
end_comment

begin_function_decl
name|void
name|eloop_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check whether event loop has been terminated. */
end_comment

begin_function_decl
name|int
name|eloop_terminated
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ELOOP_H */
end_comment

end_unit

