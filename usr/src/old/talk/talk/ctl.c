begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1985  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

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
literal|"@(#)ctl.c	5.1 (Berkeley) 6/6/85"
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

begin_decl_stmt
name|struct
name|sockaddr_in
name|my_addr
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
name|int
name|sockt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|invitation_waiting
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CTL_MSG
name|msg
decl_stmt|;
end_decl_stmt

begin_macro
name|open_sockt
argument_list|()
end_macro

begin_block
block|{
name|int
name|length
decl_stmt|;
name|my_addr
operator|.
name|sin_addr
operator|=
name|my_machine_addr
expr_stmt|;
name|my_addr
operator|.
name|sin_port
operator|=
literal|0
expr_stmt|;
name|sockt
operator|=
name|socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_STREAM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|sockt
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
name|sockt
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|my_addr
argument_list|,
sizeof|sizeof
argument_list|(
name|my_addr
argument_list|)
argument_list|)
operator|!=
literal|0
condition|)
name|p_error
argument_list|(
literal|"Binding local socket"
argument_list|)
expr_stmt|;
name|length
operator|=
sizeof|sizeof
argument_list|(
name|my_addr
argument_list|)
expr_stmt|;
if|if
condition|(
name|getsockname
argument_list|(
name|sockt
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|my_addr
argument_list|,
operator|&
name|length
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|p_error
argument_list|(
literal|"Bad address for socket"
argument_list|)
expr_stmt|;
block|}
end_block

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
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
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
operator|==
operator|-
literal|1
condition|)
name|p_error
argument_list|(
literal|"Bad address for ctl socket"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* print_addr is a debug print routine */
end_comment

begin_macro
name|print_addr
argument_list|(
argument|addr
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
name|printf
argument_list|(
literal|"addr = %x, port = %o, family = %o zero = "
argument_list|,
name|addr
operator|.
name|sin_addr
argument_list|,
name|addr
operator|.
name|sin_port
argument_list|,
name|addr
operator|.
name|sin_family
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"%o "
argument_list|,
operator|(
name|int
operator|)
name|addr
operator|.
name|sin_zero
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

