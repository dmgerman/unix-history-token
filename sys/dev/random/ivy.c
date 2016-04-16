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
file|<sys/conf.h>
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

begin_define
define|#
directive|define
name|RETRY_COUNT
value|10
end_define

begin_function_decl
specifier|static
name|u_int
name|random_ivy_read
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|random_source
name|random_ivy
init|=
block|{
operator|.
name|rs_ident
operator|=
literal|"Intel Secure Key RNG"
block|,
operator|.
name|rs_source
operator|=
name|RANDOM_PURE_RDRAND
block|,
operator|.
name|rs_read
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
name|u_long
modifier|*
name|buf
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
name|u_long
name|rndval
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
literal|"rdrand	%1\n\t"
comment|/* read randomness into rndval */
literal|"jc		2f\n\t"
comment|/* CF is set on success, exit retry loop */
literal|"dec	%0\n\t"
comment|/* otherwise, retry-- */
literal|"jne	1b\n\t"
comment|/* and loop if retries are not exhausted */
literal|"2:"
operator|:
literal|"+r"
operator|(
name|retry
operator|)
operator|,
literal|"=r"
operator|(
name|rndval
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_expr_stmt
operator|*
name|buf
operator|=
name|rndval
expr_stmt|;
end_expr_stmt

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

begin_comment
unit|}
comment|/* It is required that buf length is a multiple of sizeof(u_long). */
end_comment

begin_function
unit|static
name|u_int
name|random_ivy_read
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|u_int
name|c
parameter_list|)
block|{
name|u_long
modifier|*
name|b
decl_stmt|,
name|rndval
decl_stmt|;
name|u_int
name|count
decl_stmt|;
name|KASSERT
argument_list|(
name|c
operator|%
sizeof|sizeof
argument_list|(
operator|*
name|b
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
name|b
operator|=
name|buf
expr_stmt|;
for|for
control|(
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
operator|*
name|b
argument_list|)
control|)
block|{
if|if
condition|(
name|ivy_rng_store
argument_list|(
operator|&
name|rndval
argument_list|)
operator|==
literal|0
condition|)
break|break;
operator|*
name|b
operator|++
operator|=
name|rndval
expr_stmt|;
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
block|{
name|random_source_register
argument_list|(
operator|&
name|random_ivy
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"random: fast provider: \"%s\"\n"
argument_list|,
name|random_ivy
operator|.
name|rs_ident
argument_list|)
expr_stmt|;
block|}
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
name|random_source_deregister
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
name|DEV_MODULE
argument_list|(
name|rdrand
argument_list|,
name|rdrand_modevent
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|rdrand
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|rdrand
argument_list|,
name|random_device
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

