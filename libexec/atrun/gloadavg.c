begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *  gloadavg.c - get load average for Linux  *  Copyright (C) 1993  Thomas Koenig  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author(s) may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: gloadavg.c,v 1.1.2.1 1997/12/12 07:15:37 charnier Exp $"
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
name|__FreeBSD__
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_SOURCE
value|1
end_define

begin_comment
comment|/* System Headers */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Local headers */
end_comment

begin_include
include|#
directive|include
file|"gloadavg.h"
end_include

begin_comment
comment|/* Global functions */
end_comment

begin_function_decl
name|void
name|perr
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|double
name|gloadavg
parameter_list|(
name|void
parameter_list|)
comment|/* return the current load average as a floating point number, or<0 for  * error  */
block|{
name|double
name|result
decl_stmt|;
ifndef|#
directive|ifndef
name|__FreeBSD__
name|FILE
modifier|*
name|fp
decl_stmt|;
if|if
condition|(
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|PROC_DIR
literal|"loadavg"
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|result
operator|=
operator|-
literal|1.0
expr_stmt|;
else|else
block|{
if|if
condition|(
name|fscanf
argument_list|(
name|fp
argument_list|,
literal|"%lf"
argument_list|,
operator|&
name|result
argument_list|)
operator|!=
literal|1
condition|)
name|result
operator|=
operator|-
literal|1.0
expr_stmt|;
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
if|if
condition|(
name|getloadavg
argument_list|(
operator|&
name|result
argument_list|,
literal|1
argument_list|)
operator|!=
literal|1
condition|)
name|perr
argument_list|(
literal|"error in getloadavg"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|result
return|;
block|}
end_function

end_unit

