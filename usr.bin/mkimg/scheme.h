begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013,2014 Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MKIMG_SCHEME_H_
end_ifndef

begin_define
define|#
directive|define
name|_MKIMG_SCHEME_H_
end_define

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_enum
enum|enum
name|alias
block|{
name|ALIAS_NONE
block|,
comment|/* Keep first! */
comment|/* start */
name|ALIAS_EBR
block|,
name|ALIAS_EFI
block|,
name|ALIAS_FAT32
block|,
name|ALIAS_FREEBSD
block|,
name|ALIAS_FREEBSD_BOOT
block|,
name|ALIAS_FREEBSD_NANDFS
block|,
name|ALIAS_FREEBSD_SWAP
block|,
name|ALIAS_FREEBSD_UFS
block|,
name|ALIAS_FREEBSD_VINUM
block|,
name|ALIAS_FREEBSD_ZFS
block|,
name|ALIAS_MBR
block|,
comment|/* end */
name|ALIAS_COUNT
comment|/* Keep last! */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mkimg_alias
block|{
name|u_int
name|alias
decl_stmt|;
name|uintptr_t
name|type
decl_stmt|;
define|#
directive|define
name|ALIAS_PTR2TYPE
parameter_list|(
name|p
parameter_list|)
value|(uintptr_t)(p)
define|#
directive|define
name|ALIAS_INT2TYPE
parameter_list|(
name|i
parameter_list|)
value|(i)
define|#
directive|define
name|ALIAS_TYPE2PTR
parameter_list|(
name|p
parameter_list|)
value|(void *)(p)
define|#
directive|define
name|ALIAS_TYPE2INT
parameter_list|(
name|i
parameter_list|)
value|(i)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mkimg_scheme
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
name|struct
name|mkimg_alias
modifier|*
name|aliases
decl_stmt|;
name|u_int
function_decl|(
modifier|*
name|metadata
function_decl|)
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
define|#
directive|define
name|SCHEME_META_IMG_START
value|1
define|#
directive|define
name|SCHEME_META_IMG_END
value|2
define|#
directive|define
name|SCHEME_META_PART_BEFORE
value|3
define|#
directive|define
name|SCHEME_META_PART_AFTER
value|4
name|int
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|(
name|lba_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|u_int
name|nparts
decl_stmt|;
name|u_int
name|labellen
decl_stmt|;
name|u_int
name|bootcode
decl_stmt|;
name|u_int
name|maxsecsz
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|schemes
argument_list|,
expr|struct
name|mkimg_scheme
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|SCHEME_DEFINE
parameter_list|(
name|nm
parameter_list|)
value|DATA_SET(schemes, nm)
end_define

begin_function_decl
name|int
name|scheme_select
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mkimg_scheme
modifier|*
name|scheme_selected
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scheme_bootcode
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scheme_check_part
parameter_list|(
name|struct
name|part
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|scheme_max_parts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|scheme_max_secsz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lba_t
name|scheme_metadata
parameter_list|(
name|u_int
parameter_list|,
name|lba_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scheme_write
parameter_list|(
name|lba_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MKIMG_SCHEME_H_ */
end_comment

end_unit

