begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: tmp.c,v 1.7 2001/02/19 15:45:45 jdolecek Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Peter McIlroy.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

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
unit|__RCSID("$NetBSD: tmp.c,v 1.7 2001/02/19 15:45:45 jdolecek Exp $"); __SCCSID("@(#)tmp.c	8.1 (Berkeley) 6/6/93");
endif|#
directive|endif
end_endif

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
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"sort.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_define
define|#
directive|define
name|_NAME_TMP
value|"sort.XXXXXXXX"
end_define

begin_function
name|FILE
modifier|*
name|ftmp
parameter_list|()
block|{
name|sigset_t
name|set
decl_stmt|,
name|oset
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|char
name|pathb
index|[
name|MAXPATHLEN
index|]
decl_stmt|,
modifier|*
name|path
decl_stmt|;
name|path
operator|=
name|pathb
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|path
argument_list|,
sizeof|sizeof
argument_list|(
name|pathb
argument_list|)
argument_list|,
literal|"%s%s%s"
argument_list|,
name|tmpdir
argument_list|,
operator|(
name|tmpdir
index|[
name|strlen
argument_list|(
name|tmpdir
argument_list|)
operator|-
literal|1
index|]
operator|!=
literal|'/'
operator|)
condition|?
literal|"/"
else|:
literal|""
argument_list|,
name|_NAME_TMP
argument_list|)
expr_stmt|;
name|sigfillset
argument_list|(
operator|&
name|set
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sigprocmask
argument_list|(
name|SIG_BLOCK
argument_list|,
operator|&
name|set
argument_list|,
operator|&
name|oset
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|fd
operator|=
name|mkstemp
argument_list|(
name|path
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|err
argument_list|(
literal|2
argument_list|,
literal|"ftmp: mkstemp(\"%s\")"
argument_list|,
name|path
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|fp
operator|=
name|fdopen
argument_list|(
name|fd
argument_list|,
literal|"w+"
argument_list|)
operator|)
condition|)
name|err
argument_list|(
literal|2
argument_list|,
literal|"ftmp: fdopen(\"%s\")"
argument_list|,
name|path
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|unlink
argument_list|(
name|path
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sigprocmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|oset
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
operator|(
name|fp
operator|)
return|;
block|}
end_function

end_unit

