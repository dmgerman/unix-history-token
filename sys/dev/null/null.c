begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Mark R. V. Murray& Jeroen C. van Gelderen  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/disk.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
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

begin_comment
comment|/* For use with destroy_dev(9). */
end_comment

begin_decl_stmt
specifier|static
name|dev_t
name|null_dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|dev_t
name|zero_dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_write_t
name|null_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|null_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_read_t
name|zero_read
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
name|NULL_MINOR
value|2
end_define

begin_define
define|#
directive|define
name|ZERO_MINOR
value|12
end_define

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|null_cdevsw
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
operator|(
name|d_read_t
operator|*
operator|)
name|nullop
block|,
comment|/* write */
name|null_write
block|,
comment|/* ioctl */
name|null_ioctl
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
literal|"null"
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
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|zero_cdevsw
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
name|zero_read
block|,
comment|/* write */
name|null_write
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
literal|"zero"
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
name|D_MMAP_ANON
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
modifier|*
name|zbuf
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|null_write
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
name|uio
operator|->
name|uio_resid
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|null_ioctl
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
if|if
condition|(
name|cmd
operator|!=
name|DIOCGKERNELDUMP
condition|)
return|return
operator|(
name|noioctl
argument_list|(
name|dev
argument_list|,
name|cmd
argument_list|,
name|data
argument_list|,
name|fflag
argument_list|,
name|td
argument_list|)
operator|)
return|;
name|error
operator|=
name|suser
argument_list|(
name|td
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return
operator|(
name|error
operator|)
return|;
return|return
operator|(
name|set_dumper
argument_list|(
name|NULL
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|zero_read
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
name|zbuf
argument_list|,
name|c
argument_list|,
name|uio
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|null_modevent
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
literal|"null:<null device, zero device>\n"
argument_list|)
expr_stmt|;
name|zbuf
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
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
name|zero_dev
operator|=
name|make_dev
argument_list|(
operator|&
name|zero_cdevsw
argument_list|,
name|ZERO_MINOR
argument_list|,
name|UID_ROOT
argument_list|,
name|GID_WHEEL
argument_list|,
literal|0666
argument_list|,
literal|"zero"
argument_list|)
expr_stmt|;
name|null_dev
operator|=
name|make_dev
argument_list|(
operator|&
name|null_cdevsw
argument_list|,
name|NULL_MINOR
argument_list|,
name|UID_ROOT
argument_list|,
name|GID_WHEEL
argument_list|,
literal|0666
argument_list|,
literal|"null"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
case|case
name|MOD_UNLOAD
case|:
name|destroy_dev
argument_list|(
name|null_dev
argument_list|)
expr_stmt|;
name|destroy_dev
argument_list|(
name|zero_dev
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|zbuf
argument_list|,
name|M_TEMP
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
name|null
argument_list|,
name|null_modevent
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

