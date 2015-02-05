begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
operator|!
name|defined
name|__ntp_iocompletionport_h
end_if

begin_define
define|#
directive|define
name|__ntp_iocompletionport_h
end_define

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_include
include|#
directive|include
file|"clockstuff.h"
end_include

begin_include
include|#
directive|include
file|"ntp_worker.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_IO_COMPLETION_PORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|init_io_completion_port
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|uninit_io_completion_port
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|io_completion_port_add_socket
parameter_list|(
name|SOCKET
name|fd
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|refclockio
struct_decl|;
end_struct_decl

begin_comment
comment|/* in ntp_refclock.h but inclusion here triggers problems */
end_comment

begin_function_decl
specifier|extern
name|int
name|io_completion_port_add_clock_io
parameter_list|(
name|struct
name|refclockio
modifier|*
name|rio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|io_completion_port_remove_clock_io
parameter_list|(
name|struct
name|refclockio
modifier|*
name|rio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|io_completion_port_sendto
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|GetReceivedBuffers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|HANDLE
name|WaitableExitEventHandle
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

end_unit

