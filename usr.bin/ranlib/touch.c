begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Hugh Smith at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)touch.c	8.1 (Berkeley) 6/6/93";
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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ar.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<ranlib.h>
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
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"archive.h"
end_include

begin_decl_stmt
specifier|extern
name|CHDR
name|chdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* converted header */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|archive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* archive name */
end_comment

begin_function_decl
specifier|extern
name|void
name|error
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|settime
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|touch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|touch
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|afd
decl_stmt|;
name|afd
operator|=
name|open_archive
argument_list|(
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|get_arobj
argument_list|(
name|afd
argument_list|)
operator|||
name|strncmp
argument_list|(
name|RANLIBMAG
argument_list|,
name|chdr
operator|.
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|RANLIBMAG
argument_list|)
operator|-
literal|1
argument_list|)
condition|)
block|{
name|warnx
argument_list|(
literal|"%s: no symbol table"
argument_list|,
name|archive
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|settime
argument_list|(
name|afd
argument_list|)
expr_stmt|;
name|close_archive
argument_list|(
name|afd
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|settime
parameter_list|(
name|afd
parameter_list|)
name|int
name|afd
decl_stmt|;
block|{
name|struct
name|ar_hdr
modifier|*
name|hdr
decl_stmt|;
name|off_t
name|size
decl_stmt|;
name|char
name|buf
index|[
literal|50
index|]
decl_stmt|;
name|size
operator|=
name|SARMAG
operator|+
sizeof|sizeof
argument_list|(
name|hdr
operator|->
name|ar_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|lseek
argument_list|(
name|afd
argument_list|,
name|size
argument_list|,
name|SEEK_SET
argument_list|)
operator|==
operator|(
name|off_t
operator|)
operator|-
literal|1
condition|)
name|error
argument_list|(
name|archive
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%-12ld"
argument_list|,
operator|(
name|long
operator|)
name|time
argument_list|(
operator|(
name|time_t
operator|*
operator|)
name|NULL
argument_list|)
operator|+
name|RANLIBSKEW
argument_list|)
expr_stmt|;
if|if
condition|(
name|write
argument_list|(
name|afd
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|hdr
operator|->
name|ar_date
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|hdr
operator|->
name|ar_date
argument_list|)
condition|)
name|error
argument_list|(
name|archive
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

