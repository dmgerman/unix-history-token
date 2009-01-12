begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006, 2008 Stanislav Sedov<stas@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INTEL_H
end_ifndef

begin_define
define|#
directive|define
name|INTEL_H
end_define

begin_comment
comment|/*  * Prototypes.  */
end_comment

begin_decl_stmt
name|ucode_probe_t
name|intel_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ucode_update_t
name|intel_update
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|intel_fw_header
block|{
name|uint32_t
name|header_version
decl_stmt|;
comment|/* Version of the header. */
name|int32_t
name|revision
decl_stmt|;
comment|/* Unique version number. */
name|uint32_t
name|date
decl_stmt|;
comment|/* Date of creation in BCD. */
name|uint32_t
name|cpu_signature
decl_stmt|;
comment|/* Extended family, extended 						   model, type, family, model 						   and stepping. */
name|uint32_t
name|checksum
decl_stmt|;
comment|/* Sum of all DWORDS should 						   be 0. */
name|uint32_t
name|loader_revision
decl_stmt|;
comment|/* Version of the loader 						   required to load update. */
name|uint32_t
name|cpu_flags
decl_stmt|;
comment|/* Platform IDs encoded in 						   the lower 8 bits. */
name|uint32_t
name|data_size
decl_stmt|;
name|uint32_t
name|total_size
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|intel_fw_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|intel_cpu_signature
block|{
name|uint32_t
name|cpu_signature
decl_stmt|;
name|uint32_t
name|cpu_flags
decl_stmt|;
name|uint32_t
name|checksum
decl_stmt|;
block|}
name|intel_cpu_signature_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|intel_ext_header
block|{
name|uint32_t
name|sig_count
decl_stmt|;
name|uint32_t
name|checksum
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|intel_ext_header_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INTEL_HEADER_VERSION
value|0x00000001
end_define

begin_define
define|#
directive|define
name|INTEL_LOADER_REVISION
value|0x00000001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !INTEL_H */
end_comment

end_unit

