begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|storage
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|kzipmalloc
parameter_list|(
name|nbytes
parameter_list|)
name|size_t
name|nbytes
decl_stmt|;
block|{
name|unsigned
name|char
modifier|*
name|p
init|=
name|storage
decl_stmt|;
name|storage
operator|+=
name|nbytes
expr_stmt|;
if|if
condition|(
name|storage
operator|>=
operator|(
name|unsigned
name|char
operator|*
operator|)
literal|0xa0000
condition|)
block|{
name|putstr
argument_list|(
literal|"warning: malloc wrapped\n"
argument_list|)
expr_stmt|;
name|p
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
literal|0x50000
expr_stmt|;
name|storage
operator|=
name|p
operator|+
name|nbytes
expr_stmt|;
block|}
return|return
name|p
return|;
block|}
end_function

begin_function
name|void
name|kzipfree
parameter_list|(
name|cp
parameter_list|)
name|void
modifier|*
name|cp
decl_stmt|;
block|{ }
end_function

end_unit

