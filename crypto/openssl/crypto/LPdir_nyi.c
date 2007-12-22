begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $LP: LPlib/source/LPdir_win.c,v 1.1 2004/06/14 10:07:56 _cvs_levitte Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004, Richard Levitte<richard@levitte.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LPDIR_H
end_ifndef

begin_include
include|#
directive|include
file|"LPdir.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|LP_dir_context_st
block|{
name|void
modifier|*
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|const
name|char
modifier|*
name|LP_find_file
parameter_list|(
name|LP_DIR_CTX
modifier|*
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|directory
parameter_list|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|LP_find_file_end
parameter_list|(
name|LP_DIR_CTX
modifier|*
modifier|*
name|ctx
parameter_list|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

