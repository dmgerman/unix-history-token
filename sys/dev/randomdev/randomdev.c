begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Mark Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/kobj.h>
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<crypto/blowfish/blowfish.h>
end_include

begin_include
include|#
directive|include
file|<dev/randomdev/yarrow.h>
end_include

begin_decl_stmt
specifier|static
name|d_read_t
name|randomread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_write_t
name|randomwrite
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CDEV_MAJOR
value|2
end_define

begin_define
define|#
directive|define
name|RANDOM_MINOR
value|3
end_define

begin_define
define|#
directive|define
name|URANDOM_MINOR
value|4
end_define

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|random_cdevsw
init|=
block|{
comment|/* open */
operator|(
name|d_open_t
operator|*
operator|)
name|nullop
block|,
comment|/* close */
operator|(
name|d_close_t
operator|*
operator|)
name|nullop
block|,
comment|/* read */
name|randomread
block|,
comment|/* write */
name|randomwrite
block|,
comment|/* ioctl */
name|noioctl
block|,
comment|/* poll */
name|nopoll
block|,
comment|/* mmap */
name|nommap
block|,
comment|/* strategy */
name|nostrategy
block|,
comment|/* name */
literal|"random"
block|,
comment|/* maj */
name|CDEV_MAJOR
block|,
comment|/* dump */
name|nodump
block|,
comment|/* psize */
name|nopsize
block|,
comment|/* flags */
literal|0
block|,
comment|/* bmaj */
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For use with make_dev(9)/destroy_dev(9). */
end_comment

begin_decl_stmt
specifier|static
name|dev_t
name|randomdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|dev_t
name|urandomdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|randominit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|state
name|state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is mostly academic at the moment; as Yarrow gets extended, it will    become more relevant */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|random
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Random Number Generator"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_kern_random
argument_list|,
name|OID_AUTO
argument_list|,
name|yarrow
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Yarrow Parameters"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_kern_random_yarrow
argument_list|,
name|OID_AUTO
argument_list|,
name|gengateinterval
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|state
operator|.
name|gengateinterval
argument_list|,
literal|10
argument_list|,
literal|"Generator Gate Interval"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|randomread
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|flag
parameter_list|)
block|{
name|u_int
name|c
decl_stmt|,
name|ret
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
name|c
operator|=
name|min
argument_list|(
name|uio
operator|->
name|uio_resid
argument_list|,
name|PAGE_SIZE
argument_list|)
expr_stmt|;
name|buf
operator|=
operator|(
name|void
operator|*
operator|)
name|malloc
argument_list|(
name|c
argument_list|,
name|M_TEMP
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
while|while
condition|(
name|uio
operator|->
name|uio_resid
operator|>
literal|0
operator|&&
name|error
operator|==
literal|0
condition|)
block|{
name|ret
operator|=
name|read_random
argument_list|(
name|buf
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|error
operator|=
name|uiomove
argument_list|(
name|buf
argument_list|,
name|ret
argument_list|,
name|uio
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|buf
argument_list|,
name|M_TEMP
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|randomwrite
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|flag
parameter_list|)
block|{
name|u_int
name|c
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
name|buf
operator|=
operator|(
name|void
operator|*
operator|)
name|malloc
argument_list|(
name|PAGE_SIZE
argument_list|,
name|M_TEMP
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
while|while
condition|(
name|uio
operator|->
name|uio_resid
operator|>
literal|0
condition|)
block|{
name|c
operator|=
name|min
argument_list|(
name|uio
operator|->
name|uio_resid
argument_list|,
name|PAGE_SIZE
argument_list|)
expr_stmt|;
name|error
operator|=
name|uiomove
argument_list|(
name|buf
argument_list|,
name|c
argument_list|,
name|uio
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
break|break;
comment|/* write_random(buf, c); */
block|}
name|free
argument_list|(
name|buf
argument_list|,
name|M_TEMP
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|random_modevent
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
literal|"random:<entropy source>\n"
argument_list|)
expr_stmt|;
name|randomdev
operator|=
name|make_dev
argument_list|(
operator|&
name|random_cdevsw
argument_list|,
name|RANDOM_MINOR
argument_list|,
name|UID_ROOT
argument_list|,
name|GID_WHEEL
argument_list|,
literal|0666
argument_list|,
literal|"random"
argument_list|)
expr_stmt|;
name|urandomdev
operator|=
name|make_dev
argument_list|(
operator|&
name|random_cdevsw
argument_list|,
name|URANDOM_MINOR
argument_list|,
name|UID_ROOT
argument_list|,
name|GID_WHEEL
argument_list|,
literal|0666
argument_list|,
literal|"urandom"
argument_list|)
expr_stmt|;
name|randominit
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
case|case
name|MOD_UNLOAD
case|:
name|destroy_dev
argument_list|(
name|randomdev
argument_list|)
expr_stmt|;
name|destroy_dev
argument_list|(
name|urandomdev
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
case|case
name|MOD_SHUTDOWN
case|:
return|return
literal|0
return|;
default|default:
return|return
name|EOPNOTSUPP
return|;
block|}
block|}
end_function

begin_expr_stmt
name|DEV_MODULE
argument_list|(
name|random
argument_list|,
name|random_modevent
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

