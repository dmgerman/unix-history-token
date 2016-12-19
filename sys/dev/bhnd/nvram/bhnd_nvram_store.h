begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_STORE_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_STORE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_data.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_io.h"
end_include

begin_struct_decl
struct_decl|struct
name|bhnd_nvram_store
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * NVRAM export flags.  */
end_comment

begin_enum
enum|enum
block|{
name|BHND_NVSTORE_EXPORT_CHILDREN
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/**< Include all subpaths */
name|BHND_NVSTORE_EXPORT_PRESERVE_DEVPATHS
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/**< Preserve existing device path definitions (default) */
name|BHND_NVSTORE_EXPORT_COMPACT_DEVPATHS
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/**< Re-encode all device paths using compact syntax */
name|BHND_NVSTORE_EXPORT_EXPAND_DEVPATHS
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
comment|/**< Re-encode all device paths using non-compact syntax */
name|BHND_NVSTORE_EXPORT_ALL_VARS
init|=
operator|(
literal|1
operator|<<
literal|6
operator||
literal|1
operator|<<
literal|7
operator|)
block|,
comment|/**< Include all variables (default) */
name|BHND_NVSTORE_EXPORT_COMMITTED
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
comment|/**< Include all committed changes */
name|BHND_NVSTORE_EXPORT_UNCOMMITTED
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
comment|/**< Include all uncommitted changes (not including deletions) */
name|BHND_NVSTORE_EXPORT_DELETED
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
comment|/**< Include all uncommitted deltions (as 								     properties of type BHND_NVRAM_TYPE_NULL) */
block|}
enum|;
end_enum

begin_function_decl
name|int
name|bhnd_nvram_store_new
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
modifier|*
name|store
parameter_list|,
name|struct
name|bhnd_nvram_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_store_parse_new
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
modifier|*
name|store
parameter_list|,
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|,
name|bhnd_nvram_data_class
modifier|*
name|cls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_nvram_store_free
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|store
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_store_export
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|store
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|bhnd_nvram_data_class
modifier|*
modifier|*
name|cls
parameter_list|,
name|bhnd_nvram_plist
modifier|*
modifier|*
name|props
parameter_list|,
name|bhnd_nvram_plist
modifier|*
modifier|*
name|options
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_store_getvar
parameter_list|(
name|struct
name|bhnd_nvram_store
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
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|,
name|bhnd_nvram_type
name|otype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_store_setvar
parameter_list|(
name|struct
name|bhnd_nvram_store
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
name|inp
parameter_list|,
name|size_t
name|ilen
parameter_list|,
name|bhnd_nvram_type
name|itype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_store_unsetvar
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_store_setval
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bhnd_nvram_val
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_STORE_H_ */
end_comment

end_unit

