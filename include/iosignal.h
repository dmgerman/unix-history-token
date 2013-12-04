begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
operator|!
name|defined
name|_ntp_iosignaled_h
end_if

begin_define
define|#
directive|define
name|_ntp_iosignaled_h
end_define

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SIGNALED_IO
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|block_sigio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unblock_sigio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_clock_sig
parameter_list|(
name|struct
name|refclockio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_socket_sig
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_signal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RETSIGTYPE
name|sigio_handler
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BLOCKIO
parameter_list|()
value|block_sigio()
end_define

begin_define
define|#
directive|define
name|UNBLOCKIO
parameter_list|()
value|unblock_sigio()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BLOCKIO
parameter_list|()
end_define

begin_define
define|#
directive|define
name|UNBLOCKIO
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SIGNALED_IO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

