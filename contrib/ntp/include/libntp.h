begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* libntp.h */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYSCONF
argument_list|)
operator|&&
name|defined
argument_list|(
name|_SC_OPEN_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|GETDTABLESIZE
parameter_list|()
value|((int)sysconf(_SC_OPEN_MAX))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_GETDTABLESIZE
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GETDTABLESIZE
value|getdtablesize
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * if we have no idea about the max fd value set up things  * so we will start at FOPEN_MAX  */
end_comment

begin_define
define|#
directive|define
name|GETDTABLESIZE
parameter_list|()
value|(FOPEN_MAX + FD_CHUNK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|make_socket_nonblocking
parameter_list|(
name|SOCKET
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SOCKET
name|move_fd
parameter_list|(
name|SOCKET
name|fd
parameter_list|)
function_decl|;
end_function_decl

end_unit

