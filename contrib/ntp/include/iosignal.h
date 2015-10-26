begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|IOSIGNAL_H
end_ifndef

begin_define
define|#
directive|define
name|IOSIGNAL_H
end_define

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_comment
comment|/*  * Some systems (MOST) define SIGPOLL == SIGIO, others SIGIO == SIGPOLL, and  * a few have separate SIGIO and SIGPOLL signals.  This code checks for the  * SIGIO == SIGPOLL case at compile time.  * Do not define USE_SIGPOLL or USE_SIGIO.  * these are interal only to iosignal.c and ntpd/work_fork.c!  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_SIGPOLL
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|USE_SIGPOLL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_SIGIO
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|USE_SIGIO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* type of input handler function - only shared between iosignal.c and ntp_io.c */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|input_handler_t
function_decl|)
parameter_list|(
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SIGNALED_IO
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_TTY_SIGPOLL
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_UDP_SIGPOLL
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_SIGPOLL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USE_TTY_SIGPOLL
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|USE_UDP_SIGPOLL
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_SIGIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_SIGIO
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_SIGPOLL
argument_list|)
end_if

begin_if
if|#
directive|if
name|SIGIO
operator|==
name|SIGPOLL
end_if

begin_define
define|#
directive|define
name|USE_SIGIO
end_define

begin_undef
undef|#
directive|undef
name|USE_SIGPOLL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGIO == SIGPOLL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_SIGIO&& USE_SIGPOLL */
end_comment

begin_define
define|#
directive|define
name|USING_SIGIO
parameter_list|()
value|using_sigio
end_define

begin_decl_stmt
specifier|extern
name|int
name|using_sigio
decl_stmt|;
end_decl_stmt

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
name|input_handler_t
modifier|*
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

begin_comment
comment|/* !HAVE_SIGNALED_IO follows */
end_comment

begin_define
define|#
directive|define
name|BLOCKIO
parameter_list|()
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|UNBLOCKIO
parameter_list|()
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|USING_SIGIO
parameter_list|()
value|FALSE
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
comment|/* IOSIGNAL_H */
end_comment

end_unit

