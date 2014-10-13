begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 The FreeBSD Foundation  * Copyright (c) 2013 David E. O'Brien<obrien@NUXI.org>  * Copyright (c) 2012 Konstantin Belousov<kib@FreeBSD.org>  * All rights reserved.  *  * Portions of this software were developed by Konstantin Belousov  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
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
file|<sys/random.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
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
file|<dev/random/live_entropy_sources.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/random_adaptors.h>
end_include

begin_define
define|#
directive|define
name|RETRY_COUNT
value|10
end_define

begin_function_decl
specifier|static
name|int
name|random_ivy_read
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|random_hardware_source
name|random_ivy
init|=
block|{
operator|.
name|ident
operator|=
literal|"Hardware, Intel Secure Key RNG"
block|,
operator|.
name|source
operator|=
name|RANDOM_PURE_RDRAND
block|,
operator|.
name|read
operator|=
name|random_ivy_read
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|int
name|ivy_rng_store
parameter_list|(
name|long
modifier|*
name|buf
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
name|long
name|tmp
decl_stmt|;
name|int
name|retry
decl_stmt|;
name|retry
operator|=
name|RETRY_COUNT
expr_stmt|;
asm|__asm __volatile(
literal|"1:\n\t"
literal|"rdrand	%2\n\t"
comment|/* read randomness into tmp */
literal|"jb		2f\n\t"
comment|/* CF is set on success, exit retry loop */
literal|"dec	%0\n\t"
comment|/* otherwise, retry-- */
literal|"jne	1b\n\t"
comment|/* and loop if retries are not exhausted */
literal|"jmp	3f\n"
comment|/* failure, retry is 0, used as return value */
literal|"2:\n\t"
literal|"mov	%2,%1\n\t"
comment|/* *buf = tmp */
literal|"3:"
operator|:
literal|"+q"
operator|(
name|retry
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|buf
operator|)
operator|,
literal|"+q"
operator|(
name|tmp
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|retry
operator|)
return|;
end_return

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUCLIKE_ASM */
end_comment

begin_return
return|return
operator|(
literal|0
operator|)
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_function
unit|}  static
name|int
name|random_ivy_read
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|c
parameter_list|)
block|{
name|long
modifier|*
name|b
decl_stmt|;
name|int
name|count
decl_stmt|;
name|KASSERT
argument_list|(
name|c
operator|%
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|==
literal|0
argument_list|,
operator|(
literal|"partial read %d"
operator|,
name|c
operator|)
argument_list|)
expr_stmt|;
for|for
control|(
name|b
operator|=
name|buf
operator|,
name|count
operator|=
name|c
init|;
name|count
operator|>
literal|0
condition|;
name|count
operator|-=
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|,
name|b
operator|++
control|)
block|{
if|if
condition|(
name|ivy_rng_store
argument_list|(
name|b
argument_list|)
operator|==
literal|0
condition|)
break|break;
block|}
return|return
operator|(
name|c
operator|-
name|count
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|rdrand_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|unused
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
if|if
condition|(
name|cpu_feature2
operator|&
name|CPUID2_RDRAND
condition|)
name|live_entropy_source_register
argument_list|(
operator|&
name|random_ivy
argument_list|)
expr_stmt|;
elseif|else
ifndef|#
directive|ifndef
name|KLD_MODULE
if|if
condition|(
name|bootverbose
condition|)
endif|#
directive|endif
name|printf
argument_list|(
literal|"%s: RDRAND is not present\n"
argument_list|,
name|random_ivy
operator|.
name|ident
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
if|if
condition|(
name|cpu_feature2
operator|&
name|CPUID2_RDRAND
condition|)
name|live_entropy_source_deregister
argument_list|(
operator|&
name|random_ivy
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
name|LIVE_ENTROPY_SRC_MODULE
argument_list|(
name|random_rdrand
argument_list|,
name|rdrand_modevent
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

