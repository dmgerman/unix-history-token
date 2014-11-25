begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2014 Devin Teske<dteske@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FIGPAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_FIGPAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * Union for storing various types of data in a single common container.  */
end_comment

begin_union
union|union
name|fp_cfgvalue
block|{
name|void
modifier|*
name|data
decl_stmt|;
comment|/* Pointer to NUL-terminated string */
name|char
modifier|*
name|str
decl_stmt|;
comment|/* Pointer to NUL-terminated string */
name|char
modifier|*
modifier|*
name|strarray
decl_stmt|;
comment|/* Pointer to an array of strings */
name|int32_t
name|num
decl_stmt|;
comment|/* Signed 32-bit integer value */
name|uint32_t
name|u_num
decl_stmt|;
comment|/* Unsigned 32-bit integer value */
name|uint32_t
name|boolean
range|:
literal|1
decl_stmt|;
comment|/* Boolean integer value (0 or 1) */
block|}
union|;
end_union

begin_comment
comment|/*  * Option types (based on above cfgvalue union)  */
end_comment

begin_enum
enum|enum
name|fp_cfgtype
block|{
name|FP_TYPE_NONE
init|=
literal|0x0000
block|,
comment|/* for directives with no value */
name|FP_TYPE_BOOL
init|=
literal|0x0001
block|,
comment|/* boolean */
name|FP_TYPE_INT
init|=
literal|0x0002
block|,
comment|/* signed 32 bit integer */
name|FP_TYPE_UINT
init|=
literal|0x0004
block|,
comment|/* unsigned 32 bit integer */
name|FP_TYPE_STR
init|=
literal|0x0008
block|,
comment|/* string pointer */
name|FP_TYPE_STRARRAY
init|=
literal|0x0010
block|,
comment|/* string array pointer */
name|FP_TYPE_DATA1
init|=
literal|0x0020
block|,
comment|/* void data type-1 (whatever) */
name|FP_TYPE_DATA2
init|=
literal|0x0040
block|,
comment|/* void data type-2 (whatever) */
name|FP_TYPE_DATA3
init|=
literal|0x0080
block|,
comment|/* void data type-3 (whatever) */
name|FP_TYPE_RESERVED1
init|=
literal|0x0100
block|,
comment|/* reserved data type-1 (future) */
name|FP_TYPE_RESERVED2
init|=
literal|0x0200
block|,
comment|/* reserved data type-2 (future) */
name|FP_TYPE_RESERVED3
init|=
literal|0x0400
block|,
comment|/* reserved data type-3 (future) */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Options to parse_config() for processing_options bitmask  */
end_comment

begin_define
define|#
directive|define
name|FP_BREAK_ON_EQUALS
value|0x0001
end_define

begin_comment
comment|/* stop reading directive at `=' */
end_comment

begin_define
define|#
directive|define
name|FP_BREAK_ON_SEMICOLON
value|0x0002
end_define

begin_comment
comment|/* `;' starts a new line */
end_comment

begin_define
define|#
directive|define
name|FP_CASE_SENSITIVE
value|0x0004
end_define

begin_comment
comment|/* directives are case sensitive */
end_comment

begin_define
define|#
directive|define
name|FP_REQUIRE_EQUALS
value|0x0008
end_define

begin_comment
comment|/* assignment directives only */
end_comment

begin_define
define|#
directive|define
name|FP_STRICT_EQUALS
value|0x0010
end_define

begin_comment
comment|/* `=' must be part of directive */
end_comment

begin_comment
comment|/*  * Anatomy of a config file option  */
end_comment

begin_struct
struct|struct
name|fp_config
block|{
name|enum
name|fp_cfgtype
name|type
decl_stmt|;
comment|/* Option value type */
specifier|const
name|char
modifier|*
name|directive
decl_stmt|;
comment|/* config file keyword */
name|union
name|fp_cfgvalue
name|value
decl_stmt|;
comment|/* NB: set by action */
comment|/* 	 * Function pointer; action to be taken when the directive is found 	 */
name|int
function_decl|(
modifier|*
name|action
function_decl|)
parameter_list|(
name|struct
name|fp_config
modifier|*
name|option
parameter_list|,
name|uint32_t
name|line
parameter_list|,
name|char
modifier|*
name|directive
parameter_list|,
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|fp_config
name|fp_dummy_config
decl_stmt|;
end_decl_stmt

begin_function_decl
name|__BEGIN_DECLS
name|int
name|parse_config
parameter_list|(
name|struct
name|fp_config
name|_options
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
function_decl|(
modifier|*
name|_unknown
function_decl|)
parameter_list|(
name|struct
name|fp_config
modifier|*
name|_option
parameter_list|,
name|uint32_t
name|_line
parameter_list|,
name|char
modifier|*
name|_directive
parameter_list|,
name|char
modifier|*
name|_value
parameter_list|)
parameter_list|,
name|uint16_t
name|_processing_options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fp_config
modifier|*
name|get_config_option
parameter_list|(
name|struct
name|fp_config
name|_options
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
name|_directive
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FIGPAR_H_ */
end_comment

end_unit

