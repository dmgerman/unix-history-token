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
literal|"@(#)msgs.c	5.1 (Berkeley) 6/6/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*   * A package to display what is happening every MSG_INTERVAL seconds  * if we are slow connecting.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|"talk.h"
end_include

begin_define
define|#
directive|define
name|MSG_INTERVAL
value|4
end_define

begin_define
define|#
directive|define
name|LONG_TIME
value|100000
end_define

begin_decl_stmt
name|char
modifier|*
name|current_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|current_line
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|itimerval
name|itimer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|timeval
name|wait
init|=
block|{
name|MSG_INTERVAL
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|timeval
name|undo
init|=
block|{
name|LONG_TIME
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|disp_msg
parameter_list|()
block|{
name|message
argument_list|(
name|current_state
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|start_msgs
argument_list|()
end_macro

begin_block
block|{
name|message
argument_list|(
name|current_state
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|disp_msg
argument_list|)
expr_stmt|;
name|itimer
operator|.
name|it_value
operator|=
name|itimer
operator|.
name|it_interval
operator|=
name|wait
expr_stmt|;
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|itimer
argument_list|,
operator|(
expr|struct
name|itimerval
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|end_msgs
argument_list|()
end_macro

begin_block
block|{
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|timerclear
argument_list|(
operator|&
name|itimer
operator|.
name|it_value
argument_list|)
expr_stmt|;
name|timerclear
argument_list|(
operator|&
name|itimer
operator|.
name|it_interval
argument_list|)
expr_stmt|;
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|itimer
argument_list|,
operator|(
expr|struct
name|itimerval
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

