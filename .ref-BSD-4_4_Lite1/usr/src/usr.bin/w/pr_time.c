begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)pr_time.c	8.2 (Berkeley) 4/4/94"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<tzfile.h>
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/*  * pr_attime --  *	Print the time since the user logged in.   *  *	Note: SCCS forces the bizarre string manipulation, things like  *	8.2 get replaced in the source code.  */
end_comment

begin_function
name|void
name|pr_attime
parameter_list|(
name|started
parameter_list|,
name|now
parameter_list|)
name|time_t
modifier|*
name|started
decl_stmt|,
decl|*
name|now
decl_stmt|;
end_function

begin_block
block|{
specifier|static
name|char
name|buf
index|[
literal|256
index|]
decl_stmt|;
name|struct
name|tm
modifier|*
name|tp
decl_stmt|;
name|time_t
name|diff
decl_stmt|;
name|char
name|fmt
index|[
literal|20
index|]
decl_stmt|;
name|tp
operator|=
name|localtime
argument_list|(
name|started
argument_list|)
expr_stmt|;
name|diff
operator|=
operator|*
name|now
operator|-
operator|*
name|started
expr_stmt|;
comment|/* If more than a week, use day-month-year. */
if|if
condition|(
name|diff
operator|>
name|SECSPERDAY
operator|*
name|DAYSPERWEEK
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|fmt
argument_list|,
literal|"%d%b%y"
argument_list|)
expr_stmt|;
comment|/* If not today, use day-hour-am/pm. */
elseif|else
if|if
condition|(
operator|*
name|now
operator|/
name|SECSPERDAY
operator|!=
operator|*
name|started
operator|/
name|SECSPERDAY
condition|)
block|{
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|fmt
argument_list|,
name|__CONCAT
argument_list|(
literal|"%a%"
argument_list|,
literal|"I%p"
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Default is hh:mm{am,pm}. */
else|else
block|{
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|fmt
argument_list|,
name|__CONCAT
argument_list|(
literal|"%l:%"
argument_list|,
literal|"M%p"
argument_list|)
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|strftime
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
name|fmt
argument_list|,
name|tp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * pr_idle --  *	Display the idle time.  */
end_comment

begin_function
name|void
name|pr_idle
parameter_list|(
name|idle
parameter_list|)
name|time_t
name|idle
decl_stmt|;
block|{
comment|/* If idle more than 36 hours, print as a number of days. */
if|if
condition|(
name|idle
operator|>=
literal|36
operator|*
name|SECSPERHOUR
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" %ddays "
argument_list|,
name|idle
operator|/
name|SECSPERDAY
argument_list|)
expr_stmt|;
comment|/* If idle more than an hour, print as HH:MM. */
elseif|else
if|if
condition|(
name|idle
operator|>=
name|SECSPERHOUR
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" %2d:%02d "
argument_list|,
name|idle
operator|/
name|SECSPERHOUR
argument_list|,
operator|(
name|idle
operator|%
name|SECSPERHOUR
operator|)
operator|/
name|SECSPERMIN
argument_list|)
expr_stmt|;
comment|/* Else print the minutes idle. */
else|else
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"    %2d "
argument_list|,
name|idle
operator|/
name|SECSPERMIN
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

