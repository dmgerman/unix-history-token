begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1983 The Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)mkdate.c	5.5 (Berkeley) 6/1/90"
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
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IRIS
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|main
parameter_list|()
block|{
name|struct
name|tm
modifier|*
name|t
decl_stmt|;
name|long
name|clock
decl_stmt|;
name|char
name|name
index|[
literal|100
index|]
decl_stmt|;
name|int
name|namelen
decl_stmt|;
name|printf
argument_list|(
literal|"char *date = \""
argument_list|)
expr_stmt|;
name|clock
operator|=
name|time
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|t
operator|=
name|localtime
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d/%d/%d "
argument_list|,
name|t
operator|->
name|tm_mon
operator|+
literal|1
argument_list|,
name|t
operator|->
name|tm_mday
argument_list|,
name|t
operator|->
name|tm_year
operator|%
literal|100
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d:%02d"
argument_list|,
name|t
operator|->
name|tm_hour
argument_list|,
name|t
operator|->
name|tm_min
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|IRIS
name|gethostname
argument_list|(
name|name
argument_list|,
operator|&
name|namelen
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" (%s)"
argument_list|,
name|name
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"\";\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

