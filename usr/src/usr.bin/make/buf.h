begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  *  *	@(#)buf.h	5.3 (Berkeley) %G%  */
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
name|struct
name|Buffer
modifier|*
name|Buffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Byte
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
name|Buf_AddByte
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Add a single byte to a buffer */
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

