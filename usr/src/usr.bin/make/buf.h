begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  *  *	@(#)buf.h	5.5 (Berkeley) %G%  */
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
value|(void) (--(bp)->left<= 0 ? Buf_OvAddByte(bp, byte), 1 : \ 		(*(bp)->inPtr++ = (byte), *(bp)->inPtr = 0), 1)
end_define

begin_define
define|#
directive|define
name|BUF_ERROR
value|256
end_define

begin_decl_stmt
name|void
name|Buf_AddBytes
name|__P
argument_list|(
operator|(
name|Buffer
operator|,
name|int
operator|,
name|Byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Buf_Destroy
name|__P
argument_list|(
operator|(
name|Buffer
operator|,
name|Boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Buf_Discard
name|__P
argument_list|(
operator|(
name|Buffer
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Byte
modifier|*
name|Buf_GetAll
name|__P
argument_list|(
operator|(
name|Buffer
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Buf_GetByte
name|__P
argument_list|(
operator|(
name|Buffer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Buf_GetBytes
name|__P
argument_list|(
operator|(
name|Buffer
operator|,
name|int
operator|,
name|Byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Buffer
name|Buf_Init
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Buf_OvAddByte
name|__P
argument_list|(
operator|(
name|Buffer
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Buf_Size
name|__P
argument_list|(
operator|(
name|Buffer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Buf_UngetByte
name|__P
argument_list|(
operator|(
name|Buffer
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Buf_UngetBytes
name|__P
argument_list|(
operator|(
name|Buffer
operator|,
name|int
operator|,
name|Byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BUF_H */
end_comment

end_unit

