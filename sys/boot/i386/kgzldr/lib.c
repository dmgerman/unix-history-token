begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Global Technology Associates, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"kgzldr.h"
end_include

begin_define
define|#
directive|define
name|MEMSIZ
value|0x8000
end_define

begin_comment
comment|/* Memory pool size */
end_comment

begin_decl_stmt
name|int
name|kgz_con
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Console control */
end_comment

begin_decl_stmt
specifier|static
name|size_t
name|memtot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Memory allocated: bytes */
end_comment

begin_decl_stmt
specifier|static
name|u_int
name|memcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Memory allocated: blocks */
end_comment

begin_comment
comment|/*  * Library functions required by inflate().  */
end_comment

begin_comment
comment|/*  * Allocate memory block.  */
end_comment

begin_function
name|unsigned
name|char
modifier|*
name|kzipmalloc
parameter_list|(
name|int
name|size
parameter_list|)
block|{
specifier|static
name|u_char
name|mem
index|[
name|MEMSIZ
index|]
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
name|memtot
operator|+
name|size
operator|>
name|MEMSIZ
condition|)
return|return
name|NULL
return|;
name|ptr
operator|=
name|mem
operator|+
name|memtot
expr_stmt|;
name|memtot
operator|+=
name|size
expr_stmt|;
name|memcnt
operator|++
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_function

begin_comment
comment|/*  * Free allocated memory block.  */
end_comment

begin_function
name|void
name|kzipfree
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|memcnt
operator|--
expr_stmt|;
if|if
condition|(
operator|!
name|memcnt
condition|)
name|memtot
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Write a string to the console.  */
end_comment

begin_function
name|void
name|putstr
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|int
name|c
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|str
operator|++
operator|)
condition|)
block|{
if|if
condition|(
name|kgz_con
operator|&
name|KGZ_CRT
condition|)
name|crt_putchr
argument_list|(
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|kgz_con
operator|&
name|KGZ_SIO
condition|)
name|sio_putchr
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

