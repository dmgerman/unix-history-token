begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Code for manipulating FIFO buffers.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: buffer.h,v 1.6 2000/09/07 20:27:50 deraadt Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUFFER_H
end_ifndef

begin_define
define|#
directive|define
name|BUFFER_H
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* Buffer for data. */
name|unsigned
name|int
name|alloc
decl_stmt|;
comment|/* Number of bytes allocated for data. */
name|unsigned
name|int
name|offset
decl_stmt|;
comment|/* Offset of first byte containing data. */
name|unsigned
name|int
name|end
decl_stmt|;
comment|/* Offset of last byte containing data. */
block|}
name|Buffer
typedef|;
end_typedef

begin_comment
comment|/* Initializes the buffer structure. */
end_comment

begin_function_decl
name|void
name|buffer_init
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Frees any memory used for the buffer. */
end_comment

begin_function_decl
name|void
name|buffer_free
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Clears any data from the buffer, making it empty.  This does not actually    zero the memory. */
end_comment

begin_function_decl
name|void
name|buffer_clear
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Appends data to the buffer, expanding it if necessary. */
end_comment

begin_function_decl
name|void
name|buffer_append
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Appends space to the buffer, expanding the buffer if necessary. This does  * not actually copy the data into the buffer, but instead returns a pointer  * to the allocated region.  */
end_comment

begin_function_decl
name|void
name|buffer_append_space
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|char
modifier|*
modifier|*
name|datap
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the number of bytes of data in the buffer. */
end_comment

begin_function_decl
name|unsigned
name|int
name|buffer_len
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Gets data from the beginning of the buffer. */
end_comment

begin_function_decl
name|void
name|buffer_get
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Consumes the given number of bytes from the beginning of the buffer. */
end_comment

begin_function_decl
name|void
name|buffer_consume
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Consumes the given number of bytes from the end of the buffer. */
end_comment

begin_function_decl
name|void
name|buffer_consume_end
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns a pointer to the first used byte in the buffer. */
end_comment

begin_function_decl
name|char
modifier|*
name|buffer_ptr
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Dumps the contents of the buffer to stderr in hex.  This intended for  * debugging purposes only.  */
end_comment

begin_function_decl
name|void
name|buffer_dump
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BUFFER_H */
end_comment

end_unit

