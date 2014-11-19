begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2013 Mark R V Murray  * Copyright (c) 2013 Arthur Mesh<arthurmesh@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * NOTE NOTE NOTE  *  * This file is compiled into the kernel unconditionally. Any random(4)  * infrastructure that needs to be in the kernel by default goes here!  *  * Except ...  *  * The adaptor code all goes into random_adaptor.c, which is also compiled  * the kernel by default. The module in that file is initialised before  * this one.  *  * Other modules must be initialised after the above two, and are  * software random processors which plug into random_adaptor.c.  *  */
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
file|"opt_random.h"
end_include

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
file|<sys/bus.h>
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
file|<sys/filio.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
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
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/randomdev.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/random_adaptors.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/random_harvestq.h>
end_include

begin_define
define|#
directive|define
name|RANDOM_MINOR
value|0
end_define

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|randomdev_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|random_cdevsw
init|=
block|{
operator|.
name|d_name
operator|=
literal|"random"
block|,
operator|.
name|d_version
operator|=
name|D_VERSION
block|,
operator|.
name|d_read
operator|=
name|random_adaptor_read
block|,
operator|.
name|d_write
operator|=
name|random_adaptor_write
block|,
operator|.
name|d_poll
operator|=
name|random_adaptor_poll
block|,
operator|.
name|d_ioctl
operator|=
name|randomdev_ioctl
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For use with make_dev(9)/destroy_dev(9). */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|cdev
modifier|*
name|random_dev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set up the sysctl root node for the entropy device */
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
name|MALLOC_DEFINE
argument_list|(
name|M_ENTROPY
argument_list|,
literal|"entropy"
argument_list|,
literal|"Entropy harvesting buffers and data structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|randomdev_ioctl
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
name|__unused
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|addr
name|__unused
parameter_list|,
name|int
name|flags
name|__unused
parameter_list|,
name|struct
name|thread
modifier|*
name|td
name|__unused
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
comment|/* Really handled in upper layer */
case|case
name|FIOASYNC
case|:
case|case
name|FIONBIO
case|:
break|break;
default|default:
name|error
operator|=
name|ENOTTY
expr_stmt|;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Helper routine to enable kproc_exit() to work while the module is  * being (or has been) unloaded.  * This routine is in this file because it is always linked into the kernel,  * and will thus never be unloaded. This is critical for unloadable modules  * that have threads.  */
end_comment

begin_function
name|void
name|randomdev_set_wakeup_exit
parameter_list|(
name|void
modifier|*
name|control
parameter_list|)
block|{
name|wakeup
argument_list|(
name|control
argument_list|)
expr_stmt|;
name|kproc_exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|randomdev_modevent
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
name|int
name|error
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|MOD_LOAD
case|:
name|printf
argument_list|(
literal|"random: entropy device infrastructure driver\n"
argument_list|)
expr_stmt|;
name|random_dev
operator|=
name|make_dev_credf
argument_list|(
name|MAKEDEV_ETERNAL_KLD
argument_list|,
operator|&
name|random_cdevsw
argument_list|,
name|RANDOM_MINOR
argument_list|,
name|NULL
argument_list|,
name|UID_ROOT
argument_list|,
name|GID_WHEEL
argument_list|,
literal|0644
argument_list|,
literal|"random"
argument_list|)
expr_stmt|;
name|make_dev_alias
argument_list|(
name|random_dev
argument_list|,
literal|"urandom"
argument_list|)
expr_stmt|;
comment|/* compatibility */
name|random_adaptors_init
argument_list|()
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
name|random_adaptors_deinit
argument_list|()
expr_stmt|;
name|destroy_dev
argument_list|(
name|random_dev
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_SHUTDOWN
case|:
break|break;
default|default:
name|error
operator|=
name|EOPNOTSUPP
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DEV_MODULE_ORDERED
argument_list|(
name|randomdev
argument_list|,
name|randomdev_modevent
argument_list|,
name|NULL
argument_list|,
name|SI_ORDER_SECOND
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|randomdev
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ================  * Harvesting stubs  * ================  */
end_comment

begin_comment
comment|/* Internal stub/fake routine for when no entropy processor is loaded.  * If the entropy device is not loaded, don't act on harvesting calls  * and just return.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|void
name|random_harvest_phony
parameter_list|(
specifier|const
name|void
modifier|*
name|entropy
name|__unused
parameter_list|,
name|u_int
name|count
name|__unused
parameter_list|,
name|u_int
name|bits
name|__unused
parameter_list|,
name|enum
name|random_entropy_source
name|origin
name|__unused
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* Hold the address of the routine which is actually called */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|reap_func
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|random_entropy_source
parameter_list|)
init|=
name|random_harvest_phony
function_decl|;
end_function_decl

begin_comment
comment|/* Initialise the harvester when/if it is loaded */
end_comment

begin_function
name|void
name|randomdev_init_harvester
parameter_list|(
name|void
function_decl|(
modifier|*
name|reaper
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|random_entropy_source
parameter_list|)
parameter_list|)
block|{
name|reap_func
operator|=
name|reaper
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Deinitialise the harvester when/if it is unloaded */
end_comment

begin_function
name|void
name|randomdev_deinit_harvester
parameter_list|(
name|void
parameter_list|)
block|{
name|reap_func
operator|=
name|random_harvest_phony
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Entropy harvesting routine.  * Implemented as in indirect call to allow non-inclusion of  * the entropy device.  */
end_comment

begin_function
name|void
name|random_harvest
parameter_list|(
specifier|const
name|void
modifier|*
name|entropy
parameter_list|,
name|u_int
name|count
parameter_list|,
name|u_int
name|bits
parameter_list|,
name|enum
name|random_entropy_source
name|origin
parameter_list|)
block|{
call|(
modifier|*
name|reap_func
call|)
argument_list|(
name|entropy
argument_list|,
name|count
argument_list|,
name|bits
argument_list|,
name|origin
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ================================  * Internal reading stubs and fakes  * ================================  */
end_comment

begin_comment
comment|/* Hold the address of the routine which is actually called */
end_comment

begin_function_decl
specifier|static
name|u_int
function_decl|(
modifier|*
name|read_func
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
init|=
name|dummy_random_read_phony
function_decl|;
end_function_decl

begin_comment
comment|/* Initialise the reader when/if it is loaded */
end_comment

begin_function
name|void
name|randomdev_init_reader
parameter_list|(
name|u_int
function_decl|(
modifier|*
name|reader
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
parameter_list|)
block|{
name|read_func
operator|=
name|reader
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Deinitialise the reader when/if it is unloaded */
end_comment

begin_function
name|void
name|randomdev_deinit_reader
parameter_list|(
name|void
parameter_list|)
block|{
name|read_func
operator|=
name|dummy_random_read_phony
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Kernel API version of read_random().  * Implemented as in indirect call to allow non-inclusion of  * the entropy device.  */
end_comment

begin_function
name|int
name|read_random
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
block|{
return|return
operator|(
call|(
name|int
call|)
argument_list|(
operator|*
name|read_func
argument_list|)
argument_list|(
name|buf
argument_list|,
operator|(
name|u_int
operator|)
name|count
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

