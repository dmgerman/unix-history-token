begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
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

begin_comment
comment|/* hold the address of the routine which is actually called if */
end_comment

begin_comment
comment|/* the ramdomdev is loaded                                     */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|reap
function_decl|)
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
init|=
name|NULL
function_decl|;
end_function_decl

begin_comment
comment|/* Initialise the harvester at load time */
end_comment

begin_function
name|void
name|random_init_harvester
parameter_list|(
name|void
function_decl|(
modifier|*
name|reaper
function_decl|)
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
parameter_list|)
block|{
name|reap
operator|=
name|reaper
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Deinitialise the harvester at unload time */
end_comment

begin_function
name|void
name|random_deinit_harvester
parameter_list|(
name|void
parameter_list|)
block|{
name|reap
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Entropy harvesting routine. This is supposed to be fast; do */
end_comment

begin_comment
comment|/* not do anything slow in here!                               */
end_comment

begin_comment
comment|/* Implemented as in indirect call to allow non-inclusion of   */
end_comment

begin_comment
comment|/* the entropy device.                                         */
end_comment

begin_function
name|void
name|random_harvest
parameter_list|(
name|u_int64_t
name|entropy
parameter_list|,
name|u_int
name|bits
parameter_list|,
name|u_int
name|frac
parameter_list|,
name|u_int
name|source
parameter_list|)
block|{
name|struct
name|timespec
name|nanotime
decl_stmt|;
if|if
condition|(
name|reap
condition|)
block|{
name|getnanotime
argument_list|(
operator|&
name|nanotime
argument_list|)
expr_stmt|;
call|(
modifier|*
name|reap
call|)
argument_list|(
operator|&
name|nanotime
argument_list|,
name|entropy
argument_list|,
name|bits
argument_list|,
name|frac
argument_list|,
name|source
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

