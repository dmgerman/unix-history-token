begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_PARSERVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_PARSERVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_common.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_parser.h"
end_include

begin_define
define|#
directive|define
name|NVRAM_IDX_VAR_THRESH
value|15
end_define

begin_comment
comment|/**< index is generated if minimum variable count is met */
end_comment

begin_define
define|#
directive|define
name|NVRAM_IDX_OFFSET_MAX
value|UINT16_MAX
end_define

begin_comment
comment|/**< maximum indexable offset */
end_comment

begin_define
define|#
directive|define
name|NVRAM_IDX_LEN_MAX
value|UINT8_MAX
end_define

begin_comment
comment|/**< maximum indexable key/value length */
end_comment

begin_define
define|#
directive|define
name|NVRAM_KEY_MAX
value|64
end_define

begin_comment
comment|/**< maximum key length (not incl. NUL) */
end_comment

begin_define
define|#
directive|define
name|NVRAM_VAL_MAX
value|255
end_define

begin_comment
comment|/**< maximum value length (not incl. NUL) */
end_comment

begin_define
define|#
directive|define
name|NVRAM_DEVPATH_STR
value|"devpath"
end_define

begin_comment
comment|/**< name prefix of device path aliases */
end_comment

begin_define
define|#
directive|define
name|NVRAM_DEVPATH_LEN
value|(sizeof(NVRAM_DEVPATH_STR) - 1)
end_define

begin_define
define|#
directive|define
name|NVRAM_SMALL_HASH_SIZE
value|16
end_define

begin_comment
comment|/**< hash table size for pending/default tuples */
end_comment

begin_comment
comment|/**  * NVRAM devpath record.  *   * Aliases index values to full device paths.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_devpath
block|{
name|u_long
name|index
decl_stmt|;
comment|/** alias index */
name|char
modifier|*
name|path
decl_stmt|;
comment|/** aliased path */
name|LIST_ENTRY
argument_list|(
argument|bhnd_nvram_devpath
argument_list|)
name|dp_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * NVRAM index record.  *   * Provides entry offsets into a backing NVRAM buffer.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_idx_entry
block|{
name|uint16_t
name|env_offset
decl_stmt|;
comment|/**< offset to env string */
name|uint8_t
name|key_len
decl_stmt|;
comment|/**< key length */
name|uint8_t
name|val_len
decl_stmt|;
comment|/**< value length */
block|}
struct|;
end_struct

begin_comment
comment|/**  * NVRAM index.  *   * Provides a compact binary search index into the backing NVRAM buffer.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_idx
block|{
name|size_t
name|num_entries
decl_stmt|;
comment|/**< entry count */
name|struct
name|bhnd_nvram_idx_entry
name|entries
index|[]
decl_stmt|;
comment|/**< index entries */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_PARSERVAR_H_ */
end_comment

end_unit

