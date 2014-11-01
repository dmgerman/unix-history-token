begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"atf-c/detail/sanity.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
specifier|static
name|void
name|fail
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|char
name|buf
index|[
literal|4096
index|]
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|warnx
argument_list|(
literal|"%s"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|warnx
argument_list|(
literal|"%s"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|warnx
argument_list|(
literal|"This is probably a bug in this application or one of the "
literal|"libraries it uses.  If you believe this problem is caused "
literal|"by, or is related to "
name|PACKAGE_STRING
literal|", please report it "
literal|"to "
name|PACKAGE_BUGREPORT
literal|" and provide as many details as "
literal|"possible describing how you got to this condition."
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|atf_sanity_inv
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|cond
parameter_list|)
block|{
name|fail
argument_list|(
literal|"Invariant check failed at %s:%d: %s"
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|cond
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|atf_sanity_pre
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|cond
parameter_list|)
block|{
name|fail
argument_list|(
literal|"Precondition check failed at %s:%d: %s"
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|cond
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|atf_sanity_post
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|cond
parameter_list|)
block|{
name|fail
argument_list|(
literal|"Postcondition check failed at %s:%d: %s"
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|cond
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

