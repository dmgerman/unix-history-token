begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2006 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/conf/umount/umount_bsd44.c  *  */
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
name|mntdir
parameter_list|,
specifier|const
name|char
modifier|*
name|mnttabname
parameter_list|,
name|u_int
name|unmount_flags
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
name|mntdir
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
name|mntdir
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
comment|/* not sure why this happens, but it does.  ask kirk one day... */
name|dlog
argument_list|(
literal|"%s: unmount: %m"
argument_list|,
name|mntdir
argument_list|)
expr_stmt|;
goto|goto
name|eintr
goto|;
ifdef|#
directive|ifdef
name|MNT2_GEN_OPT_FORCE
case|case
name|EBUSY
case|:
case|case
name|EIO
case|:
case|case
name|ESTALE
case|:
comment|/* caller determines if forced unmounts should be used */
if|if
condition|(
name|unmount_flags
operator|&
name|AMU_UMOUNT_FORCE
condition|)
block|{
name|error
operator|=
name|umount2_fs
argument_list|(
name|mntdir
argument_list|,
name|unmount_flags
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
else|else
return|return
name|error
return|;
block|}
comment|/* fallthrough */
endif|#
directive|endif
comment|/* MNT2_GEN_OPT_FORCE */
default|default:
name|dlog
argument_list|(
literal|"%s: unmount: %m"
argument_list|,
name|mntdir
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|error
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|MNT2_GEN_OPT_FORCE
end_ifdef

begin_comment
comment|/* force unmount, no questions asked, without touching mnttab file */
end_comment

begin_function
name|int
name|umount2_fs
parameter_list|(
specifier|const
name|char
modifier|*
name|mntdir
parameter_list|,
name|u_int
name|unmount_flags
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|unmount_flags
operator|&
name|AMU_UMOUNT_FORCE
condition|)
block|{
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"umount2_fs: trying unmount/forced on %s"
argument_list|,
name|mntdir
argument_list|)
expr_stmt|;
name|error
operator|=
name|unmount
argument_list|(
name|mntdir
argument_list|,
name|MNT2_GEN_OPT_FORCE
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|<
literal|0
operator|&&
operator|(
name|errno
operator|==
name|EINVAL
operator|||
name|errno
operator|==
name|ENOENT
operator|)
condition|)
name|error
operator|=
literal|0
expr_stmt|;
comment|/* ignore EINVAL/ENOENT */
if|if
condition|(
name|error
operator|<
literal|0
condition|)
name|plog
argument_list|(
name|XLOG_WARNING
argument_list|,
literal|"%s: unmount/force: %m"
argument_list|,
name|mntdir
argument_list|)
expr_stmt|;
else|else
name|dlog
argument_list|(
literal|"%s: unmount/force: OK"
argument_list|,
name|mntdir
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNT2_GEN_OPT_FORCE */
end_comment

end_unit

