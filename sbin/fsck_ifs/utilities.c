begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static const char sccsid[] = "@(#)utilities.c	8.6 (Berkeley) 5/19/95";
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/dinode.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/dir.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/fs.h>
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<fstab.h>
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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"fsck.h"
end_include

begin_function
name|char
modifier|*
name|blockcheck
parameter_list|(
name|char
modifier|*
name|origname
parameter_list|)
block|{
name|struct
name|stat
name|stslash
decl_stmt|,
name|stblock
decl_stmt|,
name|stchar
decl_stmt|;
name|char
modifier|*
name|newname
decl_stmt|,
modifier|*
name|raw
decl_stmt|;
name|struct
name|fstab
modifier|*
name|fsinfo
decl_stmt|;
name|int
name|retried
init|=
literal|0
decl_stmt|,
name|len
decl_stmt|;
name|newname
operator|=
name|origname
expr_stmt|;
name|retry
label|:
if|if
condition|(
name|stat
argument_list|(
name|newname
argument_list|,
operator|&
name|stblock
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Can't stat %s: %s\n"
argument_list|,
name|newname
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|origname
operator|)
return|;
block|}
switch|switch
condition|(
name|stblock
operator|.
name|st_mode
operator|&
name|S_IFMT
condition|)
block|{
case|case
name|S_IFCHR
case|:
case|case
name|S_IFBLK
case|:
return|return
operator|(
name|newname
operator|)
return|;
case|case
name|S_IFDIR
case|:
if|if
condition|(
name|retried
condition|)
break|break;
name|len
operator|=
name|strlen
argument_list|(
name|origname
argument_list|)
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|len
operator|>
literal|0
operator|&&
name|origname
index|[
name|len
index|]
operator|==
literal|'/'
condition|)
comment|/* remove trailing slash */
name|origname
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|(
name|fsinfo
operator|=
name|getfsfile
argument_list|(
name|origname
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"Can't resolve %s to character special device"
argument_list|,
name|origname
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|newname
operator|=
name|fsinfo
operator|->
name|fs_spec
expr_stmt|;
name|retried
operator|++
expr_stmt|;
goto|goto
name|retry
goto|;
block|}
comment|/* 	 * Not a block or character device, just return name and 	 * let the user decide whether to use it. 	 */
return|return
operator|(
name|origname
operator|)
return|;
block|}
end_function

end_unit

