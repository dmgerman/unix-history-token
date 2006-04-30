begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_GPT_H_
end_define

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/gpt.h>
end_include

begin_include
include|#
directive|include
file|<uuid.h>
end_include

begin_function_decl
name|void
name|le_uuid_dec
parameter_list|(
name|void
specifier|const
modifier|*
parameter_list|,
name|uuid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|le_uuid_enc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uuid_t
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|mbr_part
block|{
name|uint8_t
name|part_flag
decl_stmt|;
comment|/* bootstrap flags */
name|uint8_t
name|part_shd
decl_stmt|;
comment|/* starting head */
name|uint8_t
name|part_ssect
decl_stmt|;
comment|/* starting sector */
name|uint8_t
name|part_scyl
decl_stmt|;
comment|/* starting cylinder */
name|uint8_t
name|part_typ
decl_stmt|;
comment|/* partition type */
name|uint8_t
name|part_ehd
decl_stmt|;
comment|/* end head */
name|uint8_t
name|part_esect
decl_stmt|;
comment|/* end sector */
name|uint8_t
name|part_ecyl
decl_stmt|;
comment|/* end cylinder */
name|uint16_t
name|part_start_lo
decl_stmt|;
comment|/* absolute starting ... */
name|uint16_t
name|part_start_hi
decl_stmt|;
comment|/* ... sector number */
name|uint16_t
name|part_size_lo
decl_stmt|;
comment|/* partition size ... */
name|uint16_t
name|part_size_hi
decl_stmt|;
comment|/* ... in sectors */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mbr
block|{
name|uint16_t
name|mbr_code
index|[
literal|223
index|]
decl_stmt|;
name|struct
name|mbr_part
name|mbr_part
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|mbr_sig
decl_stmt|;
define|#
directive|define
name|MBR_SIG
value|0xAA55
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|device_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|off_t
name|mediasz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|parts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|secsz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|readonly
decl_stmt|,
name|verbose
decl_stmt|;
end_decl_stmt

begin_function_decl
name|uint32_t
name|crc32
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gpt_close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpt_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|gpt_read
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpt_write
parameter_list|(
name|int
parameter_list|,
name|map_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|utf16_to_utf8
parameter_list|(
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|utf8_to_utf16
parameter_list|(
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmd_add
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmd_create
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmd_destroy
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmd_label
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmd_migrate
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmd_recover
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmd_remove
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmd_show
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GPT_H_ */
end_comment

end_unit

