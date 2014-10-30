begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2014 Mark R V Murray  * Copyright (c) 2004 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * This is the loadable infrastructure base file for software CSPRNG  * drivers such as Yarrow or Fortuna.  *  * It is anticipated that one instance of this file will be used  * for _each_ invocation of a CSPRNG, but with different #defines  * set. See below.  *  */
end_comment

begin_include
include|#
directive|include
file|"opt_random.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|RANDOM_YARROW
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|RANDOM_FORTUNA
argument_list|)
end_if

begin_define
define|#
directive|define
name|RANDOM_YARROW
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|RANDOM_YARROW
argument_list|)
operator|&&
name|defined
argument_list|(
name|RANDOM_FORTUNA
argument_list|)
end_elif

begin_error
error|#
directive|error
literal|"Must define either RANDOM_YARROW or RANDOM_FORTUNA"
end_error

begin_endif
endif|#
directive|endif
end_endif

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
file|<sys/poll.h>
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
file|<dev/random/randomdev_soft.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/random_harvestq.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/random_adaptors.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_YARROW
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dev/random/yarrow.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_FORTUNA
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dev/random/fortuna.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|struct
name|random_adaptor
name|random_soft_processor
init|=
block|{
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_YARROW
argument_list|)
define|#
directive|define
name|RANDOM_CSPRNG_NAME
value|"yarrow"
operator|.
name|ra_ident
operator|=
literal|"Yarrow"
block|,
operator|.
name|ra_priority
operator|=
literal|90
block|,
comment|/* High priority, so top of the list. Fortuna may still win. */
operator|.
name|ra_read
operator|=
name|random_yarrow_read
block|,
operator|.
name|ra_write
operator|=
name|random_yarrow_write
block|,
operator|.
name|ra_reseed
operator|=
name|random_yarrow_reseed
block|,
operator|.
name|ra_seeded
operator|=
name|random_yarrow_seeded
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_FORTUNA
argument_list|)
define|#
directive|define
name|RANDOM_CSPRNG_NAME
value|"fortuna"
operator|.
name|ra_ident
operator|=
literal|"Fortuna"
block|,
operator|.
name|ra_priority
operator|=
literal|100
block|,
comment|/* High priority, so top of the list. Beat Yarrow. */
operator|.
name|ra_read
operator|=
name|random_fortuna_read
block|,
operator|.
name|ra_write
operator|=
name|random_fortuna_write
block|,
operator|.
name|ra_reseed
operator|=
name|random_fortuna_reseed
block|,
operator|.
name|ra_seeded
operator|=
name|random_fortuna_seeded
block|,
endif|#
directive|endif
operator|.
name|ra_init
operator|=
name|randomdev_init
block|,
operator|.
name|ra_deinit
operator|=
name|randomdev_deinit
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|randomdev_init
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_YARROW
argument_list|)
name|random_yarrow_init_alg
argument_list|()
expr_stmt|;
name|random_harvestq_init
argument_list|(
name|random_yarrow_process_event
argument_list|,
literal|2
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_FORTUNA
argument_list|)
name|random_fortuna_init_alg
argument_list|()
expr_stmt|;
name|random_harvestq_init
argument_list|(
name|random_fortuna_process_event
argument_list|,
literal|32
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Register the randomness harvesting routine */
name|randomdev_init_harvester
argument_list|(
name|random_harvestq_internal
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|randomdev_deinit
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Deregister the randomness harvesting routine */
name|randomdev_deinit_harvester
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_YARROW
argument_list|)
name|random_yarrow_deinit_alg
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_FORTUNA
argument_list|)
name|random_fortuna_deinit_alg
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|randomdev_soft_modevent
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
name|unused
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
literal|"random: SOFT: %s init()\n"
argument_list|,
name|RANDOM_CSPRNG_NAME
argument_list|)
expr_stmt|;
name|random_adaptor_register
argument_list|(
name|RANDOM_CSPRNG_NAME
argument_list|,
operator|&
name|random_soft_processor
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
name|random_adaptor_deregister
argument_list|(
name|RANDOM_CSPRNG_NAME
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

begin_define
define|#
directive|define
name|MID_DEV_MODULE
parameter_list|(
name|name
parameter_list|,
name|evh
parameter_list|,
name|arg
parameter_list|)
define|\
value|static moduledata_t name##_mod = {		\     #name,					\     evh,					\     arg						\ };						\ DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS, SI_ORDER_MIDDLE)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_YARROW
argument_list|)
end_if

begin_expr_stmt
name|MID_DEV_MODULE
argument_list|(
name|yarrow
argument_list|,
name|randomdev_soft_modevent
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|yarrow
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|yarrow
argument_list|,
name|random_adaptors
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_FORTUNA
argument_list|)
end_if

begin_expr_stmt
name|MID_DEV_MODULE
argument_list|(
name|fortuna
argument_list|,
name|randomdev_soft_modevent
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|fortuna
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|fortuna
argument_list|,
name|random_adaptors
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

