begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Modified for OpenSSH by Kevin Steves  * October 2000  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$OpenBSD: setproctitle.c,v 1.8 2001/11/06 19:21:40 art Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETPROCTITLE
end_ifndef

begin_define
define|#
directive|define
name|SPT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SPT_PSTAT
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SPT_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_NONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_PSTAT
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/pstat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPT_TYPE == SPT_PSTAT */
end_comment

begin_define
define|#
directive|define
name|MAX_PROCTITLE
value|2048
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Set Process Title (SPT) defines.  Modeled after sendmail's  * SPT type definition strategy.  *  * SPT_TYPE:  *  * SPT_NONE:	Don't set the process title.  Default.  * SPT_PSTAT:	Use pstat(PSTAT_SETCMD).  HP-UX specific.  */
end_comment

begin_function
name|void
name|setproctitle
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
if|#
directive|if
name|SPT_TYPE
operator|!=
name|SPT_NONE
name|va_list
name|ap
decl_stmt|;
name|char
name|buf
index|[
name|MAX_PROCTITLE
index|]
decl_stmt|;
name|size_t
name|used
decl_stmt|;
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_PSTAT
name|union
name|pstun
name|pst
decl_stmt|;
endif|#
directive|endif
comment|/* SPT_TYPE == SPT_PSTAT */
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
if|if
condition|(
name|fmt
operator|!=
name|NULL
condition|)
block|{
name|used
operator|=
name|snprintf
argument_list|(
name|buf
argument_list|,
name|MAX_PROCTITLE
argument_list|,
literal|"%s: "
argument_list|,
name|__progname
argument_list|)
expr_stmt|;
if|if
condition|(
name|used
operator|>=
name|MAX_PROCTITLE
condition|)
name|used
operator|=
name|MAX_PROCTITLE
operator|-
literal|1
expr_stmt|;
operator|(
name|void
operator|)
name|vsnprintf
argument_list|(
name|buf
operator|+
name|used
argument_list|,
name|MAX_PROCTITLE
operator|-
name|used
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
block|}
else|else
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
name|MAX_PROCTITLE
argument_list|,
literal|"%s"
argument_list|,
name|__progname
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|used
operator|=
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_PSTAT
name|pst
operator|.
name|pst_command
operator|=
name|buf
expr_stmt|;
name|pstat
argument_list|(
name|PSTAT_SETCMD
argument_list|,
name|pst
argument_list|,
name|used
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SPT_TYPE == SPT_PSTAT */
endif|#
directive|endif
comment|/* SPT_TYPE != SPT_NONE */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SETPROCTITLE */
end_comment

end_unit

