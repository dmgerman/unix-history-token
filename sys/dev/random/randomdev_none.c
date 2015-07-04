begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
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
file|<sys/malloc.h>
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
file|<dev/random/randomdev.h>
end_include

begin_include
include|#
directive|include
file|"opt_random.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_DUMMY
argument_list|)
operator|||
name|defined
argument_list|(
name|RANDOM_YARROW
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Cannot define any of RANDOM_DUMMY and RANDOM_YARROW without 'device random'"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-  * Dummy "not even here" device. Stub out all routines that the kernel would need.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|u_int
name|read_random
parameter_list|(
name|void
modifier|*
name|random_buf
name|__unused
parameter_list|,
name|u_int
name|len
name|__unused
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|void
name|random_harvest_direct
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
comment|/* ARGSUSED */
end_comment

begin_function
name|void
name|random_harvest_queue
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
comment|/* ARGSUSED */
end_comment

begin_function
name|void
name|random_harvest_fast
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

end_unit

