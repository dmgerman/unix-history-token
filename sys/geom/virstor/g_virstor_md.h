begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Ivan Voras<ivoras@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_VIRSTOR_MD_H_
end_ifndef

begin_define
define|#
directive|define
name|_G_VIRSTOR_MD_H_
end_define

begin_comment
comment|/*  * Metadata declaration  */
end_comment

begin_define
define|#
directive|define
name|G_VIRSTOR_MAGIC
value|"GEOM::VIRSTOR"
end_define

begin_define
define|#
directive|define
name|G_VIRSTOR_VERSION
value|1
end_define

begin_comment
comment|/* flag: provider is allocated */
end_comment

begin_define
define|#
directive|define
name|VIRSTOR_PROVIDER_ALLOCATED
value|1
end_define

begin_comment
comment|/* flag: provider is currently being filled (usually it's the last  * provider with VIRSTOR_PROVIDER_ALLOCATED flag */
end_comment

begin_define
define|#
directive|define
name|VIRSTOR_PROVIDER_CURRENT
value|2
end_define

begin_struct
struct|struct
name|g_virstor_metadata
block|{
comment|/* Data global to the virstor device */
name|char
name|md_magic
index|[
literal|16
index|]
decl_stmt|;
comment|/* Magic value. */
name|uint32_t
name|md_version
decl_stmt|;
comment|/* Version number. */
name|char
name|md_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* Device name (e.g. "mydata") */
name|uint32_t
name|md_id
decl_stmt|;
comment|/* Unique ID. */
name|uint64_t
name|md_virsize
decl_stmt|;
comment|/* Virtual device's size */
name|uint32_t
name|md_chunk_size
decl_stmt|;
comment|/* Chunk size in bytes */
name|uint16_t
name|md_count
decl_stmt|;
comment|/* Total number of providers */
comment|/* Data local to this provider */
name|char
name|provider
index|[
literal|16
index|]
decl_stmt|;
comment|/* Hardcoded provider name */
name|uint16_t
name|no
decl_stmt|;
comment|/* Provider number/index */
name|uint64_t
name|provsize
decl_stmt|;
comment|/* Provider's size */
name|uint32_t
name|chunk_count
decl_stmt|;
comment|/* Number of chunks in this pr. */
name|uint32_t
name|chunk_next
decl_stmt|;
comment|/* Next chunk to allocate */
name|uint16_t
name|chunk_reserved
decl_stmt|;
comment|/* Count of "reserved" chunks */
name|uint16_t
name|flags
decl_stmt|;
comment|/* Provider's flags */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|virstor_metadata_encode
parameter_list|(
name|struct
name|g_virstor_metadata
modifier|*
name|md
parameter_list|,
name|unsigned
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virstor_metadata_decode
parameter_list|(
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|struct
name|g_virstor_metadata
modifier|*
name|md
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_G_VIRSTOR_H_ */
end_comment

end_unit

