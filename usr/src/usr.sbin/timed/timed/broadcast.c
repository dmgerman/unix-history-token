begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)broadcast.c	1.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"globals.h"
end_include

begin_include
include|#
directive|include
file|<protocols/timed.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|sock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in
name|server
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * `broadcast' broadcasts the given message on the local network   * at the broadcast address set in main.c  */
end_comment

begin_macro
name|broadcast
argument_list|(
argument|msg
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|tsp
modifier|*
name|msg
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|struct
name|in_addr
name|broadcastaddr
decl_stmt|;
name|msg
operator|->
name|tsp_vers
operator|=
name|TSPVERSION
expr_stmt|;
name|server
operator|.
name|sin_addr
operator|=
name|broadcastaddr
expr_stmt|;
if|if
condition|(
name|sendto
argument_list|(
name|sock
argument_list|,
operator|(
name|char
operator|*
operator|)
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tsp
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|&
name|server
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|sockaddr_in
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"sendto: %m"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

