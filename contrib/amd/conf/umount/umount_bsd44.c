begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: umount_bsd44.c,v 1.2 1999/01/10 21:54:22 ezk Exp $  *  */
end_comment

begin_comment
comment|/*  * Unmounting filesystems under BSD 4.4.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_include
include|#
directive|include
file|<am_defs.h>
end_include

begin_include
include|#
directive|include
file|<amu.h>
end_include

begin_function
name|int
name|umount_fs
parameter_list|(
name|char
modifier|*
name|fs_name
parameter_list|,
specifier|const
name|char
modifier|*
name|mnttabname
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|eintr
label|:
name|error
operator|=
name|unmount
argument_list|(
name|fs_name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|<
literal|0
condition|)
name|error
operator|=
name|errno
expr_stmt|;
switch|switch
condition|(
name|error
condition|)
block|{
case|case
name|EINVAL
case|:
case|case
name|ENOTBLK
case|:
case|case
name|ENOENT
case|:
name|plog
argument_list|(
name|XLOG_WARNING
argument_list|,
literal|"unmount: %s is not mounted"
argument_list|,
name|fs_name
argument_list|)
expr_stmt|;
name|error
operator|=
literal|0
expr_stmt|;
comment|/* Not really an error */
break|break;
case|case
name|EINTR
case|:
ifdef|#
directive|ifdef
name|DEBUG
comment|/* not sure why this happens, but it does.  ask kirk one day... */
name|dlog
argument_list|(
literal|"%s: unmount: %m"
argument_list|,
name|fs_name
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
goto|goto
name|eintr
goto|;
ifdef|#
directive|ifdef
name|DEBUG
default|default:
name|dlog
argument_list|(
literal|"%s: unmount: %m"
argument_list|,
name|fs_name
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* DEBUG */
block|}
return|return
name|error
return|;
block|}
end_function

end_unit

