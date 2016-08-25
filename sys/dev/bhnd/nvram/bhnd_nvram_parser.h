begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_PARSER_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_PARSER_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_common.h"
end_include

begin_union_decl
union_decl|union
name|bhnd_nvram_ident
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|bhnd_nvram_idx
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bhnd_nvram_ops
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bhnd_nvram_devpath
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bhnd_nvram
struct_decl|;
end_struct_decl

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|bhnd_nvram_devpaths
argument_list|,
name|bhnd_nvram_devpath
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|bhnd_nvram_parser_identify
parameter_list|(
specifier|const
name|union
name|bhnd_nvram_ident
modifier|*
name|ident
parameter_list|,
name|bhnd_nvram_format
name|expected
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_parser_init
parameter_list|(
name|struct
name|bhnd_nvram
modifier|*
name|sc
parameter_list|,
name|device_t
name|owner
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|,
name|bhnd_nvram_format
name|fmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_nvram_parser_fini
parameter_list|(
name|struct
name|bhnd_nvram
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_parser_getvar
parameter_list|(
name|struct
name|bhnd_nvram
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_parser_setvar
parameter_list|(
name|struct
name|bhnd_nvram
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** BCM NVRAM header */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_header
block|{
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|uint32_t
name|cfg0
decl_stmt|;
comment|/**< crc:8, version:8, sdram_init:16 */
name|uint32_t
name|cfg1
decl_stmt|;
comment|/**< sdram_config:16, sdram_refresh:16 */
name|uint32_t
name|sdram_ncdl
decl_stmt|;
comment|/**< sdram_ncdl */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**   * NVRAM format identification.  *   * To perform identification of the NVRAM format using bhnd_nvram_identify(),  * read `sizeof(bhnd_nvram_indent)` bytes from the head of the NVRAM data.  */
end_comment

begin_union
union|union
name|bhnd_nvram_ident
block|{
name|struct
name|bhnd_nvram_header
name|bcm
decl_stmt|;
name|char
name|btxt
index|[
literal|4
index|]
decl_stmt|;
struct|struct
name|bhnd_tlv_ident
block|{
name|uint8_t
name|tag
decl_stmt|;
name|uint8_t
name|size
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
block|}
name|__packed
name|tlv
struct|;
block|}
union|;
end_union

begin_comment
comment|/** bhnd nvram parser instance state */
end_comment

begin_struct
struct|struct
name|bhnd_nvram
block|{
name|device_t
name|dev
decl_stmt|;
comment|/**< parent device, or NULL */
specifier|const
name|struct
name|bhnd_nvram_ops
modifier|*
name|ops
decl_stmt|;
name|uint8_t
modifier|*
name|buf
decl_stmt|;
comment|/**< nvram data */
name|size_t
name|buf_size
decl_stmt|;
name|size_t
name|num_buf_vars
decl_stmt|;
comment|/**< number of records in @p buf (0 if not yet calculated) */
name|struct
name|bhnd_nvram_idx
modifier|*
name|idx
decl_stmt|;
comment|/**< key index */
name|struct
name|bhnd_nvram_devpaths
name|devpaths
decl_stmt|;
comment|/**< device paths */
name|struct
name|bhnd_nvram_varmap
name|defaults
decl_stmt|;
comment|/**< default values */
name|struct
name|bhnd_nvram_varmap
name|pending
decl_stmt|;
comment|/**< uncommitted writes */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_PARSER_H_ */
end_comment

end_unit

