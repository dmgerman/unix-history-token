begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)kern_acct.c 8.8 (Berkeley) 5/14/95  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_macro
name|acct
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|acct_args
comment|/* { 		syscallarg(char *) path; 	} */
modifier|*
name|a2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|a3
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_block

begin_macro
name|acct_process
argument_list|(
argument|a1
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

begin_comment
comment|/*  * Periodically check the file system to see if accounting  * should be turned on or off. Beware the case where the vnode  * has been vgone()'d out from underneath us, e.g. when the file  * system containing the accounting file has been forcibly unmounted.  */
end_comment

begin_comment
comment|/*  * Values associated with enabling and disabling accounting  */
end_comment

begin_decl_stmt
name|int
name|acctsuspend
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stop accounting when< 2% free space left */
end_comment

begin_decl_stmt
name|int
name|acctresume
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resume when free space risen to> 4% */
end_comment

begin_decl_stmt
name|int
name|acctchkfreq
init|=
literal|15
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frequency (in seconds) to check space */
end_comment

begin_comment
comment|/*  * SHOULD REPLACE THIS WITH A DRIVER THAT CAN BE READ TO SIMPLIFY.  */
end_comment

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|acctp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|savacctp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|void
name|acctwatch
parameter_list|(
name|a
parameter_list|)
name|void
modifier|*
name|a
decl_stmt|;
block|{
name|struct
name|statfs
name|sb
decl_stmt|;
if|if
condition|(
name|savacctp
condition|)
block|{
if|if
condition|(
name|savacctp
operator|->
name|v_type
operator|==
name|VBAD
condition|)
block|{
operator|(
name|void
operator|)
name|vn_close
argument_list|(
name|savacctp
argument_list|,
name|FWRITE
argument_list|,
name|NOCRED
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|savacctp
operator|=
name|NULL
expr_stmt|;
return|return;
block|}
operator|(
name|void
operator|)
name|VFS_STATFS
argument_list|(
name|savacctp
operator|->
name|v_mount
argument_list|,
operator|&
name|sb
argument_list|,
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|sb
operator|.
name|f_bavail
operator|>
name|acctresume
operator|*
name|sb
operator|.
name|f_blocks
operator|/
literal|100
condition|)
block|{
name|acctp
operator|=
name|savacctp
expr_stmt|;
name|savacctp
operator|=
name|NULL
expr_stmt|;
name|log
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"Accounting resumed\n"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|acctp
operator|==
name|NULL
condition|)
return|return;
if|if
condition|(
name|acctp
operator|->
name|v_type
operator|==
name|VBAD
condition|)
block|{
operator|(
name|void
operator|)
name|vn_close
argument_list|(
name|acctp
argument_list|,
name|FWRITE
argument_list|,
name|NOCRED
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|acctp
operator|=
name|NULL
expr_stmt|;
return|return;
block|}
operator|(
name|void
operator|)
name|VFS_STATFS
argument_list|(
name|acctp
operator|->
name|v_mount
argument_list|,
operator|&
name|sb
argument_list|,
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|sb
operator|.
name|f_bavail
operator|<=
name|acctsuspend
operator|*
name|sb
operator|.
name|f_blocks
operator|/
literal|100
condition|)
block|{
name|savacctp
operator|=
name|acctp
expr_stmt|;
name|acctp
operator|=
name|NULL
expr_stmt|;
name|log
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"Accounting suspended\n"
argument_list|)
expr_stmt|;
block|}
block|}
name|timeout
argument_list|(
name|acctwatch
argument_list|,
name|NULL
argument_list|,
name|acctchkfreq
operator|*
name|hz
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

