begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  *  *	@(#)buf.h	5.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*-  * buf.h --  *	Header for users of the buf library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BUF_H
end_ifndef

begin_define
define|#
directive|define
name|_BUF_H
end_define

begin_include
include|#
directive|include
file|"sprite.h"
end_include

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Byte
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Buffer
block|{
name|int
name|size
decl_stmt|;
comment|/* Current size of the buffer */
name|int
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

begin_function_decl
name|Buffer
name|Buf_Init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize a buffer */
end_comment

begin_function_decl
name|void
name|Buf_Destroy
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Destroy a buffer */
end_comment

begin_function_decl
name|void
name|Buf_AddBytes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Add a range of bytes to a buffer */
end_comment

begin_function_decl
name|int
name|Buf_GetByte
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Get a byte from a buffer */
end_comment

begin_function_decl
name|int
name|Buf_GetBytes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Get multiple bytes */
end_comment

begin_function_decl
name|void
name|Buf_UngetByte
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Push a byte back into the buffer */
end_comment

begin_function_decl
name|void
name|Buf_UngetBytes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Push many bytes back into the buf */
end_comment

begin_function_decl
name|Byte
modifier|*
name|Buf_GetAll
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Get them all */
end_comment

begin_function_decl
name|void
name|Buf_Discard
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Throw away some of the bytes */
end_comment

begin_function_decl
name|int
name|Buf_Size
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* See how many are there */
end_comment

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
value|(--(bp)->left<= 0 ? Buf_OvAddByte(bp, byte) : \ 		(void)(*(bp)->inPtr++ = (byte), *(bp)->inPtr = 0))
end_define

begin_function_decl
name|void
name|Buf_OvAddByte
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* adds a byte when buffer overflows */
end_comment

begin_define
define|#
directive|define
name|BUF_ERROR
value|256
end_define

begin_endif
endif|#
directive|endif
endif|_BUF_H
end_endif

end_unit

