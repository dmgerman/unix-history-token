begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/procfs.h>
end_include

begin_include
include|#
directive|include
file|<thread_db.h>
end_include

begin_include
include|#
directive|include
file|<ucontext.h>
end_include

begin_include
include|#
directive|include
file|"libpthread_db.h"
end_include

begin_function
name|void
name|pt_reg_to_ucontext
parameter_list|(
specifier|const
name|struct
name|reg
modifier|*
name|r
name|__unused
parameter_list|,
name|ucontext_t
modifier|*
name|uc
name|__unused
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|pt_ucontext_to_reg
parameter_list|(
specifier|const
name|ucontext_t
modifier|*
name|uc
name|__unused
parameter_list|,
name|struct
name|reg
modifier|*
name|r
name|__unused
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|pt_fpreg_to_ucontext
parameter_list|(
specifier|const
name|struct
name|fpreg
modifier|*
name|r
name|__unused
parameter_list|,
name|ucontext_t
modifier|*
name|uc
name|__unused
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|pt_ucontext_to_fpreg
parameter_list|(
specifier|const
name|ucontext_t
modifier|*
name|uc
name|__unused
parameter_list|,
name|struct
name|fpreg
modifier|*
name|r
name|__unused
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|pt_md_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|int
name|pt_reg_sstep
parameter_list|(
name|struct
name|reg
modifier|*
name|reg
name|__unused
parameter_list|,
name|int
name|step
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

end_unit

