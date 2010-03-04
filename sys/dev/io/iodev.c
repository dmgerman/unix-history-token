begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
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
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
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
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/iodev.h>
end_include

begin_decl_stmt
specifier|static
name|struct
name|cdev
modifier|*
name|iodev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|io_cdevsw
init|=
block|{
operator|.
name|d_version
operator|=
name|D_VERSION
block|,
operator|.
name|d_open
operator|=
name|ioopen
block|,
operator|.
name|d_close
operator|=
name|ioclose
block|,
operator|.
name|d_ioctl
operator|=
name|ioioctl
block|,
operator|.
name|d_name
operator|=
literal|"io"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|io_modevent
parameter_list|(
name|module_t
name|mod
name|__unused
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
name|__unused
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|MOD_LOAD
case|:
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"io:<I/O>\n"
argument_list|)
expr_stmt|;
name|iodev
operator|=
name|make_dev
argument_list|(
operator|&
name|io_cdevsw
argument_list|,
literal|0
argument_list|,
name|UID_ROOT
argument_list|,
name|GID_WHEEL
argument_list|,
literal|0600
argument_list|,
literal|"io"
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
name|destroy_dev
argument_list|(
name|iodev
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_SHUTDOWN
case|:
break|break;
default|default:
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
break|break;
block|}
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
name|io
argument_list|,
name|io_modevent
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|io
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

