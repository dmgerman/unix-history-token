begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|SESSION_H
end_ifndef

begin_define
define|#
directive|define
name|SESSION_H
end_define

begin_comment
comment|/* SSH1 */
end_comment

begin_function_decl
name|void
name|do_authenticated
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* SSH2 */
end_comment

begin_function_decl
name|void
name|do_authenticated2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|session_open
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|session_input_channel_req
parameter_list|(
name|int
name|id
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|session_close_by_pid
parameter_list|(
name|pid_t
name|pid
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|session_close_by_channel
parameter_list|(
name|int
name|id
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

