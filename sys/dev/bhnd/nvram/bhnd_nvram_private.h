begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_PRIVATE_H_
end_define

begin_comment
comment|/*  * Private BHND NVRAM definitions.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
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
file|"bhnd_nvram.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_value.h"
end_include

begin_comment
comment|/*  * bhnd_nvram_crc8() lookup table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|uint8_t
name|bhnd_nvram_crc8_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declarations */
end_comment

begin_struct_decl
struct_decl|struct
name|bhnd_nvram_vardefn
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_BHND_NVRAM
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|bhnd_nv_isupper
parameter_list|(
name|c
parameter_list|)
value|isupper(c)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_islower
parameter_list|(
name|c
parameter_list|)
value|islower(c)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_isalpha
parameter_list|(
name|c
parameter_list|)
value|isalpha(c)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_isprint
parameter_list|(
name|c
parameter_list|)
value|isprint(c)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_isspace
parameter_list|(
name|c
parameter_list|)
value|isspace(c)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_isdigit
parameter_list|(
name|c
parameter_list|)
value|isdigit(c)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_isxdigit
parameter_list|(
name|c
parameter_list|)
value|isxdigit(c)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_toupper
parameter_list|(
name|c
parameter_list|)
value|toupper(c)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_malloc
parameter_list|(
name|size
parameter_list|)
value|malloc((size), M_BHND_NVRAM, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_calloc
parameter_list|(
name|n
parameter_list|,
name|size
parameter_list|)
value|malloc((n) * (size), M_BHND_NVRAM, \ 					    M_NOWAIT | M_ZERO)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_reallocf
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
value|reallocf((buf), (size), M_BHND_NVRAM, \ 					    M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_free
parameter_list|(
name|buf
parameter_list|)
value|free((buf), M_BHND_NVRAM)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_asprintf
parameter_list|(
name|buf
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|asprintf((buf), M_BHND_NVRAM,	\ 					    fmt, ## __VA_ARGS__)
end_define

begin_comment
comment|/* We need our own strdup() implementation to pass required M_NOWAIT */
end_comment

begin_function
specifier|static
specifier|inline
name|char
modifier|*
name|bhnd_nv_strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|char
modifier|*
name|dest
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|str
argument_list|)
expr_stmt|;
name|dest
operator|=
name|malloc
argument_list|(
name|len
operator|+
literal|1
argument_list|,
name|M_BHND_NVRAM
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|dest
argument_list|,
name|str
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|dest
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|dest
operator|)
return|;
block|}
end_function

begin_comment
comment|/* We need our own strndup() implementation to pass required M_NOWAIT */
end_comment

begin_function
specifier|static
specifier|inline
name|char
modifier|*
name|bhnd_nv_strndup
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|char
modifier|*
name|dest
decl_stmt|;
name|len
operator|=
name|strnlen
argument_list|(
name|str
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|dest
operator|=
name|malloc
argument_list|(
name|len
operator|+
literal|1
argument_list|,
name|M_BHND_NVRAM
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|dest
argument_list|,
name|str
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|dest
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|dest
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|BHND_NV_INVARIANTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BHND_NV_ASSERT
parameter_list|(
name|expr
parameter_list|,
modifier|...
parameter_list|)
value|KASSERT(expr, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|BHND_NV_VERBOSE
value|(bootverbose)
end_define

begin_define
define|#
directive|define
name|BHND_NV_PANIC
parameter_list|(
modifier|...
parameter_list|)
value|panic(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|BHND_NV_LOG
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|printf("%s: " fmt, __FUNCTION__, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_ummax
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ummax((a), (b))
end_define

begin_define
define|#
directive|define
name|bhnd_nv_ummin
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ummin((a), (b))
end_define

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
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* ASCII-specific ctype variants that work consistently regardless  * of current locale */
end_comment

begin_define
define|#
directive|define
name|bhnd_nv_isupper
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'A'&& (c)<= 'Z')
end_define

begin_define
define|#
directive|define
name|bhnd_nv_islower
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'a'&& (c)<= 'z')
end_define

begin_define
define|#
directive|define
name|bhnd_nv_isalpha
parameter_list|(
name|c
parameter_list|)
value|(bhnd_nv_isupper(c) || bhnd_nv_islower(c))
end_define

begin_define
define|#
directive|define
name|bhnd_nv_isprint
parameter_list|(
name|c
parameter_list|)
value|((c)>= ' '&& (c)<= '~')
end_define

begin_define
define|#
directive|define
name|bhnd_nv_isspace
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || ((c)>= '\t'&& (c)<= '\r'))
end_define

begin_define
define|#
directive|define
name|bhnd_nv_isdigit
parameter_list|(
name|c
parameter_list|)
value|isdigit(c)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_isxdigit
parameter_list|(
name|c
parameter_list|)
value|isxdigit(c)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_toupper
parameter_list|(
name|c
parameter_list|)
value|((c) -	\     (('a' - 'A') * ((c)>= 'a'&& (c)<= 'z')))
end_define

begin_define
define|#
directive|define
name|bhnd_nv_malloc
parameter_list|(
name|size
parameter_list|)
value|malloc((size))
end_define

begin_define
define|#
directive|define
name|bhnd_nv_calloc
parameter_list|(
name|n
parameter_list|,
name|size
parameter_list|)
value|calloc((n), (size))
end_define

begin_define
define|#
directive|define
name|bhnd_nv_reallocf
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
value|reallocf((buf), (size))
end_define

begin_define
define|#
directive|define
name|bhnd_nv_free
parameter_list|(
name|buf
parameter_list|)
value|free((buf))
end_define

begin_define
define|#
directive|define
name|bhnd_nv_strdup
parameter_list|(
name|str
parameter_list|)
value|strdup(str)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_strndup
parameter_list|(
name|str
parameter_list|,
name|len
parameter_list|)
value|strndup(str, len)
end_define

begin_define
define|#
directive|define
name|bhnd_nv_asprintf
parameter_list|(
name|buf
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|asprintf((buf), fmt, ## __VA_ARGS__)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_define
define|#
directive|define
name|BHND_NV_INVARIANTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BHND_NV_INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|BHND_NV_ASSERT
parameter_list|(
name|expr
parameter_list|,
name|msg
parameter_list|)
value|do {				\ 	if (!(expr)) {							\ 		fprintf(stderr, "Assertion failed: %s, function %s, "	\ 		    "file %s, line %u\n", __STRING(expr), __FUNCTION__,	\ 		    __FILE__, __LINE__);				\ 		BHND_NV_PANIC msg;					\ 	}								\ } while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !BHND_NV_INVARIANTS */
end_comment

begin_define
define|#
directive|define
name|BHND_NV_ASSERT
parameter_list|(
name|expr
parameter_list|,
name|msg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BHND_NV_INVARIANTS */
end_comment

begin_define
define|#
directive|define
name|BHND_NV_VERBOSE
value|(0)
end_define

begin_define
define|#
directive|define
name|BHND_NV_PANIC
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	fprintf(stderr, "panic: " fmt "\n", ##__VA_ARGS__);	\ 	abort();						\ } while(0)
end_define

begin_define
define|#
directive|define
name|BHND_NV_LOG
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|fprintf(stderr, "%s: " fmt, __FUNCTION__, ##__VA_ARGS__)
end_define

begin_function
specifier|static
specifier|inline
name|uintmax_t
name|bhnd_nv_ummax
parameter_list|(
name|uintmax_t
name|a
parameter_list|,
name|uintmax_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uintmax_t
name|bhnd_nv_ummin
parameter_list|(
name|uintmax_t
name|a
parameter_list|,
name|uintmax_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BHND_NV_VERBOSE
end_ifdef

begin_define
define|#
directive|define
name|BHND_NV_DEBUG
parameter_list|(
modifier|...
parameter_list|)
value|BHND_NV_LOG(__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !BHND_NV_VERBOSE */
end_comment

begin_define
define|#
directive|define
name|BHND_NV_DEBUG
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BHND_NV_VERBOSE */
end_comment

begin_comment
comment|/* Limit a size_t value to a suitable range for use as a printf string field  * width */
end_comment

begin_define
define|#
directive|define
name|BHND_NV_PRINT_WIDTH
parameter_list|(
name|_len
parameter_list|)
define|\
value|((_len)> (INT_MAX) ? (INT_MAX) : (int)(_len))
end_define

begin_function_decl
name|int
name|bhnd_nvram_value_coerce
parameter_list|(
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
name|bhnd_nvram_value_check_aligned
parameter_list|(
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
name|bhnd_nvram_value_nelem
parameter_list|(
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
parameter_list|,
name|size_t
modifier|*
name|nelem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|bhnd_nvram_value_size
parameter_list|(
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
parameter_list|,
name|size_t
name|nelem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_value_printf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
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
parameter_list|,
name|char
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_value_vprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
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
parameter_list|,
name|char
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|bhnd_nvram_value_array_next
parameter_list|(
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
parameter_list|,
specifier|const
name|void
modifier|*
name|prev
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhnd_nvram_vardefn
modifier|*
name|bhnd_nvram_find_vardefn
parameter_list|(
specifier|const
name|char
modifier|*
name|varname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhnd_nvram_vardefn
modifier|*
name|bhnd_nvram_get_vardefn
parameter_list|(
name|size_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|bhnd_nvram_get_vardefn_id
parameter_list|(
specifier|const
name|struct
name|bhnd_nvram_vardefn
modifier|*
name|defn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_parse_int
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|maxlen
parameter_list|,
name|u_int
name|base
parameter_list|,
name|size_t
modifier|*
name|nbytes
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
name|bhnd_nvram_parse_env
parameter_list|(
specifier|const
name|char
modifier|*
name|env
parameter_list|,
name|size_t
name|env_len
parameter_list|,
name|char
name|delim
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|name
parameter_list|,
name|size_t
modifier|*
name|name_len
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|value
parameter_list|,
name|size_t
modifier|*
name|value_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|bhnd_nvram_parse_field
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|inp
parameter_list|,
name|size_t
name|ilen
parameter_list|,
name|char
name|delim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|bhnd_nvram_trim_field
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|inp
parameter_list|,
name|size_t
name|ilen
parameter_list|,
name|char
name|delim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|bhnd_nvram_trim_path_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_nvram_validate_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Calculate CRC-8 over @p buf using the Broadcom SPROM/NVRAM CRC-8  * polynomial.  *   * @param buf input buffer  * @param size buffer size  * @param crc last computed crc, or BHND_NVRAM_CRC8_INITIAL  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|bhnd_nvram_crc8
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|uint8_t
name|crc
parameter_list|)
block|{
specifier|const
name|uint8_t
modifier|*
name|p
init|=
operator|(
specifier|const
name|uint8_t
operator|*
operator|)
name|buf
decl_stmt|;
while|while
condition|(
name|size
operator|--
condition|)
name|crc
operator|=
name|bhnd_nvram_crc8_tab
index|[
operator|(
name|crc
operator|^
operator|*
name|p
operator|++
operator|)
index|]
expr_stmt|;
return|return
operator|(
name|crc
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|BHND_NVRAM_CRC8_INITIAL
value|0xFF
end_define

begin_comment
comment|/**< Initial bhnd_nvram_crc8 value */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_CRC8_VALID
value|0x9F
end_define

begin_comment
comment|/**< Valid CRC-8 checksum */
end_comment

begin_comment
comment|/** NVRAM variable flags */
end_comment

begin_enum
enum|enum
block|{
name|BHND_NVRAM_VF_MFGINT
init|=
literal|1
operator|<<
literal|0
block|,
comment|/**< mfg-internal variable; should not 					     be externally visible */
name|BHND_NVRAM_VF_IGNALL1
init|=
literal|1
operator|<<
literal|1
comment|/**< hide variable if its value has all 					     bits set. */
block|}
enum|;
end_enum

begin_comment
comment|/**  * SPROM layout flags  */
end_comment

begin_enum
enum|enum
block|{
comment|/** 	 * SPROM layout does not have magic identification value. 	 * 	 * This applies to SPROM revisions 1-3, where the actual 	 * layout must be determined by looking for a matching sromrev 	 * at the expected offset, and then verifying the CRC to ensure 	 * that the match was not a false positive. 	 */
name|SPROM_LAYOUT_MAGIC_NONE
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,	 }
enum|;
end_enum

begin_comment
comment|/** NVRAM variable definition */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_vardefn
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< variable name */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/**< human readable description, 						     or NULL */
specifier|const
name|char
modifier|*
name|help
decl_stmt|;
comment|/**< human readable help text, 						     or NULL */
name|bhnd_nvram_type
name|type
decl_stmt|;
comment|/**< variable type */
name|uint8_t
name|nelem
decl_stmt|;
comment|/**< element count, or 1 if not 						     an array-typed variable */
specifier|const
name|bhnd_nvram_val_fmt
modifier|*
name|fmt
decl_stmt|;
comment|/**< value format */
name|uint32_t
name|flags
decl_stmt|;
comment|/**< flags (BHND_NVRAM_VF_*) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * NVRAM variable definitions generated from nvram_map.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|bhnd_nvram_vardefn
name|bhnd_nvram_vardefns
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|bhnd_nvram_num_vardefns
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * SPROM layout descriptor.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bhnd_sprom_layout
block|{
name|size_t
name|size
decl_stmt|;
comment|/**< SPROM image size, in bytes */
name|uint8_t
name|rev
decl_stmt|;
comment|/**< SPROM revision */
name|uint8_t
name|flags
decl_stmt|;
comment|/**< layout flags (SPROM_LAYOUT_*) */
name|size_t
name|srev_offset
decl_stmt|;
comment|/**< offset to SROM revision */
name|size_t
name|magic_offset
decl_stmt|;
comment|/**< offset to magic value */
name|uint16_t
name|magic_value
decl_stmt|;
comment|/**< expected magic value */
name|size_t
name|crc_offset
decl_stmt|;
comment|/**< offset to crc8 value */
specifier|const
name|uint8_t
modifier|*
name|bindings
decl_stmt|;
comment|/**< SPROM binding opcode table */
name|size_t
name|bindings_size
decl_stmt|;
comment|/**< SPROM binding opcode table size */
name|uint16_t
name|num_vars
decl_stmt|;
comment|/**< total number of variables defined 					     for this layout by the binding 					     table */
block|}
name|bhnd_sprom_layout
typedef|;
end_typedef

begin_comment
comment|/*  * SPROM layout descriptions generated from nvram_map.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|bhnd_sprom_layout
name|bhnd_sprom_layouts
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|bhnd_sprom_num_layouts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * SPROM binding opcodes.  *   * Most opcodes are provided with two variants:  *  * - Standard:	The opcode's data directly follows the opcode. The data type  * 		(SPROM_OPCODE_DATA_*) is encoded in the opcode immediate (IMM).  * - Immediate:	The opcode's data is encoded directly in the opcode immediate  *		(IMM).  */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPC_MASK
value|0xF0
end_define

begin_comment
comment|/**< operation mask */
end_comment

begin_define
define|#
directive|define
name|SPROM_IMM_MASK
value|0x0F
end_define

begin_comment
comment|/**< immediate value mask */
end_comment

begin_define
define|#
directive|define
name|SPROM_IMM_MAX
value|SPROM_IMM_MASK
end_define

begin_define
define|#
directive|define
name|SPROM_OP_DATA_U8
value|0x00
end_define

begin_comment
comment|/**< data is u8 */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_DATA_U8_SCALED
value|0x01
end_define

begin_comment
comment|/**< data is u8; multiply by 						     type width */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_DATA_U16
value|0x02
end_define

begin_comment
comment|/**< data is u16-le */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_DATA_U32
value|0x03
end_define

begin_comment
comment|/**< data is u32-le */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_DATA_I8
value|0x04
end_define

begin_comment
comment|/**< data is i8 */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_EXT
value|0x00
end_define

begin_comment
comment|/**< extended opcodes defined 						     in IMM */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_EOF
value|0x00
end_define

begin_comment
comment|/**< marks end of opcode 						     stream */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_NELEM
value|0x01
end_define

begin_comment
comment|/**< variable array element 						     count follows as U8 */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_VAR_END
value|0x02
end_define

begin_comment
comment|/**< marks end of variable 						     definition */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_TYPE
value|0x03
end_define

begin_comment
comment|/**< input type follows as U8 						     (see BHND_NVRAM_TYPE_*) */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_VAR_IMM
value|0x10
end_define

begin_comment
comment|/**< variable ID (imm) */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_VAR_REL_IMM
value|0x20
end_define

begin_comment
comment|/**< relative variable ID 						     (last ID + imm) */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_VAR
value|0x30
end_define

begin_comment
comment|/**< variable ID */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_REV_IMM
value|0x40
end_define

begin_comment
comment|/**< revision range (imm) */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_REV_RANGE
value|0x50
end_define

begin_comment
comment|/**< revision range (8-bit range)*/
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_REV_RANGE_MAX
value|0x0F
end_define

begin_comment
comment|/**< maximum representable SROM 						     revision */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_REV_START_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|SPROM_OP_REV_START_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SPROM_OP_REV_END_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|SPROM_OP_REV_END_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SPROM_OPCODE_MASK_IMM
value|0x60
end_define

begin_comment
comment|/**< value mask (imm) */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_MASK
value|0x70
end_define

begin_comment
comment|/**< value mask */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_SHIFT_IMM
value|0x80
end_define

begin_comment
comment|/**< value shift (unsigned 						     imm, multipled by 2) */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_SHIFT
value|0x90
end_define

begin_comment
comment|/**< value shift */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_OFFSET_REL_IMM
value|0xA0
end_define

begin_comment
comment|/**< relative input offset 						     (last offset + 						      (imm * type width)) */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_OFFSET
value|0xB0
end_define

begin_comment
comment|/**< input offset */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_TYPE_IMM
value|0xC0
end_define

begin_comment
comment|/**< input type (imm, 						     see BHND_NVRAM_TYPE_*) */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_DO_BIND
value|0xD0
end_define

begin_comment
comment|/**< bind current value, 						     advance input/output 						     offsets as per IMM */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_BIND_SKIP_IN_MASK
value|0x03
end_define

begin_comment
comment|/**< the number of input 						     elements to advance after 						     the bind */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_BIND_SKIP_IN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SPROM_OP_BIND_SKIP_IN_SIGN
value|(1<<2)
end_define

begin_comment
comment|/**< SKIP_IN sign bit */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_BIND_SKIP_OUT_MASK
value|0x08
end_define

begin_comment
comment|/**< the number of output 						     elements to advance after 						     the bind */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_BIND_SKIP_OUT_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|SPROM_OPCODE_DO_BINDN_IMM
value|0xE0
end_define

begin_comment
comment|/**< bind IMM times, advancing 						     input/output offsets by one 						     element each time */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_DO_BINDN
value|0xF0
end_define

begin_comment
comment|/**< bind N times, advancing 						     input/output offsets as per 						     SPROM_OP_BIND_SKIP_IN/SPROM_OP_BIND_SKIP_OUT 						     IMM values. The U8 element 						     count follows. */
end_comment

begin_comment
comment|/** Evaluates to true if opcode is an extended opcode */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_IS_EXT
parameter_list|(
name|_opcode
parameter_list|)
define|\
value|(((_opcode)& SPROM_OPC_MASK) == SPROM_OPCODE_EXT)
end_define

begin_comment
comment|/** Return the opcode constant for a simple or extended opcode */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_OP
parameter_list|(
name|_opcode
parameter_list|)
define|\
value|(SPROM_OPCODE_IS_EXT(_opcode) ? (_opcode) : ((_opcode)& SPROM_OPC_MASK))
end_define

begin_comment
comment|/** Return the opcode immediate for a simple opcode, or zero if this is   * an extended opcode  */
end_comment

begin_define
define|#
directive|define
name|SPROM_OPCODE_IMM
parameter_list|(
name|_opcode
parameter_list|)
define|\
value|(SPROM_OPCODE_IS_EXT(_opcode) ? 0 : ((_opcode)& SPROM_IMM_MASK))
end_define

begin_comment
comment|/** Evaluates to true if the given opcode produces an implicit  *  SPROM_OPCODE_VAR_END instruction for any open variable */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_IS_IMPLICIT_VAR_END
parameter_list|(
name|_opcode
parameter_list|)
define|\
value|(((_opcode) == SPROM_OPCODE_VAR_IMM)	||	\      ((_opcode) == SPROM_OPCODE_VAR_REL_IMM)	||	\      ((_opcode) == SPROM_OPCODE_VAR)		||	\      ((_opcode) == SPROM_OPCODE_REV_IMM)	||	\      ((_opcode) == SPROM_OPCODE_REV_RANGE))
end_define

begin_comment
comment|/** Evaluates to true if the given opcode is either an explicit   * SPROM_OPCODE_VAR_END instruction, or is an opcode that produces an   * implicit terminatation of any open variable */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_IS_VAR_END
parameter_list|(
name|_opcode
parameter_list|)
define|\
value|(((_opcode) == SPROM_OPCODE_VAR_END) ||	\      SPROM_OP_IS_IMPLICIT_VAR_END(_opcode))
end_define

begin_comment
comment|/** maximum representable immediate value */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_IMM_MAX
value|SPROM_IMM_MASK
end_define

begin_comment
comment|/** maximum representable SROM revision */
end_comment

begin_define
define|#
directive|define
name|SPROM_OP_REV_MAX
value|MAX(SPROM_OP_REV_RANGE_MAX, SPROM_IMM_MAX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_PRIVATE_H_ */
end_comment

end_unit

