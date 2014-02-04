begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Arthur Mesh<arthurmesh@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
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
file|<dev/random/live_entropy_sources.h>
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

begin_function_decl
specifier|static
name|int
name|random_example_read
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
name|random_adaptor
name|random_example
init|=
block|{
operator|.
name|ident
operator|=
literal|"Example RNG"
block|,
operator|.
name|source
operator|=
name|RANDOM_PURE_BOGUS
block|,
comment|/* Make sure this is in 					 * sys/random.h and is unique */
operator|.
name|read
operator|=
name|random_example_read
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Used under the license provided @ http://xkcd.com/221/  * http://creativecommons.org/licenses/by-nc/2.5/  */
end_comment

begin_function
specifier|static
name|uint8_t
name|getRandomNumber
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|4
return|;
comment|/* chosen by fair dice roll, guaranteed to be random */
block|}
end_function

begin_function
specifier|static
name|int
name|random_example_read
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|c
parameter_list|)
block|{
name|uint8_t
modifier|*
name|b
decl_stmt|;
name|int
name|count
decl_stmt|;
name|b
operator|=
name|buf
expr_stmt|;
for|for
control|(
name|count
operator|=
literal|0
init|;
name|count
operator|<
name|c
condition|;
name|count
operator|++
control|)
name|b
index|[
name|count
index|]
operator|=
name|getRandomNumber
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"returning %d bytes of pure randomness\n"
argument_list|,
name|c
argument_list|)
expr_stmt|;
return|return
operator|(
name|c
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|random_example_modevent
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
name|live_entropy_source_register
argument_list|(
operator|&
name|random_example
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
name|live_entropy_source_deregister
argument_list|(
operator|&
name|random_example
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
name|live_entropy_source_example
argument_list|,
name|random_example_modevent
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

