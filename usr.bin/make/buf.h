begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)buf.h	8.2 (Berkeley) 4/28/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|buf_h_a61a6812
end_ifndef

begin_define
define|#
directive|define
name|buf_h_a61a6812
end_define

begin_comment
comment|/*-  * buf.h --  *	Header for users of the buf library.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"sprite.h"
end_include

begin_comment
comment|/*  * There are several places where expandable buffers are used (parse.c and  * var.c). This constant is merely the starting point for those buffers. If  * lines tend to be much shorter than this, it would be best to reduce BSIZE.  * If longer, it should be increased. Reducing it will cause more copying to  * be done for longer lines, but will save space for shorter ones. In any  * case, it ought to be a power of two simply because most storage allocation  * schemes allocate in powers of two.  */
end_comment

begin_define
define|#
directive|define
name|MAKE_BSIZE
value|256
end_define

begin_comment
comment|/* starting size for expandable buffers */
end_comment

begin_define
define|#
directive|define
name|BUF_ERROR
value|256
end_define

begin_typedef
typedef|typedef
name|char
name|Byte
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Buffer
block|{
name|size_t
name|size
decl_stmt|;
comment|/* Current size of the buffer */
name|size_t
name|left
decl_stmt|;
comment|/* Space left (== size - (inPtr - buffer)) */
name|Byte
modifier|*
name|buffer
decl_stmt|;
comment|/* The buffer itself */
name|Byte
modifier|*
name|inPtr
decl_stmt|;
comment|/* Place to write to */
name|Byte
modifier|*
name|outPtr
decl_stmt|;
comment|/* Place to read from */
block|}
typedef|*
name|Buffer
typedef|;
end_typedef

begin_comment
comment|/* Buf_AddByte adds a single byte to a buffer. */
end_comment

begin_define
define|#
directive|define
name|Buf_AddByte
parameter_list|(
name|bp
parameter_list|,
name|byte
parameter_list|)
define|\
value|(void)(--(bp)->left<= 0 ? Buf_OvAddByte((bp), (byte)), 1 : \ 		(*(bp)->inPtr++ = (byte), *(bp)->inPtr = 0), 1)
end_define

begin_function_decl
name|void
name|Buf_OvAddByte
parameter_list|(
name|Buffer
parameter_list|,
name|Byte
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Buf_AddBytes
parameter_list|(
name|Buffer
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|Byte
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Buf_UngetByte
parameter_list|(
name|Buffer
parameter_list|,
name|Byte
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Buf_UngetBytes
parameter_list|(
name|Buffer
parameter_list|,
name|size_t
parameter_list|,
name|Byte
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Buf_GetByte
parameter_list|(
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Buf_GetBytes
parameter_list|(
name|Buffer
parameter_list|,
name|size_t
parameter_list|,
name|Byte
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Byte
modifier|*
name|Buf_GetAll
parameter_list|(
name|Buffer
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Buf_Discard
parameter_list|(
name|Buffer
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|Buf_Size
parameter_list|(
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Buffer
name|Buf_Init
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Buf_Destroy
parameter_list|(
name|Buffer
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Buf_ReplaceLastByte
parameter_list|(
name|Buffer
parameter_list|,
name|Byte
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* buf_h_a61a6812 */
end_comment

end_unit

