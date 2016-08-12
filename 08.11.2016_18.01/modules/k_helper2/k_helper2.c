begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: k_helper2.c,v 1.2 2010/11/03 16:10:23 christos Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2010 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__KERNEL_RCSID
argument_list|(
literal|0
argument_list|,
literal|"$NetBSD: k_helper2.c,v 1.2 2010/11/03 16:10:23 christos Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<prop/proplib.h>
end_include

begin_expr_stmt
name|MODULE
argument_list|(
name|MODULE_CLASS_MISC
argument_list|,
name|k_helper2
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* Sysctl interface to query information about the module.               */
end_comment

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* TODO: Change the integer variables below that represent booleans to  * bools, once sysctl(8) supports CTLTYPE_BOOL nodes. */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|sysctllog
modifier|*
name|clogp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|present
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|K_HELPER2
value|0x23456781
end_define

begin_define
define|#
directive|define
name|K_HELPER_PRESENT
value|0
end_define

begin_macro
name|SYSCTL_SETUP
argument_list|(
argument|sysctl_k_helper2_setup
argument_list|,
literal|"sysctl k_helper subtree setup"
argument_list|)
end_macro

begin_block
block|{
name|sysctl_createv
argument_list|(
name|clog
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|CTLFLAG_PERMANENT
argument_list|,
name|CTLTYPE_NODE
argument_list|,
literal|"k_helper2"
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|CTL_VENDOR
argument_list|,
name|K_HELPER2
argument_list|,
name|CTL_EOL
argument_list|)
expr_stmt|;
name|sysctl_createv
argument_list|(
name|clog
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|CTLFLAG_PERMANENT
argument_list|,
name|CTLTYPE_INT
argument_list|,
literal|"present"
argument_list|,
name|SYSCTL_DESCR
argument_list|(
literal|"Whether the module was loaded or not"
argument_list|)
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
operator|&
name|present
argument_list|,
literal|0
argument_list|,
name|CTL_VENDOR
argument_list|,
name|K_HELPER2
argument_list|,
name|K_HELPER_PRESENT
argument_list|,
name|CTL_EOL
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* Module management.                                                    */
end_comment

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_function
specifier|static
name|int
name|k_helper2_init
parameter_list|(
name|prop_dictionary_t
name|props
parameter_list|)
block|{
name|sysctl_k_helper2_setup
argument_list|(
operator|&
name|clogp
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|k_helper2_fini
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|sysctl_teardown
argument_list|(
operator|&
name|clogp
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|k_helper2_modcmd
parameter_list|(
name|modcmd_t
name|cmd
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|MODULE_CMD_INIT
case|:
name|ret
operator|=
name|k_helper2_init
argument_list|(
name|arg
argument_list|)
expr_stmt|;
break|break;
case|case
name|MODULE_CMD_FINI
case|:
name|ret
operator|=
name|k_helper2_fini
argument_list|(
name|arg
argument_list|)
expr_stmt|;
break|break;
case|case
name|MODULE_CMD_STAT
case|:
default|default:
name|ret
operator|=
name|ENOTTY
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function

end_unit

