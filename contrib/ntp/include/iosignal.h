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

begin_decl_stmt
specifier|extern
name|void
name|block_sigio
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unblock_sigio
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|init_clock_sig
name|P
argument_list|(
operator|(
expr|struct
name|refclockio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_socket_sig
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_signal
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RETSIGTYPE
name|sigio_handler
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BLOCKIO
parameter_list|()
value|((void) block_sigio())
end_define

begin_define
define|#
directive|define
name|UNBLOCKIO
parameter_list|()
value|((void) unblock_sigio())
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

