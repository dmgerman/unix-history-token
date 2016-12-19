begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: buf.c,v 1.25 2012/04/24 20:26:58 sjg Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAKE_NATIVE
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$NetBSD: buf.c,v 1.25 2012/04/24 20:26:58 sjg Exp $"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_else
unit|static char sccsid[] = "@(#)buf.c	8.1 (Berkeley) 6/6/93";
else|#
directive|else
end_else

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: buf.c,v 1.25 2012/04/24 20:26:58 sjg Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-  * buf.c --  *	Functions for automatically-expanded buffers.  */
end_comment

begin_include
include|#
directive|include
file|"make.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|max
end_ifndef

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BUF_DEF_SIZE
value|256
end_define

begin_comment
comment|/* Default buffer size */
end_comment

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Buf_Expand_1 --  *	Extend buffer for single byte add.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|Buf_Expand_1
parameter_list|(
name|Buffer
modifier|*
name|bp
parameter_list|)
block|{
name|bp
operator|->
name|size
operator|+=
name|max
argument_list|(
name|bp
operator|->
name|size
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|bp
operator|->
name|buffer
operator|=
name|bmake_realloc
argument_list|(
name|bp
operator|->
name|buffer
argument_list|,
name|bp
operator|->
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Buf_AddBytes --  *	Add a number of bytes to the buffer.  *  * Results:  *	None.  *  * Side Effects:  *	Guess what?  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|Buf_AddBytes
parameter_list|(
name|Buffer
modifier|*
name|bp
parameter_list|,
name|int
name|numBytes
parameter_list|,
specifier|const
name|Byte
modifier|*
name|bytesPtr
parameter_list|)
block|{
name|int
name|count
init|=
name|bp
operator|->
name|count
decl_stmt|;
name|Byte
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
name|__predict_false
argument_list|(
name|count
operator|+
name|numBytes
operator|>=
name|bp
operator|->
name|size
argument_list|)
condition|)
block|{
name|bp
operator|->
name|size
operator|+=
name|max
argument_list|(
name|bp
operator|->
name|size
argument_list|,
name|numBytes
operator|+
literal|16
argument_list|)
expr_stmt|;
name|bp
operator|->
name|buffer
operator|=
name|bmake_realloc
argument_list|(
name|bp
operator|->
name|buffer
argument_list|,
name|bp
operator|->
name|size
argument_list|)
expr_stmt|;
block|}
name|ptr
operator|=
name|bp
operator|->
name|buffer
operator|+
name|count
expr_stmt|;
name|bp
operator|->
name|count
operator|=
name|count
operator|+
name|numBytes
expr_stmt|;
name|ptr
index|[
name|numBytes
index|]
operator|=
literal|0
expr_stmt|;
name|memcpy
argument_list|(
name|ptr
argument_list|,
name|bytesPtr
argument_list|,
name|numBytes
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Buf_GetAll --  *	Get all the available data at once.  *  * Results:  *	A pointer to the data and the number of bytes available.  *  * Side Effects:  *	None.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|Byte
modifier|*
name|Buf_GetAll
parameter_list|(
name|Buffer
modifier|*
name|bp
parameter_list|,
name|int
modifier|*
name|numBytesPtr
parameter_list|)
block|{
if|if
condition|(
name|numBytesPtr
operator|!=
name|NULL
condition|)
operator|*
name|numBytesPtr
operator|=
name|bp
operator|->
name|count
expr_stmt|;
return|return
operator|(
name|bp
operator|->
name|buffer
operator|)
return|;
block|}
end_function

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Buf_Empty --  *	Throw away bytes in a buffer.  *  * Results:  *	None.  *  * Side Effects:  *	The bytes are discarded.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|Buf_Empty
parameter_list|(
name|Buffer
modifier|*
name|bp
parameter_list|)
block|{
name|bp
operator|->
name|count
operator|=
literal|0
expr_stmt|;
operator|*
name|bp
operator|->
name|buffer
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Buf_Init --  *	Initialize a buffer. If no initial size is given, a reasonable  *	default is used.  *  * Input:  *	size		Initial size for the buffer  *  * Results:  *	A buffer to be given to other functions in this library.  *  * Side Effects:  *	The buffer is created, the space allocated and pointers  *	initialized.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|Buf_Init
parameter_list|(
name|Buffer
modifier|*
name|bp
parameter_list|,
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
name|size
operator|<=
literal|0
condition|)
block|{
name|size
operator|=
name|BUF_DEF_SIZE
expr_stmt|;
block|}
name|bp
operator|->
name|size
operator|=
name|size
expr_stmt|;
name|bp
operator|->
name|count
operator|=
literal|0
expr_stmt|;
name|bp
operator|->
name|buffer
operator|=
name|bmake_malloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
operator|*
name|bp
operator|->
name|buffer
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Buf_Destroy --  *	Nuke a buffer and all its resources.  *  * Input:  *	buf		Buffer to destroy  *	freeData	TRUE if the data should be destroyed  *  * Results:  *	Data buffer, NULL if freed  *  * Side Effects:  *	The buffer is freed.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|Byte
modifier|*
name|Buf_Destroy
parameter_list|(
name|Buffer
modifier|*
name|buf
parameter_list|,
name|Boolean
name|freeData
parameter_list|)
block|{
name|Byte
modifier|*
name|data
decl_stmt|;
name|data
operator|=
name|buf
operator|->
name|buffer
expr_stmt|;
if|if
condition|(
name|freeData
condition|)
block|{
name|free
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|data
operator|=
name|NULL
expr_stmt|;
block|}
name|buf
operator|->
name|size
operator|=
literal|0
expr_stmt|;
name|buf
operator|->
name|count
operator|=
literal|0
expr_stmt|;
name|buf
operator|->
name|buffer
operator|=
name|NULL
expr_stmt|;
return|return
name|data
return|;
block|}
end_function

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Buf_DestroyCompact --  *	Nuke a buffer and return its data.  *  * Input:  *	buf		Buffer to destroy  *  * Results:  *	Data buffer  *  * Side Effects:  *	If the buffer size is much greater than its content,  *	a new buffer will be allocated and the old one freed.  *  *-----------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUF_COMPACT_LIMIT
end_ifndef

begin_define
define|#
directive|define
name|BUF_COMPACT_LIMIT
value|128
end_define

begin_comment
comment|/* worthwhile saving */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|Byte
modifier|*
name|Buf_DestroyCompact
parameter_list|(
name|Buffer
modifier|*
name|buf
parameter_list|)
block|{
if|#
directive|if
name|BUF_COMPACT_LIMIT
operator|>
literal|0
name|Byte
modifier|*
name|data
decl_stmt|;
if|if
condition|(
name|buf
operator|->
name|size
operator|-
name|buf
operator|->
name|count
operator|>=
name|BUF_COMPACT_LIMIT
condition|)
block|{
comment|/* We trust realloc to be smart */
name|data
operator|=
name|bmake_realloc
argument_list|(
name|buf
operator|->
name|buffer
argument_list|,
name|buf
operator|->
name|count
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|data
condition|)
block|{
name|data
index|[
name|buf
operator|->
name|count
index|]
operator|=
literal|0
expr_stmt|;
name|Buf_Destroy
argument_list|(
name|buf
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
return|return
name|data
return|;
block|}
block|}
endif|#
directive|endif
return|return
name|Buf_Destroy
argument_list|(
name|buf
argument_list|,
name|FALSE
argument_list|)
return|;
block|}
end_function

end_unit

