begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)msgs.c	5.5 (Berkeley) 6/1/90"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

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
name|struct
name|itimerval
name|itimer
decl_stmt|;
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
operator|.
name|tv_sec
operator|=
name|itimer
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
name|MSG_INTERVAL
expr_stmt|;
name|itimer
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
name|itimer
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
literal|0
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
name|struct
name|itimerval
name|itimer
decl_stmt|;
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
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

