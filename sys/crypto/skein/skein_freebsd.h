begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2016 Allan Jude  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SKEIN_FREEBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SKEIN_FREEBSD_H_
end_define

begin_define
define|#
directive|define
name|SKEIN_256_BLOCK_BYTES
value|( 8*SKEIN_256_STATE_WORDS)
end_define

begin_define
define|#
directive|define
name|SKEIN_512_BLOCK_BYTES
value|( 8*SKEIN_512_STATE_WORDS)
end_define

begin_define
define|#
directive|define
name|SKEIN1024_BLOCK_BYTES
value|( 8*SKEIN1024_STATE_WORDS)
end_define

begin_define
define|#
directive|define
name|SKEIN256_BLOCK_LENGTH
value|SKEIN_256_BLOCK_BYTES
end_define

begin_define
define|#
directive|define
name|SKEIN256_DIGEST_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|SKEIN256_DIGEST_STRING_LENGTH
value|(SKEIN256_DIGEST_LENGTH * 2 + 1)
end_define

begin_define
define|#
directive|define
name|SKEIN512_BLOCK_LENGTH
value|SKEIN_512_BLOCK_BYTES
end_define

begin_define
define|#
directive|define
name|SKEIN512_DIGEST_LENGTH
value|64
end_define

begin_define
define|#
directive|define
name|SKEIN512_DIGEST_STRING_LENGTH
value|(SKEIN512_DIGEST_LENGTH * 2 + 1)
end_define

begin_define
define|#
directive|define
name|SKEIN1024_BLOCK_LENGTH
value|SKEIN1024_BLOCK_BYTES
end_define

begin_define
define|#
directive|define
name|SKEIN1024_DIGEST_LENGTH
value|128
end_define

begin_define
define|#
directive|define
name|SKEIN1024_DIGEST_STRING_LENGTH
value|(SKEIN1024_DIGEST_LENGTH * 2 + 1)
end_define

begin_comment
comment|/* Make the context types look like the other hashes on FreeBSD */
end_comment

begin_typedef
typedef|typedef
name|Skein_256_Ctxt_t
name|SKEIN256_CTX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Skein_512_Ctxt_t
name|SKEIN512_CTX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Skein1024_Ctxt_t
name|SKEIN1024_CTX
typedef|;
end_typedef

begin_comment
comment|/* Make the prototypes look like the other hashes */
end_comment

begin_function_decl
name|void
name|SKEIN256_Init
parameter_list|(
name|SKEIN256_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SKEIN512_Init
parameter_list|(
name|SKEIN512_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SKEIN1024_Init
parameter_list|(
name|SKEIN1024_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SKEIN256_Update
parameter_list|(
name|SKEIN256_CTX
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|in
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SKEIN512_Update
parameter_list|(
name|SKEIN512_CTX
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|in
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SKEIN1024_Update
parameter_list|(
name|SKEIN1024_CTX
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|in
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SKEIN256_Final
parameter_list|(
name|unsigned
name|char
name|digest
index|[
name|__min_size
argument_list|(
name|SKEIN256_DIGEST_LENGTH
argument_list|)
index|]
parameter_list|,
name|SKEIN256_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SKEIN512_Final
parameter_list|(
name|unsigned
name|char
name|digest
index|[
name|__min_size
argument_list|(
name|SKEIN512_DIGEST_LENGTH
argument_list|)
index|]
parameter_list|,
name|SKEIN512_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SKEIN1024_Final
parameter_list|(
name|unsigned
name|char
name|digest
index|[
name|__min_size
argument_list|(
name|SKEIN1024_DIGEST_LENGTH
argument_list|)
index|]
parameter_list|,
name|SKEIN1024_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|char
modifier|*
name|SKEIN256_End
parameter_list|(
name|SKEIN256_CTX
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN512_End
parameter_list|(
name|SKEIN512_CTX
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN1024_End
parameter_list|(
name|SKEIN1024_CTX
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN256_Data
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN512_Data
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN1024_Data
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN256_Fd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN512_Fd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN1024_Fd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN256_FdChunk
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN512_FdChunk
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN1024_FdChunk
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN256_File
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN512_File
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN1024_File
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN256_FileChunk
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN512_FileChunk
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SKEIN1024_FileChunk
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef _SKEIN_FREEBSD_H_ */
end_comment

end_unit

