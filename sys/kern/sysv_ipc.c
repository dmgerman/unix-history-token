begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: sysv_ipc.c,v 1.7 1994/06/29 06:33:11 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 Herb Peyerl<hpeyerl@novatel.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Herb Peyerl.  * 4. The name of Herb Peyerl may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_comment
comment|/*  * Check for ipc permission  */
end_comment

begin_function
name|int
name|ipcperm
parameter_list|(
name|cred
parameter_list|,
name|perm
parameter_list|,
name|mode
parameter_list|)
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
name|struct
name|ipc_perm
modifier|*
name|perm
decl_stmt|;
name|int
name|mode
decl_stmt|;
block|{
if|if
condition|(
name|cred
operator|->
name|cr_uid
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Check for user match. */
if|if
condition|(
name|cred
operator|->
name|cr_uid
operator|!=
name|perm
operator|->
name|cuid
operator|&&
name|cred
operator|->
name|cr_uid
operator|!=
name|perm
operator|->
name|uid
condition|)
block|{
if|if
condition|(
name|mode
operator|&
name|IPC_M
condition|)
return|return
operator|(
name|EPERM
operator|)
return|;
comment|/* Check for group match. */
name|mode
operator|>>=
literal|3
expr_stmt|;
if|if
condition|(
operator|!
name|groupmember
argument_list|(
name|perm
operator|->
name|gid
argument_list|,
name|cred
argument_list|)
operator|&&
operator|!
name|groupmember
argument_list|(
name|perm
operator|->
name|cgid
argument_list|,
name|cred
argument_list|)
condition|)
comment|/* Check for `other' match. */
name|mode
operator|>>=
literal|3
expr_stmt|;
block|}
if|if
condition|(
name|mode
operator|&
name|IPC_M
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
operator|(
name|mode
operator|&
name|perm
operator|->
name|mode
operator|)
operator|==
name|mode
condition|?
literal|0
else|:
name|EACCES
operator|)
return|;
block|}
end_function

end_unit

