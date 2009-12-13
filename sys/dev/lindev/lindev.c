begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 "Bjoern A. Zeeb"<bz@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * "lindev" is supposed to be a collection of linux-specific devices  * that we also support, just not by default.  * While currently there is only "/dev/full", we are planning to see  * more in the future.  * This file is only the container to load/unload all supported devices;  * the implementation of each should go into its own file.  */
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

begin_include
include|#
directive|include
file|<sys/param.h>
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
file|<dev/lindev/lindev.h>
end_include

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|lindev_modevent
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
name|int
name|error
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|MOD_LOAD
case|:
name|error
operator|=
name|lindev_modevent_full
argument_list|(
name|mod
argument_list|,
name|type
argument_list|,
name|data
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
name|error
operator|=
name|lindev_modevent_full
argument_list|(
name|mod
argument_list|,
name|type
argument_list|,
name|data
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_SHUTDOWN
case|:
name|error
operator|=
name|lindev_modevent_full
argument_list|(
name|mod
argument_list|,
name|type
argument_list|,
name|data
argument_list|)
expr_stmt|;
break|break;
default|default:
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DEV_MODULE
argument_list|(
name|lindev
argument_list|,
name|lindev_modevent
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|lindev
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

