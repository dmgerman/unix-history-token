begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Network Associates Technology, Inc.  * All rights reserved.  *  * This software was developed in part by NAI Labs, the Security Research  * Division of Network Associates, Inc. under DARPA/SPAWAR contract  * N66001-01-C-8035 ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_mac.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mac.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<fs/pseudofs/pseudofs.h>
end_include

begin_include
include|#
directive|include
file|<fs/procfs/procfs.h>
end_include

begin_function
name|int
name|procfs_piddir_refreshlabel
parameter_list|(
name|PFS_REFRESHLABEL_ARGS
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|MAC
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
name|mac_update_vnode_from_mount
argument_list|(
name|vp
argument_list|,
name|vp
operator|->
name|v_mount
argument_list|)
expr_stmt|;
else|else
block|{
name|PROC_LOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|mac_update_procfsvnode
argument_list|(
name|vp
argument_list|,
name|p
operator|->
name|p_ucred
argument_list|)
expr_stmt|;
name|PROC_UNLOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

