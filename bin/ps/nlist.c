begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char sccsid[] = "@(#)nlist.c	8.4 (Berkeley) 4/2/94";
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"ps.h"
end_include

begin_decl_stmt
name|fixpt_t
name|ccpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel _ccpu variable */
end_comment

begin_decl_stmt
name|int
name|nlistread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if nlist already read. */
end_comment

begin_decl_stmt
name|int
name|mempages
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of pages of phys. memory */
end_comment

begin_decl_stmt
name|int
name|fscale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel _fscale variable */
end_comment

begin_function
name|int
name|donlist
parameter_list|(
name|void
parameter_list|)
block|{
name|size_t
name|oldlen
decl_stmt|;
name|oldlen
operator|=
sizeof|sizeof
argument_list|(
name|ccpu
argument_list|)
expr_stmt|;
if|if
condition|(
name|sysctlbyname
argument_list|(
literal|"kern.ccpu"
argument_list|,
operator|&
name|ccpu
argument_list|,
operator|&
name|oldlen
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|oldlen
operator|=
sizeof|sizeof
argument_list|(
name|fscale
argument_list|)
expr_stmt|;
if|if
condition|(
name|sysctlbyname
argument_list|(
literal|"kern.fscale"
argument_list|,
operator|&
name|fscale
argument_list|,
operator|&
name|oldlen
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|oldlen
operator|=
sizeof|sizeof
argument_list|(
name|mempages
argument_list|)
expr_stmt|;
if|if
condition|(
name|sysctlbyname
argument_list|(
literal|"hw.availpages"
argument_list|,
operator|&
name|mempages
argument_list|,
operator|&
name|oldlen
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|nlistread
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

