begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: mtab.c,v 1.2 1999/01/10 21:54:37 ezk Exp $  *  */
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

begin_comment
comment|/*  * Firewall /etc/mtab entries  */
end_comment

begin_function
name|void
name|mnt_free
parameter_list|(
name|mntent_t
modifier|*
name|mp
parameter_list|)
block|{
name|XFREE
argument_list|(
name|mp
operator|->
name|mnt_fsname
argument_list|)
expr_stmt|;
name|XFREE
argument_list|(
name|mp
operator|->
name|mnt_dir
argument_list|)
expr_stmt|;
name|XFREE
argument_list|(
name|mp
operator|->
name|mnt_type
argument_list|)
expr_stmt|;
name|XFREE
argument_list|(
name|mp
operator|->
name|mnt_opts
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_FIELD_MNTENT_T_MNT_TIME
ifdef|#
directive|ifdef
name|HAVE_FIELD_MNTENT_T_MNT_TIME_STRING
name|XFREE
argument_list|(
name|mp
operator|->
name|mnt_time
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_FIELD_MNTENT_T_MNT_TIME_STRING */
endif|#
directive|endif
comment|/* HAVE_FIELD_MNTENT_T_MNT_TIME */
name|XFREE
argument_list|(
name|mp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Discard memory allocated for mount list  */
end_comment

begin_function
name|void
name|discard_mntlist
parameter_list|(
name|mntlist
modifier|*
name|mp
parameter_list|)
block|{
name|mntlist
modifier|*
name|mp2
decl_stmt|;
while|while
condition|(
operator|(
name|mp2
operator|=
name|mp
operator|)
condition|)
block|{
name|mp
operator|=
name|mp
operator|->
name|mnext
expr_stmt|;
if|if
condition|(
name|mp2
operator|->
name|mnt
condition|)
name|mnt_free
argument_list|(
name|mp2
operator|->
name|mnt
argument_list|)
expr_stmt|;
name|XFREE
argument_list|(
name|mp2
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Throw away a mount list  */
end_comment

begin_function
name|void
name|free_mntlist
parameter_list|(
name|mntlist
modifier|*
name|mp
parameter_list|)
block|{
name|discard_mntlist
argument_list|(
name|mp
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MOUNT_TABLE_ON_FILE
name|unlock_mntlist
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* MOUNT_TABLE_ON_FILE */
block|}
end_function

begin_comment
comment|/*  * Utility routine which determines the value of a  * numeric option in the mount options (such as port=%d).  * Returns 0 if the option is not specified.  */
end_comment

begin_function
name|int
name|hasmntval
parameter_list|(
name|mntent_t
modifier|*
name|mnt
parameter_list|,
name|char
modifier|*
name|opt
parameter_list|)
block|{
name|char
modifier|*
name|str
init|=
name|hasmntopt
argument_list|(
name|mnt
argument_list|,
name|opt
argument_list|)
decl_stmt|;
if|if
condition|(
name|str
condition|)
block|{
name|char
modifier|*
name|eq
init|=
name|strchr
argument_list|(
name|str
argument_list|,
literal|'='
argument_list|)
decl_stmt|;
if|if
condition|(
name|eq
condition|)
return|return
name|atoi
argument_list|(
name|eq
operator|+
literal|1
argument_list|)
return|;
else|else
name|plog
argument_list|(
name|XLOG_USER
argument_list|,
literal|"bad numeric option \"%s\" in \"%s\""
argument_list|,
name|opt
argument_list|,
name|str
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

