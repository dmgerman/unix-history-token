begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)msgs.c	8.1 (Berkeley) 6/6/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
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
comment|/*  * A package to display what is happening every MSG_INTERVAL seconds  * if we are slow connecting.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
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

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|void
name|disp_msg
parameter_list|(
name|signo
parameter_list|)
name|int
name|signo
decl_stmt|;
block|{
name|message
argument_list|(
name|current_state
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|start_msgs
parameter_list|()
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
name|itimerval
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|end_msgs
parameter_list|()
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
name|itimerval
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
end_function

end_unit

