begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_cpu.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/random_adaptors.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/randomdev.h>
end_include

begin_function
name|void
name|random_ident_hardware
parameter_list|(
name|struct
name|random_adaptor
modifier|*
modifier|*
name|adaptor
parameter_list|)
block|{
name|struct
name|random_adaptor
modifier|*
name|tmp
decl_stmt|;
name|int
name|enable
decl_stmt|;
comment|/* Set default to software (yarrow) */
operator|*
name|adaptor
operator|=
name|random_adaptor_get
argument_list|(
literal|"yarrow"
argument_list|)
expr_stmt|;
comment|/* Then go looking for hardware */
name|enable
operator|=
literal|1
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"hw.nehemiah_rng_enable"
argument_list|,
operator|&
name|enable
argument_list|)
expr_stmt|;
if|if
condition|(
name|enable
operator|&&
operator|(
name|tmp
operator|=
name|random_adaptor_get
argument_list|(
literal|"nehemiah"
argument_list|)
operator|)
condition|)
operator|*
name|adaptor
operator|=
name|tmp
expr_stmt|;
name|enable
operator|=
literal|1
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"hw.ivy_rng_enable"
argument_list|,
operator|&
name|enable
argument_list|)
expr_stmt|;
if|if
condition|(
name|enable
operator|&&
operator|(
name|tmp
operator|=
name|random_adaptor_get
argument_list|(
literal|"rdrand"
argument_list|)
operator|)
condition|)
operator|*
name|adaptor
operator|=
name|tmp
expr_stmt|;
block|}
end_function

end_unit

