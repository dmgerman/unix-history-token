begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /a/guest/moore/talk/RCS/msgs.c,v 1.4 83/07/06 00:17:22 moore Exp $ */
end_comment

begin_comment
comment|/*   * a package to display what is happening every MSG_INTERVAL seconds  * if we are slow connecting.  */
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

begin_macro
name|disp_msg
argument_list|()
end_macro

begin_block
block|{
name|message
argument_list|(
name|current_state
argument_list|)
expr_stmt|;
block|}
end_block

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
name|timerval
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
name|timerval
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

