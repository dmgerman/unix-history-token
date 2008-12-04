begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2002, 2007 Robert N. M. Watson  * Copyright (c) 2001-2005 Networks Associates Technology, Inc.  * Copyright (c) 2005 Tom Rhodes  * Copyright (c) 2006 SPARTA, Inc.  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  * It was later enhanced by Tom Rhodes for the TrustedBSD Project.  *  * This software was developed for the FreeBSD Project in part by Network  * Associates Laboratories, the Security Research Division of Network  * Associates, Inc. under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"),  * as part of the DARPA CHATS research program.  *  * This software was enhanced by SPARTA ISSO under SPAWAR contract  * N66001-04-C-6019 ("SEFOS").  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/acl.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/jail.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
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
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<security/mac/mac_policy.h>
end_include

begin_include
include|#
directive|include
file|<security/mac_bsdextended/mac_bsdextended.h>
end_include

begin_include
include|#
directive|include
file|<security/mac_bsdextended/ugidfw_internal.h>
end_include

begin_function
name|int
name|ugidfw_system_check_acct
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|label
modifier|*
name|vplabel
parameter_list|)
block|{
if|if
condition|(
name|vp
operator|!=
name|NULL
condition|)
return|return
operator|(
name|ugidfw_check_vp
argument_list|(
name|cred
argument_list|,
name|vp
argument_list|,
name|MBI_WRITE
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|ugidfw_system_check_auditctl
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|label
modifier|*
name|vplabel
parameter_list|)
block|{
if|if
condition|(
name|vp
operator|!=
name|NULL
condition|)
return|return
operator|(
name|ugidfw_check_vp
argument_list|(
name|cred
argument_list|,
name|vp
argument_list|,
name|MBI_WRITE
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|ugidfw_system_check_swapon
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|label
modifier|*
name|vplabel
parameter_list|)
block|{
return|return
operator|(
name|ugidfw_check_vp
argument_list|(
name|cred
argument_list|,
name|vp
argument_list|,
name|MBI_WRITE
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

