begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_DATA_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_DATA_H_
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

begin_comment
comment|/* _KERNEL */
end_comment

begin_include
include|#
directive|include
file|"bhnd_nvram.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_io.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_plist.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_value.h"
end_include

begin_comment
comment|/* NVRAM data class */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvram_data_class
name|bhnd_nvram_data_class
typedef|;
end_typedef

begin_comment
comment|/* NVRAM data instance */
end_comment

begin_struct_decl
struct_decl|struct
name|bhnd_nvram_data
struct_decl|;
end_struct_decl

begin_comment
comment|/** Declare a bhnd_nvram_data_class with name @p _n */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_DATA_CLASS_DECL
parameter_list|(
name|_n
parameter_list|)
define|\
value|extern 	struct bhnd_nvram_data_class bhnd_nvram_ ## _n ## _class
end_define

begin_expr_stmt
name|BHND_NVRAM_DATA_CLASS_DECL
argument_list|(
name|bcm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_NVRAM_DATA_CLASS_DECL
argument_list|(
name|bcmraw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_NVRAM_DATA_CLASS_DECL
argument_list|(
name|tlv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_NVRAM_DATA_CLASS_DECL
argument_list|(
name|btxt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_NVRAM_DATA_CLASS_DECL
argument_list|(
name|sprom
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/** bhnd_nvram_data capabilities */
end_comment

begin_enum
enum|enum
block|{
comment|/** Supports efficient lookup of variables by name */
name|BHND_NVRAM_DATA_CAP_INDEXED
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/** Supports direct access to backing buffer */
name|BHND_NVRAM_DATA_CAP_READ_PTR
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/** Supports device path prefixed variables */
name|BHND_NVRAM_DATA_CAP_DEVPATHS
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * A standard set of probe priorities returned by bhnd_nvram_data_probe().  *   * Priority is defined in ascending order, with 0 being the highest priority.  * Return values greater than zero are interpreted as regular unix error codes.  */
end_comment

begin_enum
enum|enum
block|{
name|BHND_NVRAM_DATA_PROBE_MAYBE
init|=
operator|-
literal|40
block|,
comment|/**< Possible match */
name|BHND_NVRAM_DATA_PROBE_DEFAULT
init|=
operator|-
literal|20
block|,
comment|/**< Definite match of a base 						     OS-supplied data class */
name|BHND_NVRAM_DATA_PROBE_SPECIFIC
init|=
literal|0
block|,
comment|/**< Terminate search and use 						     this data class for 						     parsing */
block|}
enum|;
end_enum

begin_function_decl
specifier|const
name|char
modifier|*
name|bhnd_nvram_data_class_desc
parameter_list|(
name|bhnd_nvram_data_class
modifier|*
name|cls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_nvram_data_class_caps
parameter_list|(
name|bhnd_nvram_data_class
modifier|*
name|cls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_data_serialize
parameter_list|(
name|bhnd_nvram_data_class
modifier|*
name|cls
parameter_list|,
name|bhnd_nvram_plist
modifier|*
name|props
parameter_list|,
name|bhnd_nvram_plist
modifier|*
name|options
parameter_list|,
name|void
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_data_probe
parameter_list|(
name|bhnd_nvram_data_class
modifier|*
name|cls
parameter_list|,
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_data_probe_classes
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
modifier|*
name|data
parameter_list|,
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|,
name|bhnd_nvram_data_class
modifier|*
name|classes
index|[]
parameter_list|,
name|size_t
name|num_classes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_data_getvar_direct
parameter_list|(
name|bhnd_nvram_data_class
modifier|*
name|cls
parameter_list|,
name|struct
name|bhnd_nvram_io
modifier|*
name|io
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
name|bhnd_nvram_data_new
parameter_list|(
name|bhnd_nvram_data_class
modifier|*
name|cls
parameter_list|,
name|struct
name|bhnd_nvram_data
modifier|*
modifier|*
name|nv
parameter_list|,
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhnd_nvram_data
modifier|*
name|bhnd_nvram_data_retain
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_nvram_data_release
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvram_data_class
modifier|*
name|bhnd_nvram_data_get_class
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|bhnd_nvram_data_count
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvram_plist
modifier|*
name|bhnd_nvram_data_options
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_nvram_data_caps
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|bhnd_nvram_data_next
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|bhnd_nvram_data_find
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
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
name|bhnd_nvram_data_getvar_order
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep1
parameter_list|,
name|void
modifier|*
name|cookiep2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_data_getvar
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep
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
specifier|const
name|void
modifier|*
name|bhnd_nvram_data_getvar_ptr
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
name|bhnd_nvram_type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|bhnd_nvram_data_getvar_name
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_data_copy_val
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|,
name|bhnd_nvram_val
modifier|*
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_data_filter_setvar
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bhnd_nvram_val
modifier|*
name|value
parameter_list|,
name|bhnd_nvram_val
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_data_filter_unsetvar
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_DATA_H_ */
end_comment

end_unit

