begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Interface to packet compression for ssh.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: compress.h,v 1.6 2000/09/07 20:27:50 deraadt Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPRESS_H
end_ifndef

begin_define
define|#
directive|define
name|COMPRESS_H
end_define

begin_comment
comment|/*  * Initializes compression; level is compression level from 1 to 9 (as in  * gzip).  */
end_comment

begin_function_decl
name|void
name|buffer_compress_init
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Frees any data structures allocated by buffer_compress_init. */
end_comment

begin_function_decl
name|void
name|buffer_compress_uninit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Compresses the contents of input_buffer into output_buffer.  All packets  * compressed using this function will form a single compressed data stream;  * however, data will be flushed at the end of every call so that each  * output_buffer can be decompressed independently (but in the appropriate  * order since they together form a single compression stream) by the  * receiver.  This appends the compressed data to the output buffer.  */
end_comment

begin_function_decl
name|void
name|buffer_compress
parameter_list|(
name|Buffer
modifier|*
name|input_buffer
parameter_list|,
name|Buffer
modifier|*
name|output_buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Uncompresses the contents of input_buffer into output_buffer.  All packets  * uncompressed using this function will form a single compressed data  * stream; however, data will be flushed at the end of every call so that  * each output_buffer.  This must be called for the same size units that the  * buffer_compress was called, and in the same order that buffers compressed  * with that.  This appends the uncompressed data to the output buffer.  */
end_comment

begin_function_decl
name|void
name|buffer_uncompress
parameter_list|(
name|Buffer
modifier|*
name|input_buffer
parameter_list|,
name|Buffer
modifier|*
name|output_buffer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPRESS_H */
end_comment

end_unit

