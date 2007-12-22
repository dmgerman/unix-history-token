begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 nCircle Network Security, Inc.  * All rights reserved.  *  * This software was developed by Robert N. M. Watson for the TrustedBSD  * Project under contract to nCircle Network Security, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR, NCIRCLE NETWORK SECURITY,  * INC., OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * MAC checks for system privileges.  */
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
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<security/mac/mac_framework.h>
end_include

begin_include
include|#
directive|include
file|<security/mac/mac_internal.h>
end_include

begin_include
include|#
directive|include
file|<security/mac/mac_policy.h>
end_include

begin_comment
comment|/*  * The MAC Framework interacts with kernel privilege checks in two ways: it  * may restrict the granting of privilege to a subject, and it may grant  * additional privileges to the subject.  Policies may implement none, one,  * or both of these entry points.  Restriction of privilege by any policy  * always overrides granting of privilege by any policy or other privilege  * mechanism.  See kern_priv.c:priv_check_cred() for details of the  * composition.  */
end_comment

begin_comment
comment|/*  * Restrict access to a privilege for a credential.  Return failure if any  * policy denies access.  */
end_comment

begin_function
name|int
name|mac_priv_check
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|priv
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|MAC_CHECK
argument_list|(
name|priv_check
argument_list|,
name|cred
argument_list|,
name|priv
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Grant access to a privilege for a credential.  Return success if any  * policy grants access.  */
end_comment

begin_function
name|int
name|mac_priv_grant
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|priv
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|MAC_GRANT
argument_list|(
name|priv_grant
argument_list|,
name|cred
argument_list|,
name|priv
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

end_unit

