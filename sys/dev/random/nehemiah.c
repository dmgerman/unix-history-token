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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/randomdev.h>
end_include

begin_function_decl
specifier|static
name|int
name|random_nehemiah_read
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|random_systat
name|random_nehemiah
init|=
block|{
operator|.
name|ident
operator|=
literal|"Hardware, VIA Nehemiah"
block|,
operator|.
name|init
operator|=
operator|(
name|random_init_func_t
operator|*
operator|)
name|random_null_func
block|,
operator|.
name|deinit
operator|=
operator|(
name|random_deinit_func_t
operator|*
operator|)
name|random_null_func
block|,
operator|.
name|read
operator|=
name|random_nehemiah_read
block|,
operator|.
name|write
operator|=
operator|(
name|random_write_func_t
operator|*
operator|)
name|random_null_func
block|,
operator|.
name|reseed
operator|=
operator|(
name|random_reseed_func_t
operator|*
operator|)
name|random_null_func
block|,
operator|.
name|seeded
operator|=
literal|1
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|random_nehemiah_read
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|c
parameter_list|)
block|{
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|__i386__
argument_list|)
name|int
name|count
init|=
name|c
decl_stmt|;
name|int
name|rate
init|=
literal|0
decl_stmt|;
comment|/* VIA C3 Nehemiah "rep; xstore" */
asm|__asm __volatile("rep; .byte 0x0f, 0xa7, 0xc0"
block|:
literal|"+D"
operator|(
name|buf
operator|)
operator|,
literal|"+c"
operator|(
name|count
operator|)
operator|,
literal|"=d"
operator|(
name|rate
operator|)
operator|:
operator|:
literal|"memory"
block|)
function|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
operator|(
name|c
operator|)
return|;
end_return

unit|}
end_unit

