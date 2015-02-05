begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|WIN32_IO_H
end_ifndef

begin_define
define|#
directive|define
name|WIN32_IO_H
end_define

begin_function_decl
specifier|extern
name|void
name|InitSockets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|connection_reset_fix
parameter_list|(
name|SOCKET
name|fd
parameter_list|,
name|sockaddr_u
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32_IO_H */
end_comment

end_unit

