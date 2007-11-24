begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Scott Long  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Linux ioctl handler for the aac device driver  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
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
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_include
include|#
directive|include
file|<machine/../linux32/linux.h>
end_include

begin_include
include|#
directive|include
file|<machine/../linux32/linux32_proto.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/../linux/linux.h>
end_include

begin_include
include|#
directive|include
file|<machine/../linux/linux_proto.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<compat/linux/linux_ioctl.h>
end_include

begin_comment
comment|/* There are multiple ioctl number ranges that need to be handled */
end_comment

begin_define
define|#
directive|define
name|AAC_LINUX_IOCTL_MIN
value|0x0000
end_define

begin_define
define|#
directive|define
name|AAC_LINUX_IOCTL_MAX
value|0x21ff
end_define

begin_decl_stmt
specifier|static
name|linux_ioctl_function_t
name|aac_linux_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|linux_ioctl_handler
name|aac_linux_handler
init|=
block|{
name|aac_linux_ioctl
block|,
name|AAC_LINUX_IOCTL_MIN
block|,
name|AAC_LINUX_IOCTL_MAX
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSINIT
argument_list|(
name|aac_linux_register
argument_list|,
name|SI_SUB_KLD
argument_list|,
name|SI_ORDER_MIDDLE
argument_list|,
name|linux_ioctl_register_handler
argument_list|,
operator|&
name|aac_linux_handler
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSUNINIT
argument_list|(
name|aac_linux_unregister
argument_list|,
name|SI_SUB_KLD
argument_list|,
name|SI_ORDER_MIDDLE
argument_list|,
name|linux_ioctl_unregister_handler
argument_list|,
operator|&
name|aac_linux_handler
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|aac_linux_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
comment|/* Do we care about any specific load/unload actions? */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DEV_MODULE
argument_list|(
name|aac_linux
argument_list|,
name|aac_linux_modevent
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|aac_linux
argument_list|,
name|linux
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|aac_linux_ioctl
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|linux_ioctl_args
modifier|*
name|args
parameter_list|)
block|{
name|struct
name|file
modifier|*
name|fp
decl_stmt|;
name|u_long
name|cmd
decl_stmt|;
name|int
name|error
decl_stmt|;
if|if
condition|(
operator|(
name|error
operator|=
name|fget
argument_list|(
name|td
argument_list|,
name|args
operator|->
name|fd
argument_list|,
operator|&
name|fp
argument_list|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|cmd
operator|=
name|args
operator|->
name|cmd
expr_stmt|;
comment|/* 	 * Pass the ioctl off to our standard handler. 	 */
name|error
operator|=
operator|(
name|fo_ioctl
argument_list|(
name|fp
argument_list|,
name|cmd
argument_list|,
operator|(
name|caddr_t
operator|)
name|args
operator|->
name|arg
argument_list|,
name|td
operator|->
name|td_ucred
argument_list|,
name|td
argument_list|)
operator|)
expr_stmt|;
name|fdrop
argument_list|(
name|fp
argument_list|,
name|td
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

