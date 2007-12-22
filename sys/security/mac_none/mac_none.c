begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2002, 2007 Robert N. M. Watson  * Copyright (c) 2001-2003 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * This software was developed for the FreeBSD Project in part by Network  * Associates Laboratories, the Security Research Division of Network  * Associates, Inc. under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"),  * as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Developed by the TrustedBSD Project.  *  * Sample policy implementing no entry points; for performance measurement  * purposes only.  If you're looking for a stub policy to base new policies  * on, try mac_stub.  */
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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<security/mac/mac_policy.h>
end_include

begin_decl_stmt
specifier|static
name|struct
name|mac_policy_ops
name|mac_none_ops
init|=
block|{ }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|MAC_POLICY_SET
argument_list|(
operator|&
name|mac_none_ops
argument_list|,
name|mac_none
argument_list|,
literal|"TrustedBSD MAC/None"
argument_list|,
name|MPC_LOADTIME_FLAG_UNLOADOK
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

