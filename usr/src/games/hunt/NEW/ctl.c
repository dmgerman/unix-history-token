begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_include
include|#
directive|include
file|"bsd.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TALK_43
argument_list|)
operator|||
name|defined
argument_list|(
name|TALK_42
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ctl.c	5.2 (Berkeley) 3/13/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * This file handles haggling with the various talk daemons to  * get a socket to talk to. sockt is opened and connected in  * the progress  */
end_comment

begin_include
include|#
directive|include
file|"talk_ctl.h"
end_include

begin_decl_stmt
name|struct
name|sockaddr_in
name|daemon_addr
init|=
block|{
name|AF_INET
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr_in
name|ctl_addr
init|=
block|{
name|AF_INET
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inet addresses of the two machines */
end_comment

begin_decl_stmt
name|struct
name|in_addr
name|my_machine_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|in_addr
name|his_machine_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|daemon_port
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* port number of the talk daemon */
end_comment

begin_decl_stmt
name|int
name|ctl_sockt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CTL_MSG
name|msg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* open the ctl socket */
end_comment

begin_macro
name|open_ctl
argument_list|()
end_macro

begin_block
block|{
name|int
name|length
decl_stmt|;
name|ctl_addr
operator|.
name|sin_port
operator|=
literal|0
expr_stmt|;
name|ctl_addr
operator|.
name|sin_addr
operator|=
name|my_machine_addr
expr_stmt|;
name|ctl_sockt
operator|=
name|socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_DGRAM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctl_sockt
operator|<=
literal|0
condition|)
name|p_error
argument_list|(
literal|"Bad socket"
argument_list|)
expr_stmt|;
if|if
condition|(
name|bind
argument_list|(
name|ctl_sockt
argument_list|,
operator|&
name|ctl_addr
argument_list|,
sizeof|sizeof
argument_list|(
name|ctl_addr
argument_list|)
argument_list|)
operator|!=
literal|0
condition|)
name|p_error
argument_list|(
literal|"Couldn't bind to control socket"
argument_list|)
expr_stmt|;
name|length
operator|=
sizeof|sizeof
argument_list|(
name|ctl_addr
argument_list|)
expr_stmt|;
if|if
condition|(
name|getsockname
argument_list|(
name|ctl_sockt
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|ctl_addr
argument_list|,
operator|&
name|length
argument_list|)
operator|<
literal|0
condition|)
name|p_error
argument_list|(
literal|"Bad address for ctl socket"
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

